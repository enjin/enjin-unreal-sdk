// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/ApproveMaxEnj.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FApproveMaxEnj::FApproveMaxEnj() : IGraphQlRequest(TEXT("enjin.sdk.player.ApproveMaxEnj")),
                                                       TTransactionFragmentArguments<FApproveMaxEnj>()
{
}

FString Enjin::Sdk::Player::FApproveMaxEnj::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FApproveMaxEnj::ToJson() const
{
	return TTransactionFragmentArguments<FApproveMaxEnj>::ToJson();
}

bool Enjin::Sdk::Player::FApproveMaxEnj::operator==(const FApproveMaxEnj& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FApproveMaxEnj>&>(*this) == Rhs;
}

bool Enjin::Sdk::Player::FApproveMaxEnj::operator!=(const FApproveMaxEnj& Rhs) const
{
	return !(*this == Rhs);
}
