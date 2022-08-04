// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Pusher
{
/**
 * @brief Constants used in the Pusher protocol.
 */
class FPusherConstants final
{
public:
	FPusherConstants() = delete;

	~FPusherConstants() = delete;

	/**
	 * @brief Returns the prefix string for Pusher messages.
	 * @return The string.
	 */
	static FString PusherMessagePrefix();

	// Message keys

	/**
	 * @brief Returns the key for channel subscription messages.
	 * @return The key.
	 */
	static FString ChannelSubscribe();

	/**
	 * @brief Returns the key for channel subscription error messages.
	 * @return The key.
	 */
	static FString ChannelSubscriptionError();

	/**
	 * @brief Returns the key for channel subscription success messages.
	 * @return The key.
	 */
	static FString ChannelSubscriptionSucceeded();

	/**
	 * @brief Returns the key for channel unsubscription messages.
	 * @return The key.
	 */
	static FString ChannelUnsubscribe();

	// Protocol schemas

	/**
	 * @brief Returns the schema for not using encryption.
	 * @return The schema.
	 */
	static FString InsecureSchema();

	/**
	 * @brief Returns the schema for using encryption.
	 * @return The schema.
	 */
	static FString SecureSchema();
};
}
}
}
