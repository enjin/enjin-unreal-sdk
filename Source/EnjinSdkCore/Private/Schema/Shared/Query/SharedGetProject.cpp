// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/GetProject.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetProject::FGetProject() : IGraphQlRequest(TEXT("enjin.sdk.shared.GetProject"))
{
}

FString FGetProject::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

TSharedRef<FJsonObject> FGetProject::ToJson() const
{
	return MakeShared<FJsonObject>();
}

bool FGetProject::operator==(const FGetProject& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs;
}

bool FGetProject::operator!=(const FGetProject& Rhs) const
{
	return !(*this == Rhs);
}
