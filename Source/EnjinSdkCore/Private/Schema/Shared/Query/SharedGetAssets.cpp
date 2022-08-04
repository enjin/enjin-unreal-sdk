// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/GetAssets.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetAssets::FGetAssets() : IGraphQlRequest(TEXT("enjin.sdk.shared.GetAssets")),
                           TAssetFragmentArguments<FGetAssets>(),
                           TPaginationArguments<FGetAssets>()
{
}

FString FGetAssets::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FGetAssets& FGetAssets::SetFilter(FAssetFilter Filter)
{
	FilterOpt.Emplace(MoveTemp(Filter));
	return *this;
}

FGetAssets& FGetAssets::SetSort(FAssetSortInput Sort)
{
	SortOpt.Emplace(MoveTemp(Sort));
	return *this;
}

TSharedRef<FJsonObject> FGetAssets::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TAssetFragmentArguments<FGetAssets>::ToJson());
	FJsonUtil::JoinObject(JsonRef, TPaginationArguments<FGetAssets>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("filter"), FilterOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("sort"), SortOpt);

	return JsonRef;
}

bool FGetAssets::operator==(const FGetAssets& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TAssetFragmentArguments<FGetAssets>&>(*this) == Rhs
		&& static_cast<const TPaginationArguments<FGetAssets>&>(*this) == Rhs
		&& FilterOpt == Rhs.FilterOpt
		&& SortOpt == Rhs.SortOpt;
}

bool FGetAssets::operator!=(const FGetAssets& Rhs) const
{
	return !(*this == Rhs);
}
