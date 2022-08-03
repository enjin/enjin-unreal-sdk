// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/UnlinkWallet.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FUnlinkWallet::FUnlinkWallet() : IGraphQlRequest(TEXT("enjin.sdk.player.UnlinkWallet"))
{
}

FString Enjin::Sdk::Player::FUnlinkWallet::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FUnlinkWallet::ToJson() const
{
	return MakeShared<FJsonObject>();
}

bool Enjin::Sdk::Player::FUnlinkWallet::operator==(const FUnlinkWallet& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs;
}

bool Enjin::Sdk::Player::FUnlinkWallet::operator!=(const FUnlinkWallet& Rhs) const
{
	return !(*this == Rhs);
}
