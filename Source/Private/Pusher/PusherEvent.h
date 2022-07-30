// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"

namespace Enjin
{
namespace Sdk
{
namespace Pusher
{
/**
 * @brief Models Pusher events received from a Pusher server.
 */
class FPusherEvent final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructor an instance of this class.
	 */
	FPusherEvent() = default;

	/**
	 * @brief Default destructor.
	 */
	virtual ~FPusherEvent() override = default;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the name of the channel that the event was broadcasted on.
	 * @return The channel name.
	 */
	const TOptional<FString>& GetChannelName() const;

	/**
	 * @brief Returns the data of the event.
	 * @return The data.
	 */
	const TOptional<FString>& GetData() const;

	/**
	 * @brief Returns the name of the event.
	 * @return The event name.
	 */
	const TOptional<FString>& GetEventName() const;

	/**
	 * @brief Returns the user ID of the event.
	 * @return The user ID.
	 */
	const TOptional<FString>& GetUserId() const;

	bool operator==(const FPusherEvent& Rhs) const;

	bool operator!=(const FPusherEvent& Rhs) const;

private:
	TOptional<FString> ChannelName;
	TOptional<FString> Data;
	TOptional<FString> EventName;
	TOptional<FString> UserId;
};
}
}
}
