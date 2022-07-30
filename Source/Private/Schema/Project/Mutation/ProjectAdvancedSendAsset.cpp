// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/AdvancedSendAsset.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FAdvancedSendAsset::FAdvancedSendAsset()
	: IGraphQlRequest(TEXT("enjin.sdk.project.AdvancedSendAsset")),
	  TTransactionRequestArguments<FAdvancedSendAsset>()
{
}

FString Enjin::Sdk::Project::FAdvancedSendAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FAdvancedSendAsset& Enjin::Sdk::Project::FAdvancedSendAsset::SetData(FString Data)
{
	DataOpt.Emplace(MoveTemp(Data));
	return *this;
}

Enjin::Sdk::Project::FAdvancedSendAsset&
Enjin::Sdk::Project::FAdvancedSendAsset::SetTransfers(TArray<FTransferInput> Transfers)
{
	TransfersOpt.Emplace(MoveTemp(Transfers));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FAdvancedSendAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FAdvancedSendAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("data"), DataOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("transfers"), TransfersOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FAdvancedSendAsset::operator==(const FAdvancedSendAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FAdvancedSendAsset>&>(*this) == Rhs
		&& DataOpt == Rhs.DataOpt
		&& TransfersOpt == Rhs.TransfersOpt;
}

bool Enjin::Sdk::Project::FAdvancedSendAsset::operator!=(const FAdvancedSendAsset& Rhs) const
{
	return !(*this == Rhs);
}
