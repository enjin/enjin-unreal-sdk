// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/TransferInput.h"
#include "Shared/TransactionFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Player
{
/**
 * @brief Request for sending one or more assets in a single transaction.
 */
class ENJINSDK_API FAdvancedSendAsset final : public GraphQl::IGraphQlRequest,
                                              public Shared::TTransactionFragmentArguments<FAdvancedSendAsset>
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
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithAssetData();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithBlockchainData();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithEncodedData();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithError();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithLogEvent();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithMeta();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithNonce();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithReceipt();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithReceiptLogs();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithSignedTxs();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithState();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithTransactionProjectUuid();

template ENJINSDK_API Player::FAdvancedSendAsset&
TTransactionFragmentArguments<Player::FAdvancedSendAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
