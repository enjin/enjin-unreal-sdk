// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "GraphQlResponse.h"
#include "Model/AccessToken.h"
#include "Model/Player.h"
#include "Model/Transaction.h"
#include "Model/Wallet.h"
#include "Project/AdvancedSendAsset.h"
#include "Project/ApproveEnj.h"
#include "Project/ApproveMaxEnj.h"
#include "Project/AuthPlayer.h"
#include "Project/AuthProject.h"
#include "Project/BridgeAsset.h"
#include "Project/BridgeAssets.h"
#include "Project/BridgeClaimAsset.h"
#include "Project/CompleteTrade.h"
#include "Project/CreateAsset.h"
#include "Project/CreatePlayer.h"
#include "Project/CreateTrade.h"
#include "Project/DecreaseMaxMeltFee.h"
#include "Project/DecreaseMaxTransferFee.h"
#include "Project/DeletePlayer.h"
#include "Project/GetPlayer.h"
#include "Project/GetPlayers.h"
#include "Project/GetWallet.h"
#include "Project/GetWallets.h"
#include "Project/InvalidateAssetMetadata.h"
#include "Project/MeltAsset.h"
#include "Project/Message.h"
#include "Project/MintAsset.h"
#include "Project/ReleaseReserve.h"
#include "Project/ResetEnjApproval.h"
#include "Project/SendAsset.h"
#include "Project/SendEnj.h"
#include "Project/SetApprovalForAll.h"
#include "Project/SetMeltFee.h"
#include "Project/SetTransferFee.h"
#include "Project/SetTransferable.h"
#include "Project/SetUri.h"
#include "Project/SetWhitelisted.h"
#include "Project/UnlinkWallet.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Interface for project schema.
 */
class ENJINSDKRUNTIME_API IProjectSchema
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~IProjectSchema() = default;

	/**
	 * @brief Sends the AdvancedSendAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	AdvancedSendAsset(const FAdvancedSendAsset& Request) = 0;

	/**
	 * @brief Sends the ApproveEnj request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ApproveEnj(const FApproveEnj& Request) = 0;

	/**
	 * @brief Sends the ApproveMaxEnj request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ApproveMaxEnj(const FApproveMaxEnj& Request) = 0;

	/**
	 * @brief Sends the AuthPlayer request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FAccessToken>>
	AuthPlayer(const FAuthPlayer& Request) = 0;

	/**
	 * @brief Sends the AuthProject request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FAccessToken>>
	AuthProject(const FAuthProject& Request) = 0;

	/**
	 * @brief Sends the BridgeAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	BridgeAsset(const FBridgeAsset& Request) = 0;

	/**
	 * @brief Sends the BridgeAssets request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	BridgeAssets(const FBridgeAssets& Request) = 0;

	/**
	 * @brief Sends the BridgeClaimAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	BridgeClaimAsset(const FBridgeClaimAsset& Request) = 0;

	/**
	 * @brief Sends the CompleteTrade request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	CompleteTrade(const FCompleteTrade& Request) = 0;

	/**
	 * @brief Sends the CreateAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	CreateAsset(const FCreateAsset& Request) = 0;

	/**
	 * @brief Sends the CreatePlayer request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FAccessToken>>
	CreatePlayer(const FCreatePlayer& Request) = 0;

	/**
	 * @brief Sends the CreateTrade request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	CreateTrade(const FCreateTrade& Request) = 0;

	/**
	 * @brief Sends the DecreaseMaxMeltFee request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	DecreaseMaxMeltFee(const FDecreaseMaxMeltFee& Request) = 0;

	/**
	 * @brief Sends the DecreaseMaxTransferFee request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	DecreaseMaxTransferFee(const FDecreaseMaxTransferFee& Request) = 0;

	/**
	 * @brief Sends the DeletePlayer request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<bool>>
	DeletePlayer(const FDeletePlayer& Request) = 0;

	/**
	 * @brief Sends the GetPlayer request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FPlayer>>
	GetPlayer(const FGetPlayer& Request) = 0;

	/**
	 * @brief Sends the GetPlayers request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FPlayer>>
	GetPlayers(const FGetPlayers& Request) = 0;

	/**
	 * @brief Sends the GetWallet request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FWallet>>
	GetWallet(const FGetWallet& Request) = 0;

	/**
	 * @brief Sends the GetWallets request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FWallet>>
	GetWallets(const FGetWallets& Request) = 0;

	/**
	 * @brief Sends the InvalidateAssetMetadata request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<bool>>
	InvalidateAssetMetadata(const FInvalidateAssetMetadata& Request) = 0;

	/**
	 * @brief Sends the MeltAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	MeltAsset(const FMeltAsset& Request) = 0;

	/**
	 * @brief Sends the Message request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	Message(const FMessage& Request) = 0;

	/**
	 * @brief Sends the MintAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	MintAsset(const FMintAsset& Request) = 0;

	/**
	 * @brief Sends the ReleaseReserve request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ReleaseReserve(const FReleaseReserve& Request) = 0;

	/**
	 * @brief Sends the ResetEnjApproval request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ResetEnjApproval(const FResetEnjApproval& Request) = 0;

	/**
	 * @brief Sends the SendAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SendAsset(const FSendAsset& Request) = 0;

	/**
	 * @brief Sends the SendEnj request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SendEnj(const FSendEnj& Request) = 0;

	/**
	 * @brief Sends the SetApprovalForAll request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetApprovalForAll(const FSetApprovalForAll& Request) = 0;

	/**
	 * @brief Sends the SetMeltFee request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetMeltFee(const FSetMeltFee& Request) = 0;

	/**
	 * @brief Sends the SetTransferFee request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetTransferFee(const FSetTransferFee& Request) = 0;

	/**
	 * @brief Sends the SetTransferable request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetTransferable(const FSetTransferable& Request) = 0;

	/**
	 * @brief Sends the SetUri request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetUri(const FSetUri& Request) = 0;

	/**
	 * @brief Sends the SetWhitelisted request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetWhitelisted(const FSetWhitelisted& Request) = 0;

	/**
	 * @brief Sends the UnlinkWallet request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<bool>>
	UnlinkWallet(const FUnlinkWallet& Request) = 0;
};
}
}
}
