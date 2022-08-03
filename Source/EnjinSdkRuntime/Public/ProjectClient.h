// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IClient.h"
#include "Timer.h"
#include "Model/AccessToken.h"
#include "Project/ProjectSchema.h"
#include <mutex>

namespace Enjin
{
namespace Sdk
{
/**
 * @brief Platform client based on the project schema.
 */
class ENJINSDKRUNTIME_API FProjectClient final : public IClient,
                                          public Project::FProjectSchema
{
public:
	class FProjectClientBuilder;

	FProjectClient() = delete;

	FProjectClient(const FProjectClient&) = delete;

	FProjectClient(FProjectClient&&) = delete;

	/**
	 * @brief Default destructor.
	 */
	virtual ~FProjectClient() override = default;

	/**
	 * @brief Authenticates this client with the given authentication token.
	 * @param Token The authentication token.
	 * @remarks If this client has automatic reauthentication enabled, then this method will halt the reauthentication
	 * timer.
	 */
	virtual void Auth(FString Token) override;

	/**
	 * @brief Authenticates this client with the given access token model.
	 * @param AccessToken The access token.
	 * @remarks If this client has automatic reauthentication enabled, then this method may halt the reauthentication
	 * timer if the access token is malformed, empty, or would otherwise result in this client no longer being
	 * authenticated.
	 */
	void Auth(const Model::FAccessToken AccessToken);

	/**
	 * @brief Sends a request to the platform to authenticate this client.
	 * @param Uuid The project's UUID.
	 * @param Secret The project's secret.
	 * @return The future for this operation.
	 * @remarks If this client is enabled for automatic reauthentication, then it will cache the UUID and secret and
	 * reauthenticate itself before the access token returned by the platform expires.
	 */
	TFuture<bool> AuthClient(FString Uuid, FString Secret);

	/**
	 * @brief Determines if this client is authenticated.
	 * @return Whether this client is authenticated.
	 */
	virtual bool IsAuthenticated() const override;

	/**
	 * @brief Determines if this client is enabled for automatic reauthentication.
	 * @return Whether this client is enabled for automatic reauthentication.
	 */
	bool IsAutomaticReauthenticationEnabled() const;

	/**
	 * @brief Determines if the reauthentication timer is running.
	 * @return Whether the reauthentication timer is running.
	 */
	bool IsReauthenticationRunning() const;

	/**
	 * @brief Creates a builder for this class.
	 * @return The builder.
	 */
	static FProjectClientBuilder Builder();

	/**
	 * @brief Builder class for @link FProjectClient @endlink.
	 */
	class ENJINSDKRUNTIME_API FProjectClientBuilder final
	{
	public:
		/**
		 * @brief Default destructor.
		 */
		~FProjectClientBuilder() = default;

		/**
		 * @brief Sets the handler to be used by the client in the event that its fails to authenticate due to a faulty
		 * state.
		 * @param Handler The handler.
		 * @return This builder for chaining.
		 */
		FProjectClientBuilder& AuthenticationFailedHandler(TFunction<void()> Handler);

		/**
		 * @brief Builds the client.
		 * @return The client.
		 */
		TUniquePtr<FProjectClient> Build() const;

		/**
		 * @brief Sets the base URL for the platform that the client will be using.
		 * @param Url The URL.
		 * @return This builder for chaining.
		 */
		FProjectClientBuilder& BaseUrl(FString Url);

		/**
		 * @brief Enables the client to automatically reauthenticate itself when authenticated using its
		 * @link AuthClient @endlink member-function.
		 * @return This builder for chaining.
		 */
		FProjectClientBuilder& EnableAutomaticReauthentication();

		/**
		 * @brief Sets the log level for HTTP traffic processed by the client.
		 * @param HttpLogLevel The log level for HTTP traffic.
		 * @return This builder for chaining.
		 */
		FProjectClientBuilder& HttpLogLevel(const Http::EHttpLogLevel HttpLogLevel);

		/**
		 * @brief Sets the logger provider the client will use.
		 * @param LoggerProvider The logger provider
		 * @return This builder for chaining.
		 */
		FProjectClientBuilder& LoggerProvider(Util::FLoggerProviderPtr LoggerProvider);

		/**
		 * @brief Sets the handler to be used by the client in the event that its automatic reauthentication is halted.
		 * @param Handler The handler.
		 * @return This builder for chaining.
		 */
		FProjectClientBuilder& ReauthenticationStoppedHandler(TFunction<void()> Handler);

	private:
		TOptional<TFunction<void()>> AuthenticationFailedHandlerOpt;
		TOptional<FString> BaseUrlOpt;
		TOptional<bool> EnableAutomaticReauthenticationOpt;
		TOptional<Util::FLoggerProviderPtr> LoggerProviderOpt;
		TOptional<Http::EHttpLogLevel> HttpLogLevelOpt;
		TOptional<TFunction<void()>> ReauthenticationStoppedHandlerOpt;

		/**
		 * @brief Default constructor.
		 */
		FProjectClientBuilder() = default;

		friend FProjectClientBuilder FProjectClient::Builder();
	};

private:
	const bool bIsAutomaticReauthenticationEnabled;
	bool bIsReauthenticationRunning = false;
	TSharedPtr<Util::FTimer, ESPMode::ThreadSafe> AuthTimer;
	TOptional<FString> UuidOpt;
	TOptional<FString> SecretOpt;

	// Auth handlers
	const TOptional<TFunction<void()>> AuthenticationFailedHandlerOpt;
	const TOptional<TFunction<void()>> ReauthenticationStoppedHandlerOpt;

	// Mutexes
	mutable std::mutex AuthMutex;

	/**
	 * @brief Amount of time in seconds to preempt the expiration period of an access token.
	 */
	static constexpr int16 PreemptAuthExpirationTime = 60;

	/**
	 * @brief Constructs an instance of this class.
	 * @param BaseUrl The base URL for the platform.
	 * @param LoggerProvider The logger provider.
	 * @param HttpLogLevel The log level for HTTP traffic.
	 * @param bEnableAutomaticReauthentication Whether automatic reauthentication will be enabled.
	 * @param AuthenticationFailedHandlerOpt The handler for failed authentication attempts.
	 * @param ReauthenticationStoppedHandlerOpt The handler for when reauthentication is stopped.
	 */
	FProjectClient(FString BaseUrl,
	               Util::FLoggerProviderPtr LoggerProvider,
	               const Http::EHttpLogLevel HttpLogLevel,
	               const bool bEnableAutomaticReauthentication,
	               TOptional<TFunction<void()>> AuthenticationFailedHandlerOpt,
	               TOptional<TFunction<void()>> ReauthenticationStoppedHandlerOpt);

	/**
	 * @brief Authenticates this client with the given authentication token and resets the reauthentication timer if
	 * appropriate.
	 * @param Token The authentication token.
	 * @param ExpiresIn The time in seconds until the authentication token expires.
	 */
	void Auth(const TOptional<FString> Token, TOptional<int64> ExpiresIn);

	/**
	 * @brief Convenience function for calling the handler contained within
	 * @link AuthenticationFailedHandlerOpt @endlink if it is set.
	 */
	void CallAuthFailedHandler() const;

	/**
	 * @brief Tries to restart the reauthentication timer.
	 * @param DurationOpt The duration in seconds.
	 * @return Whether the timer was restarted.
	 */
	bool RestartAuthenticationTimer(TOptional<int64> DurationOpt);

	/**
	 * @brief Helper function to send the authentication request by verifying the UUID and secret are set in a
	 * thread-safe manner.
	 */
	void SendRequestAndAuth();

	/**
	 * @brief Sends a authentication request to the platform and authenticates this client with the resulting
	 * access token.
	 * @param Uuid The project's UUID.
	 * @param Secret The project's secret.
	 * @return The future for this operation.
	 */
	TFuture<bool> SendRequestAndAuth(FString Uuid, FString Secret);
};
}
}
