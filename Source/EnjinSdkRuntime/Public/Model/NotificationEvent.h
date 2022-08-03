// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "Dom/JsonObject.h"
#include "Model/EventType.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Container class for notification data from the platform.
 */
class ENJINSDKRUNTIME_API FNotificationEvent final
{
public:
	FNotificationEvent() = delete;

	/**
	 * @brief Constructs an instance of this class with the given data.
	 * @param Type The event type.
	 * @param Channel The event channel.
	 * @param Message The serialized message.
	 */
	FNotificationEvent(const EEventType Type, FString Channel, FString Message);

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FNotificationEvent(const FNotificationEvent& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FNotificationEvent(FNotificationEvent&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	~FNotificationEvent();

	/**
	 * @brief Returns the channel the event was broadcasted on.
	 * @return The channel.
	 */
	const FString& GetChannel() const;

	/**
	 * @brief Returns the deserialized message data of the event.
	 * @return The deserialized data.
	 */
	const TSharedPtr<const FJsonObject>& GetData() const;

	/**
	 * @brief Returns the serialized message broadcasted with the event.
	 * @return The message.
	 */
	const FString& GetMessage() const;

	/**
	 * @brief Returns the event type.
	 * @return The event type.
	 */
	EEventType GetType() const;

	bool operator==(const FNotificationEvent& Rhs) const;

	bool operator!=(const FNotificationEvent& Rhs) const;

	FNotificationEvent& operator=(const FNotificationEvent& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
