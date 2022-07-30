// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Pusher
{
/**
 * @brief Enums for different connection states for a Pusher client.
 */
enum class EPusherConnectionState
{
	/**
	 * @brief Value used to indicate any state when used as a function argument.
	 */
	All,
	Connected,
	Connecting,
	Disconnected,
	Disconnecting,
	Reconnecting,
};

/**
 * @brief Serializes the connection state into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
const TCHAR* ToString(const EPusherConnectionState Value);
}
}
}
