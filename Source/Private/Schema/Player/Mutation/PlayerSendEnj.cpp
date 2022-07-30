// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/SendEnj.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FSendEnj::FSendEnj() : IGraphQlRequest(TEXT("enjin.sdk.player.SendEnj")),
                                           TTransactionFragmentArguments<FSendEnj>()
{
}

FString Enjin::Sdk::Player::FSendEnj::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Player::FSendEnj& Enjin::Sdk::Player::FSendEnj::SetRecipientAddress(FString Address)
{
	RecipientAddressOpt.Emplace(MoveTemp(Address));
	return *this;
}

Enjin::Sdk::Player::FSendEnj& Enjin::Sdk::Player::FSendEnj::SetValue(FString Value)
{
	ValueOpt.Emplace(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FSendEnj::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FSendEnj>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("recipientAddress"), RecipientAddressOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

	return JsonRef;
}

bool Enjin::Sdk::Player::FSendEnj::operator==(const FSendEnj& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FSendEnj>&>(*this) == Rhs
		&& RecipientAddressOpt == Rhs.RecipientAddressOpt
		&& ValueOpt == Rhs.ValueOpt;
}

bool Enjin::Sdk::Player::FSendEnj::operator!=(const FSendEnj& Rhs) const
{
	return !(*this == Rhs);
}
