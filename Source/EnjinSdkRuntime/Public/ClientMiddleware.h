// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "Interfaces/IHttpRequest.h"
#include <mutex>

namespace Enjin
{
namespace Sdk
{
/**
 * @brief Middleware for communicating with the platform.
 */
class ENJINSDK_API FClientMiddleware final
{
public:
	FClientMiddleware() = delete;

	/**
	 * @brief Constructs an instance of this class.
	 * @param BaseUrl The base URL.
	 */
	explicit FClientMiddleware(FString BaseUrl);

	/**
	 * @brief Class destructor.
	 */
	~FClientMiddleware() = default;

	/**
	 * @brief Creates a new HTTP request and sets any necessary data needed for communicating with the platform.
	 * @return The shared reference to the request.
	 */
	TSharedRef<IHttpRequest, ESPMode::ThreadSafe> CreateRequest() const;

	/**
	 * @brief Returns the base URL for this middleware.
	 * @return The base URL.
	 */
	const FString& GetBaseUrl() const;

	/**
	 * @brief Determines whether this middleware is authenticated.
	 * @return Whether this middleware is authenticated.
	 */
	bool IsAuthenticated() const;

	/**
	 * @brief Sets the authentication token for this middleware.
	 * @param Token The authentication token.
	 */
	void SetAuthToken(FString Token);

private:
	FString AuthToken;
	const FString BaseUrl;
	FString UserAgentVersion;

	// Mutexes
	mutable std::mutex AuthTokenMutex;
};
}
}
