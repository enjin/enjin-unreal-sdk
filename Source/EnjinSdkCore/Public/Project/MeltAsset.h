// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/MeltInput.h"
#include "Project/TransactionRequestArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for melting assets.
 */
class ENJINSDKCORE_API FMeltAsset final : public GraphQl::IGraphQlRequest,
                                      public TTransactionRequestArguments<FMeltAsset>
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

// region TTransactionRequestArguments

template ENJINSDKCORE_API FMeltAsset&
TTransactionRequestArguments<FMeltAsset>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithAssetData();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithError();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithMeta();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithNonce();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithReceipt();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithState();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FMeltAsset&
TTransactionFragmentArguments<Project::FMeltAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
