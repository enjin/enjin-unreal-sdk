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
 * @brief Represents a channel to subscribe to cloud events for assets.
 */
class FAssetChannel final : public IChannel
{
public:
	FAssetChannel() = delete;

	/**
	 * @brief Constructs an instance of this class.
	 * @param Platform The platform details.
	 * @param Asset The asset ID.
	 */
	FAssetChannel(const Model::FPlatform& Platform, const FString& Asset);

	/**
	 * @brief Class destructor.
	 */
	virtual ~FAssetChannel() override = default;

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
