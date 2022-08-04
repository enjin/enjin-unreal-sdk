// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/PlayerSchema.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Http;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Player;
using namespace Enjin::Sdk::Util;

FPlayerSchema::FPlayerSchema(FString BaseUrl, const EHttpLogLevel HttpLogLevel, FLoggerProviderPtr LoggerProvider)
	: FSharedSchema(MoveTemp(BaseUrl), TEXT("player"), HttpLogLevel, MoveTemp(LoggerProvider))
{
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::AdvancedSendAsset(const Enjin::Sdk::Player::FAdvancedSendAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::ApproveEnj(const Enjin::Sdk::Player::FApproveEnj& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::ApproveMaxEnj(const Enjin::Sdk::Player::FApproveMaxEnj& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::BridgeAsset(const Enjin::Sdk::Player::FBridgeAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::BridgeAssets(const Enjin::Sdk::Player::FBridgeAssets& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::BridgeClaimAsset(const Enjin::Sdk::Player::FBridgeClaimAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FPlayer>>
FPlayerSchema::GetPlayer(const Enjin::Sdk::Player::FGetPlayer& Request)
{
	return SendRequestForOne<FPlayer>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FWallet>>
FPlayerSchema::GetWallet(const Enjin::Sdk::Player::FGetWallet& Request)
{
	return SendRequestForOne<FWallet>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::MeltAsset(const Enjin::Sdk::Player::FMeltAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::Message(const Enjin::Sdk::Player::FMessage& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::ResetEnjApproval(const Enjin::Sdk::Player::FResetEnjApproval& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::SendAsset(const Enjin::Sdk::Player::FSendAsset& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::SendEnj(const Enjin::Sdk::Player::FSendEnj& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>>
FPlayerSchema::SetApprovalForAll(const Enjin::Sdk::Player::FSetApprovalForAll& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForOnePtr<bool>>
FPlayerSchema::UnlinkWallet(const Enjin::Sdk::Player::FUnlinkWallet& Request)
{
	return SendRequestForOne<bool>(Request);
}
