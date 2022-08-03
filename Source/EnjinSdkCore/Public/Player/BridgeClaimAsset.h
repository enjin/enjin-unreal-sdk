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
 * @brief Request for claiming assets on the bridge.
 */
class ENJINSDKCORE_API FBridgeClaimAsset final : public GraphQl::IGraphQlRequest,
                                             public Shared::TTransactionFragmentArguments<FBridgeClaimAsset>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FBridgeClaimAsset();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FBridgeClaimAsset() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets which assets to filter by the given ID.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FBridgeClaimAsset& SetAssetId(FString Id);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FBridgeClaimAsset& Rhs) const;

	bool operator!=(const FBridgeClaimAsset& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
};
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithAssetData();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithBlockchainData();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithEncodedData();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithError();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithLogEvent();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithMeta();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithNonce();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithReceipt();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithReceiptLogs();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithSignedTxs();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithState();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Player::FBridgeClaimAsset&
TTransactionFragmentArguments<Player::FBridgeClaimAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
