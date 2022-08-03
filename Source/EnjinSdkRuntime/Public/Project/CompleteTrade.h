// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Project/TransactionRequestArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for completing a trade between two wallets.
 */
class ENJINSDKRUNTIME_API FCompleteTrade final : public GraphQl::IGraphQlRequest,
                                          public TTransactionRequestArguments<FCompleteTrade>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FCompleteTrade();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FCompleteTrade() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the trade ID.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FCompleteTrade& SetTradeId(FString Id);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FCompleteTrade& Rhs) const;

	bool operator!=(const FCompleteTrade& Rhs) const;

private:
	TOptional<FString> TradeIdOpt;
};

// region TTransactionRequestArguments

template ENJINSDKRUNTIME_API FCompleteTrade&
TTransactionRequestArguments<FCompleteTrade>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithError();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithState();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FCompleteTrade&
TTransactionFragmentArguments<Project::FCompleteTrade>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
