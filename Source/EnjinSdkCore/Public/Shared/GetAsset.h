// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Shared/AssetFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Request for getting a asset on the platform.
 */
class ENJINSDKCORE_API FGetAsset final : public GraphQl::IGraphQlRequest,
                                     public TAssetFragmentArguments<FGetAsset>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetAsset();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetAsset() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the ID of the asset to get.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FGetAsset& SetId(FString Id);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetAsset& Rhs) const;

	bool operator!=(const FGetAsset& Rhs) const;

private:
	TOptional<FString> IdOpt;
};

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithAssetBlocks();

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithAssetVariantMode();

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithAssetVariants();

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithConfigData();

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithCreator();

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithMeltDetails();

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithMetadataUri();

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithStateData();

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithSupplyDetails();

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithTransferSettings();

template ENJINSDKCORE_API FGetAsset&
TAssetFragmentArguments<FGetAsset>::SetWithVariantMetadata();
}
}
}
