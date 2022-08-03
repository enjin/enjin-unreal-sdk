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
class ENJINSDK_API FGetPlayer final : public GraphQl::IGraphQlRequest,
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

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithAssetBlocks();

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithAssetVariantMode();

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithAssetVariants();

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithConfigData();

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithCreator();

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithMeltDetails();

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithMetadataUri();

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithStateData();

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithSupplyDetails();

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithTransferSettings();

template ENJINSDK_API Player::FGetPlayer&
TAssetFragmentArguments<Player::FGetPlayer>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template ENJINSDK_API Player::FGetPlayer&
TBalanceFragmentArguments<Player::FGetPlayer>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Player::FGetPlayer&
TBalanceFragmentArguments<Player::FGetPlayer>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDK_API Player::FGetPlayer&
TBalanceFragmentArguments<Player::FGetPlayer>::SetWithBalProjectUuid();

template ENJINSDK_API Player::FGetPlayer&
TBalanceFragmentArguments<Player::FGetPlayer>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TPlayerFragmentArguments

template ENJINSDK_API Player::FGetPlayer&
TPlayerFragmentArguments<Player::FGetPlayer>::SetLinkingCodeQrSize(const int32 Size);

template ENJINSDK_API Player::FGetPlayer&
TPlayerFragmentArguments<Player::FGetPlayer>::SetWithLinkingInfo();

template ENJINSDK_API Player::FGetPlayer&
TPlayerFragmentArguments<Player::FGetPlayer>::SetWithPlayerWallet();

// endregion TPlayerFragmentArguments

// region TTransactionFragmentArguments

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithAssetData();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithBlockchainData();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithEncodedData();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithError();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithLogEvent();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithMeta();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithNonce();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithReceipt();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithReceiptLogs();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithSignedTxs();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithState();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithTransactionProjectUuid();

template ENJINSDK_API Player::FGetPlayer&
TTransactionFragmentArguments<Player::FGetPlayer>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template ENJINSDK_API Player::FGetPlayer&
TWalletFragmentArguments<Player::FGetPlayer>::SetWalletBalanceFilter(Model::FBalanceFilter Filter);

template ENJINSDK_API Player::FGetPlayer&
TWalletFragmentArguments<Player::FGetPlayer>::SetWithAssetsCreated();

template ENJINSDK_API Player::FGetPlayer&
TWalletFragmentArguments<Player::FGetPlayer>::SetWithWalletBalances();

template ENJINSDK_API Player::FGetPlayer&
TWalletFragmentArguments<Player::FGetPlayer>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments
}
}
}
