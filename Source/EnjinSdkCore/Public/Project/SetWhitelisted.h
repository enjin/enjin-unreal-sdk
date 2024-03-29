﻿// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/Whitelisted.h"
#include "Project/TransactionRequestArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for setting an asset's whitelist.
 */
class ENJINSDKCORE_API FSetWhitelisted final : public GraphQl::IGraphQlRequest,
                                           public TTransactionRequestArguments<FSetWhitelisted>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FSetWhitelisted();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FSetWhitelisted() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the account address to be added to the whitelist.
	 * @param Address The address.
	 * @return This request for chaining.
	 */
	FSetWhitelisted& SetAccountAddress(FString Address);

	/**
	 * @brief Sets the asset ID.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FSetWhitelisted& SetAssetId(FString Id);

	/**
	 * @brief Sets whether the whitelist setting is on or off.
	 * @param bIsOn The setting state.
	 * @return This request for chaining.
	 */
	FSetWhitelisted& SetOn(const bool bIsOn);

	/**
	 * @brief Sets the whitelist setting for the account.
	 * @param Setting The setting.
	 * @return This request for chaining.
	 */
	FSetWhitelisted& SetWhitelisted(const Model::EWhitelisted Setting);

	/**
	 * @brief Sets the specified address for sending or receiving.
	 * @param Address The address.
	 * @return This request for chaining.
	 */
	FSetWhitelisted& SetWhitelistedAddress(FString Address);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FSetWhitelisted& Rhs) const;

	bool operator!=(const FSetWhitelisted& Rhs) const;

private:
	TOptional<FString> AccountAddressOpt;
	TOptional<FString> AssetIdOpt;
	TOptional<bool> OnOpt;
	TOptional<FString> WhitelistedAddressOpt;
	TOptional<Model::EWhitelisted> WhitelistedOpt;
};

// region TTransactionRequestArguments

template ENJINSDKCORE_API FSetWhitelisted&
TTransactionRequestArguments<FSetWhitelisted>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetTransactionAssetIdFormat(
	const Model::EAssetIdFormat Format);

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithAssetData();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithBlockchainData();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithEncodedData();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithError();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithLogEvent();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithMeta();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithNonce();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithReceipt();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithReceiptLogs();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithSignedTxs();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithState();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithTransactionProjectUuid();

template ENJINSDKCORE_API Project::FSetWhitelisted&
TTransactionFragmentArguments<Project::FSetWhitelisted>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
