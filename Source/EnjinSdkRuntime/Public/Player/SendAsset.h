// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Shared/TransactionFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Player
{
/**
 * @brief Request for sending a asset.
 */
class ENJINSDK_API FSendAsset final : public GraphQl::IGraphQlRequest,
                                      public Shared::TTransactionFragmentArguments<FSendAsset>
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
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithAssetData();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithBlockchainData();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithEncodedData();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithError();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithLogEvent();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithMeta();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithNonce();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithReceipt();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithReceiptLogs();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithSignedTxs();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithState();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithTransactionProjectUuid();

template ENJINSDK_API Player::FSendAsset&
TTransactionFragmentArguments<Player::FSendAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
