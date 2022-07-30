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
 * @brief Request for releasing the reserve of an asset.
 */
class ENJINSDK_API FReleaseReserve final : public GraphQl::IGraphQlRequest,
                                           public TTransactionRequestArguments<FReleaseReserve>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FReleaseReserve();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FReleaseReserve() override = default;

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
	FReleaseReserve& SetAssetId(FString Id);

	/**
	 * @brief Sets the amount to release.
	 * @param Value The amount.
	 * @return This request for chaining.
	 */
	FReleaseReserve& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FReleaseReserve& Rhs) const;

	bool operator!=(const FReleaseReserve& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<FString> ValueOpt;
};

// region TTransactionRequestArguments

template ENJINSDK_API FReleaseReserve&
TTransactionRequestArguments<FReleaseReserve>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithAssetData();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithBlockchainData();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithEncodedData();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithError();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithLogEvent();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithMeta();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithNonce();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithReceipt();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithReceiptLogs();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithSignedTxs();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithState();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithTransactionProjectUuid();

template ENJINSDK_API Project::FReleaseReserve&
TTransactionFragmentArguments<Project::FReleaseReserve>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
