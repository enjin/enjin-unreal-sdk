// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/ResetEnjApproval.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FResetEnjApproval::FResetEnjApproval() : IGraphQlRequest(TEXT("enjin.sdk.player.ResetEnjApproval")),
                                                             TTransactionFragmentArguments<FResetEnjApproval>()
{
}

FString Enjin::Sdk::Player::FResetEnjApproval::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FResetEnjApproval::ToJson() const
{
	return TTransactionFragmentArguments<FResetEnjApproval>::ToJson();
}

bool Enjin::Sdk::Player::FResetEnjApproval::operator==(const FResetEnjApproval& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FResetEnjApproval>&>(*this) == Rhs;
}

bool Enjin::Sdk::Player::FResetEnjApproval::operator!=(const FResetEnjApproval& Rhs) const
{
	return !(*this == Rhs);
}
