// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "GraphQlResponse.h"
#include "HttpLogLevel.h"
#include "IGraphQlRequest.h"
#include "LoggerProvider.h"
#include "ClientMiddleware.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"

namespace Enjin
{
namespace Sdk
{
/**
 * @brief Base class for schemas with functionality to send GraphQL requests to the platform and process the responses.
 */
class ENJINSDK_API FBaseSchema
{
public:
	FBaseSchema() = delete;

	/**
	 * @brief Default destructor.
	 */
	virtual ~FBaseSchema() = default;

	/**
	 * @brief Returns the logger provider used by this schema.
	 * @return The logger provider.
	 */
	const Util::FLoggerProviderPtr& GetLoggerProvider() const;

protected:
	/**
	 * @brief The middleware used by this schema.
	 */
	FClientMiddleware Middleware;

	/**
	 * @brief The type of this schema.
	 */
	const FString Schema;

	/**
	 * @brief The logger provider.
	 */
	const Util::FLoggerProviderPtr LoggerProvider;

	/**
	 * @brief Constructs an instance of this class.
	 * @param BaseUrl The base URL for the platform.
	 * @param Schema The schema type.
	 * @param HttpLogLevel The log level for HTTP traffic.
	 * @param LoggerProvider The logger provider.
	 */
	FBaseSchema(FString BaseUrl,
	            FString Schema,
	            const Http::EHttpLogLevel HttpLogLevel,
	            Util::FLoggerProviderPtr LoggerProvider = nullptr);

	/**
	 * @brief Sends a request for one result to the platform.
	 * @tparam T The type contained by the response.
	 * @param Request The request.
	 * @return The future for this operation.
	 */
	template <class T>
	TFuture<GraphQl::TGraphQlResponseForOnePtr<T>> SendRequestForOne(const GraphQl::IGraphQlRequest& Request)
	{
		return Async(EAsyncExecution::Thread, [this, HttpRequest = CreateRequest(Request)]()
		{
			if (HttpRequest == nullptr)
			{
				// Cannot use nullptr keyword due to issue with type deduction
				return GraphQl::TGraphQlResponseForOnePtr<T>();
			}

			const FHttpResponsePtr HttpResponse = SendRequest(HttpRequest);
			if (HttpResponse == nullptr)
			{
				// Cannot use nullptr keyword due to issue with type deduction
				return GraphQl::TGraphQlResponseForOnePtr<T>();
			}

			// Cannot use MakeShared due to issue with type deduction
			// ReSharper disable once CppSmartPointerVsMakeFunction
			return GraphQl::TGraphQlResponseForOnePtr<T>(
				new GraphQl::TGraphQlResponseForOne<T>(HttpResponse->GetContentAsString()));
		});
	}

	/**
	 * @brief Sends a request for many results to the platform.
	 * @tparam T The type contained by the response.
	 * @param Request The request.
	 * @return The future for this operation.
	 */
	template <class T>
	TFuture<GraphQl::TGraphQlResponseForManyPtr<T>>
	SendRequestForMany(const GraphQl::IGraphQlRequest& Request)
	{
		return Async(EAsyncExecution::Thread, [this, HttpRequest = CreateRequest(Request)]()
		{
			if (HttpRequest == nullptr)
			{
				// Cannot use nullptr keyword due to issue with type deduction
				return GraphQl::TGraphQlResponseForManyPtr<T>();
			}

			const FHttpResponsePtr HttpResponse = SendRequest(HttpRequest);
			if (HttpResponse == nullptr)
			{
				// Cannot use nullptr keyword due to issue with type deduction
				return GraphQl::TGraphQlResponseForManyPtr<T>();
			}

			// Cannot use MakeShared due to issue with type deduction
			// ReSharper disable once CppSmartPointerVsMakeFunction
			return GraphQl::TGraphQlResponseForManyPtr<T>(
				new GraphQl::TGraphQlResponseForMany<T>(HttpResponse->GetContentAsString()));
		});
	}

private:
	const Http::EHttpLogLevel HttpLogLevel;

	/**
	 * @brief Creates a HTTP request from a GraphQL request ready for sending to the platform.
	 * @param Request The GraphQL request.
	 * @return The HTTP request.
	 */
	TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> CreateRequest(const GraphQl::IGraphQlRequest& Request) const;

	/**
	 * @brief Logs a HTTP request if logging is enabled.
	 * @param Request The request.
	 */
	void LogRequest(const TSharedPtr<IHttpRequest, ESPMode::ThreadSafe>& Request);

	/**
	 * @brief Logs a HTTP response if logging is enabled.
	 * @param Response The response
	 * @param Rtt The round-trip time.
	 */
	void LogResponse(const FHttpResponsePtr& Response, const int32 Rtt);

	/**
	 * @brief Synchronously sends a HTTP request and gets the response.
	 * @param Request The request.
	 * @return The response.
	 */
	FHttpResponsePtr SendRequest(const TSharedPtr<IHttpRequest, ESPMode::ThreadSafe> Request);

	/**
	 * @brief Creates a request body for sending to the platform using a GraphQL request.
	 * @param Request The GraphQL request.
	 * @param OutBody The out string for the body.
	 * @return Whether the request body was created.
	 */
	bool TryCreateRequestBody(const GraphQl::IGraphQlRequest& Request, FString& OutBody) const;
};
}
}
