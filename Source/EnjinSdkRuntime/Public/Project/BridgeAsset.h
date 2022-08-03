// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Project/TransactionRequestArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for bridging an asset.
 */
class ENJINSDKRUNTIME_API FBridgeAsset final : public GraphQl::IGraphQlRequest,
                                        public TTransactionRequestArguments<FBridgeAsset>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FBridgeAsset();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FBridgeAsset() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the ID of the asset to bridge.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FBridgeAsset& SetAssetId(FString Id);

	/**
	 * @brief Sets the index of the asset to bridge if the asset is an NFT.
	 * @param Index The index.
	 * @return This request for chaining.
	 */
	FBridgeAsset& SetAssetIndex(FString Index);

	/**
	 * @brief Sets the amount to bridge.
	 * @param Value The amount.
	 * @return This request for chaining.
	 */
	FBridgeAsset& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FBridgeAsset& Rhs) const;

	bool operator!=(const FBridgeAsset& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<FString> AssetIndexOpt;
	TOptional<FString> ValueOpt;
};

// region TTransactionRequestArguments

template ENJINSDKRUNTIME_API FBridgeAsset&
TTransactionRequestArguments<FBridgeAsset>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithError();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithState();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FBridgeAsset&
TTransactionFragmentArguments<Project::FBridgeAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
