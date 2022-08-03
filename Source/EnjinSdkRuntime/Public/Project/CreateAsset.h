// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"
#include "Model/AssetSupplyModel.h"
#include "Model/AssetTransferFeeSettingsInput.h"
#include "Model/AssetTransferable.h"
#include "Project/TransactionRequestArguments.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for creating an asset on the platform.
 */
class ENJINSDKRUNTIME_API FCreateAsset final : public GraphQl::IGraphQlRequest,
                                        public TTransactionRequestArguments<FCreateAsset>
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FCreateAsset();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FCreateAsset() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the initial reserve of the asset.
	 * @param InitialReserve The reserve.
	 * @return This request for chaining.
	 */
	FCreateAsset& SetInitialReserve(FString InitialReserve);

	/**
	 * @brief Sets the ratio of the melt value to be returned to the creator.
	 * @param MeltFeeRatio The ratio.
	 * @return This request for chaining.
	 * @remarks The ratio is in the range 0-5000 to allow fractional ratios, e.g. 1 = 0.01%, 5000 = 50%, ect...
	 */
	FCreateAsset& SetMeltFeeRatio(const int32 MeltFeeRatio);

	/**
	 * @brief Sets the melt value of the asset.
	 * @param MeltValue The value.
	 * @return This request for chaining.
	 */
	FCreateAsset& SetMeltValue(FString MeltValue);

	/**
	 * @brief Sets the name of the asset.
	 * @param Name The name.
	 * @return This request for chaining.
	 */
	FCreateAsset& SetName(FString Name);

	/**
	 * @brief Sets whether the asset will be non-fungible or not.
	 * @param bIsNonFungible The fungible state.
	 * @return This request for chaining.
	 */
	FCreateAsset& SetNonFungible(const bool bIsNonFungible);

	/**
	 * @brief Sets the supply model of the asset.
	 * @param SupplyModel The supply model.
	 * @return This request for chaining.
	 */
	FCreateAsset& SetSupplyModel(const Model::EAssetSupplyModel SupplyModel);

	/**
	 * @brief Sets the total supply of the asset.
	 * @param TotalSupply The total supply.
	 * @return This request for chaining.
	 */
	FCreateAsset& SetTotalSupply(FString TotalSupply);

	/**
	 * @brief Sets the transfer fee settings of the asset.
	 * @param Settings The settings.
	 * @return This request for chaining.
	 */
	FCreateAsset& SetTransferFeeSettings(Model::FAssetTransferFeeSettingsInput Settings);

	/**
	 * @brief Sets the transferable type of the asset.
	 * @param Transferable The transferable type.
	 * @return This request for chaining.
	 */
	FCreateAsset& SetTransferable(const Model::EAssetTransferable Transferable);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FCreateAsset& Rhs) const;

	bool operator!=(const FCreateAsset& Rhs) const;

private:
	TOptional<FString> InitialReserveOpt;
	TOptional<int32> MeltFeeRatioOpt;
	TOptional<FString> MeltValueOpt;
	TOptional<FString> NameOpt;
	TOptional<bool> NonFungibleOpt;
	TOptional<Model::EAssetSupplyModel> SupplyModelOpt;
	TOptional<FString> TotalSupplyOpt;
	TOptional<Model::FAssetTransferFeeSettingsInput> TransferFeeSettingsOpt;
	TOptional<Model::EAssetTransferable> TransferableOpt;;
};

// region TTransactionRequestArguments

template ENJINSDKRUNTIME_API FCreateAsset&
TTransactionRequestArguments<FCreateAsset>::SetEthAddress(FString Address);

// endregion TTransactionRequestArguments
}

namespace Shared
{
// region TTransactionFragmentArguments

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format);

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithAssetData();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithBlockchainData();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithEncodedData();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithError();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithLogEvent();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithMeta();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithNonce();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithReceipt();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithReceiptLogs();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithSignedTxs();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithState();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithTransactionProjectUuid();

template ENJINSDKRUNTIME_API Project::FCreateAsset&
TTransactionFragmentArguments<Project::FCreateAsset>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments
}
}
}
