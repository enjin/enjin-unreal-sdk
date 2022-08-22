// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/DecreaseMaxTransferFee.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FDecreaseMaxTransferFee::FDecreaseMaxTransferFee() : IGraphQlRequest(TEXT("enjin.sdk.project.DecreaseMaxTransferFee")),
                                                     TTransactionRequestArguments<FDecreaseMaxTransferFee>()
{
}

FString FDecreaseMaxTransferFee::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FDecreaseMaxTransferFee& FDecreaseMaxTransferFee::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

FDecreaseMaxTransferFee& FDecreaseMaxTransferFee::SetMaxTransferFee(const int32 MaxTransferFee)
{
	MaxTransferFeeOpt.Emplace(MaxTransferFee);
	return *this;
}

TSharedRef<FJsonObject> FDecreaseMaxTransferFee::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FDecreaseMaxTransferFee>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("maxTransferFee"), MaxTransferFeeOpt);

	return JsonRef;
}

bool FDecreaseMaxTransferFee::operator==(const FDecreaseMaxTransferFee& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FDecreaseMaxTransferFee>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& MaxTransferFeeOpt == Rhs.MaxTransferFeeOpt;
}

bool FDecreaseMaxTransferFee::operator!=(const FDecreaseMaxTransferFee& Rhs) const
{
	return !(*this == Rhs);
}
