// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "Model/NotificationEvent.h"

namespace Enjin
{
namespace Sdk
{
namespace Event
{
/**
 * @brief Event listener interface for notifications from the platform.
 */
class ENJINSDK_API IEventListener
{
public:
	/**
	 * @brief Class destructor.
	 */
	virtual ~IEventListener() = default;

	/**
	 * @brief Called when an event is received.
	 * @param Event The event.
	 */
	virtual void NotificationReceived(const Model::FNotificationEvent& Event) = 0;
};
}
}
}
