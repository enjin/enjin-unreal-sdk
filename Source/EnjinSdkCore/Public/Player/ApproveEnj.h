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
 * @brief Request for approving the crypto items contract to spend ENJ.
 */
class ENJINSDKCORE_API FApproveEnj final : public GraphQl::IGraphQlRequest,
                                       public Shared::TTransactionFragmentArguments<FApproveEnj>
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
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithAssetData();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithBlockchainData();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithEncodedData();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithError();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithLogEvent();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithMeta();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithNonce();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithReceipt();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithReceiptLogs();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithSignedTxs();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithState();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Player::FApproveEnj&
TTransactionFragmentArguments<Player::FApproveEnj>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
