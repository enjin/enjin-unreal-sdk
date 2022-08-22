// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/DeletePlayer.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FDeletePlayer::FDeletePlayer() : IGraphQlRequest(TEXT("enjin.sdk.project.DeletePlayer"))
{
}

FString FDeletePlayer::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FDeletePlayer& FDeletePlayer::SetId(FString Id)
{
	IdOpt.Emplace(MoveTemp(Id));
	return *this;
}

TSharedRef<FJsonObject> FDeletePlayer::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);

	return JsonRef;
}

bool FDeletePlayer::operator==(const FDeletePlayer& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& IdOpt == Rhs.IdOpt;
}

bool FDeletePlayer::operator!=(const FDeletePlayer& Rhs) const
{
	return !(*this == Rhs);
}
