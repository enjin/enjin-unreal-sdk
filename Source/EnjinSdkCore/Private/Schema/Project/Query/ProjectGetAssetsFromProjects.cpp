// Copyright 2023 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/GetAssetsFromProjects.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetAssetsFromProjects::FGetAssetsFromProjects() : IGraphQlRequest(TEXT("enjin.sdk.project.FGetAssetsFromProjects")),
                                                   TAssetFragmentArguments<FGetAssetsFromProjects>(),
                                                   TPaginationArguments<FGetAssetsFromProjects>()
{
}

FString FGetAssetsFromProjects::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FGetAssetsFromProjects& FGetAssetsFromProjects::SetFilter(Model::FAssetFilter Filter)
{
	FilterOpt = MoveTemp(Filter);
	return *this;
}

FGetAssetsFromProjects& FGetAssetsFromProjects::SetProjects(TArray<FString> Projects)
{
	ProjectsOpt = MoveTemp(Projects);
	return *this;
}

FGetAssetsFromProjects& FGetAssetsFromProjects::SetSort(Model::FAssetSortInput Sort)
{
	SortOpt = MoveTemp(Sort);
	return *this;
}

TSharedRef<FJsonObject> FGetAssetsFromProjects::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TAssetFragmentArguments<FGetAssetsFromProjects>::ToJson());
	FJsonUtil::JoinObject(JsonRef, TPaginationArguments<FGetAssetsFromProjects>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("filter"), FilterOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("projects"), ProjectsOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("sort"), SortOpt);

	return JsonRef;
}

bool FGetAssetsFromProjects::operator==(const FGetAssetsFromProjects& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TAssetFragmentArguments<FGetAssetsFromProjects>&>(*this) == Rhs
		&& static_cast<const TPaginationArguments<FGetAssetsFromProjects>&>(*this) == Rhs
		&& FilterOpt == Rhs.FilterOpt
		&& ProjectsOpt == Rhs.ProjectsOpt
		&& SortOpt == Rhs.SortOpt;
}

bool FGetAssetsFromProjects::operator!=(const FGetAssetsFromProjects& Rhs) const
{
	return !(*this == Rhs);
}
