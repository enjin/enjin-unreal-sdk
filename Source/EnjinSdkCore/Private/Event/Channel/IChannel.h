// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Event
{
/**
 * @brief Interface for cloud event channels.
 */
class IChannel
{
public:
	/**
	 * @brief Class destructor.
	 */
	virtual ~IChannel() = default;

	/**
	 * @brief Returns the channel formatted as a string.
	 * @return The channel string.
	 */
	virtual const FString& GetChannel() const = 0;
};
}
}
}
