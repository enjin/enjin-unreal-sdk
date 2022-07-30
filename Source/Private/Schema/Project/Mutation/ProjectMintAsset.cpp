// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/MintAsset.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FMintAsset::FMintAsset() : IGraphQlRequest(TEXT("enjin.sdk.project.MintAsset")),
                           TTransactionRequestArguments<FMintAsset>()
{
}

FString FMintAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FMintAsset& FMintAsset::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

FMintAsset& FMintAsset::SetMints(TArray<FMintInput> Mints)
{
	MintsOpt.Emplace(MoveTemp(Mints));
	return *this;
}

TSharedRef<FJsonObject> FMintAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FMintAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("mints"), MintsOpt);

	return JsonRef;
}

bool FMintAsset::operator==(const FMintAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FMintAsset>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& MintsOpt == Rhs.MintsOpt;
}

bool FMintAsset::operator!=(const FMintAsset& Rhs) const
{
	return !(*this == Rhs);
}
