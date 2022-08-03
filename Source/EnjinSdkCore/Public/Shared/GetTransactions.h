// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/TransactionFilter.h"
#include "Model/TransactionSortInput.h"
#include "Shared/PaginationArguments.h"
#include "Shared/TransactionFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Request for getting transactions on the platform.
 */
class ENJINSDKCORE_API FGetTransactions final : public GraphQl::IGraphQlRequest,
                                            public TTransactionFragmentArguments<FGetTransactions>,
                                            public TPaginationArguments<FGetTransactions>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetTransactions();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetTransactions() override = default;

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
	FGetTransactions& SetFilter(Model::FTransactionFilter Filter);

	/**
	 * @brief Sets the sort input for this request.
	 * @param Sort The sort input.
	 * @return This request for chaining.
	 */
	FGetTransactions& SetSort(Model::FTransactionSortInput Sort);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetTransactions& Rhs) const;

	bool operator!=(const FGetTransactions& Rhs) const;

private:
	TOptional<Model::FTransactionFilter> FilterOpt;
	TOptional<Model::FTransactionSortInput> SortOpt;
};

// region TPaginationArguments

template ENJINSDKCORE_API FGetTransactions&
TPaginationArguments<FGetTransactions>::SetPagination(Model::FPaginationInput Pagination);

template ENJINSDKCORE_API FGetTransactions&
TPaginationArguments<FGetTransactions>::SetPagination(const int32 Page, const int32 Limit);

// endregion TPaginationArguments

// region TTransactionFragmentArguments

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithAssetData();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithBlockchainData();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithEncodedData();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithError();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithLogEvent();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithMeta();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithNonce();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithReceipt();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithReceiptLogs();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithSignedTxs();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithState();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
