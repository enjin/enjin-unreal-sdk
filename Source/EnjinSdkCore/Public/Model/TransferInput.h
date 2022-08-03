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
 * @brief Models a transfer input for transfer requests.
 */
class ENJINSDKCORE_API FTransferInput final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FTransferInput();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FTransferInput(const FTransferInput& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FTransferInput(FTransferInput&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FTransferInput() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the asset ID to transfer or ENJ if unused.
	 * @param Id The ID.
	 * @return This input for chaining.
	 */
	FTransferInput& SetAssetId(FString Id);

	/**
	 * @brief Sets the index for non-fungible assets.
	 * @param Index The index.
	 * @return This input for chaining.
	 */
	FTransferInput& SetAssetIndex(FString Index);

	/**
	 * @brief Sets the source Ethereum address.
	 * @param From The source.
	 * @return This input for chaining.
	 */
	FTransferInput& SetFrom(FString From);

	/**
	 * @brief Sets the destination Ethereum address.
	 * @param To The destination.
	 * @return This input for chaining.
	 */
	FTransferInput& SetTo(FString To);

	/**
	 * @brief Sets the amount of assets to transfer.
	 * @param Value The amount.
	 * @return This input for chaining.
	 */
	FTransferInput& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FTransferInput& Rhs) const;

	bool operator!=(const FTransferInput& Rhs) const;

	FTransferInput& operator=(const FTransferInput& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
