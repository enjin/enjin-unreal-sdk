// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/InvalidateAssetMetadata.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FInvalidateAssetMetadata::FInvalidateAssetMetadata()
	: IGraphQlRequest(TEXT("enjin.sdk.project.InvalidateAssetMetadata"))
{
}

FString FInvalidateAssetMetadata::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FInvalidateAssetMetadata& FInvalidateAssetMetadata::SetId(FString Id)
{
	IdOpt.Emplace(MoveTemp(Id));
	return *this;
}

TSharedRef<FJsonObject> FInvalidateAssetMetadata::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);

	return JsonRef;
}

bool FInvalidateAssetMetadata::operator==(const FInvalidateAssetMetadata& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& IdOpt == Rhs.IdOpt;
}

bool FInvalidateAssetMetadata::operator!=(const FInvalidateAssetMetadata& Rhs) const
{
	return !(*this == Rhs);
}
