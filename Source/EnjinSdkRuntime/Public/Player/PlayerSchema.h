// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "Player/IPlayerSchema.h"
#include "Shared/SharedSchema.h"

namespace Enjin
{
namespace Sdk
{
namespace Player
{
/**
 * @brief Class for sending requests in the player schema.
 */
class ENJINSDKRUNTIME_API FPlayerSchema : public IPlayerSchema,
                                   public Shared::FSharedSchema
{
public:
	FPlayerSchema() = delete;

	/**
	 * @brief Default destructor.
	 */
	virtual ~FPlayerSchema() override = default;

	/**
	 * @brief Sends the AdvancedSendAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	AdvancedSendAsset(const Enjin::Sdk::Player::FAdvancedSendAsset& Request) override;

	/**
	 * @brief Sends the ApproveEnj request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ApproveEnj(const Enjin::Sdk::Player::FApproveEnj& Request) override;

	/**
	 * @brief Sends the ApproveMaxEnj request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ApproveMaxEnj(const Enjin::Sdk::Player::FApproveMaxEnj& Request) override;

	/**
	 * @brief Sends the BridgeAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	BridgeAsset(const Enjin::Sdk::Player::FBridgeAsset& Request) override;

	/**
	 * @brief Sends the BridgeAssets request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	BridgeAssets(const Enjin::Sdk::Player::FBridgeAssets& Request) override;

	/**
	 * @brief Sends the BridgeClaimAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	BridgeClaimAsset(const Enjin::Sdk::Player::FBridgeClaimAsset& Request) override;

	/**
	 * @brief Sends the GetPlayer request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FPlayer>>
	GetPlayer(const Enjin::Sdk::Player::FGetPlayer& Request) override;

	/**
	 * @brief Sends the GetWallet request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FWallet>>
	GetWallet(const Enjin::Sdk::Player::FGetWallet& Request) override;

	/**
	 * @brief Sends the MeltAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	MeltAsset(const Enjin::Sdk::Player::FMeltAsset& Request) override;

	/**
	 * @brief Sends the Message request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	Message(const Enjin::Sdk::Player::FMessage& Request) override;

	/**
	 * @brief Sends the ResetEnjApproval request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	ResetEnjApproval(const Enjin::Sdk::Player::FResetEnjApproval& Request) override;

	/**
	 * @brief Sends the SendAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SendAsset(const Enjin::Sdk::Player::FSendAsset& Request) override;

	/**
	 * @brief Sends the SendEnj request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SendEnj(const Enjin::Sdk::Player::FSendEnj& Request) override;

	/**
	 * @brief Sends the SetApprovalForAll request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	SetApprovalForAll(const Enjin::Sdk::Player::FSetApprovalForAll& Request) override;

	/**
	 * @brief Sends the UnlinkWallet request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<bool>>
	UnlinkWallet(const Enjin::Sdk::Player::FUnlinkWallet& Request) override;

protected:
	/**
	 * @brief Constructs an instance of this class
	 * @param BaseUrl The base URL for the platform.
	 * @param HttpLogLevel The log level for HTTP traffic.
	 * @param LoggerProvider The logger provider.
	 */
	explicit FPlayerSchema(FString BaseUrl,
	                       const Http::EHttpLogLevel HttpLogLevel,
	                       Util::FLoggerProviderPtr LoggerProvider = nullptr);
};
}
}
}
