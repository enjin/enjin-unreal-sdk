// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/ApproveEnj.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FApproveEnj::FApproveEnj() : IGraphQlRequest(TEXT("enjin.sdk.project.ApproveEnj")),
                                                  TTransactionRequestArguments<FApproveEnj>()
{
}

FString Enjin::Sdk::Project::FApproveEnj::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FApproveEnj& Enjin::Sdk::Project::FApproveEnj::SetValue(FString Value)
{
	ValueOpt.Emplace(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FApproveEnj::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FApproveEnj>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FApproveEnj::operator==(const FApproveEnj& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FApproveEnj>&>(*this) == Rhs
		&& ValueOpt == Rhs.ValueOpt;
}

bool Enjin::Sdk::Project::FApproveEnj::operator!=(const FApproveEnj& Rhs) const
{
	return !(*this == Rhs);
}
