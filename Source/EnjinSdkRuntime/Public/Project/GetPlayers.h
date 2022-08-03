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
class ENJINSDK_API FGetPlayers final : public GraphQl::IGraphQlRequest,
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

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithAssetBlocks();

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithAssetVariantMode();

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithAssetVariants();

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithConfigData();

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithCreator();

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithMeltDetails();

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithMetadataUri();

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithStateData();

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithSupplyDetails();

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithTransferSettings();

template ENJINSDK_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template ENJINSDK_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDK_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetWithBalProjectUuid();

template ENJINSDK_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TPaginationArguments

template ENJINSDK_API Project::FGetPlayers&
TPaginationArguments<Project::FGetPlayers>::SetPagination(Model::FPaginationInput Pagination);

template ENJINSDK_API Project::FGetPlayers&
TPaginationArguments<Project::FGetPlayers>::SetPagination(const int32 Page, const int32 Limit);

// endregion TPaginationArguments

// region TPlayerFragmentArguments

template ENJINSDK_API Project::FGetPlayers&
TPlayerFragmentArguments<Project::FGetPlayers>::SetLinkingCodeQrSize(const int32 Size);

template ENJINSDK_API Project::FGetPlayers&
TPlayerFragmentArguments<Project::FGetPlayers>::SetWithLinkingInfo();

template ENJINSDK_API Project::FGetPlayers&
TPlayerFragmentArguments<Project::FGetPlayers>::SetWithPlayerWallet();

// endregion TPlayerFragmentArguments

// region TTransactionFragmentArguments

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithAssetData();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithBlockchainData();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithEncodedData();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithError();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithLogEvent();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithMeta();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithNonce();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithReceipt();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithReceiptLogs();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithSignedTxs();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithState();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithTransactionProjectUuid();

template ENJINSDK_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template ENJINSDK_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWalletBalanceFilter(Model::FBalanceFilter Filter);

template ENJINSDK_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWithAssetsCreated();

template ENJINSDK_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWithWalletBalances();

template ENJINSDK_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments
}
}
}
