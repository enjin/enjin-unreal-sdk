// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/Message.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FMessage::FMessage() : IGraphQlRequest(TEXT("enjin.sdk.project.Message")),
                                            TTransactionRequestArguments<FMessage>()
{
}

FString Enjin::Sdk::Project::FMessage::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FMessage& Enjin::Sdk::Project::FMessage::SetMessage(FString Message)
{
	MessageOpt.Emplace(MoveTemp(Message));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FMessage::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FMessage>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("message"), MessageOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FMessage::operator==(const FMessage& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FMessage>&>(*this) == Rhs
		&& MessageOpt == Rhs.MessageOpt;
}

bool Enjin::Sdk::Project::FMessage::operator!=(const FMessage& Rhs) const
{
	return !(*this == Rhs);
}
