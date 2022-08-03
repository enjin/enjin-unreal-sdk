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
 * @brief Request for bridging multiple indices of an NFT in a single transaction.
 */
class ENJINSDK_API FBridgeAssets final : public GraphQl::IGraphQlRequest,
                                         public Shared::TTransactionFragmentArguments<FBridgeAssets>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FBridgeAssets();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FBridgeAssets() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the ID of the asset to bridge.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FBridgeAssets& SetAssetId(FString Id);

	/**
	 * @brief Sets the asset indices to bridge.
	 * @param Indices The indices.
	 * @return This request for chaining.
	 */
	FBridgeAssets& SetAssetIndices(TArray<FString> Indices);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FBridgeAssets& Rhs) const;

	bool operator!=(const FBridgeAssets& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<TArray<FString>> AssetIndicesOpt;
};
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithAssetData();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithBlockchainData();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithEncodedData();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithError();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithLogEvent();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithMeta();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithNonce();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithReceipt();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithReceiptLogs();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithSignedTxs();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithState();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithTransactionProjectUuid();

template ENJINSDK_API Player::FBridgeAssets&
TTransactionFragmentArguments<Player::FBridgeAssets>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
