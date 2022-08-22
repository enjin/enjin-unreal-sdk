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
 * @brief Request for setting the max transfer fee of an asset to a lower value.
 */
class ENJINSDKCORE_API FDecreaseMaxTransferFee final : public GraphQl::IGraphQlRequest,
                                                   public TTransactionRequestArguments<FDecreaseMaxTransferFee>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FDecreaseMaxTransferFee();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FDecreaseMaxTransferFee() override = default;

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
	FDecreaseMaxTransferFee& SetAssetId(FString Id);

	/**
	 * @brief Sets the new max transfer fee in Wei.
	 * @param MaxTransferFee The new fee.
	 * @return This request for chaining.
	 */
	FDecreaseMaxTransferFee& SetMaxTransferFee(const int32 MaxTransferFee);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FDecreaseMaxTransferFee& Rhs) const;

	bool operator!=(const FDecreaseMaxTransferFee& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<int32> MaxTransferFeeOpt;
};

// region TTransactionRequestArguments

template ENJINSDKCORE_API FDecreaseMaxTransferFee&
TTransactionRequestArguments<FDecreaseMaxTransferFee>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithAssetData();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithError();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithMeta();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithNonce();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithReceipt();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithState();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FDecreaseMaxTransferFee&
TTransactionFragmentArguments<Project::FDecreaseMaxTransferFee>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
