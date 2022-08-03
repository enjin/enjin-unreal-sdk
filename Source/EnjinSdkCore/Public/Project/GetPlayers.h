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
class ENJINSDKCORE_API FGetPlayers final : public GraphQl::IGraphQlRequest,
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

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetAssetIdFormat(Model::EAssetIdFormat AssetIdFormat);

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithAssetBlocks();

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithAssetVariantMode();

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithAssetVariants();

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithConfigData();

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithCreator();

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithMeltDetails();

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithMetadataUri();

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithStateData();

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithSupplyDetails();

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithTransferSettings();

template ENJINSDKCORE_API Project::FGetPlayers&
TAssetFragmentArguments<Project::FGetPlayers>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template ENJINSDKCORE_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetBalIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetBalIndexFormat(const Model::EAssetIndexFormat Format);

template ENJINSDKCORE_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetWithBalProjectUuid();

template ENJINSDKCORE_API Project::FGetPlayers&
TBalanceFragmentArguments<Project::FGetPlayers>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TPaginationArguments

template ENJINSDKCORE_API Project::FGetPlayers&
TPaginationArguments<Project::FGetPlayers>::SetPagination(Model::FPaginationInput Pagination);

template ENJINSDKCORE_API Project::FGetPlayers&
TPaginationArguments<Project::FGetPlayers>::SetPagination(const int32 Page, const int32 Limit);

// endregion TPaginationArguments

// region TPlayerFragmentArguments

template ENJINSDKCORE_API Project::FGetPlayers&
TPlayerFragmentArguments<Project::FGetPlayers>::SetLinkingCodeQrSize(const int32 Size);

template ENJINSDKCORE_API Project::FGetPlayers&
TPlayerFragmentArguments<Project::FGetPlayers>::SetWithLinkingInfo();

template ENJINSDKCORE_API Project::FGetPlayers&
TPlayerFragmentArguments<Project::FGetPlayers>::SetWithPlayerWallet();

// endregion TPlayerFragmentArguments

// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithAssetData();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithError();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithMeta();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithNonce();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithReceipt();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithState();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FGetPlayers&
TTransactionFragmentArguments<Project::FGetPlayers>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template ENJINSDKCORE_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWalletBalanceFilter(Model::FBalanceFilter Filter);

template ENJINSDKCORE_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWithAssetsCreated();

template ENJINSDKCORE_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWithWalletBalances();

template ENJINSDKCORE_API Project::FGetPlayers&
TWalletFragmentArguments<Project::FGetPlayers>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments
}
}
}
