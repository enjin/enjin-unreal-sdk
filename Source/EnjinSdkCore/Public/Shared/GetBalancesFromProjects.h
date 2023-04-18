// Copyright 2023 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/BalanceFilter.h"
#include "Shared/BalanceFragmentArguments.h"
#include "Shared/PaginationArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Request for getting balances from different projects on the platform.
 */
class ENJINSDKCORE_API FGetBalancesFromProjects final : public GraphQl::IGraphQlRequest,
                                                        public Shared::TBalanceFragmentArguments<
	                                                        FGetBalancesFromProjects>,
                                                        public Shared::TPaginationArguments<FGetBalancesFromProjects>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetBalancesFromProjects();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetBalancesFromProjects() override = default;

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
	FGetBalancesFromProjects& SetFilter(Model::FBalanceFilter Filter);

	/**
	 * @brief Sets the project UUIDs.
	 * @param Projects The UUIDs.
	 * @return This request for chaining.
	 */
	FGetBalancesFromProjects& SetProjects(TArray<FString> Projects);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetBalancesFromProjects& Rhs) const;

	bool operator!=(const FGetBalancesFromProjects& Rhs) const;

private:
	TOptional<Model::FBalanceFilter> FilterOpt;
	TOptional<TArray<FString>> ProjectsOpt;
};

template ENJINSDKCORE_API FGetBalancesFromProjects&
TBalanceFragmentArguments<FGetBalancesFromProjects>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API FGetBalancesFromProjects&
TBalanceFragmentArguments<FGetBalancesFromProjects>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDKCORE_API FGetBalancesFromProjects&
TPaginationArguments<FGetBalancesFromProjects>::SetPagination(Model::FPaginationInput Pagination);

template ENJINSDKCORE_API FGetBalancesFromProjects&
TPaginationArguments<FGetBalancesFromProjects>::SetPagination(const int32 Page, const int32 Limit);

template ENJINSDKCORE_API FGetBalancesFromProjects&
TBalanceFragmentArguments<FGetBalancesFromProjects>::SetWithBalProjectUuid();

template ENJINSDKCORE_API FGetBalancesFromProjects&
TBalanceFragmentArguments<FGetBalancesFromProjects>::SetWithBalWalletAddress();
}
}
}
