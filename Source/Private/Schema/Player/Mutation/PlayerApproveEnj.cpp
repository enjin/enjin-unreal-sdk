// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/ApproveEnj.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FApproveEnj::FApproveEnj() : IGraphQlRequest(TEXT("enjin.sdk.player.ApproveEnj")),
                                                 TTransactionFragmentArguments<FApproveEnj>()
{
}

FString Enjin::Sdk::Player::FApproveEnj::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Player::FApproveEnj& Enjin::Sdk::Player::FApproveEnj::SetValue(FString Value)
{
	ValueOpt.Emplace(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FApproveEnj::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FApproveEnj>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

	return JsonRef;
}

bool Enjin::Sdk::Player::FApproveEnj::operator==(const FApproveEnj& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FApproveEnj>&>(*this) == Rhs
		&& ValueOpt == Rhs.ValueOpt;
}

bool Enjin::Sdk::Player::FApproveEnj::operator!=(const FApproveEnj& Rhs) const
{
	return !(*this == Rhs);
}
