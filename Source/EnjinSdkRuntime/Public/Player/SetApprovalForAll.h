// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Shared/TransactionFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Player
{
/**
 * @brief Request for allowing an operator complete control of all assets owned by the caller.
 */
class ENJINSDK_API FSetApprovalForAll final : public GraphQl::IGraphQlRequest,
                                              public Shared::TTransactionFragmentArguments<FSetApprovalForAll>
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
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithAssetData();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithBlockchainData();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithEncodedData();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithError();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithLogEvent();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithMeta();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithNonce();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithReceipt();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithReceiptLogs();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithSignedTxs();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithState();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithTransactionProjectUuid();

template ENJINSDK_API Player::FSetApprovalForAll&
TTransactionFragmentArguments<Player::FSetApprovalForAll>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
