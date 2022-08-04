// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"
#include "Model/AssetTransferFeeType.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models input for the transfer fee settings used in GraphQL requests.
 */
class ENJINSDKCORE_API FAssetTransferFeeSettingsInput final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAssetTransferFeeSettingsInput();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FAssetTransferFeeSettingsInput(const FAssetTransferFeeSettingsInput& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FAssetTransferFeeSettingsInput(FAssetTransferFeeSettingsInput&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FAssetTransferFeeSettingsInput() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the asset ID for this input.
	 * @param AssetId The ID.
	 * @return This input for chaining.
	 */
	FAssetTransferFeeSettingsInput& SetAssetId(FString AssetId);

	/**
	 * @brief Sets the transfer type for this input.
	 * @param Type The type.
	 * @return This input for chaining.
	 */
	FAssetTransferFeeSettingsInput& SetType(const EAssetTransferFeeType Type);

	/**
	 * @brief Sets the value in Wei for this input.
	 * @param Value The value.
	 * @return This input for chaining.
	 */
	FAssetTransferFeeSettingsInput& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FAssetTransferFeeSettingsInput& Rhs) const;

	bool operator!=(const FAssetTransferFeeSettingsInput& Rhs) const;

	FAssetTransferFeeSettingsInput& operator=(const FAssetTransferFeeSettingsInput& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
