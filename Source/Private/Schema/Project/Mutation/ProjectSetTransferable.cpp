// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/SetTransferable.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FSetTransferable::FSetTransferable() : IGraphQlRequest(TEXT("enjin.sdk.project.SetTransferable")),
                                       TTransactionRequestArguments<FSetTransferable>()
{
}

FString FSetTransferable::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FSetTransferable& FSetTransferable::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

FSetTransferable& FSetTransferable::SetAssetIndex(FString Index)
{
	AssetIndexOpt.Emplace(MoveTemp(Index));
	return *this;
}

FSetTransferable& FSetTransferable::SetTransferable(const EAssetTransferable Transferable)
{
	TransferableOpt.Emplace(Transferable);
	return *this;
}

TSharedRef<FJsonObject> FSetTransferable::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FSetTransferable>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("assetIndex"), AssetIndexOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("transferable"), TransferableOpt);

	return JsonRef;
}

bool FSetTransferable::operator==(const FSetTransferable& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FSetTransferable>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& AssetIndexOpt == Rhs.AssetIndexOpt
		&& TransferableOpt == Rhs.TransferableOpt;
}

bool FSetTransferable::operator!=(const FSetTransferable& Rhs) const
{
	return !(*this == Rhs);
}
