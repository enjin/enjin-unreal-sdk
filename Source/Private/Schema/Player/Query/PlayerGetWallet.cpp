// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/GetWallet.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FGetWallet::FGetWallet() : IGraphQlRequest(TEXT("enjin.sdk.player.GetWallet")),
                                               TWalletFragmentArguments<FGetWallet>()
{
}

FString Enjin::Sdk::Player::FGetWallet::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FGetWallet::ToJson() const
{
	return TWalletFragmentArguments<FGetWallet>::ToJson();
}

bool Enjin::Sdk::Player::FGetWallet::operator==(const FGetWallet& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TWalletFragmentArguments<FGetWallet>&>(*this) == Rhs;
}

bool Enjin::Sdk::Player::FGetWallet::operator!=(const FGetWallet& Rhs) const
{
	return !(*this == Rhs);
}
