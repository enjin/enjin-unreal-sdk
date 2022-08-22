// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Pusher
{
/**
 * @brief Error codes that may be received from a Pusher server.
 */
enum class EPusherErrorCodes : int32
{
	/**
	 * @brief Catch all error code.
	 */
	Unknown = 0,
	SubscriptionError = 5003,
};
}
}
}
