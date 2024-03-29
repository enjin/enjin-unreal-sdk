﻿// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

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
class ENJINSDKCORE_API FMintAsset final : public GraphQl::IGraphQlRequest,
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

template ENJINSDKCORE_API FMintAsset&
TTransactionRequestArguments<FMintAsset>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithAssetData();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithError();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithMeta();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithNonce();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithReceipt();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithState();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FMintAsset&
TTransactionFragmentArguments<Project::FMintAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
