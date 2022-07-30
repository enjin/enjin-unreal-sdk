// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/Pusher.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models the notification drivers and settings for the platform.
 */
class ENJINSDK_API FNotifications final : Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FNotifications();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FNotifications(const FNotifications& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FNotifications(FNotifications&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FNotifications() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the Pusher settings of the platform.
	 * @return The Pusher settings.
	 */
	const TOptional<FPusher>& GetPusher() const;

	bool operator==(const FNotifications& Rhs) const;

	bool operator!=(const FNotifications& Rhs) const;

	FNotifications& operator=(const FNotifications& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
