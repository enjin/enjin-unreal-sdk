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
class ENJINSDKCORE_API FGetWallet final : public GraphQl::IGraphQlRequest,
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

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithAssetBlocks();

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithAssetVariantMode();

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithAssetVariants();

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithConfigData();

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithCreator();

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithMeltDetails();

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithMetadataUri();

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithStateData();

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithSupplyDetails();

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithTransferSettings();

template ENJINSDKCORE_API Player::FGetWallet&
TAssetFragmentArguments<Player::FGetWallet>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template ENJINSDKCORE_API Player::FGetWallet&
TBalanceFragmentArguments<Player::FGetWallet>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Player::FGetWallet&
TBalanceFragmentArguments<Player::FGetWallet>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDKCORE_API Player::FGetWallet&
TBalanceFragmentArguments<Player::FGetWallet>::SetWithBalProjectUuid();

template ENJINSDKCORE_API Player::FGetWallet&
TBalanceFragmentArguments<Player::FGetWallet>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TTransactionFragmentArguments

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithAssetData();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithBlockchainData();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithEncodedData();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithError();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithLogEvent();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithMeta();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithNonce();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithReceipt();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithReceiptLogs();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithSignedTxs();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithState();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Player::FGetWallet&
TTransactionFragmentArguments<Player::FGetWallet>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template ENJINSDKCORE_API Player::FGetWallet&
TWalletFragmentArguments<Player::FGetWallet>::SetWalletBalanceFilter(Model::FBalanceFilter Filter);

template ENJINSDKCORE_API Player::FGetWallet&
TWalletFragmentArguments<Player::FGetWallet>::SetWithAssetsCreated();

template ENJINSDKCORE_API Player::FGetWallet&
TWalletFragmentArguments<Player::FGetWallet>::SetWithWalletBalances();

template ENJINSDKCORE_API Player::FGetWallet&
TWalletFragmentArguments<Player::FGetWallet>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments
}
}
}
