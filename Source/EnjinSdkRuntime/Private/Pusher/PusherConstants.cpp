// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PusherConstants.h"

using namespace Enjin::Sdk::Pusher;

FString FPusherConstants::PusherMessagePrefix()
{
	return TEXT("pusher");
}

FString FPusherConstants::ChannelSubscribe()
{
	return TEXT("pusher:subscribe");
}

FString FPusherConstants::ChannelSubscriptionError()
{
	return TEXT("pusher_internal:subscription_error");
}

FString FPusherConstants::ChannelSubscriptionSucceeded()
{
	return TEXT("pusher_internal:subscription_succeeded");
}

FString FPusherConstants::ChannelUnsubscribe()
{
	return TEXT("pusher:unsubscribe");
}

FString FPusherConstants::InsecureSchema()
{
	return TEXT("ws://");
}

FString FPusherConstants::SecureSchema()
{
	return TEXT("wss://");
}
