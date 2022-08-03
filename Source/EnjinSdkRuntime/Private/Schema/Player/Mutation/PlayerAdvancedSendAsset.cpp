// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/AdvancedSendAsset.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FAdvancedSendAsset::FAdvancedSendAsset()
	: IGraphQlRequest(TEXT("enjin.sdk.player.AdvancedSendAsset")),
	  TTransactionFragmentArguments<FAdvancedSendAsset>()
{
}

FString Enjin::Sdk::Player::FAdvancedSendAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Player::FAdvancedSendAsset& Enjin::Sdk::Player::FAdvancedSendAsset::SetData(FString Data)
{
	DataOpt.Emplace(MoveTemp(Data));
	return *this;
}

Enjin::Sdk::Player::FAdvancedSendAsset&
Enjin::Sdk::Player::FAdvancedSendAsset::SetTransfers(TArray<FTransferInput> Transfers)
{
	TransfersOpt.Emplace(MoveTemp(Transfers));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FAdvancedSendAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FAdvancedSendAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("data"), DataOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("transfers"), TransfersOpt);

	return JsonRef;
}

bool Enjin::Sdk::Player::FAdvancedSendAsset::operator==(const FAdvancedSendAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FAdvancedSendAsset>&>(*this) == Rhs
		&& DataOpt == Rhs.DataOpt
		&& TransfersOpt == Rhs.TransfersOpt;
}

bool Enjin::Sdk::Player::FAdvancedSendAsset::operator!=(const FAdvancedSendAsset& Rhs) const
{
	return !(*this == Rhs);
}
