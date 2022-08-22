// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "ClientMiddleware.h"

#include "HttpModule.h"
#include "StringUtil.h"
#include "Interfaces/IPluginManager.h"

using namespace Enjin::Sdk;
using namespace Enjin::Sdk::Util;

FClientMiddleware::FClientMiddleware(FString BaseUrl) : BaseUrl(MoveTemp(BaseUrl))
{
	const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("EnjinSdk"));
	UserAgentVersion = Plugin->GetDescriptor().VersionName;
}

TSharedRef<IHttpRequest, ESPMode::ThreadSafe> FClientMiddleware::CreateRequest() const
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();

	Request->SetTimeout(20);
	Request->SetHeader(TEXT("User-Agent"), FString::Printf(TEXT("Enjin Unreal SDK v%s"), *UserAgentVersion));

	std::unique_lock<std::mutex> Lock(AuthTokenMutex);
	if (!AuthToken.IsEmpty())
	{
		Request->SetHeader(TEXT("Authorization"), FString::Printf(TEXT("Bearer %s"), *AuthToken));
	}
	Lock.unlock();

	return Request;
}

const FString& FClientMiddleware::GetBaseUrl() const
{
	return BaseUrl;
}

bool FClientMiddleware::IsAuthenticated() const
{
	std::lock_guard<std::mutex> Guard(AuthTokenMutex);
	return !FStringUtil::IsEmptyOrWhitespace(AuthToken);
}

void FClientMiddleware::SetAuthToken(FString Token)
{
	std::lock_guard<std::mutex> Guard(AuthTokenMutex);
	AuthToken = MoveTemp(Token);
}
