// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/GetPlayer.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FGetPlayer::FGetPlayer() : IGraphQlRequest(TEXT("enjin.sdk.project.GetPlayer")),
                                                TPlayerFragmentArguments<FGetPlayer>()
{
}

FString Enjin::Sdk::Project::FGetPlayer::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FGetPlayer& Enjin::Sdk::Project::FGetPlayer::SetId(FString Id)
{
	IdOpt.Emplace(MoveTemp(Id));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FGetPlayer::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TPlayerFragmentArguments<FGetPlayer>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FGetPlayer::operator==(const FGetPlayer& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TPlayerFragmentArguments<FGetPlayer>&>(*this) == Rhs
		&& IdOpt == Rhs.IdOpt;
}

bool Enjin::Sdk::Project::FGetPlayer::operator!=(const FGetPlayer& Rhs) const
{
	return !(*this == Rhs);
}
