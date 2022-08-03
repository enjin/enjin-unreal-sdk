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
 * @brief Request for resetting the crypto items contract approval for ENJ.
 */
class ENJINSDKRUNTIME_API FResetEnjApproval final : public GraphQl::IGraphQlRequest,
                                             public TTransactionRequestArguments<FResetEnjApproval>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FResetEnjApproval();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FResetEnjApproval() override = default;

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

	bool operator==(const FResetEnjApproval& Rhs) const;

	bool operator!=(const FResetEnjApproval& Rhs) const;
};

// region TTransactionRequestArguments

template ENJINSDKRUNTIME_API FResetEnjApproval&
TTransactionRequestArguments<FResetEnjApproval>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithError();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithState();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
