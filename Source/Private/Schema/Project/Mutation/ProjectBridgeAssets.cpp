// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/BridgeAssets.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FBridgeAssets::FBridgeAssets() : IGraphQlRequest(TEXT("enjin.sdk.project.BridgeAssets")),
                                                      TTransactionRequestArguments<FBridgeAssets>()
{
}

FString Enjin::Sdk::Project::FBridgeAssets::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FBridgeAssets& Enjin::Sdk::Project::FBridgeAssets::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

Enjin::Sdk::Project::FBridgeAssets& Enjin::Sdk::Project::FBridgeAssets::SetAssetIndices(TArray<FString> Indices)
{
	AssetIndicesOpt.Emplace(MoveTemp(Indices));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FBridgeAssets::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FBridgeAssets>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("assetIndices"), AssetIndicesOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FBridgeAssets::operator==(const FBridgeAssets& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FBridgeAssets>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& AssetIndicesOpt == Rhs.AssetIndicesOpt;
}

bool Enjin::Sdk::Project::FBridgeAssets::operator!=(const FBridgeAssets& Rhs) const
{
	return !(*this == Rhs);
}
