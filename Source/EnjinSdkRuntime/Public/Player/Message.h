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
 * @brief Request to sign a message to prove wallet ownership.
 */
class ENJINSDK_API FMessage final : public GraphQl::IGraphQlRequest,
                                    public Shared::TTransactionFragmentArguments<FMessage>
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
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithAssetData();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithBlockchainData();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithEncodedData();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithError();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithLogEvent();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithMeta();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithNonce();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithReceipt();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithReceiptLogs();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithSignedTxs();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithState();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithTransactionProjectUuid();

template ENJINSDK_API Player::FMessage&
TTransactionFragmentArguments<Player::FMessage>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
