﻿// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Shared/PlayerFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for getting a player for the project.
 */
class ENJINSDKRUNTIME_API FGetPlayer final : public GraphQl::IGraphQlRequest,
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
	 * @brief Sets the player ID.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FGetPlayer& SetId(FString Id);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetPlayer& Rhs) const;

	bool operator!=(const FGetPlayer& Rhs) const;

private:
	TOptional<FString> IdOpt;
};
}

namespace Shared
{
// region TAssetFragmentArguments

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithAssetBlocks();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithAssetVariantMode();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithAssetVariants();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithConfigData();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithCreator();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithMeltDetails();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithMetadataUri();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithStateData();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithSupplyDetails();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithTransferSettings();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TAssetFragmentArguments<Project::FGetPlayer>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TBalanceFragmentArguments<Project::FGetPlayer>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TBalanceFragmentArguments<Project::FGetPlayer>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TBalanceFragmentArguments<Project::FGetPlayer>::SetWithBalProjectUuid();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TBalanceFragmentArguments<Project::FGetPlayer>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TPlayerFragmentArguments

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TPlayerFragmentArguments<Project::FGetPlayer>::SetLinkingCodeQrSize(const int32 Size);

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TPlayerFragmentArguments<Project::FGetPlayer>::SetWithLinkingInfo();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TPlayerFragmentArguments<Project::FGetPlayer>::SetWithPlayerWallet();

// endregion TPlayerFragmentArguments

// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithError();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithState();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TTransactionFragmentArguments<Project::FGetPlayer>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TWalletFragmentArguments<Project::FGetPlayer>::SetWalletBalanceFilter(Model::FBalanceFilter Filter);

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TWalletFragmentArguments<Project::FGetPlayer>::SetWithAssetsCreated();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TWalletFragmentArguments<Project::FGetPlayer>::SetWithWalletBalances();

template ENJINSDKRUNTIME_API Project::FGetPlayer&
TWalletFragmentArguments<Project::FGetPlayer>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments
}
}
}
