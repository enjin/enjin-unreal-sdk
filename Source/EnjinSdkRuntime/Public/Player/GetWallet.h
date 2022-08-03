// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Shared/WalletFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Player
{
/**
 * @brief Request for getting the player's wallet.
 */
class ENJINSDKRUNTIME_API FGetWallet final : public GraphQl::IGraphQlRequest,
                                      public Shared::TWalletFragmentArguments<FGetWallet>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetWallet();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetWallet() override = default;

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

	bool operator==(const FGetWallet& Rhs) const;

	bool operator!=(const FGetWallet& Rhs) const;
};
}

namespace Shared
{
// region TAssetFragmentArguments

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithAssetBlocks();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithAssetVariantMode();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithAssetVariants();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithConfigData();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithCreator();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithMeltDetails();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithMetadataUri();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithStateData();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithSupplyDetails();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithTransferSettings();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template ENJINSDKRUNTIME_API Player::FGetWallet&
TBalanceFragmentArguments<Player::FGetWallet>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Player::FGetWallet&
TBalanceFragmentArguments<Player::FGetWallet>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDKRUNTIME_API Player::FGetWallet&
TBalanceFragmentArguments<Player::FGetWallet>::SetWithBalProjectUuid();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TBalanceFragmentArguments<Player::FGetWallet>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithAssetData();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithError();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithMeta();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithNonce();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithReceipt();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithState();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template ENJINSDKRUNTIME_API Player::FGetWallet&
TWalletFragmentArguments<Player::FGetWallet>::SetWalletBalanceFilter(Model::FBalanceFilter Filter);

template ENJINSDKRUNTIME_API Player::FGetWallet&
TWalletFragmentArguments<Player::FGetWallet>::SetWithAssetsCreated();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TWalletFragmentArguments<Player::FGetWallet>::SetWithWalletBalances();

template ENJINSDKRUNTIME_API Player::FGetWallet&
TWalletFragmentArguments<Player::FGetWallet>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments
}
}
}
