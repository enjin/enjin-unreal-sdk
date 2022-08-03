// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/AssetTransferFeeType.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models transfer fee settings for an asset.
 */
class ENJINSDKRUNTIME_API FAssetTransferFeeSettings final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAssetTransferFeeSettings();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FAssetTransferFeeSettings(const FAssetTransferFeeSettings& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FAssetTransferFeeSettings(FAssetTransferFeeSettings&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FAssetTransferFeeSettings() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the asset ID or "0" if ENJ.
	 * @return The asset ID.
	 */
	const TOptional<FString>& GetAssetId() const;

	/**
	 * @brief Returns the transfer fee type.
	 * @return The transfer fee type.
	 */
	const TOptional<EAssetTransferFeeType>& GetType() const;

	/**
	 * @brief Returns the fee value in Wei.
	 * @return The value.
	 */
	const TOptional<FString>& GetValue() const;

	bool operator==(const FAssetTransferFeeSettings& Rhs) const;

	bool operator!=(const FAssetTransferFeeSettings& Rhs) const;

	FAssetTransferFeeSettings& operator=(const FAssetTransferFeeSettings& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
