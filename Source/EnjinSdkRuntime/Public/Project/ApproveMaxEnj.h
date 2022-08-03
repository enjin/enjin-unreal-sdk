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
class ENJINSDKRUNTIME_API FApproveMaxEnj final : public GraphQl::IGraphQlRequest,
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

template ENJINSDKRUNTIME_API FApproveMaxEnj&
TTransactionRequestArguments<FApproveMaxEnj>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithError();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithState();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FApproveMaxEnj&
TTransactionFragmentArguments<Project::FApproveMaxEnj>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
