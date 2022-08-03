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
 * @brief Request for setting the max melt fee of an asset to a lower value.
 */
class ENJINSDK_API FDecreaseMaxMeltFee final : public GraphQl::IGraphQlRequest,
                                               public TTransactionRequestArguments<FDecreaseMaxMeltFee>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FDecreaseMaxMeltFee();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FDecreaseMaxMeltFee() override = default;

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
	FDecreaseMaxMeltFee& SetAssetId(FString Id);

	/**
	 * @brief Sets the new max melt fee for the asset.
	 * @param MeltFeeRatio The new melt fee ratio.
	 * @return This request for chaining.
	 * @remarks The ratio is in the range 0-5000 to allow fractional ratios, e.g. 1 = 0.01%, 5000 = 50%, ect...
	 */
	FDecreaseMaxMeltFee& SetMaxMeltFee(const int32 MeltFeeRatio);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FDecreaseMaxMeltFee& Rhs) const;

	bool operator!=(const FDecreaseMaxMeltFee& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<int32> MaxMeltFeeOpt;
};

// region TTransactionRequestArguments

template ENJINSDK_API FDecreaseMaxMeltFee&
TTransactionRequestArguments<FDecreaseMaxMeltFee>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithAssetData();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithBlockchainData();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithEncodedData();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithError();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithLogEvent();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithMeta();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithNonce();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithReceipt();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithReceiptLogs();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithSignedTxs();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithState();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithTransactionProjectUuid();

template ENJINSDK_API Project::FDecreaseMaxMeltFee&
TTransactionFragmentArguments<Project::FDecreaseMaxMeltFee>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
