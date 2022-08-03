// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

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
 * @brief Request for getting balances on the platform.
 */
class ENJINSDKRUNTIME_API FGetBalances final : public GraphQl::IGraphQlRequest,
                                        public TBalanceFragmentArguments<FGetBalances>,
                                        public TPaginationArguments<FGetBalances>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetBalances();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetBalances() override = default;

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
	FGetBalances& SetFilter(Model::FBalanceFilter Filter);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetBalances& Rhs) const;

	bool operator!=(const FGetBalances& Rhs) const;

private:
	TOptional<Model::FBalanceFilter> FilterOpt;
};

template ENJINSDKRUNTIME_API FGetBalances&
TBalanceFragmentArguments<FGetBalances>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API FGetBalances&
TBalanceFragmentArguments<FGetBalances>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDKRUNTIME_API FGetBalances&
TPaginationArguments<FGetBalances>::SetPagination(Model::FPaginationInput Pagination);

template ENJINSDKRUNTIME_API FGetBalances&
TPaginationArguments<FGetBalances>::SetPagination(const int32 Page, const int32 Limit);

template ENJINSDKRUNTIME_API FGetBalances&
TBalanceFragmentArguments<FGetBalances>::SetWithBalProjectUuid();

template ENJINSDKRUNTIME_API FGetBalances&
TBalanceFragmentArguments<FGetBalances>::SetWithBalWalletAddress();
}
}
}
