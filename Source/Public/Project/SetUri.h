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
 * @brief Request to set the metadata of an asset.
 */
class ENJINSDK_API FSetUri final : public GraphQl::IGraphQlRequest,
                                   public TTransactionRequestArguments<FSetUri>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FSetUri();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FSetUri() override = default;

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
	FSetUri& SetAssetId(FString Id);

	/**
	 * @brief Sets the index for non-fungible assets.
	 * @param Index The index.
	 * @return This request for chaining.
	 */
	FSetUri& SetAssetIndex(FString Index);

	/**
	 * @brief Sets the new URI for the asset's metadata.
	 * @param Uri The URI.
	 * @return This request for chaining.
	 */
	FSetUri& SetUri(FString Uri);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FSetUri& Rhs) const;

	bool operator!=(const FSetUri& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<FString> AssetIndexOpt;
	TOptional<FString> UriOpt;
};

// region TTransactionRequestArguments

template ENJINSDK_API FSetUri&
TTransactionRequestArguments<FSetUri>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithAssetData();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithBlockchainData();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithEncodedData();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithError();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithLogEvent();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithMeta();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithNonce();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithReceipt();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithReceiptLogs();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithSignedTxs();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithState();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithTransactionProjectUuid();

template ENJINSDK_API Project::FSetUri&
TTransactionFragmentArguments<Project::FSetUri>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
