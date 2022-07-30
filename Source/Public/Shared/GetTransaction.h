// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Shared/TransactionFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Request for getting a transaction on the platform.
 */
class ENJINSDK_API FGetTransaction final : public GraphQl::IGraphQlRequest,
                                           public TTransactionFragmentArguments<FGetTransaction>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetTransaction();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetTransaction() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the ID of the transaction to get.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FGetTransaction& SetId(const int32 Id);

	/**
	 * @brief Sets the hash ID of the transaction to get.
	 * @param Id The hash ID.
	 * @return This request for chaining.
	 */
	FGetTransaction& SetTransactionId(FString Id);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetTransaction& Rhs) const;

	bool operator!=(const FGetTransaction& Rhs) const;

private:
	TOptional<int32> IdOpt;
	TOptional<FString> TransactionIdOpt;
};

// region TTransactionFragmentArguments

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithAssetData();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithBlockchainData();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithEncodedData();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithError();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithLogEvent();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithMeta();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithNonce();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithReceipt();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithReceiptLogs();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithSignedTxs();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithState();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithTransactionProjectUuid();

template ENJINSDK_API FGetTransaction&
TTransactionFragmentArguments<FGetTransaction>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
