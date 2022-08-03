// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/PusherChannels.h"
#include "Model/PusherOptions.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models Pusher settings for the platform.
 */
class ENJINSDKRUNTIME_API FPusher final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FPusher();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FPusher(const FPusher& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FPusher(FPusher&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPusher() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the Pusher channels the platform broadcasts on.
	 * @return The channels.
	 */
	const TOptional<FPusherChannels>& GetChannels() const;

	/**
	 * @brief Returns the key for the platform.
	 * @return The key.
	 */
	const TOptional<FString>& GetKey() const;

	/**
	 * @brief Returns the namespace the platform broadcasts on.
	 * @return The namespace.
	 */
	const TOptional<FString>& GetNamespace() const;

	/**
	 * @brief Returns the Pusher options the platform uses.
	 * @return The options.
	 */
	const TOptional<FPusherOptions>& GetOptions() const;

	bool operator==(const FPusher& Rhs) const;

	bool operator!=(const FPusher& Rhs) const;

	FPusher& operator=(const FPusher& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
