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
 * @brief Request for getting a wallet from the platform.
 */
class ENJINSDK_API FGetWallet final : public GraphQl::IGraphQlRequest,
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
	 * @brief Sets the Ethereum address of the wallet to get.
	 * @param EthAddress The address.
	 * @return This request for chaining.
	 */
	FGetWallet& SetEthAddress(FString EthAddress);

	/**
	 * @brief Sets the user ID owning the wallet to get.
	 * @param UserId The ID.
	 * @return This request for chaining.
	 */
	FGetWallet& SetUserId(FString UserId);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetWallet& Rhs) const;

	bool operator!=(const FGetWallet& Rhs) const;

private:
	TOptional<FString> EthAddressOpt;
	TOptional<FString> UserIdOpt;
};
}

namespace Shared
{
// region TAssetFragmentArguments

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithAssetBlocks();

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithAssetVariantMode();

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithAssetVariants();

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithConfigData();

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithCreator();

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithMeltDetails();

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithMetadataUri();

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithStateData();

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithSupplyDetails();

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithTransferSettings();

template ENJINSDK_API Project::FGetWallet&
TAssetFragmentArguments<Project::FGetWallet>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template ENJINSDK_API Project::FGetWallet&
TBalanceFragmentArguments<Project::FGetWallet>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Project::FGetWallet&
TBalanceFragmentArguments<Project::FGetWallet>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDK_API Project::FGetWallet&
TBalanceFragmentArguments<Project::FGetWallet>::SetWithBalProjectUuid();

template ENJINSDK_API Project::FGetWallet&
TBalanceFragmentArguments<Project::FGetWallet>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TTransactionFragmentArguments

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithAssetData();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithBlockchainData();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithEncodedData();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithError();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithLogEvent();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithMeta();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithNonce();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithReceipt();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithReceiptLogs();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithSignedTxs();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithState();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithTransactionProjectUuid();

template ENJINSDK_API Project::FGetWallet&
TTransactionFragmentArguments<Project::FGetWallet>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template ENJINSDK_API Project::FGetWallet&
TWalletFragmentArguments<Project::FGetWallet>::SetWalletBalanceFilter(Model::FBalanceFilter Filter);

template ENJINSDK_API Project::FGetWallet&
TWalletFragmentArguments<Project::FGetWallet>::SetWithAssetsCreated();

template ENJINSDK_API Project::FGetWallet&
TWalletFragmentArguments<Project::FGetWallet>::SetWithWalletBalances();

template ENJINSDK_API Project::FGetWallet&
TWalletFragmentArguments<Project::FGetWallet>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments
}
}
}
