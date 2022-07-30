// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/Message.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FMessage::FMessage() : IGraphQlRequest(TEXT("enjin.sdk.player.Message")),
                                           TTransactionFragmentArguments<FMessage>()
{
}

FString Enjin::Sdk::Player::FMessage::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Player::FMessage& Enjin::Sdk::Player::FMessage::SetMessage(FString Message)
{
	MessageOpt.Emplace(MoveTemp(Message));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FMessage::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FMessage>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("message"), MessageOpt);

	return JsonRef;
}

bool Enjin::Sdk::Player::FMessage::operator==(const FMessage& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FMessage>&>(*this) == Rhs
		&& MessageOpt == Rhs.MessageOpt;
}

bool Enjin::Sdk::Player::FMessage::operator!=(const FMessage& Rhs) const
{
	return !(*this == Rhs);
}
