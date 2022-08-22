// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "Pusher/PusherEvent.h"

namespace Enjin
{
namespace Sdk
{
namespace Pusher
{
/**
 * @brief Interface for an event listener for receiving Pusher events.
 */
class ISubscriptionEventListener
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~ISubscriptionEventListener() = default;

	/**
	 * @brief Handler for Pusher events.
	 * @param Event The Pusher event.
	 */
	virtual void OnEvent(const FPusherEvent& Event) = 0;
};
}
}
}
