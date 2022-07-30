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
 * @brief Request for approving the crypto items contract for to spend the maximum amount of ENJ.
 */
class ENJINSDK_API FApproveMaxEnj final : public GraphQl::IGraphQlRequest,
                                          public Shared::TTransactionFragmentArguments<FApproveMaxEnj>
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
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithAssetData();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithBlockchainData();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithEncodedData();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithError();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithLogEvent();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithMeta();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithNonce();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithReceipt();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithReceiptLogs();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithSignedTxs();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithState();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithTransactionProjectUuid();

template ENJINSDK_API Player::FApproveMaxEnj&
TTransactionFragmentArguments<Player::FApproveMaxEnj>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
