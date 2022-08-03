// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/PlayerFilter.h"
#include "Shared/PaginationArguments.h"
#include "Shared/PlayerFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for getting players for the project. 
 */
class ENJINSDKRUNTIME_API FGetPlayers final : public GraphQl::IGraphQlRequest,
                                       public Shared::TPlayerFragmentArguments<FGetPlayers>,
                                       public Shared::TPaginationArguments<FGetPlayers>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetPlayers();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetPlayers() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the filter this request will use.
	 * @param Filter The filter.
	 * @return This request for chaining.
	 */
	FGetPlayers& SetFilter(Model::FPlayerFilter Filter);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetPlayers& Rhs) const;

	bool operator!=(const FGetPlayers& Rhs) const;

private:
	TOptional<Model::FPlayerFilter> FilterOpt;
};
}

namespace Shared
{
// region TAssetFragmentArguments

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithAssetBlocks();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithAssetVariantMode();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithAssetVariants();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithConfigData();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithCreator();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithMeltDetails();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithMetadataUri();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithStateData();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithSupplyDetails();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithTransferSettings();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetWithBalProjectUuid();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TPaginationArguments

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TPaginationArguments<Project::FGetPlayers>::SetPagination(Model::FPaginationInput Pagination);

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TPaginationArguments<Project::FGetPlayers>::SetPagination(const int32 Page, const int32 Limit);

// endregion TPaginationArguments

// region TPlayerFragmentArguments

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TPlayerFragmentArguments<Project::FGetPlayers>::SetLinkingCodeQrSize(const int32 Size);

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TPlayerFragmentArguments<Project::FGetPlayers>::SetWithLinkingInfo();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TPlayerFragmentArguments<Project::FGetPlayers>::SetWithPlayerWallet();

// endregion TPlayerFragmentArguments

// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithError();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithState();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWalletBalanceFilter(Model::FBalanceFilter Filter);

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWithAssetsCreated();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWithWalletBalances();

template ENJINSDKRUNTIME_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments
}
}
}
