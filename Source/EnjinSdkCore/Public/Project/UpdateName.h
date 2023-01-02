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
 * @brief Request for setting the name of an existing asset.
 */
class ENJINSDKCORE_API FUpdateName final : public GraphQl::IGraphQlRequest,
                                           public TTransactionRequestArguments<FUpdateName>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FUpdateName();

	/**
	 * @brief Class destructor.
	 */
	virtual ~FUpdateName() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the ID of the asset to be updated.
	 * @param AssetId The ID.
	 * @return This request for chaining.
	 */
	FUpdateName& SetAssetId(FString AssetId);

	/**
	 * @brief Sets the name the asset will be updated to.
	 * @param Name The name.
	 * @return This request for chaining.
	 */
	FUpdateName& SetName(FString Name);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FUpdateName& Rhs) const;

	bool operator!=(const FUpdateName& Rhs) const;

private:
	TOptional<FString> AssetIdOpt;
	TOptional<FString> NameOpt;
};

// region TTransactionRequestArguments

template ENJINSDKCORE_API FUpdateName&
TTransactionRequestArguments<FUpdateName>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithAssetData();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithError();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithMeta();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithNonce();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithReceipt();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithState();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FUpdateName&
TTransactionFragmentArguments<Project::FUpdateName>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
