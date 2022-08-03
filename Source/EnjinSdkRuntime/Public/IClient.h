// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
/**
 * @brief Interface for platform clients.
 */
class ENJINSDKRUNTIME_API IClient
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~IClient() = default;

	/**
	 * @brief Authenticates this client with the given authentication token.
	 * @param Token The authentication token.
	 */
	virtual void Auth(FString Token) = 0;

	/**
	 * @brief Determines if this client is authenticated.
	 * @return Whether this client is authenticated.
	 */
	virtual bool IsAuthenticated() const = 0;
};
}
}
