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
 * @brief Request for allowing an operator complete control of all assets owned by the caller.
 */
class ENJINSDKCORE_API FSetApprovalForAll final : public GraphQl::IGraphQlRequest,
                                              public TTransactionRequestArguments<FSetApprovalForAll>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FSetApprovalForAll();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FSetApprovalForAll() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the approval state.
	 * @param bIsApproved The approval.
	 * @return This request for chaining.
	 */
	FSetApprovalForAll& SetApproved(const bool bIsApproved);

	/**
	 * @brief Sets the wallet address of the operator.
	 * @param Address The address.
	 * @return This request for chaining.
	 */
	FSetApprovalForAll& SetOperatorAddress(FString Address);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FSetApprovalForAll& Rhs) const;

	bool operator!=(const FSetApprovalForAll& Rhs) const;

private:
	TOptional<bool> ApprovedOpt;
	TOptional<FString> OperatorAddressOpt;
};

// region TTransactionRequestArguments

template ENJINSDKCORE_API FSetApprovalForAll&
TTransactionRequestArguments<FSetApprovalForAll>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithAssetData();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithError();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithMeta();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithNonce();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithReceipt();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithState();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FSetApprovalForAll&
TTransactionFragmentArguments<Project::FSetApprovalForAll>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
