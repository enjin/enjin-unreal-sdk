// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/ReleaseReserve.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FReleaseReserve::FReleaseReserve() : IGraphQlRequest(TEXT("enjin.sdk.project.ReleaseReserve")),
                                     TTransactionRequestArguments<FReleaseReserve>()
{
}

FString FReleaseReserve::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FReleaseReserve& FReleaseReserve::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

FReleaseReserve& FReleaseReserve::SetValue(FString Value)
{
	ValueOpt.Emplace(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> FReleaseReserve::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FReleaseReserve>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

	return JsonRef;
}

bool FReleaseReserve::operator==(const FReleaseReserve& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FReleaseReserve>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& ValueOpt == Rhs.ValueOpt;
}

bool FReleaseReserve::operator!=(const FReleaseReserve& Rhs) const
{
	return !(*this == Rhs);
}
