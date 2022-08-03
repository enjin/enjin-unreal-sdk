// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/MeltAsset.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FMeltAsset::FMeltAsset() : IGraphQlRequest(TEXT("enjin.sdk.project.MeltAsset")),
                                                TTransactionRequestArguments<FMeltAsset>()
{
}

FString Enjin::Sdk::Project::FMeltAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FMeltAsset& Enjin::Sdk::Project::FMeltAsset::SetMelts(TArray<FMeltInput> Melts)
{
	MeltsOpt.Emplace(MoveTemp(Melts));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FMeltAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FMeltAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("melts"), MeltsOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FMeltAsset::operator==(const FMeltAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FMeltAsset>&>(*this) == Rhs
		&& MeltsOpt == Rhs.MeltsOpt;
}

bool Enjin::Sdk::Project::FMeltAsset::operator!=(const FMeltAsset& Rhs) const
{
	return !(*this == Rhs);
}
