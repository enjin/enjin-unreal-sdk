// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/TradeInput.h"
#include "Project/TransactionRequestArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for creating a trade between two wallets.
 */
class ENJINSDKRUNTIME_API FCreateTrade final : public GraphQl::IGraphQlRequest,
                                        public TTransactionRequestArguments<FCreateTrade>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FCreateTrade();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FCreateTrade() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the assets the sender is asking for.
	 * @param Assets The assets.
	 * @return This request for chaining.
	 */
	FCreateTrade& SetAskingAssets(TArray<Model::FTradeInput> Assets);

	/**
	 * @brief Sets the assets to be offered by the sender.
	 * @param Assets The assets.
	 * @return This request for chaining.
	 */
	FCreateTrade& SetOfferingAssets(TArray<Model::FTradeInput> Assets);

	/**
	 * @brief Sets the wallet address of the recipient.
	 * @param Address The address.
	 * @return This request for chaining.
	 */
	FCreateTrade& SetRecipientAddress(FString Address);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FCreateTrade& Rhs) const;

	bool operator!=(const FCreateTrade& Rhs) const;

private:
	TOptional<TArray<Model::FTradeInput>> AskingAssetsOpt;
	TOptional<TArray<Model::FTradeInput>> OfferingAssetsOpt;
	TOptional<FString> RecipientAddressOpt;
};

// region TTransactionRequestArguments

template ENJINSDKRUNTIME_API FCreateTrade&
TTransactionRequestArguments<FCreateTrade>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithError();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithState();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FCreateTrade&
TTransactionFragmentArguments<Project::FCreateTrade>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
