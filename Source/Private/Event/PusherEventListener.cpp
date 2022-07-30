// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PusherEventListener.h"

#include "EventTypeDef.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Pusher;
using namespace Enjin::Sdk::Util;

FPusherEventListener::FPusherEventListener(FPusherEventService& EventService) : EventService(EventService)
{
}

void FPusherEventListener::OnEvent(const FPusherEvent& Event)
{
	const FString Key = Event.GetEventName().Get(TEXT(""));
	FString Channel = Event.GetChannelName().Get(TEXT(""));
	FString Message = Event.GetData().Get(TEXT(""));

	const TArray<FEventListenerRegistrationRef>& Registrations = EventService.GetRegistrations();
	const FLoggerProviderPtr& LoggerProvider = EventService.GetLoggerProvider();

	if (LoggerProvider.IsValid())
	{
		LoggerProvider->Log(ELogLevel::Info,
		                    FString::Printf(TEXT("Received event %s on channel %s with data %s"),
		                                    *Key,
		                                    *Channel,
		                                    *Message));
	}

	if (Registrations.Num() == 0)
	{
		if (LoggerProvider.IsValid())
		{
			LoggerProvider->Log(ELogLevel::Warn, TEXT("No registered listener when event was received"));
		}

		return;
	}

	const EEventType Type = FEventTypeDef::GetFromKey(Key).GetType();
	if (Type == EEventType::Unknown)
	{
		if (LoggerProvider.IsValid())
		{
			LoggerProvider->Log(ELogLevel::Warn,
			                    FString::Printf(TEXT("Unknown event type for key %s"), *Key));
		}

		return;
	}

	const FNotificationEvent NotificationEvent(Type, MoveTemp(Channel), MoveTemp(Message));

	for (const FEventListenerRegistrationRef& Registration : Registrations)
	{
		if (Registration->GetMatcher()(Type))
		{
			Registration->GetListener()->NotificationReceived(NotificationEvent);
		}
	}
}
