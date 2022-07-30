// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/MeltInput.h"
#include "Shared/TransactionFragmentArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Player
{
/**
 * @brief Request for melting assets.
 */
class ENJINSDK_API FMeltAsset final : public GraphQl::IGraphQlRequest,
                                      public Shared::TTransactionFragmentArguments<FMeltAsset>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FMeltAsset();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FMeltAsset() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the melts to be performed.
	 * @param Melts The melts.
	 * @return This request for chaining.
	 */
	FMeltAsset& SetMelts(TArray<Model::FMeltInput> Melts);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FMeltAsset& Rhs) const;

	bool operator!=(const FMeltAsset& Rhs) const;

private:
	TOptional<TArray<Model::FMeltInput>> MeltsOpt;
};
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithAssetData();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithBlockchainData();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithEncodedData();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithError();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithLogEvent();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithMeta();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithNonce();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithReceipt();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithReceiptLogs();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithSignedTxs();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithState();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithTransactionProjectUuid();

template ENJINSDK_API Player::FMeltAsset&
TTransactionFragmentArguments<Player::FMeltAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
