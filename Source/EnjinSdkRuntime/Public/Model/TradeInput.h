// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a trade input for trade requests.
 */
class ENJINSDKRUNTIME_API FTradeInput final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FTradeInput();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FTradeInput(const FTradeInput& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FTradeInput(FTradeInput&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FTradeInput() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the asset ID to trade or ENJ if unused.
	 * @param Id The ID.
	 * @return This input for chaining.
	 */
	FTradeInput& SetAssetId(FString Id);

	/**
	 * @brief Sets the index for non-fungible assets.
	 * @param Index The index.
	 * @return This input for chaining.
	 */
	FTradeInput& SetAssetIndex(FString Index);

	/**
	 * @brief Sets the amount of assets to trade.
	 * @param Value The amount.
	 * @return This input for chaining.
	 */
	FTradeInput& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FTradeInput& Rhs) const;

	bool operator!=(const FTradeInput& Rhs) const;

	FTradeInput& operator=(const FTradeInput& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
