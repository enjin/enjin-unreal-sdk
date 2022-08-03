// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PusherClient.h"

#include "JsonUtil.h"
#include "WebSocketsModule.h"
#include "Interfaces/IPluginManager.h"
#include "Modules/ModuleManager.h"
#include "Pusher/PusherConstants.h"
#include "Pusher/PusherErrorCodes.h"
#include "Pusher/PusherEvent.h"
#include <chrono>

using namespace Enjin::Sdk::Pusher;
using namespace Enjin::Sdk::Util;

FPusherClient::FPusherClient(FString Key, FPusherOptionsInput Options, FLoggerProviderPtr LoggerProvider)
	: Key(MoveTemp(Key)), Options(MoveTemp(Options)), LoggerProvider(MoveTemp(LoggerProvider))
{
	Init();
}

FPusherClient::~FPusherClient()
{
	if (WebSocket.IsValid())
	{
		WebSocket->OnClosed().Clear();
		WebSocket->OnConnected().Clear();
		WebSocket->OnConnectionError().Clear();
		WebSocket->OnMessage().Clear();
	}

	Close();
}

void FPusherClient::Bind(const FString& EventName, TSharedRef<ISubscriptionEventListener, ESPMode::ThreadSafe> Listener)
{
	std::lock_guard<std::mutex> Guard(EventListenerMutex);

	if (EventListeners.Contains(EventName))
	{
		EventListeners[EventName].Add(MoveTemp(Listener));
	}
	else
	{
		TSet<TSharedRef<ISubscriptionEventListener, ESPMode::ThreadSafe>> Set = {MoveTemp(Listener)};
		EventListeners.Emplace(EventName, MoveTemp(Set));
	}
}

TFuture<bool> FPusherClient::Close()
{
	if (!IsInitialized())
	{
		return Async(EAsyncExecution::Thread, []()
		{
			return false;
		});
	}

	bool bIsConnectionStateChanged;

	{
		std::lock_guard<std::mutex> Guard(ConnectionMutex);

		if (ConnectionState == EPusherConnectionState::Disconnected)
		{
			return Async(EAsyncExecution::Thread, []()
			{
				return true;
			});
		}

		if (ConnectionState == EPusherConnectionState::Disconnecting)
		{
			bIsConnectionStateChanged = false;
		}
		else
		{
			ConnectionState = EPusherConnectionState::Disconnecting;
			bIsConnectionStateChanged = true;
		}
	}

	if (bIsConnectionStateChanged)
	{
		OnConnectionStateChangedEvent.Broadcast(EPusherConnectionState::Disconnecting);
	}

	return Async(EAsyncExecution::Thread, [this]()
	{
		std::unique_lock<std::mutex> Lock(ConnectionMutex);

		WebSocket->Close();

		while (ConnectionState == EPusherConnectionState::Disconnecting)
		{
			ConnectionCv.wait(Lock);
		}

		return ConnectionState == EPusherConnectionState::Disconnected;
	});
}

TFuture<bool> FPusherClient::Connect()
{
	if (!IsInitialized())
	{
		return Async(EAsyncExecution::Thread, []()
		{
			return false;
		});
	}

	bool bIsConnectionStateChanged;

	{
		std::lock_guard<std::mutex> Guard(ConnectionMutex);

		if (ConnectionState == EPusherConnectionState::Connected)
		{
			return Async(EAsyncExecution::Thread, []()
			{
				return true;
			});
		}

		if (ConnectionState == EPusherConnectionState::Connecting)
		{
			bIsConnectionStateChanged = false;
		}
		else
		{
			ConnectionState = EPusherConnectionState::Connecting;
			bIsConnectionStateChanged = true;
		}
	}

	if (bIsConnectionStateChanged)
	{
		OnConnectionStateChangedEvent.Broadcast(EPusherConnectionState::Connecting);
	}

	return Async(EAsyncExecution::Thread, [this]()
	{
		std::unique_lock<std::mutex> Lock(ConnectionMutex);

		WebSocket->Connect();

		while (ConnectionState == EPusherConnectionState::Connecting)
		{
			ConnectionCv.wait(Lock);
		}

		return ConnectionState == EPusherConnectionState::Connected;
	});
}

EPusherConnectionState FPusherClient::GetConnectionState() const
{
	std::lock_guard<std::mutex> Guard(ConnectionMutex);
	return ConnectionState;
}

void FPusherClient::Subscribe(const FString& ChannelName)
{
	if (!IsInitialized())
	{
		return;
	}

	{
		std::lock_guard<std::mutex> Guard(ChannelMutex);

		const bool* ChannelValue = Channels.Find(ChannelName);
		const bool bIsSubscribed = ChannelValue != nullptr && *ChannelValue;
		const bool bIsPending = PendingChannels.Contains(ChannelName);

		if (bIsSubscribed || bIsPending)
		{
			return;
		}

		PendingChannels.Emplace(ChannelName);
		Channels.Emplace(ChannelName, false);
	}

	if (GetConnectionState() != EPusherConnectionState::Connected)
	{
		return;
	}

	WebSocket->Send(GetSubscriptionMessageForChannelName(ChannelName));
}

bool FPusherClient::IsConnected() const
{
	return IsInitialized() && WebSocket->IsConnected();
}

bool FPusherClient::IsInitialized() const
{
	return bIsInitialized;
}

bool FPusherClient::IsSubscribed(const FString& ChannelName) const
{
	std::lock_guard<std::mutex> Guard(ChannelMutex);
	const bool* Value = Channels.Find(ChannelName);

	return Value != nullptr && *Value;
}

bool FPusherClient::IsSubscribedOrPending(const FString& ChannelName) const
{
	return IsSubscribed(ChannelName) || IsSubscriptionPending(ChannelName);
}

bool FPusherClient::IsSubscriptionPending(const FString& ChannelName) const
{
	std::lock_guard<std::mutex> Guard(ChannelMutex);
	return PendingChannels.Contains(ChannelName);
}

FPusherClient::FPusherConnectionStateChangedEvent& FPusherClient::OnConnectionStateChanged()
{
	return OnConnectionStateChangedEvent;
}

FPusherClient::FPusherErrorEvent& FPusherClient::OnError()
{
	return OnErrorEvent;
}

void FPusherClient::Unbind(const FString& EventName)
{
	std::lock_guard<std::mutex> Guard(EventListenerMutex);
	EventListeners.Remove(EventName);
}

void FPusherClient::Unsubscribe(const FString& ChannelName)
{
	if (!IsInitialized())
	{
		return;
	}

	{
		std::lock_guard<std::mutex> Guard(ChannelMutex);

		if (!PendingChannels.Contains(ChannelName) && !Channels.Contains(ChannelName))
		{
			return;
		}

		PendingChannels.Remove(ChannelName);
		Channels.Remove(ChannelName);
	}

	if (GetConnectionState() != EPusherConnectionState::Connected)
	{
		return;
	}

	WebSocket->Send(GetUnsubscriptionMessageForChannelName(ChannelName));
}

// ReSharper disable once CppMemberFunctionMayBeConst
void FPusherClient::EmitEvent(const FPusherEvent& Event)
{
	if (!Event.GetEventName().IsSet())
	{
		return;
	}

	const FString& EventName = Event.GetEventName().GetValue();

	TMap<FString, TSet<TSharedRef<ISubscriptionEventListener, ESPMode::ThreadSafe>>> Listeners;

	{
		std::lock_guard<std::mutex> Lock(EventListenerMutex);
		Listeners = EventListeners;
	}

	const TSet<TSharedRef<ISubscriptionEventListener, ESPMode::ThreadSafe>>* Value = Listeners.Find(EventName);
	if (Value != nullptr)
	{
		for (const TSharedRef<ISubscriptionEventListener, ESPMode::ThreadSafe>& Listener : *Value)
		{
			Listener->OnEvent(Event);
		}
	}
}

void FPusherClient::Init()
{
	const TSharedPtr<IPlugin> Plugin = IPluginManager::Get().FindPlugin(TEXT("EnjinSdk"));
	if (!Plugin.IsValid())
	{
		return;
	}

	const FString Version = Plugin->GetDescriptor().VersionName;

	const FString& Schema = Options.IsEncrypted()
		                        ? FPusherConstants::SecureSchema()
		                        : FPusherConstants::InsecureSchema();
	const FString Url = FString::Printf(TEXT("%s%s/app/%s?protocol=5&client=enjin-unreal-pusher-client&version=%s"),
	                                    *Schema,
	                                    *Options.Host(),
	                                    *Key,
	                                    *Version);

	if (!LoadWebsocketsModule())
	{
		return;
	}

	WebSocket = FWebSocketsModule::Get().CreateWebSocket(Url);
	if (!WebSocket.IsValid())
	{
		return;
	}

	WebSocket->OnClosed().AddLambda([this](const int32 Code, const FString& Reason, const bool)
	{
		WebsocketClosed(Code, Reason);
	});

	WebSocket->OnConnected().AddLambda([this]()
	{
		WebsocketConnected();
	});

	WebSocket->OnConnectionError().AddLambda([this](const FString& Error)
	{
		WebsocketConnectionError(Error);
	});

	WebSocket->OnMessage().AddLambda([this](const FString& Message)
	{
		WebsocketMessage(Message);
	});

	bIsInitialized = true;
}

bool FPusherClient::LoadWebsocketsModule()
{
	FModuleManager& ModuleManager = FModuleManager::Get();
	const TCHAR* ModuleName = TEXT("Websockets");

	if (ModuleManager.IsModuleLoaded(ModuleName))
	{
		return true;
	}

	AsyncTask(ENamedThreads::GameThread, [this, &ModuleManager, &ModuleName]()
	{
		ModuleManager.LoadModule(ModuleName)->StartupModule();
		WebsocketModuleCv.notify_all();
	});

	std::unique_lock<std::mutex> Lock(WebsocketModuleMutex);
	WebsocketModuleCv.wait_for(Lock, std::chrono::seconds(10));

	return ModuleManager.IsModuleLoaded(ModuleName);
}

void FPusherClient::Reconnect()
{
	bool bIsReconnecting;

	{
		std::lock_guard<std::mutex> Guard(ConnectionMutex);

		if (ReconnectAttempt < MaxReconnectAttempts)
		{
			ReconnectAttempt++;
			bIsReconnecting = true;
		}
		else
		{
			ReconnectAttempt = 0;
			bIsReconnecting = false;
		}
	}

	if (bIsReconnecting)
	{
		SetConnectionState(EPusherConnectionState::Reconnecting);
		WebSocket->Connect();
	}
	else
	{
		SetConnectionState(EPusherConnectionState::Disconnected);

		{
			std::lock_guard<std::mutex> Guard(ConnectionMutex);
			ConnectionCv.notify_all();
		}
	}
}

void FPusherClient::SetConnectionState(const EPusherConnectionState State)
{
	{
		std::lock_guard<std::mutex> Guard(ConnectionMutex);
		ConnectionState = State;
	}

	OnConnectionStateChangedEvent.Broadcast(State);
}

void FPusherClient::SubscriptionSucceeded(const FString& ChannelName)
{
	std::lock_guard<std::mutex> Guard(ChannelMutex);

	PendingChannels.Remove(ChannelName);
	Channels.Emplace(ChannelName, true);
}

void FPusherClient::WebsocketClosed(const int32 Code, const FString& Reason)
{
	const EPusherConnectionState CurrentState = GetConnectionState();

	if (CurrentState == EPusherConnectionState::Disconnected)
	{
		if (LoggerProvider.IsValid())
		{
			LoggerProvider->Log(ELogLevel::Warn,
			                    TEXT("Pusher client received close message while disconnected"));
		}

		return;
	}

	bool bIsDisconnected;

	{
		std::lock_guard<std::mutex> Guard(ReconnectMutex);

		/* 4000-4099 codes from Pusher indicate reconnection should not be attempted.
		 * https://pusher.com/docs/pusher_protocol#error-codes
		 */
		if (CurrentState == EPusherConnectionState::Disconnecting
			|| Code >= 4000 && Code < 4100
			|| ReconnectAttempt == MaxReconnectAttempts)
		{
			ReconnectAttempt = 0;
			bIsDisconnected = true;
		}
		else
		{
			bIsDisconnected = false;
		}
	}

	if (bIsDisconnected)
	{
		SetConnectionState(EPusherConnectionState::Disconnected);

		{
			std::lock_guard<std::mutex> Guard(ConnectionMutex);
			ConnectionCv.notify_all();
		}
	}
	else
	{
		Reconnect();
	}
}

void FPusherClient::WebsocketConnected()
{
	SetConnectionState(EPusherConnectionState::Connected);

	// Subscribes to preregistered channels
	{
		std::lock_guard<std::mutex> Guard(ChannelMutex);

		for (const TTuple<FString, bool>& Entry : Channels)
		{
			WebSocket->Send(GetSubscriptionMessageForChannelName(Entry.Key));
		}
	}

	{
		std::lock_guard<std::mutex> Guard(ConnectionMutex);

		ConnectionCv.notify_all();
	}
}

void FPusherClient::WebsocketConnectionError(const FString& Error)
{
	if (LoggerProvider.IsValid())
	{
		LoggerProvider->Log(ELogLevel::Error,
		                    FString::Printf(TEXT("Connection error in Pusher client: %s"), *Error));
	}

	Reconnect();
}

void FPusherClient::WebsocketMessage(const FString& Message)
{
	FPusherEvent Event;
	Event.Deserialize(Message);

	EmitEvent(Event);

	const FString& MsgEvent = Event.GetEventName().Get(TEXT(""));
	if (MsgEvent.Find(FPusherConstants::PusherMessagePrefix()) == 0)
	{
		if (MsgEvent.Equals(FPusherConstants::ChannelSubscriptionSucceeded()))
		{
			if (Event.GetChannelName().IsSet())
			{
				SubscriptionSucceeded(Event.GetChannelName().GetValue());
			}
			else
			{
				OnErrorEvent.Broadcast(static_cast<int32>(EPusherErrorCodes::Unknown),
				                       TEXT("Received successful channel subscription for blank channel"));
			}
		}
		else if (MsgEvent.Equals(FPusherConstants::ChannelSubscriptionError()) && OnErrorEvent.IsBound())
		{
			OnErrorEvent.Broadcast(static_cast<int32>(EPusherErrorCodes::SubscriptionError),
			                       FString::Printf(TEXT("Error received on channel subscription: %s"), *Message));
		}
	}
}

FString FPusherClient::GetSubscriptionMessageForChannelName(const FString& ChannelName)
{
	const TSharedRef<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	const TSharedRef<FJsonObject> DataObject = MakeShared<FJsonObject>();

	DataObject->SetStringField(TEXT("channel"), ChannelName);
	JsonObject->SetObjectField(TEXT("data"), DataObject);
	JsonObject->SetStringField(TEXT("event"), FPusherConstants::ChannelSubscribe());

	return FJsonUtil::SerializeJsonObject(JsonObject);
}

FString FPusherClient::GetUnsubscriptionMessageForChannelName(const FString& ChannelName)
{
	const TSharedRef<FJsonObject> JsonObject = MakeShared<FJsonObject>();
	const TSharedRef<FJsonObject> DataObject = MakeShared<FJsonObject>();

	DataObject->SetStringField(TEXT("channel"), ChannelName);
	JsonObject->SetObjectField(TEXT("data"), DataObject);
	JsonObject->SetStringField(TEXT("event"), FPusherConstants::ChannelUnsubscribe());

	return FJsonUtil::SerializeJsonObject(JsonObject);
}
