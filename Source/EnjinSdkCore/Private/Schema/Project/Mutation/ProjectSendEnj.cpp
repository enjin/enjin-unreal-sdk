// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/SendEnj.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FSendEnj::FSendEnj() : IGraphQlRequest(TEXT("enjin.sdk.project.SendEnj")),
                                            TTransactionRequestArguments<FSendEnj>()
{
}

FString Enjin::Sdk::Project::FSendEnj::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FSendEnj& Enjin::Sdk::Project::FSendEnj::SetRecipientAddress(FString Address)
{
	RecipientAddressOpt.Emplace(MoveTemp(Address));
	return *this;
}

Enjin::Sdk::Project::FSendEnj& Enjin::Sdk::Project::FSendEnj::SetValue(FString Value)
{
	ValueOpt.Emplace(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FSendEnj::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FSendEnj>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("recipientAddress"), RecipientAddressOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FSendEnj::operator==(const FSendEnj& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FSendEnj>&>(*this) == Rhs
		&& RecipientAddressOpt == Rhs.RecipientAddressOpt
		&& ValueOpt == Rhs.ValueOpt;
}

bool Enjin::Sdk::Project::FSendEnj::operator!=(const FSendEnj& Rhs) const
{
	return !(*this == Rhs);
}
