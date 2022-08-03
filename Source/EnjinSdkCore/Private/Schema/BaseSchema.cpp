// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "BaseSchema.h"

#include "GraphQl/TemplateConstants.h"
#include <chrono>

using namespace Enjin::Sdk;
using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Http;
using namespace Enjin::Sdk::Util;

FBaseSchema::FBaseSchema(FString BaseUrl,
                         FString Schema,
                         const EHttpLogLevel HttpLogLevel,
                         FLoggerProviderPtr LoggerProvider)
	: Middleware(MoveTemp(BaseUrl)),
	  Schema(MoveTemp(Schema)),
	  LoggerProvider(MoveTemp(LoggerProvider)),
	  HttpLogLevel(HttpLogLevel)
{
}

TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> FBaseSchema::CreateRequest(const IGraphQlRequest& Request) const
{
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = Middleware.CreateRequest();

	FString Body;
	if (!TryCreateRequestBody(Request, Body))
	{
		return nullptr;
	}

	HttpRequest->SetVerb(TEXT("POST"));
	HttpRequest->SetURL(FString::Printf(TEXT("%s/graphql/%s"), *Middleware.GetBaseUrl(), *Schema));
	HttpRequest->SetContentAsString(Body);
	HttpRequest->SetHeader(TEXT("Content-Type"), TEXT("application/json; charset=utf-8"));

	return HttpRequest;
}

const FLoggerProviderPtr& FBaseSchema::GetLoggerProvider() const
{
	return LoggerProvider;
}

void FBaseSchema::LogRequest(const TSharedPtr<IHttpRequest, ESPMode::ThreadSafe>& Request)
{
	if (HttpLogLevel == EHttpLogLevel::None || !LoggerProvider.IsValid())
	{
		return;
	}

	TStringBuilder<1000> Builder;
	const FString Method = Request->GetVerb();
	const FString Url = Request->GetURL();
	const int32 ContentLength = Request->GetContentLength();

	// Basic
	if (HttpLogLevel == EHttpLogLevel::Basic)
	{
		Builder.Appendf(TEXT("--> %s %s (%d-byte body)\n"), *Method, *Url, ContentLength);
		LoggerProvider->Log(Builder.ToString());
		return;
	}

	Builder.Appendf(TEXT("--> %s %s\n"), *Method, *Url);

	// Headers
	for (const FString& Header : Request->GetAllHeaders())
	{
		Builder.Append(Header).Append(TEXT("\n"));
	}

	if (HttpLogLevel == EHttpLogLevel::Headers)
	{
		Builder.Appendf(TEXT("<-- END %s\n"), *Method);
		LoggerProvider->Log(Builder.ToString());
		return;
	}

	// Body
	Builder.Append(TEXT("\n"))
	       .Append(BytesToString(Request->GetContent().GetData(), ContentLength))
	       .Appendf(TEXT("\n<-- END %s (%d-byte body)"), *Method, ContentLength);
}

void FBaseSchema::LogResponse(const FHttpResponsePtr& Response, const int32 Rtt)
{
	if (HttpLogLevel == EHttpLogLevel::None || !LoggerProvider.IsValid())
	{
		return;
	}

	TStringBuilder<1000> Builder;
	const int32 Status = Response->GetResponseCode();
	const FString Url = Response->GetURL();

	// Basic
	Builder.Appendf(TEXT("<-- %d %s (%dms)\n"), Status, *Url, Rtt);

	if (HttpLogLevel == EHttpLogLevel::Basic)
	{
		LoggerProvider->Log(Builder.ToString());
		return;
	}

	// Headers
	for (const FString& Header : Response->GetAllHeaders())
	{
		Builder.Append(Header).Append(TEXT("\n"));
	}

	if (HttpLogLevel == EHttpLogLevel::Headers)
	{
		Builder.Append(TEXT("<-- END HTTP\n"));
		LoggerProvider->Log(Builder.ToString());
		return;
	}

	// Body
	Builder.Append(TEXT("\n"))
	       .Append(Response->GetContentAsString())
	       .Append(TEXT("\n<-- END HTTP\n"));

	LoggerProvider->Log(Builder.ToString());
}

FHttpResponsePtr FBaseSchema::SendRequest(const TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> Request)
{
	if (!Request.IsValid())
	{
		return nullptr;
	}

	LogRequest(Request);
	const std::chrono::time_point<std::chrono::steady_clock> Start = std::chrono::high_resolution_clock::now();

	if (!Request->ProcessRequest())
	{
		return nullptr;
	}

	FHttpResponsePtr Response = Request->GetResponse();
	while (Response == nullptr)
	{
		FPlatformProcess::YieldThread();
		Response = Request->GetResponse();
	}

	while (true)
	{
		const int32 Code = Response->GetResponseCode();
		if (Code != 0)
		{
			const std::chrono::time_point<std::chrono::steady_clock> End = std::chrono::high_resolution_clock::now();
			const int32 Rtt = std::chrono::duration_cast<std::chrono::milliseconds>(End - Start).count();
			LogResponse(Response, Rtt);

			return Response;
		}

		FPlatformProcess::YieldThread();
	}
}

bool FBaseSchema::TryCreateRequestBody(const IGraphQlRequest& Request, FString& OutBody) const
{
	const TMap<FString, FString>& Templates = FTemplateConstants::Templates;

	if (!Templates.Contains(Request.GetNamespace()))
	{
		LoggerProvider->Log(ELogLevel::Warn,
		                    FString::Printf(TEXT("Could not find query entry for namespace '%s'"),
		                                    *Request.GetNamespace()));

		return false;
	}

	const FString Query = Templates.FindRef(Request.GetNamespace());
	const FString RequestVariables = Request.Serialize();
	OutBody = FString::Printf(TEXT("{\"query\":\"%s\",\"variables\":%s}"), *Query, *RequestVariables);

	return true;
}
