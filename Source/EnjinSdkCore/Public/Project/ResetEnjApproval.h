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
class ENJINSDKCORE_API FResetEnjApproval final : public GraphQl::IGraphQlRequest,
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

template ENJINSDKCORE_API FResetEnjApproval&
TTransactionRequestArguments<FResetEnjApproval>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithAssetData();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithError();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithMeta();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithNonce();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithReceipt();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithState();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FResetEnjApproval&
TTransactionFragmentArguments<Project::FResetEnjApproval>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
