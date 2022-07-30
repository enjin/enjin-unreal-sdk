// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/SetApprovalForAll.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FSetApprovalForAll::FSetApprovalForAll()
	: IGraphQlRequest(TEXT("enjin.sdk.player.SetApprovalForAll")),
	  TTransactionFragmentArguments<FSetApprovalForAll>()
{
}

FString Enjin::Sdk::Player::FSetApprovalForAll::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Player::FSetApprovalForAll& Enjin::Sdk::Player::FSetApprovalForAll::SetApproved(const bool bIsApproved)
{
	ApprovedOpt.Emplace(bIsApproved);
	return *this;
}

Enjin::Sdk::Player::FSetApprovalForAll& Enjin::Sdk::Player::FSetApprovalForAll::SetOperatorAddress(FString Address)
{
	OperatorAddressOpt.Emplace(MoveTemp(Address));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FSetApprovalForAll::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FSetApprovalForAll>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("approved"), ApprovedOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("operatorAddress"), OperatorAddressOpt);

	return JsonRef;
}

bool Enjin::Sdk::Player::FSetApprovalForAll::operator==(const FSetApprovalForAll& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FSetApprovalForAll>&>(*this) == Rhs
		&& ApprovedOpt == Rhs.ApprovedOpt
		&& OperatorAddressOpt == Rhs.OperatorAddressOpt;
}

bool Enjin::Sdk::Player::FSetApprovalForAll::operator!=(const FSetApprovalForAll& Rhs) const
{
	return !(*this == Rhs);
}
