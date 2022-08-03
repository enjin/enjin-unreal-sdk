// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/ResetEnjApproval.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FResetEnjApproval::FResetEnjApproval()
	: IGraphQlRequest(TEXT("enjin.sdk.project.ResetEnjApproval")),
	  TTransactionRequestArguments<FResetEnjApproval>()
{
}

FString Enjin::Sdk::Project::FResetEnjApproval::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FResetEnjApproval::ToJson() const
{
	return TTransactionRequestArguments<FResetEnjApproval>::ToJson();
}

bool Enjin::Sdk::Project::FResetEnjApproval::operator==(const FResetEnjApproval& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FResetEnjApproval>&>(*this) == Rhs;
}

bool Enjin::Sdk::Project::FResetEnjApproval::operator!=(const FResetEnjApproval& Rhs) const
{
	return !(*this == Rhs);
}
