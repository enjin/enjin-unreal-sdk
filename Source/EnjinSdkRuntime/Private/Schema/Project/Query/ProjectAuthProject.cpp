// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/AuthProject.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FAuthProject::FAuthProject() : IGraphQlRequest(TEXT("enjin.sdk.project.AuthProject"))
{
}

FString FAuthProject::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FAuthProject& FAuthProject::SetSecret(FString Secret)
{
	SecretOpt.Emplace(MoveTemp(Secret));
	return *this;
}

FAuthProject& FAuthProject::SetUuid(FString Uuid)
{
	UuidOpt.Emplace(MoveTemp(Uuid));
	return *this;
}

TSharedRef<FJsonObject> FAuthProject::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::TrySetField(JsonRef, TEXT("secret"), SecretOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("uuid"), UuidOpt);

	return JsonRef;
}

bool FAuthProject::operator==(const FAuthProject& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& SecretOpt == Rhs.SecretOpt
		&& UuidOpt == Rhs.UuidOpt;
}

bool FAuthProject::operator!=(const FAuthProject& Rhs) const
{
	return !(*this == Rhs);
}
