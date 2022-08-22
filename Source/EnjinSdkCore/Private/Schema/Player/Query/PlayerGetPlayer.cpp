// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/GetPlayer.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FGetPlayer::FGetPlayer() : IGraphQlRequest(TEXT("enjin.sdk.player.GetPlayer")),
                                               TPlayerFragmentArguments<FGetPlayer>()
{
}

FString Enjin::Sdk::Player::FGetPlayer::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FGetPlayer::ToJson() const
{
	return TPlayerFragmentArguments<FGetPlayer>::ToJson();
}

bool Enjin::Sdk::Player::FGetPlayer::operator==(const FGetPlayer& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TPlayerFragmentArguments<FGetPlayer>&>(*this) == Rhs;
}

bool Enjin::Sdk::Player::FGetPlayer::operator!=(const FGetPlayer& Rhs) const
{
	return !(*this == Rhs);
}
