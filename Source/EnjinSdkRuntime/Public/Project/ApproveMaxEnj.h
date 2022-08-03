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
 * @brief Request for approving the crypto items contract for to spend the maximum amount of ENJ.
 */
class ENJINSDK_API FApproveMaxEnj final : public GraphQl::IGraphQlRequest,
                                          public TTransactionRequestArguments<FApproveMaxEnj>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FApproveMaxEnj();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FApproveMaxEnj() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FApproveMaxEnj& Rhs) const;

	bool operator!=(const FApproveMaxEnj& Rhs) const;
};

// region TTransactionRequestArguments

template ENJINSDK_API FApproveMaxEnj&
TTransactionRequestArguments<FApproveMaxEnj>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithAssetData();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithBlockchainData();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithEncodedData();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithError();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithLogEvent();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithMeta();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithNonce();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithReceipt();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithReceiptLogs();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithSignedTxs();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithState();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithTransactionProjectUuid();

template ENJINSDK_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
