// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/SetTransferFee.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FSetTransferFee::FSetTransferFee() : IGraphQlRequest(TEXT("enjin.sdk.project.SetTransferFee")),
                                     TTransactionRequestArguments<FSetTransferFee>()
{
}

FString FSetTransferFee::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FSetTransferFee& FSetTransferFee::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

FSetTransferFee& FSetTransferFee::SetTransferFee(FString Fee)
{
	TransferFeeOpt.Emplace(MoveTemp(Fee));
	return *this;
}

TSharedRef<FJsonObject> FSetTransferFee::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FSetTransferFee>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("transferFee"), TransferFeeOpt);

	return JsonRef;
}

bool FSetTransferFee::operator==(const FSetTransferFee& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FSetTransferFee>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& TransferFeeOpt == Rhs.TransferFeeOpt;
}

bool FSetTransferFee::operator!=(const FSetTransferFee& Rhs) const
{
	return !(*this == Rhs);
}
