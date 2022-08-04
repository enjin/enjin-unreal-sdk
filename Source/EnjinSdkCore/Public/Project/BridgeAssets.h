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
 * @brief Request for bridging multiple indices of an NFT in a single transaction.
 */
class ENJINSDKCORE_API FBridgeAssets final : public GraphQl::IGraphQlRequest,
                                         public TTransactionRequestArguments<FBridgeAssets>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FBridgeAssets();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FBridgeAssets() override = default;

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
	FBridgeAssets& SetAssetId(FString Id);

	/**
	 * @brief Sets the asset indices to bridge.
	 * @param Indices The indices.
	 * @return This request for chaining.
	 */
	FBridgeAssets& SetAssetIndices(TArray<FString> Indices);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FBridgeAssets& Rhs) const;

	bool operator!=(const FBridgeAssets& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<TArray<FString>> AssetIndicesOpt;
};

// region TTransactionRequestArguments

template ENJINSDKCORE_API FBridgeAssets&
TTransactionRequestArguments<FBridgeAssets>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithAssetData();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithError();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithMeta();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithNonce();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithReceipt();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithState();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FBridgeAssets&
TTransactionFragmentArguments<Project::FBridgeAssets>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
