// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/AuthPlayer.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FAuthPlayer::FAuthPlayer() : IGraphQlRequest(TEXT("enjin.sdk.project.AuthPlayer"))
{
}

FString FAuthPlayer::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FAuthPlayer& FAuthPlayer::SetId(FString Id)
{
	IdOpt.Emplace(MoveTemp(Id));
	return *this;
}

TSharedRef<FJsonObject> FAuthPlayer::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);

	return JsonRef;
}

bool FAuthPlayer::operator==(const FAuthPlayer& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& IdOpt == Rhs.IdOpt;
}

bool FAuthPlayer::operator!=(const FAuthPlayer& Rhs) const
{
	return !(*this == Rhs);
}
