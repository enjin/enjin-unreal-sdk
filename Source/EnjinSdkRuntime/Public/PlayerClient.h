// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IClient.h"
#include "Player/PlayerSchema.h"

namespace Enjin
{
namespace Sdk
{
/**
 * @brief Platform client based on the player schema.
 */
class ENJINSDKRUNTIME_API FPlayerClient final : public IClient,
                                         public Player::FPlayerSchema
{
public:
	class FPlayerClientBuilder;

	FPlayerClient() = delete;

	FPlayerClient(const FPlayerClient&) = delete;

	FPlayerClient(FPlayerClient&&) = delete;

	/**
	 * @brief Default destructor.
	 */
	virtual ~FPlayerClient() override = default;

	/**
	 * @brief Authenticates this client with the given authentication token.
	 * @param Token The authentication token.
	 */
	virtual void Auth(FString Token) override;

	/**
	 * @brief Determines if this client is authenticated.
	 * @return Whether this client is authenticated.
	 */
	virtual bool IsAuthenticated() const override;

	/**
	 * @brief Creates a builder for this class.
	 * @return The builder.
	 */
	static FPlayerClientBuilder Builder();

	/**
	 * @brief Builder class for @link FPlayerClient @endlink.
	 */
	class ENJINSDKRUNTIME_API FPlayerClientBuilder final
	{
	public:
		/**
		 * @brief Default destructor.
		 */
		~FPlayerClientBuilder() = default;

		/**
		 * @brief Builds the client.
		 * @return The client.
		 */
		TUniquePtr<FPlayerClient> Build() const;

		/**
		 * @brief Sets the base URL for the platform that the client will be using.
		 * @param Url The URL.
		 * @return This builder for chaining.
		 */
		FPlayerClientBuilder& BaseUrl(FString Url);

		/**
		 * @brief Sets the log level for HTTP traffic processed by the client.
		 * @param HttpLogLevel The log level for HTTP traffic.
		 * @return This builder for chaining.
		 */
		FPlayerClientBuilder& HttpLogLevel(const Http::EHttpLogLevel HttpLogLevel);

		/**
		 * @brief Sets the logger provider the client will use.
		 * @param LoggerProvider The logger provider
		 * @return This builder for chaining.
		 */
		FPlayerClientBuilder& LoggerProvider(Util::FLoggerProviderPtr LoggerProvider);

	private:
		TOptional<FString> BaseUrlOpt;
		TOptional<Http::EHttpLogLevel> HttpLogLevelOpt;
		TOptional<Util::FLoggerProviderPtr> LoggerProviderOpt;

		/**
		 * @brief Default constructor.
		 */
		FPlayerClientBuilder() = default;

		friend FPlayerClientBuilder FPlayerClient::Builder();
	};

private:
	/**
	 * @brief Constructs an instance of this class.
	 * @param BaseUrl The base URL for the platform.
	 * @param LoggerProvider The logger provider.
	 * @param HttpLogLevel The log level for HTTP traffic.
	 */
	explicit FPlayerClient(FString BaseUrl,
	                       Util::FLoggerProviderPtr LoggerProvider,
	                       const Http::EHttpLogLevel HttpLogLevel);
};
}
}
