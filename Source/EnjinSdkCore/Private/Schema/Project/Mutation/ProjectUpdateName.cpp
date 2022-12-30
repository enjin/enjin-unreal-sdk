// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/UpdateName.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FUpdateName::FUpdateName() : IGraphQlRequest(TEXT("enjin.sdk.project.UpdateName")),
                             TTransactionRequestArguments<FUpdateName>()
{
}

FUpdateName::~FUpdateName() = default;

FString FUpdateName::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FUpdateName& FUpdateName::SetAssetId(FString AssetId)
{
	AssetIdOpt = MoveTemp(AssetId);
	return *this;
}

FUpdateName& FUpdateName::SetName(FString Name)
{
	NameOpt = MoveTemp(Name);
	return *this;
}

TSharedRef<FJsonObject> FUpdateName::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FUpdateName>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("name"), NameOpt);

	return JsonRef;
}

bool FUpdateName::operator==(const FUpdateName& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FUpdateName>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& NameOpt == Rhs.NameOpt;
}

bool FUpdateName::operator!=(const FUpdateName& Rhs) const
{
	return !(*this == Rhs);
}
