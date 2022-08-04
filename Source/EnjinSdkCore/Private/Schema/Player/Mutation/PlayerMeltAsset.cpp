// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/MeltAsset.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FMeltAsset::FMeltAsset() : IGraphQlRequest(TEXT("enjin.sdk.player.MeltAsset")),
                                               TTransactionFragmentArguments<FMeltAsset>()
{
}

FString Enjin::Sdk::Player::FMeltAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Player::FMeltAsset& Enjin::Sdk::Player::FMeltAsset::SetMelts(TArray<FMeltInput> Melts)
{
	MeltsOpt.Emplace(MoveTemp(Melts));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FMeltAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FMeltAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("melts"), MeltsOpt);

	return JsonRef;
}

bool Enjin::Sdk::Player::FMeltAsset::operator==(const FMeltAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FMeltAsset>&>(*this) == Rhs
		&& MeltsOpt == Rhs.MeltsOpt;
}

bool Enjin::Sdk::Player::FMeltAsset::operator!=(const FMeltAsset& Rhs) const
{
	return !(*this == Rhs);
}
