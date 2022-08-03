// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/AssetTransferable.h"
#include "Project/TransactionRequestArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for setting if an asset may be transferred.
 */
class ENJINSDKRUNTIME_API FSetTransferable final : public GraphQl::IGraphQlRequest,
                                            public TTransactionRequestArguments<FSetTransferable>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FSetTransferable();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FSetTransferable() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the asset ID.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FSetTransferable& SetAssetId(FString Id);

	/**
	 * @brief Sets the index for non-fungible assets.
	 * @param Index The index.
	 * @return This request for chaining.
	 */
	FSetTransferable& SetAssetIndex(FString Index);

	/**
	 * @brief Sets the new transfer mode for the asset.
	 * @param Transferable The new transfer mode.
	 * @return This request for chaining.
	 */
	FSetTransferable& SetTransferable(const Model::EAssetTransferable Transferable);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FSetTransferable& Rhs) const;

	bool operator!=(const FSetTransferable& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<FString> AssetIndexOpt;
	TOptional<Model::EAssetTransferable> TransferableOpt;
};

// region TTransactionRequestArguments

template ENJINSDKRUNTIME_API FSetTransferable&
TTransactionRequestArguments<FSetTransferable>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithError();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithState();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FSetTransferable&
TTransactionFragmentArguments<Project::FSetTransferable>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
