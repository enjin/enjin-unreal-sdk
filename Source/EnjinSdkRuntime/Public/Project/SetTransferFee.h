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
 * @brief Request for setting the transfer fee of an asset.
 */
class ENJINSDKRUNTIME_API FSetTransferFee final : public GraphQl::IGraphQlRequest,
                                           public TTransactionRequestArguments<FSetTransferFee>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FSetTransferFee();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FSetTransferFee() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the asset ID.
	 * @param Id The ID.
	 * @return This request chaining.
	 */
	FSetTransferFee& SetAssetId(FString Id);

	/**
	 * @brief Sets the new transfer fee value in Wei.
	 * @param Fee The new transfer fee.
	 * @return This request chaining.
	 */
	FSetTransferFee& SetTransferFee(FString Fee);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FSetTransferFee& Rhs) const;

	bool operator!=(const FSetTransferFee& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<FString> TransferFeeOpt;
};

// region TTransactionRequestArguments

template ENJINSDKRUNTIME_API FSetTransferFee&
TTransactionRequestArguments<FSetTransferFee>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithError();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithState();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FSetTransferFee&
TTransactionFragmentArguments<Project::FSetTransferFee>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
