// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models Pusher channels used by the platform.
 */
class ENJINSDKCORE_API FPusherChannels final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FPusherChannels();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FPusherChannels(const FPusherChannels& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FPusherChannels(FPusherChannels&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPusherChannels() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the asset channel.
	 * @return The asset channel.
	 */
	const TOptional<FString>& GetAsset() const;

	/**
	 * @brief Returns the player channel.
	 * @return The player channel.
	 */
	const TOptional<FString>& GetPlayer() const;

	/**
	 * @brief Returns the project channel.
	 * @return The project channel.
	 */
	const TOptional<FString>& GetProject() const;

	/**
	 * @brief Returns the wallet channel.
	 * @return The wallet channel.
	 */
	const TOptional<FString>& GetWallet() const;

	bool operator==(const FPusherChannels& Rhs) const;

	bool operator!=(const FPusherChannels& Rhs) const;

	FPusherChannels& operator=(const FPusherChannels& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
