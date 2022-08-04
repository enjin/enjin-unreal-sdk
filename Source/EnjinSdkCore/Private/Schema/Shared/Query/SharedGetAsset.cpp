// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/GetAsset.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetAsset::FGetAsset() : IGraphQlRequest(TEXT("enjin.sdk.shared.GetAsset")),
                         TAssetFragmentArguments<FGetAsset>()
{
}

FString FGetAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FGetAsset& FGetAsset::SetId(FString Id)
{
	IdOpt.Emplace(MoveTemp(Id));
	return *this;
}

TSharedRef<FJsonObject> FGetAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TAssetFragmentArguments::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);

	return JsonRef;
}

bool FGetAsset::operator==(const FGetAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TAssetFragmentArguments<FGetAsset>&>(*this) == Rhs
		&& IdOpt == Rhs.IdOpt;
}

bool FGetAsset::operator!=(const FGetAsset& Rhs) const
{
	return !(*this == Rhs);
}
