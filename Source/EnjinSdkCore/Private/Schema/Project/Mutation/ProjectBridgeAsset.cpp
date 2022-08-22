// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/BridgeAsset.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FBridgeAsset::FBridgeAsset() : IGraphQlRequest(TEXT("enjin.sdk.project.BridgeAsset")),
                                                    TTransactionRequestArguments<FBridgeAsset>()
{
}

FString Enjin::Sdk::Project::FBridgeAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FBridgeAsset& Enjin::Sdk::Project::FBridgeAsset::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

Enjin::Sdk::Project::FBridgeAsset& Enjin::Sdk::Project::FBridgeAsset::SetAssetIndex(FString Index)
{
	AssetIndexOpt.Emplace(MoveTemp(Index));
	return *this;
}

Enjin::Sdk::Project::FBridgeAsset& Enjin::Sdk::Project::FBridgeAsset::SetValue(FString Value)
{
	ValueOpt.Emplace(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FBridgeAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FBridgeAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("assetIndex"), AssetIndexOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FBridgeAsset::operator==(const FBridgeAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FBridgeAsset>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& AssetIndexOpt == Rhs.AssetIndexOpt
		&& ValueOpt == Rhs.ValueOpt;
}

bool Enjin::Sdk::Project::FBridgeAsset::operator!=(const FBridgeAsset& Rhs) const
{
	return !(*this == Rhs);
}
