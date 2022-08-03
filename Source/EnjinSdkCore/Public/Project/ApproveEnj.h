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
 * @brief Request for approving the crypto items contract to spend ENJ.
 */
class ENJINSDKCORE_API FApproveEnj final : public GraphQl::IGraphQlRequest,
                                       public TTransactionRequestArguments<FApproveEnj>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FApproveEnj();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FApproveEnj() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the amount of ENJ to approve.
	 * @param Value The value.
	 * @return This request for chaining.
	 * @remarks The value is in Wei as 10^18 (e.g. 1 ENJ = 1000000000000000000).
	 */
	FApproveEnj& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FApproveEnj& Rhs) const;

	bool operator!=(const FApproveEnj& Rhs) const;

private:
	TOptional<FString> ValueOpt;
};

// region TTransactionRequestArguments

template ENJINSDKCORE_API FApproveEnj&
TTransactionRequestArguments<FApproveEnj>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithAssetData();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithError();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithMeta();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithNonce();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithReceipt();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithState();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FApproveEnj&
TTransactionFragmentArguments<Project::FApproveEnj>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
