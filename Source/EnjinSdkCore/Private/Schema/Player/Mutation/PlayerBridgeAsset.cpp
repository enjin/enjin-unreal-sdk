// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/BridgeAsset.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FBridgeAsset::FBridgeAsset() : IGraphQlRequest(TEXT("enjin.sdk.player.BridgeAsset")),
                                                   TTransactionFragmentArguments<FBridgeAsset>()
{
}

FString Enjin::Sdk::Player::FBridgeAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Player::FBridgeAsset& Enjin::Sdk::Player::FBridgeAsset::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

Enjin::Sdk::Player::FBridgeAsset& Enjin::Sdk::Player::FBridgeAsset::SetAssetIndex(FString Index)
{
	AssetIndexOpt.Emplace(MoveTemp(Index));
	return *this;
}

Enjin::Sdk::Player::FBridgeAsset& Enjin::Sdk::Player::FBridgeAsset::SetValue(FString Value)
{
	ValueOpt.Emplace(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FBridgeAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FBridgeAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("assetIndex"), AssetIndexOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

	return JsonRef;
}

bool Enjin::Sdk::Player::FBridgeAsset::operator==(const FBridgeAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FBridgeAsset>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& AssetIndexOpt == Rhs.AssetIndexOpt
		&& ValueOpt == Rhs.ValueOpt;
}

bool Enjin::Sdk::Player::FBridgeAsset::operator!=(const FBridgeAsset& Rhs) const
{
	return !(*this == Rhs);
}
