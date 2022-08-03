// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/ApproveMaxEnj.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FApproveMaxEnj::FApproveMaxEnj()
	: IGraphQlRequest(TEXT("enjin.sdk.project.ApproveMaxEnj")),
	  TTransactionRequestArguments<FApproveMaxEnj>()
{
}

FString Enjin::Sdk::Project::FApproveMaxEnj::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FApproveMaxEnj::ToJson() const
{
	return TTransactionRequestArguments<FApproveMaxEnj>::ToJson();
}

bool Enjin::Sdk::Project::FApproveMaxEnj::operator==(const FApproveMaxEnj& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FApproveMaxEnj>&>(*this) == Rhs;
}

bool Enjin::Sdk::Project::FApproveMaxEnj::operator!=(const FApproveMaxEnj& Rhs) const
{
	return !(*this == Rhs);
}
