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
class ENJINSDK_API FGetTransactions final : public GraphQl::IGraphQlRequest,
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

template ENJINSDK_API FGetTransactions&
TPaginationArguments<FGetTransactions>::SetPagination(Model::FPaginationInput Pagination);

template ENJINSDK_API FGetTransactions&
TPaginationArguments<FGetTransactions>::SetPagination(const int32 Page, const int32 Limit);

// endregion TPaginationArguments

// region TTransactionFragmentArguments

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithAssetData();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithBlockchainData();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithEncodedData();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithError();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithLogEvent();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithMeta();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithNonce();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithReceipt();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithReceiptLogs();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithSignedTxs();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithState();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithTransactionProjectUuid();

template ENJINSDK_API FGetTransactions&
TTransactionFragmentArguments<FGetTransactions>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
