// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/SetMeltFee.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FSetMeltFee::FSetMeltFee() : IGraphQlRequest(TEXT("enjin.sdk.project.SetMeltFee")),
                             TTransactionRequestArguments<FSetMeltFee>()
{
}

FString FSetMeltFee::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FSetMeltFee& FSetMeltFee::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

FSetMeltFee& FSetMeltFee::SetMeltFee(const int32 MeltFeeRatio)
{
	MeltFeeOpt.Emplace(MeltFeeRatio);
	return *this;
}

TSharedRef<FJsonObject> FSetMeltFee::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FSetMeltFee>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("meltFee"), MeltFeeOpt);

	return JsonRef;
}

bool FSetMeltFee::operator==(const FSetMeltFee& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FSetMeltFee>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& MeltFeeOpt == Rhs.MeltFeeOpt;
}

bool FSetMeltFee::operator!=(const FSetMeltFee& Rhs) const
{
	return !(*this == Rhs);
}
