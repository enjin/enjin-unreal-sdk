// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/BridgeClaimAsset.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FBridgeClaimAsset::FBridgeClaimAsset()
	: IGraphQlRequest(TEXT("enjin.sdk.project.BridgeClaimAsset")),
	  TTransactionRequestArguments<FBridgeClaimAsset>()
{
}

FString Enjin::Sdk::Project::FBridgeClaimAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FBridgeClaimAsset& Enjin::Sdk::Project::FBridgeClaimAsset::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FBridgeClaimAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FBridgeClaimAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FBridgeClaimAsset::operator==(const FBridgeClaimAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FBridgeClaimAsset>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt;
}

bool Enjin::Sdk::Project::FBridgeClaimAsset::operator!=(const FBridgeClaimAsset& Rhs) const
{
	return !(*this == Rhs);
}
