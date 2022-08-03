// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/AssetTransferFeeSettings.h"
#include "Model/AssetTransferable.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models the configuration data of a asset.
 */
class ENJINSDK_API FAssetConfigData final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAssetConfigData();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FAssetConfigData(const FAssetConfigData& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FAssetConfigData(FAssetConfigData&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FAssetConfigData() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the max melt fee ratio of the asset.
	 * @return The ratio.
	 * @remarks The ratio is in the range of 0-10000 to allow for fractional ratios. e.g. 1 = 0.01%, 10000 = 100%,
	 * etc...
	 */
	const TOptional<int32>& GetMeltFeeMaxRatio() const;

	/**
	 * @brief Returns the melt fee ratio of the asset.
	 * @return The ratio.
	 * @remarks The ratio is in the range of 0-10000 to allow for fractional ratios. e.g. 1 = 0.01%, 10000 = 100%,
	 * etc...
	 */
	const TOptional<int32>& GetMeltFeeRatio() const;

	/**
	 * @brief Returns the melt value for the asset. This value corresponds to its exchange rate.
	 * @return The melt value.
	 */
	const TOptional<FString>& GetMeltValue() const;

	/**
	 * @brief Returns the URI for the metadata of the asset.
	 * @return The URI.
	 */
	const TOptional<FString>& GetMetadataUri() const;

	/**
	 * @brief Returns the transfer fee settings for the asset.
	 * @return The transfer fee settings.
	 */
	const TOptional<FAssetTransferFeeSettings>& GetTransferFeeSettings() const;

	/**
	 * @brief Returns the transferable type of the asset.
	 * @return The transferable type.
	 */
	const TOptional<EAssetTransferable>& GetTransferable() const;

	bool operator==(const FAssetConfigData& Rhs) const;

	bool operator!=(const FAssetConfigData& Rhs) const;

	FAssetConfigData& operator=(const FAssetConfigData& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
