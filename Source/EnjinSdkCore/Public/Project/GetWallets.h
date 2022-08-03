// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Shared/WalletFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for getting wallets from the platform.
 */
class ENJINSDKCORE_API FGetWallets final : public GraphQl::IGraphQlRequest,
                                       public Shared::TWalletFragmentArguments<FGetWallets>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetWallets();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetWallets() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the Ethereum addresses of the wallets to get.
	 * @param Addresses The addresses.
	 * @return This request for chaining.
	 */
	FGetWallets& SetEthAddresses(TArray<FString> Addresses);

	/**
	 * @brief Sets the user IDs of the wallets to get.
	 * @param Ids The IDs.
	 * @return This request for chaining.
	 */
	FGetWallets& SetUserIds(TArray<FString> Ids);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetWallets& Rhs) const;

	bool operator!=(const FGetWallets& Rhs) const;

private:
	TOptional<TArray<FString>> EthAddressesOpt;
	TOptional<TArray<FString>> UserIdsOpt;
};
}

namespace Shared
{
// region TAssetFragmentArguments

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithAssetBlocks();

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithAssetVariantMode();

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithAssetVariants();

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithConfigData();

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithCreator();

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithMeltDetails();

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithMetadataUri();

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithStateData();

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithSupplyDetails();

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithTransferSettings();

template ENJINSDKCORE_API Project::FGetWallets&
TAssetFragmentArguments<Project::FGetWallets>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template ENJINSDKCORE_API Project::FGetWallets&
TBalanceFragmentArguments<Project::FGetWallets>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FGetWallets&
TBalanceFragmentArguments<Project::FGetWallets>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDKCORE_API Project::FGetWallets&
TBalanceFragmentArguments<Project::FGetWallets>::SetWithBalProjectUuid();

template ENJINSDKCORE_API Project::FGetWallets&
TBalanceFragmentArguments<Project::FGetWallets>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithAssetData();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithError();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithMeta();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithNonce();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithReceipt();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithState();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FGetWallets&
TTransactionFragmentArguments<Project::FGetWallets>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template ENJINSDKCORE_API Project::FGetWallets&
TWalletFragmentArguments<Project::FGetWallets>::SetWalletBalanceFilter(Model::FBalanceFilter Filter);

template ENJINSDKCORE_API Project::FGetWallets&
TWalletFragmentArguments<Project::FGetWallets>::SetWithAssetsCreated();

template ENJINSDKCORE_API Project::FGetWallets&
TWalletFragmentArguments<Project::FGetWallets>::SetWithWalletBalances();

template ENJINSDKCORE_API Project::FGetWallets&
TWalletFragmentArguments<Project::FGetWallets>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments
}
}
}
