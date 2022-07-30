// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/GetPlayers.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetPlayers::FGetPlayers() : IGraphQlRequest(TEXT("enjin.sdk.project.GetPlayers")),
                             TPlayerFragmentArguments<FGetPlayers>(),
                             TPaginationArguments<FGetPlayers>()
{
}

FString FGetPlayers::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FGetPlayers& FGetPlayers::SetFilter(FPlayerFilter Filter)
{
	FilterOpt.Emplace(MoveTemp(Filter));
	return *this;
}

TSharedRef<FJsonObject> FGetPlayers::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TPlayerFragmentArguments<FGetPlayers>::ToJson());
	FJsonUtil::JoinObject(JsonRef, TPaginationArguments<FGetPlayers>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("filter"), FilterOpt);

	return JsonRef;
}

bool FGetPlayers::operator==(const FGetPlayers& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TPlayerFragmentArguments<FGetPlayers>&>(*this) == Rhs
		&& static_cast<const TPaginationArguments<FGetPlayers>&>(*this) == Rhs
		&& FilterOpt == Rhs.FilterOpt;
}

bool FGetPlayers::operator!=(const FGetPlayers& Rhs) const
{
	return !(*this == Rhs);
}
