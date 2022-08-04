// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "Event/Channel/IChannel.h"
#include "Model/Platform.h"

namespace Enjin
{
namespace Sdk
{
namespace Event
{
/**
 * @brief Represents a channel to subscribe to cloud events for projects.
 */
class FProjectChannel final : public IChannel
{
public:
	FProjectChannel() = delete;

	/**
	 * @brief Constructs an instance of this class.
	 * @param Platform The platform details.
	 * @param Project The project UUID.
	 */
	FProjectChannel(const Model::FPlatform& Platform, const FString& Project);

	/**
	 * @brief Class destructor.
	 */
	virtual ~FProjectChannel() override = default;

	/**
	 * @brief Returns the channel formatted as a string.
	 * @return The channel string.
	 */
	virtual const FString& GetChannel() const override;

private:
	const FString Channel;
};
}
}
}
