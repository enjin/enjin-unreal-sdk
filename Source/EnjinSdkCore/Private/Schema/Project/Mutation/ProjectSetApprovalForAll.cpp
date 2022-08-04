// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/SetApprovalForAll.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FSetApprovalForAll::FSetApprovalForAll()
	: IGraphQlRequest(TEXT("enjin.sdk.project.SetApprovalForAll")),
	  TTransactionRequestArguments<FSetApprovalForAll>()
{
}

FString Enjin::Sdk::Project::FSetApprovalForAll::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FSetApprovalForAll& Enjin::Sdk::Project::FSetApprovalForAll::SetApproved(const bool bIsApproved)
{
	ApprovedOpt.Emplace(bIsApproved);
	return *this;
}

Enjin::Sdk::Project::FSetApprovalForAll& Enjin::Sdk::Project::FSetApprovalForAll::SetOperatorAddress(FString Address)
{
	OperatorAddressOpt.Emplace(MoveTemp(Address));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FSetApprovalForAll::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FSetApprovalForAll>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("approved"), ApprovedOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("operatorAddress"), OperatorAddressOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FSetApprovalForAll::operator==(const FSetApprovalForAll& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FSetApprovalForAll>&>(*this) == Rhs
		&& ApprovedOpt == Rhs.ApprovedOpt
		&& OperatorAddressOpt == Rhs.OperatorAddressOpt;
}

bool Enjin::Sdk::Project::FSetApprovalForAll::operator!=(const FSetApprovalForAll& Rhs) const
{
	return !(*this == Rhs);
}
