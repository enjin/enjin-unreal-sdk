﻿// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/TransferInput.h"
#include "Project/TransactionRequestArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for sending one or more assets in a single transaction.
 */
class ENJINSDKCORE_API FAdvancedSendAsset final : public GraphQl::IGraphQlRequest,
                                              public TTransactionRequestArguments<FAdvancedSendAsset>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAdvancedSendAsset();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FAdvancedSendAsset() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the data to forward with the transaction.
	 * @param Data The data.
	 * @return This request for chaining.
	 */
	FAdvancedSendAsset& SetData(FString Data);

	/**
	 * @brief Sets the different transfers to perform.
	 * @param Transfers The transfers.
	 * @return This request for chaining.
	 */
	FAdvancedSendAsset& SetTransfers(TArray<Model::FTransferInput> Transfers);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FAdvancedSendAsset& Rhs) const;

	bool operator!=(const FAdvancedSendAsset& Rhs) const;

private:
	TOptional<FString> DataOpt;
	TOptional<TArray<Model::FTransferInput>> TransfersOpt;
};

// region TTransactionRequestArguments

template ENJINSDKCORE_API FAdvancedSendAsset&
TTransactionRequestArguments<FAdvancedSendAsset>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithAssetData();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithError();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithMeta();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithNonce();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithReceipt();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithState();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FAdvancedSendAsset&
TTransactionFragmentArguments<Project::FAdvancedSendAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
