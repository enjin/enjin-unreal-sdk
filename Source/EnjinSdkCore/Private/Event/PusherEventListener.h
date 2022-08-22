// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "PusherEventService.h"
#include "Pusher/ISubscriptionEventListener.h"

namespace Enjin
{
namespace Sdk
{
namespace Event
{
/**
 * @brief Event listener for processing Pusher events and emitting them to listeners registered in an event service.
 */
class FPusherEventListener final : public Pusher::ISubscriptionEventListener
{
public:
	FPusherEventListener() = delete;

	/**
	 * @brief Constructs the listener and interfaces with the given event service.
	 * @param EventService The event service.
	 */
	explicit FPusherEventListener(FPusherEventService& EventService);

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPusherEventListener() override = default;

	/**
	 * @brief Handler for Pusher events.
	 * @param Event The Pusher event.
	 */
	virtual void OnEvent(const Pusher::FPusherEvent& Event) override;

private:
	FPusherEventService& EventService;
};
}
}
}
