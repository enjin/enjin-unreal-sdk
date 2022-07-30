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
 * @brief Represents a channel to subscribe to cloud events for players.
 */
class FPlayerChannel final : public IChannel
{
public:
	FPlayerChannel() = delete;

	/**
	 * @brief Constructs an instance of this class.
	 * @param Platform The platform details.
	 * @param Project The project UUID.
	 * @param Player The player ID.
	 */
	FPlayerChannel(const Model::FPlatform& Platform, const FString& Project, const FString& Player);

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPlayerChannel() override = default;

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
