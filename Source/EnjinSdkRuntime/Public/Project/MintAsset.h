// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/MintInput.h"
#include "Project/TransactionRequestArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for minting assets.
 */
class ENJINSDKRUNTIME_API FMintAsset final : public GraphQl::IGraphQlRequest,
                                      public TTransactionRequestArguments<FMintAsset>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FMintAsset();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FMintAsset() override = default;

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
	FMintAsset& SetAssetId(FString Id);

	/**
	 * @brief Sets the mints to be performed.
	 * @param Mints The mints.
	 * @return This request for chaining.
	 */
	FMintAsset& SetMints(TArray<Model::FMintInput> Mints);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FMintAsset& Rhs) const;

	bool operator!=(const FMintAsset& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<TArray<Model::FMintInput>> MintsOpt;
};

// region TTransactionRequestArguments

template ENJINSDKRUNTIME_API FMintAsset&
TTransactionRequestArguments<FMintAsset>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithError();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithState();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
