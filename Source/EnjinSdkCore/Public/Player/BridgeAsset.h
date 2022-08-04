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
 * @brief Request for bridging an asset.
 */
class ENJINSDKCORE_API FBridgeAsset final : public GraphQl::IGraphQlRequest,
                                        public Shared::TTransactionFragmentArguments<FBridgeAsset>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FBridgeAsset();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FBridgeAsset() override = default;

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
	FBridgeAsset& SetAssetId(FString Id);

	/**
	 * @brief Sets the index of the asset to bridge if the asset is an NFT.
	 * @param Index The index.
	 * @return This request for chaining.
	 */
	FBridgeAsset& SetAssetIndex(FString Index);

	/**
	 * @brief Sets the amount to bridge.
	 * @param Value The amount.
	 * @return This request for chaining.
	 */
	FBridgeAsset& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FBridgeAsset& Rhs) const;

	bool operator!=(const FBridgeAsset& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<FString> AssetIndexOpt;
	TOptional<FString> ValueOpt;
};
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithAssetData();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithBlockchainData();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithEncodedData();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithError();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithLogEvent();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithMeta();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithNonce();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithReceipt();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithReceiptLogs();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithSignedTxs();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithState();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Player::FBridgeAsset&
TTransactionFragmentArguments<Player::FBridgeAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
