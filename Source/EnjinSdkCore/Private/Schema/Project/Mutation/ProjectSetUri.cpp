// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/SetUri.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FSetUri::FSetUri() : IGraphQlRequest(TEXT("enjin.sdk.project.SetUri")),
                     TTransactionRequestArguments<FSetUri>()
{
}

FString FSetUri::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FSetUri& FSetUri::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

FSetUri& FSetUri::SetAssetIndex(FString Index)
{
	AssetIndexOpt.Emplace(MoveTemp(Index));
	return *this;
}

FSetUri& FSetUri::SetUri(FString Uri)
{
	UriOpt.Emplace(MoveTemp(Uri));
	return *this;
}

TSharedRef<FJsonObject> FSetUri::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FSetUri>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("assetIndex"), AssetIndexOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("uri"), UriOpt);

	return JsonRef;
}

bool FSetUri::operator==(const FSetUri& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FSetUri>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& AssetIndexOpt == Rhs.AssetIndexOpt
		&& UriOpt == Rhs.UriOpt;
}

bool FSetUri::operator!=(const FSetUri& Rhs) const
{
	return !(*this == Rhs);
}
