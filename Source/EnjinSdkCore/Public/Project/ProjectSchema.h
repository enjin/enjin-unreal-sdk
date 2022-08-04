// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "Project/IProjectSchema.h"
#include "Shared/SharedSchema.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Class for sending requests in the project schema.
 */
class ENJINSDKCORE_API FProjectSchema : public IProjectSchema,
                                    public Shared::FSharedSchema
{
public:
	FProjectSchema() = delete;

	/**
	 * @brief Default destructor.
	 */
	virtual ~FProjectSchema() override = default;

	/**
	 * @brief Sends the AdvancedSendAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	AdvancedSendAsset(const Enjin::Sdk::Project::FAdvancedSendAsset& Request) override;

	/**
	 * @brief Sends the ApproveEnj request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ApproveEnj(const Enjin::Sdk::Project::FApproveEnj& Request) override;

	/**
	 * @brief Sends the ApproveMaxEnj request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ApproveMaxEnj(const Enjin::Sdk::Project::FApproveMaxEnj& Request) override;

	/**
	 * @brief Sends the AuthPlayer request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FAccessToken>>
	AuthPlayer(const Enjin::Sdk::Project::FAuthPlayer& Request) override;

	/**
	 * @brief Sends the AuthProject request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FAccessToken>>
	AuthProject(const Enjin::Sdk::Project::FAuthProject& Request) override;

	/**
	 * @brief Sends the BridgeAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	BridgeAsset(const Enjin::Sdk::Project::FBridgeAsset& Request) override;

	/**
	 * @brief Sends the BridgeAssets request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	BridgeAssets(const Enjin::Sdk::Project::FBridgeAssets& Request) override;

	/**
	 * @brief Sends the BridgeClaimAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	BridgeClaimAsset(const Enjin::Sdk::Project::FBridgeClaimAsset& Request) override;

	/**
	 * @brief Sends the CompleteTrade request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	CompleteTrade(const Enjin::Sdk::Project::FCompleteTrade& Request) override;

	/**
	 * @brief Sends the CreateAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	CreateAsset(const Enjin::Sdk::Project::FCreateAsset& Request) override;

	/**
	 * @brief Sends the CreatePlayer request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FAccessToken>>
	CreatePlayer(const Enjin::Sdk::Project::FCreatePlayer& Request) override;

	/**
	 * @brief Sends the CreateTrade request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	CreateTrade(const Enjin::Sdk::Project::FCreateTrade& Request) override;

	/**
	 * @brief Sends the DecreaseMaxMeltFee request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	DecreaseMaxMeltFee(const Enjin::Sdk::Project::FDecreaseMaxMeltFee& Request) override;

	/**
	 * @brief Sends the DecreaseMaxTransferFee request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	DecreaseMaxTransferFee(const Enjin::Sdk::Project::FDecreaseMaxTransferFee& Request) override;

	/**
	 * @brief Sends the DeletePlayer request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<bool>>
	DeletePlayer(const Enjin::Sdk::Project::FDeletePlayer& Request) override;

	/**
	 * @brief Sends the GetPlayer request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FPlayer>>
	GetPlayer(const Enjin::Sdk::Project::FGetPlayer& Request) override;

	/**
	 * @brief Sends the GetPlayers request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FPlayer>>
	GetPlayers(const Enjin::Sdk::Project::FGetPlayers& Request) override;

	/**
	 * @brief Sends the GetWallet request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FWallet>>
	GetWallet(const Enjin::Sdk::Project::FGetWallet& Request) override;

	/**
	 * @brief Sends the GetWallets request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FWallet>>
	GetWallets(const Enjin::Sdk::Project::FGetWallets& Request) override;

	/**
	 * @brief Sends the InvalidateAssetMetadata request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<bool>>
	InvalidateAssetMetadata(const Enjin::Sdk::Project::FInvalidateAssetMetadata& Request) override;

	/**
	 * @brief Sends the MeltAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	MeltAsset(const Enjin::Sdk::Project::FMeltAsset& Request) override;

	/**
	 * @brief Sends the Message request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	Message(const Enjin::Sdk::Project::FMessage& Request) override;

	/**
	 * @brief Sends the MintAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	MintAsset(const Enjin::Sdk::Project::FMintAsset& Request) override;

	/**
	 * @brief Sends the ReleaseReserve request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ReleaseReserve(const Enjin::Sdk::Project::FReleaseReserve& Request) override;

	/**
	 * @brief Sends the ResetEnjApproval request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ResetEnjApproval(const Enjin::Sdk::Project::FResetEnjApproval& Request) override;

	/**
	 * @brief Sends the SendAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SendAsset(const Enjin::Sdk::Project::FSendAsset& Request) override;

	/**
	 * @brief Sends the SendEnj request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SendEnj(const Enjin::Sdk::Project::FSendEnj& Request) override;

	/**
	 * @brief Sends the SetApprovalForAll request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetApprovalForAll(const Enjin::Sdk::Project::FSetApprovalForAll& Request) override;

	/**
	 * @brief Sends the SetMeltFee request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetMeltFee(const Enjin::Sdk::Project::FSetMeltFee& Request) override;

	/**
	 * @brief Sends the SetTransferFee request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetTransferFee(const Enjin::Sdk::Project::FSetTransferFee& Request) override;

	/**
	 * @brief Sends the SetTransferable request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetTransferable(const Enjin::Sdk::Project::FSetTransferable& Request) override;

	/**
	 * @brief Sends the SetUri request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetUri(const Enjin::Sdk::Project::FSetUri& Request) override;

	/**
	 * @brief Sends the SetWhitelisted request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetWhitelisted(const Enjin::Sdk::Project::FSetWhitelisted& Request) override;

	/**
	 * @brief Sends the UnlinkWallet request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<bool>>
	UnlinkWallet(const Enjin::Sdk::Project::FUnlinkWallet& Request) override;

protected:
	/**
	 * @brief Constructs an instance of this class
	 * @param BaseUrl The base URL for the platform.
	 * @param HttpLogLevel The log level for HTTP traffic.
	 * @param LoggerProvider The logger provider.
	 */
	explicit FProjectSchema(FString BaseUrl,
	                        const Http::EHttpLogLevel HttpLogLevel,
	                        Util::FLoggerProviderPtr LoggerProvider = nullptr);
};
}
}
}
