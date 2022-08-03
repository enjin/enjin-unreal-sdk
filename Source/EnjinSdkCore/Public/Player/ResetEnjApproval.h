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
 * @brief Request for resetting the crypto items contract approval for ENJ.
 */
class ENJINSDKCORE_API FResetEnjApproval final : public GraphQl::IGraphQlRequest,
                                             public Shared::TTransactionFragmentArguments<FResetEnjApproval>
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
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithAssetData();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithBlockchainData();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithEncodedData();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithError();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithLogEvent();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithMeta();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithNonce();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithReceipt();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithReceiptLogs();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithSignedTxs();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithState();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Player::FResetEnjApproval&
TTransactionFragmentArguments<Player::FResetEnjApproval>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
