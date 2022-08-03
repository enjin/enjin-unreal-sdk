// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PusherEvent.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Pusher;
using namespace Enjin::Sdk::Util;

void FPusherEvent::Deserialize(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject;
	if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
	{
		ChannelName.Reset();
		Data.Reset();
		EventName.Reset();
		UserId.Reset();

		return;
	}

	const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

	FJsonUtil::TryGetField(JsonRef, TEXT("channel"), ChannelName);
	FJsonUtil::TryGetField(JsonRef, TEXT("data"), Data);
	FJsonUtil::TryGetField(JsonRef, TEXT("event"), EventName);
	FJsonUtil::TryGetField(JsonRef, TEXT("user_id"), UserId);
}

const TOptional<FString>& FPusherEvent::GetChannelName() const
{
	return ChannelName;
}

const TOptional<FString>& FPusherEvent::GetData() const
{
	return Data;
}

const TOptional<FString>& FPusherEvent::GetEventName() const
{
	return EventName;
}

const TOptional<FString>& FPusherEvent::GetUserId() const
{
	return UserId;
}

bool FPusherEvent::operator==(const FPusherEvent& Rhs) const
{
	return ChannelName == Rhs.ChannelName
		&& Data == Rhs.Data
		&& EventName == Rhs.EventName
		&& UserId == Rhs.UserId;
}

bool FPusherEvent::operator!=(const FPusherEvent& Rhs) const
{
	return !(*this == Rhs);
}
