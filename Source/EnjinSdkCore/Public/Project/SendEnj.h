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
 * @brief Request for sending ENJ.
 */
class ENJINSDKCORE_API FSendEnj final : public GraphQl::IGraphQlRequest,
                                    public TTransactionRequestArguments<FSendEnj>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FSendEnj();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FSendEnj() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the wallet address of the recipient.
	 * @param Address The address.
	 * @return This request for chaining.
	 */
	FSendEnj& SetRecipientAddress(FString Address);

	/**
	 * @brief Sets the amount of ENJ to send.
	 * @param Value The amount.
	 * @return This request for chaining.
	 * @remarks The value is in Wei as 10^18 (e.g. 1 ENJ = 1000000000000000000).
	 */
	FSendEnj& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FSendEnj& Rhs) const;

	bool operator!=(const FSendEnj& Rhs) const;

private:
	TOptional<FString> RecipientAddressOpt;
	TOptional<FString> ValueOpt;
};

// region TTransactionRequestArguments

template ENJINSDKCORE_API FSendEnj&
TTransactionRequestArguments<FSendEnj>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithAssetData();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithError();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithMeta();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithNonce();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithReceipt();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithState();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FSendEnj&
TTransactionFragmentArguments<Project::FSendEnj>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
