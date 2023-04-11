// Copyright 2023 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/GetBalancesFromProjects.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetBalancesFromProjects::FGetBalancesFromProjects()
	: IGraphQlRequest(TEXT("enjin.sdk.shared.GetBalancesFromProjects")),
	  TBalanceFragmentArguments<FGetBalancesFromProjects>(),
	  TPaginationArguments<FGetBalancesFromProjects>()
{
}

FString FGetBalancesFromProjects::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FGetBalancesFromProjects& FGetBalancesFromProjects::SetFilter(Model::FBalanceFilter Filter)
{
	FilterOpt = MoveTemp(Filter);
	return *this;
}

FGetBalancesFromProjects& FGetBalancesFromProjects::SetProjects(TArray<FString> Projects)
{
	ProjectsOpt = MoveTemp(Projects);
	return *this;
}

TSharedRef<FJsonObject> FGetBalancesFromProjects::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TBalanceFragmentArguments<FGetBalancesFromProjects>::ToJson());
	FJsonUtil::JoinObject(JsonRef, TPaginationArguments<FGetBalancesFromProjects>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("filter"), FilterOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("projects"), ProjectsOpt);

	return JsonRef;
}

bool FGetBalancesFromProjects::operator==(const FGetBalancesFromProjects& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TBalanceFragmentArguments<FGetBalancesFromProjects>&>(*this) == Rhs
		&& static_cast<const TPaginationArguments<FGetBalancesFromProjects>&>(*this) == Rhs
		&& FilterOpt == Rhs.FilterOpt
		&& ProjectsOpt == Rhs.ProjectsOpt;
}

bool FGetBalancesFromProjects::operator!=(const FGetBalancesFromProjects& Rhs) const
{
	return !(*this == Rhs);
}
