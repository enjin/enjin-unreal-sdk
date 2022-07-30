// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PlayerClient.h"

using namespace Enjin::Sdk;
using namespace Enjin::Sdk::Http;
using namespace Enjin::Sdk::Util;

/**
 * @brief Convenience alias for nested builder class in @link FPlayerClient @endlink.
 */
using FPlayerClientBuilder = FPlayerClient::FPlayerClientBuilder;

FPlayerClient::FPlayerClient(FString BaseUrl, FLoggerProviderPtr LoggerProvider, const EHttpLogLevel HttpLogLevel)
	: FPlayerSchema(MoveTemp(BaseUrl), HttpLogLevel, MoveTemp(LoggerProvider))
{
}

void FPlayerClient::Auth(FString Token)
{
	Middleware.SetAuthToken(MoveTemp(Token));
}

bool FPlayerClient::IsAuthenticated() const
{
	return Middleware.IsAuthenticated();
}

FPlayerClientBuilder FPlayerClient::Builder()
{
	return FPlayerClientBuilder();
}

TUniquePtr<FPlayerClient> FPlayerClientBuilder::Build() const
{
	if (!BaseUrlOpt.IsSet())
	{
		return nullptr;
	}

	return TUniquePtr<FPlayerClient>(new FPlayerClient(BaseUrlOpt.GetValue(),
	                                                   LoggerProviderOpt.Get(nullptr),
	                                                   HttpLogLevelOpt.Get(EHttpLogLevel::None)));
}

FPlayerClientBuilder& FPlayerClientBuilder::BaseUrl(FString Url)
{
	BaseUrlOpt = MoveTemp(Url);
	return *this;
}

FPlayerClientBuilder& FPlayerClientBuilder::HttpLogLevel(const Http::EHttpLogLevel HttpLogLevel)
{
	HttpLogLevelOpt = HttpLogLevel;
	return *this;
}

FPlayerClientBuilder& FPlayerClientBuilder::LoggerProvider(FLoggerProviderPtr LoggerProvider)
{
	LoggerProviderOpt = MoveTemp(LoggerProvider);
	return *this;
}
