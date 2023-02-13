// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/ProjectSchema.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Http;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FProjectSchema::FProjectSchema(FString BaseUrl, const EHttpLogLevel HttpLogLevel, FLoggerProviderPtr LoggerProvider)
	: FSharedSchema(MoveTemp(BaseUrl), TEXT("project"), HttpLogLevel, MoveTemp(LoggerProvider))
{
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::AdvancedSendAsset(const Enjin::Sdk::Project::FAdvancedSendAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::ApproveEnj(const Enjin::Sdk::Project::FApproveEnj& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::ApproveMaxEnj(const Enjin::Sdk::Project::FApproveMaxEnj& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FAccessToken>>
FProjectSchema::AuthPlayer(const Enjin::Sdk::Project::FAuthPlayer& Request)
{
	return SendRequestForOne<FAccessToken>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FAccessToken>>
FProjectSchema::AuthProject(const Enjin::Sdk::Project::FAuthProject& Request)
{
	return SendRequestForOne<FAccessToken>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::BridgeAsset(const Enjin::Sdk::Project::FBridgeAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::BridgeAssets(const Enjin::Sdk::Project::FBridgeAssets& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::BridgeClaimAsset(const Enjin::Sdk::Project::FBridgeClaimAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::CompleteTrade(const Enjin::Sdk::Project::FCompleteTrade& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::CreateAsset(const Enjin::Sdk::Project::FCreateAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FAccessToken>>
FProjectSchema::CreatePlayer(const Enjin::Sdk::Project::FCreatePlayer& Request)
{
	return SendRequestForOne<FAccessToken>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::CreateTrade(const Enjin::Sdk::Project::FCreateTrade& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::DecreaseMaxMeltFee(const Enjin::Sdk::Project::FDecreaseMaxMeltFee& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::DecreaseMaxTransferFee(const Enjin::Sdk::Project::FDecreaseMaxTransferFee& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<bool>>
FProjectSchema::DeletePlayer(const Enjin::Sdk::Project::FDeletePlayer& Request)
{
	return SendRequestForOne<bool>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FPlayer>>
FProjectSchema::GetPlayer(const Enjin::Sdk::Project::FGetPlayer& Request)
{
	return SendRequestForOne<FPlayer>(Request);
}

TFuture<TGraphQlResponseForManyPtr<FPlayer>>
FProjectSchema::GetPlayers(const Enjin::Sdk::Project::FGetPlayers& Request)
{
	return SendRequestForMany<FPlayer>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FWallet>>
FProjectSchema::GetWallet(const Enjin::Sdk::Project::FGetWallet& Request)
{
	return SendRequestForOne<FWallet>(Request);
}

TFuture<TGraphQlResponseForManyPtr<FWallet>>
FProjectSchema::GetWallets(const Enjin::Sdk::Project::FGetWallets& Request)
{
	return SendRequestForMany<FWallet>(Request);
}

TFuture<TGraphQlResponseForOnePtr<bool>>
FProjectSchema::InvalidateAssetMetadata(const Enjin::Sdk::Project::FInvalidateAssetMetadata& Request)
{
	return SendRequestForOne<bool>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::MeltAsset(const Enjin::Sdk::Project::FMeltAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::Message(const Enjin::Sdk::Project::FMessage& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::MintAsset(const Enjin::Sdk::Project::FMintAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::ReleaseReserve(const Enjin::Sdk::Project::FReleaseReserve& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::ResetEnjApproval(const Enjin::Sdk::Project::FResetEnjApproval& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::SendAsset(const Enjin::Sdk::Project::FSendAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::SendEnj(const Enjin::Sdk::Project::FSendEnj& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::SetApprovalForAll(const Enjin::Sdk::Project::FSetApprovalForAll& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::SetMeltFee(const Enjin::Sdk::Project::FSetMeltFee& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::SetTransferFee(const Enjin::Sdk::Project::FSetTransferFee& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::SetTransferable(const Enjin::Sdk::Project::FSetTransferable& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::SetUri(const Enjin::Sdk::Project::FSetUri& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::SetWhitelisted(const Enjin::Sdk::Project::FSetWhitelisted& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<bool>>
FProjectSchema::UnlinkWallet(const Enjin::Sdk::Project::FUnlinkWallet& Request)
{
	return SendRequestForOne<bool>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FProjectSchema::UpdateName(const FUpdateName& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}
