// Copyright 2023 Enjin Pte. Ltd. All Rights Reserved.

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
namespace Project
{
/**
 * @brief Request for getting assets from different projects on the platform.
 */
class ENJINSDKCORE_API FGetAssetsFromProjects final : public GraphQl::IGraphQlRequest,
                                                      public Shared::TAssetFragmentArguments<FGetAssetsFromProjects>,
                                                      public Shared::TPaginationArguments<FGetAssetsFromProjects>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetAssetsFromProjects();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetAssetsFromProjects() override = default;

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
	FGetAssetsFromProjects& SetFilter(Model::FAssetFilter Filter);

	/**
	 * @brief Sets the project UUIDs.
	 * @param Projects The UUIDs.
	 * @return This request for chaining.
	 */
	FGetAssetsFromProjects& SetProjects(TArray<FString> Projects);

	/**
	 * @brief Sets the sort input for this request.
	 * @param Sort The sort input.
	 * @return This request for chaining.
	 */
	FGetAssetsFromProjects& SetSort(Model::FAssetSortInput Sort);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetAssetsFromProjects& Rhs) const;

	bool operator!=(const FGetAssetsFromProjects& Rhs) const;

private:
	TOptional<Model::FAssetFilter> FilterOpt;
	TOptional<TArray<FString>> ProjectsOpt;
	TOptional<Model::FAssetSortInput> SortOpt;
};
}

namespace Shared
{
template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TPaginationArguments<Project::FGetAssetsFromProjects>::SetPagination(Model::FPaginationInput Pagination);

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TPaginationArguments<Project::FGetAssetsFromProjects>::SetPagination(const int32 Page, const int32 Limit);

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithAssetBlocks();

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithAssetVariantMode();

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithAssetVariants();

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithConfigData();

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithCreator();

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithMeltDetails();

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithMetadataUri();

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithStateData();

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithSupplyDetails();

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithTransferSettings();

template ENJINSDKCORE_API Project::FGetAssetsFromProjects&
TAssetFragmentArguments<Project::FGetAssetsFromProjects>::SetWithVariantMetadata();
}
}
}
