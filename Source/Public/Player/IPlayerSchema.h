// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "GraphQlResponse.h"
#include "Model/Player.h"
#include "Model/Transaction.h"
#include "Model/Wallet.h"
#include "Player/AdvancedSendAsset.h"
#include "Player/ApproveEnj.h"
#include "Player/ApproveMaxEnj.h"
#include "Player/BridgeAsset.h"
#include "Player/BridgeAssets.h"
#include "Player/BridgeClaimAsset.h"
#include "Player/GetPlayer.h"
#include "Player/GetWallet.h"
#include "Player/MeltAsset.h"
#include "Player/Message.h"
#include "Player/ResetEnjApproval.h"
#include "Player/SendAsset.h"
#include "Player/SendEnj.h"
#include "Player/SetApprovalForAll.h"
#include "Player/UnlinkWallet.h"

namespace Enjin
{
namespace Sdk
{
namespace Player
{
/**
 * @brief Interface for player schema.
 */
class ENJINSDK_API IPlayerSchema
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~IPlayerSchema() = default;

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
	 * @brief Sends the GetPlayer request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FPlayer>>
	GetPlayer(const FGetPlayer& Request) = 0;

	/**
	 * @brief Sends the GetWallet request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FWallet>>
	GetWallet(const FGetWallet& Request) = 0;

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
