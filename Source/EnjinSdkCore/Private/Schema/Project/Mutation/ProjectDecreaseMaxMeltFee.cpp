// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/DecreaseMaxMeltFee.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FDecreaseMaxMeltFee::FDecreaseMaxMeltFee() : IGraphQlRequest(TEXT("enjin.sdk.project.DecreaseMaxMeltFee")),
                                             TTransactionRequestArguments<FDecreaseMaxMeltFee>()
{
}

FString FDecreaseMaxMeltFee::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FDecreaseMaxMeltFee& FDecreaseMaxMeltFee::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

FDecreaseMaxMeltFee& FDecreaseMaxMeltFee::SetMaxMeltFee(const int32 MeltFeeRatio)
{
	MaxMeltFeeOpt.Emplace(MeltFeeRatio);
	return *this;
}

TSharedRef<FJsonObject> FDecreaseMaxMeltFee::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FDecreaseMaxMeltFee>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("maxMeltFee"), MaxMeltFeeOpt);

	return JsonRef;
}

bool FDecreaseMaxMeltFee::operator==(const FDecreaseMaxMeltFee& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FDecreaseMaxMeltFee>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& MaxMeltFeeOpt == Rhs.MaxMeltFeeOpt;
}

bool FDecreaseMaxMeltFee::operator!=(const FDecreaseMaxMeltFee& Rhs) const
{
	return !(*this == Rhs);
}
