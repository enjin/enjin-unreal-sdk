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
 * @brief Request for setting the melt fee of an asset.
 */
class ENJINSDK_API FSetMeltFee final : public GraphQl::IGraphQlRequest,
                                       public TTransactionRequestArguments<FSetMeltFee>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FSetMeltFee();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FSetMeltFee() override = default;

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
	FSetMeltFee& SetAssetId(FString Id);

	/**
	 * @brief Sets the new melt fee for the asset.
	 * @param MeltFeeRatio The new melt fee ratio.
	 * @return This request for chaining.
	 * @remarks The ratio is in the range 0-5000 to allow fractional ratios, e.g. 1 = 0.01%, 5000 = 50%, ect...
	 */
	FSetMeltFee& SetMeltFee(const int32 MeltFeeRatio);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FSetMeltFee& Rhs) const;

	bool operator!=(const FSetMeltFee& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<int32> MeltFeeOpt;
};

// region TTransactionRequestArguments

template ENJINSDK_API FSetMeltFee&
TTransactionRequestArguments<FSetMeltFee>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithAssetData();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithBlockchainData();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithEncodedData();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithError();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithLogEvent();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithMeta();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithNonce();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithReceipt();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithReceiptLogs();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithSignedTxs();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithState();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithTransactionProjectUuid();

template ENJINSDK_API Project::FSetMeltFee&
TTransactionFragmentArguments<Project::FSetMeltFee>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
