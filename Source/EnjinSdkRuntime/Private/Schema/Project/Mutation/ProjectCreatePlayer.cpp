// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/CreatePlayer.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FCreatePlayer::FCreatePlayer() : IGraphQlRequest(TEXT("enjin.sdk.project.CreatePlayer"))
{
}

FString FCreatePlayer::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FCreatePlayer& FCreatePlayer::SetId(FString Id)
{
	IdOpt.Emplace(MoveTemp(Id));
	return *this;
}

TSharedRef<FJsonObject> FCreatePlayer::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);

	return JsonRef;
}

bool FCreatePlayer::operator==(const FCreatePlayer& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& IdOpt == Rhs.IdOpt;
}

bool FCreatePlayer::operator!=(const FCreatePlayer& Rhs) const
{
	return !(*this == Rhs);
}
