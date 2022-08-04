// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/BridgeClaimAsset.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FBridgeClaimAsset::FBridgeClaimAsset() : IGraphQlRequest(TEXT("enjin.sdk.player.BridgeClaimAsset")),
                                                             TTransactionFragmentArguments<FBridgeClaimAsset>()
{
}

FString Enjin::Sdk::Player::FBridgeClaimAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Player::FBridgeClaimAsset& Enjin::Sdk::Player::FBridgeClaimAsset::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FBridgeClaimAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FBridgeClaimAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);

	return JsonRef;
}

bool Enjin::Sdk::Player::FBridgeClaimAsset::operator==(const FBridgeClaimAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FBridgeClaimAsset>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt;
}

bool Enjin::Sdk::Player::FBridgeClaimAsset::operator!=(const FBridgeClaimAsset& Rhs) const
{
	return !(*this == Rhs);
}
