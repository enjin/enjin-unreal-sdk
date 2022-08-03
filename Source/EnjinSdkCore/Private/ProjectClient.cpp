// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "ProjectClient.h"

// The namespace for this SDK's timer class is explicitly used to avoid confusion with UE's own FTimer class.
using namespace Enjin::Sdk;
using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Http;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

/**
 * @brief Convenience alias for nested builder class in @link FProjectClient @endlink.
 */
using FProjectClientBuilder = FProjectClient::FProjectClientBuilder;

FProjectClient::FProjectClient(FString BaseUrl,
                               FLoggerProviderPtr LoggerProvider,
                               const EHttpLogLevel HttpLogLevel,
                               const bool bEnableAutomaticReauthentication,
                               TOptional<TFunction<void()>> AuthenticationFailedHandlerOpt,
                               TOptional<TFunction<void()>> ReauthenticationStoppedHandlerOpt)
	: FProjectSchema(MoveTemp(BaseUrl), HttpLogLevel, MoveTemp(LoggerProvider)),
	  bIsAutomaticReauthenticationEnabled(bEnableAutomaticReauthentication),
	  AuthenticationFailedHandlerOpt(MoveTemp(AuthenticationFailedHandlerOpt)),
	  ReauthenticationStoppedHandlerOpt(MoveTemp(ReauthenticationStoppedHandlerOpt))
{
	if (bIsAutomaticReauthenticationEnabled)
	{
		AuthTimer = MakeShared<Enjin::Sdk::Util::FTimer, ESPMode::ThreadSafe>();
	}
}

void FProjectClient::Auth(FString Token)
{
	Auth(TOptional<FString>(MoveTemp(Token)), TOptional<int64>());
}

void FProjectClient::Auth(const FAccessToken AccessToken)
{
	const TOptional<FString>& Token = AccessToken.GetToken();
	const TOptional<int64>& ExpiresIn = AccessToken.GetExpiresIn();

	// Verifies the access token is not malformed
	if (Token.IsSet() ^ ExpiresIn.IsSet())
	{
		if (LoggerProvider.IsValid())
		{
			LoggerProvider->Log(ELogLevel::Error, TEXT("Access token has partial data"));
		}

		CallAuthFailedHandler();
		return;
	}

	Auth(Token, ExpiresIn);
}

void FProjectClient::Auth(const TOptional<FString> Token, TOptional<int64> ExpiresIn)
{
	bool bTimerRestarted = false;

	{
		std::lock_guard<std::mutex> Guard(AuthMutex);

		if (IsAutomaticReauthenticationEnabled() && UuidOpt.IsSet() && SecretOpt.IsSet())
		{
			bTimerRestarted = RestartAuthenticationTimer(MoveTemp(ExpiresIn));
		}
	}

	Middleware.SetAuthToken(Token.Get(TEXT("")));

	if (ReauthenticationStoppedHandlerOpt.IsSet() && AuthTimer != nullptr && !bTimerRestarted)
	{
		ReauthenticationStoppedHandlerOpt.GetValue()();
	}
}

TFuture<bool> FProjectClient::AuthClient(FString Uuid, FString Secret)
{
	if (IsAutomaticReauthenticationEnabled())
	{
		{
			std::lock_guard<std::mutex> Guard(AuthMutex);

			UuidOpt.Emplace(Uuid);
			SecretOpt.Emplace(Secret);
		}
	}

	return SendRequestAndAuth(MoveTemp(Uuid), MoveTemp(Secret));
}

void FProjectClient::CallAuthFailedHandler() const
{
	if (AuthenticationFailedHandlerOpt.IsSet())
	{
		AuthenticationFailedHandlerOpt.GetValue()();
	}
}

bool FProjectClient::IsAutomaticReauthenticationEnabled() const
{
	return bIsAutomaticReauthenticationEnabled;
}

bool FProjectClient::IsAuthenticated() const
{
	return Middleware.IsAuthenticated();
}

bool FProjectClient::IsReauthenticationRunning() const
{
	std::lock_guard<std::mutex> Guard(AuthMutex);
	return bIsReauthenticationRunning;
}

bool FProjectClient::RestartAuthenticationTimer(TOptional<int64> DurationOpt)
{
	AuthTimer->Cancel();
	bIsReauthenticationRunning = false;

	if (!DurationOpt.IsSet() || DurationOpt.GetValue() < 1)
	{
		return false;
	}

	int64 Duration = DurationOpt.GetValue();
	if (Duration - PreemptAuthExpirationTime > 0)
	{
		Duration -= PreemptAuthExpirationTime;
	}

	AuthTimer->Schedule([this]()
	{
		SendRequestAndAuth();
	}, Duration * 1000 /* Conversion from seconds to milliseconds */);
	bIsReauthenticationRunning = true;

	return true;
}

void FProjectClient::SendRequestAndAuth()
{
	bool bIsProjectDataPresent = false;
	FString Uuid;
	FString Secret;

	{
		std::lock_guard<std::mutex> Guard(AuthMutex);

		if (UuidOpt.IsSet() && SecretOpt.IsSet())
		{
			bIsProjectDataPresent = true;
			Uuid = UuidOpt.GetValue();
			Secret = SecretOpt.GetValue();
		}
	}

	if (bIsProjectDataPresent)
	{
		SendRequestAndAuth(MoveTemp(Uuid), MoveTemp(Secret));
		return;
	}

	if (LoggerProvider.IsValid())
	{
		LoggerProvider->Log(ELogLevel::Error,
		                    TEXT("Project UUID or secret were not set while attempting reauthentication"));
	}

	CallAuthFailedHandler();
}

TFuture<bool> FProjectClient::SendRequestAndAuth(FString Uuid, FString Secret)
{
	return Async(EAsyncExecution::Thread, [this, Uuid = MoveTemp(Uuid), Secret = MoveTemp(Secret)]()
	{
		const FAuthProject Req = FAuthProject().SetUuid(Uuid)
		                                       .SetSecret(Secret);

		const TGraphQlResponseForOnePtr<FAccessToken> Res = AuthProject(Req).Get();
		if (Res.IsValid() && Res->IsSuccessful())
		{
			Auth(Res->GetResult().GetValue());
		}
		else
		{
			Auth(TOptional<FString>(), TOptional<int64>());
		}

		return IsAuthenticated();
	});
}

FProjectClientBuilder FProjectClient::Builder()
{
	return FProjectClientBuilder();
}

FProjectClientBuilder& FProjectClientBuilder::AuthenticationFailedHandler(TFunction<void()> Handler)
{
	AuthenticationFailedHandlerOpt.Emplace(MoveTemp(Handler));
	return *this;
}

TUniquePtr<FProjectClient> FProjectClientBuilder::Build() const
{
	if (!BaseUrlOpt.IsSet())
	{
		return nullptr;
	}

	return TUniquePtr<FProjectClient>(new FProjectClient(BaseUrlOpt.GetValue(),
	                                                     LoggerProviderOpt.Get(nullptr),
	                                                     HttpLogLevelOpt.Get(EHttpLogLevel::None),
	                                                     EnableAutomaticReauthenticationOpt.Get(false),
	                                                     AuthenticationFailedHandlerOpt,
	                                                     ReauthenticationStoppedHandlerOpt));
}

FProjectClientBuilder& FProjectClientBuilder::BaseUrl(FString Url)
{
	BaseUrlOpt = MoveTemp(Url);
	return *this;
}

FProjectClientBuilder& FProjectClientBuilder::EnableAutomaticReauthentication()
{
	EnableAutomaticReauthenticationOpt = true;
	return *this;
}

FProjectClientBuilder& FProjectClientBuilder::HttpLogLevel(const EHttpLogLevel HttpLogLevel)
{
	HttpLogLevelOpt = HttpLogLevel;
	return *this;
}

FProjectClientBuilder& FProjectClientBuilder::LoggerProvider(FLoggerProviderPtr LoggerProvider)
{
	LoggerProviderOpt = MoveTemp(LoggerProvider);
	return *this;
}

FProjectClientBuilder& FProjectClientBuilder::ReauthenticationStoppedHandler(TFunction<void()> Handler)
{
	ReauthenticationStoppedHandlerOpt = MoveTemp(Handler);
	return *this;
}
