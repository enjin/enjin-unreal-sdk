// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/BridgeAssets.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FBridgeAssets::FBridgeAssets() : IGraphQlRequest(TEXT("enjin.sdk.player.BridgeAssets")),
                                                     TTransactionFragmentArguments<FBridgeAssets>()
{
}

FString Enjin::Sdk::Player::FBridgeAssets::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Player::FBridgeAssets& Enjin::Sdk::Player::FBridgeAssets::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

Enjin::Sdk::Player::FBridgeAssets& Enjin::Sdk::Player::FBridgeAssets::SetAssetIndices(TArray<FString> Indices)
{
	AssetIndicesOpt.Emplace(MoveTemp(Indices));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FBridgeAssets::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FBridgeAssets>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("assetIndices"), AssetIndicesOpt);

	return JsonRef;
}

bool Enjin::Sdk::Player::FBridgeAssets::operator==(const FBridgeAssets& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FBridgeAssets>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& AssetIndicesOpt == Rhs.AssetIndicesOpt;
}

bool Enjin::Sdk::Player::FBridgeAssets::operator!=(const FBridgeAssets& Rhs) const
{
	return !(*this == Rhs);
}
