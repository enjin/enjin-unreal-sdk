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
 * @brief Request for sending a asset.
 */
class ENJINSDK_API FSendAsset final : public GraphQl::IGraphQlRequest,
                                      public TTransactionRequestArguments<FSendAsset>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FSendAsset();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FSendAsset() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the asset ID.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FSendAsset& SetAssetId(FString Id);

	/**
	 * @brief Sets the index for non-fungible assets.
	 * @param Index The index.
	 * @return This request for chaining.
	 */
	FSendAsset& SetAssetIndex(FString Index);

	/**
	 * @brief Sets the data to forward with the transaction.
	 * @param Data The data.
	 * @return This request for chaining.
	 */
	FSendAsset& SetData(FString Data);

	/**
	 * @brief Sets the wallet address of the recipient.
	 * @param Address The address.
	 * @return This request for chaining.
	 */
	FSendAsset& SetRecipientAddress(FString Address);

	/**
	 * @brief Sets the amount to send.
	 * @param Value The amount.
	 * @return This request for chaining.
	 */
	FSendAsset& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FSendAsset& Rhs) const;

	bool operator!=(const FSendAsset& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<FString> AssetIndexOpt;
	TOptional<FString> DataOpt;
	TOptional<FString> RecipientAddressOpt;
	TOptional<FString> ValueOpt;
};

// region TTransactionRequestArguments

template ENJINSDK_API FSendAsset&
TTransactionRequestArguments<FSendAsset>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithAssetData();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithBlockchainData();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithEncodedData();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithError();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithLogEvent();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithMeta();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithNonce();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithReceipt();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithReceiptLogs();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithSignedTxs();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithState();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithTransactionProjectUuid();

template ENJINSDK_API Project::FSendAsset&
TTransactionFragmentArguments<Project::FSendAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
