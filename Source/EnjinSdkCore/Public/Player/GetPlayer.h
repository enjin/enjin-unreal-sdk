// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Shared/PlayerFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Player
{
/**
 * @brief Request for getting information about the player.
 */
class ENJINSDKCORE_API FGetPlayer final : public GraphQl::IGraphQlRequest,
                                      public Shared::TPlayerFragmentArguments<FGetPlayer>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetPlayer();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetPlayer() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetPlayer& Rhs) const;

	bool operator!=(const FGetPlayer& Rhs) const;
};
}

namespace Shared
{
// region TAssetFragmentArguments

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithAssetBlocks();

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithAssetVariantMode();

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithAssetVariants();

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithConfigData();

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithCreator();

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithMeltDetails();

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithMetadataUri();

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithStateData();

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithSupplyDetails();

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithTransferSettings();

template ENJINSDKCORE_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template ENJINSDKCORE_API Player::FGetPlayer&
TBalanceFragmentArguments<Player::FGetPlayer>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Player::FGetPlayer&
TBalanceFragmentArguments<Player::FGetPlayer>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDKCORE_API Player::FGetPlayer&
TBalanceFragmentArguments<Player::FGetPlayer>::SetWithBalProjectUuid();

template ENJINSDKCORE_API Player::FGetPlayer&
TBalanceFragmentArguments<Player::FGetPlayer>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TPlayerFragmentArguments

template ENJINSDKCORE_API Player::FGetPlayer&
TPlayerFragmentArguments<Player::FGetPlayer>::SetLinkingCodeQrSize(const int32 Size);

template ENJINSDKCORE_API Player::FGetPlayer&
TPlayerFragmentArguments<Player::FGetPlayer>::SetWithLinkingInfo();

template ENJINSDKCORE_API Player::FGetPlayer&
TPlayerFragmentArguments<Player::FGetPlayer>::SetWithPlayerWallet();

// endregion TPlayerFragmentArguments

// region TTransactionFragmentArguments

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithAssetData();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithBlockchainData();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithEncodedData();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithError();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithLogEvent();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithMeta();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithNonce();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithReceipt();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithReceiptLogs();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithSignedTxs();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithState();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template ENJINSDKCORE_API Player::FGetPlayer&
TWalletFragmentArguments<Player::FGetPlayer>::SetWalletBalanceFilter(Model::FBalanceFilter Filter);

template ENJINSDKCORE_API Player::FGetPlayer&
TWalletFragmentArguments<Player::FGetPlayer>::SetWithAssetsCreated();

template ENJINSDKCORE_API Player::FGetPlayer&
TWalletFragmentArguments<Player::FGetPlayer>::SetWithWalletBalances();

template ENJINSDKCORE_API Player::FGetPlayer&
TWalletFragmentArguments<Player::FGetPlayer>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments
}
}
}
