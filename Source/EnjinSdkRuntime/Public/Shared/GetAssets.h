// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/AssetFilter.h"
#include "Model/AssetSortInput.h"
#include "Shared/AssetFragmentArguments.h"
#include "Shared/PaginationArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Request for getting assets on the platform.
 */
class ENJINSDKRUNTIME_API FGetAssets final : public GraphQl::IGraphQlRequest,
                                      public TAssetFragmentArguments<FGetAssets>,
                                      public TPaginationArguments<FGetAssets>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetAssets();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetAssets() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the filter for this request.
	 * @param Filter The filter.
	 * @return This request for chaining.
	 */
	FGetAssets& SetFilter(Model::FAssetFilter Filter);

	/**
	 * @brief Sets the sort input for this request.
	 * @param Sort The sort input.
	 * @return This request for chaining.
	 */
	FGetAssets& SetSort(Model::FAssetSortInput Sort);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetAssets& Rhs) const;

	bool operator!=(const FGetAssets& Rhs) const;

private:
	TOptional<Model::FAssetFilter> FilterOpt;
	TOptional<Model::FAssetSortInput> SortOpt;
};

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDKRUNTIME_API FGetAssets&
TPaginationArguments<FGetAssets>::SetPagination(Model::FPaginationInput Pagination);

template ENJINSDKRUNTIME_API FGetAssets&
TPaginationArguments<FGetAssets>::SetPagination(const int32 Page, const int32 Limit);

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithAssetBlocks();

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithAssetVariantMode();

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithAssetVariants();

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithConfigData();

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithCreator();

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithMeltDetails();

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithMetadataUri();

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithStateData();

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithSupplyDetails();

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithTransferSettings();

template ENJINSDKRUNTIME_API FGetAssets&
TAssetFragmentArguments<FGetAssets>::SetWithVariantMetadata();
}
}
}
