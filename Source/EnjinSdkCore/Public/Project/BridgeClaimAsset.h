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
 * @brief Request for claiming assets on the bridge.
 */
class ENJINSDKCORE_API FBridgeClaimAsset final : public GraphQl::IGraphQlRequest,
                                             public TTransactionRequestArguments<FBridgeClaimAsset>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FBridgeClaimAsset();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FBridgeClaimAsset() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets which assets to filter by the given ID.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FBridgeClaimAsset& SetAssetId(FString Id);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FBridgeClaimAsset& Rhs) const;

	bool operator!=(const FBridgeClaimAsset& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
};

// region TTransactionRequestArguments

template ENJINSDKCORE_API FBridgeClaimAsset&
TTransactionRequestArguments<FBridgeClaimAsset>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithAssetData();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithError();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithMeta();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithNonce();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithReceipt();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithState();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FBridgeClaimAsset&
TTransactionFragmentArguments<Project::FBridgeClaimAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
