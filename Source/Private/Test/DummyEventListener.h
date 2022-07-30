// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IEventListener.h"

namespace Enjin
{
namespace Sdk
{
namespace Test
{
/**
 * @brief Dummy event listener to be used in plugin tests.
 */
class FDummyEventListener final : public Event::IEventListener
{
public:
	FDummyEventListener() = default;

	virtual ~FDummyEventListener() override = default;

	virtual void NotificationReceived(const Model::FNotificationEvent& Event) override;
};
}
}
}
