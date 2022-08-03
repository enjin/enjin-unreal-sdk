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
 * @brief Request to sign a message to prove wallet ownership.
 */
class ENJINSDKRUNTIME_API FMessage final : public GraphQl::IGraphQlRequest,
                                    public TTransactionRequestArguments<FMessage>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FMessage();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FMessage() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the message to sign.
	 * @param Message The message.
	 * @return This request for chaining.
	 */
	FMessage& SetMessage(FString Message);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FMessage& Rhs) const;

	bool operator!=(const FMessage& Rhs) const;

private:
	TOptional<FString> MessageOpt;
};

// region TTransactionRequestArguments

template ENJINSDKRUNTIME_API FMessage&
TTransactionRequestArguments<FMessage>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithError();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithState();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FMessage&
TTransactionFragmentArguments<Project::FMessage>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
