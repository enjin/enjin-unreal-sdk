// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IWebSocket.h"
#include "LoggerProvider.h"
#include "Pusher/ISubscriptionEventListener.h"
#include "Pusher/PusherConnectionState.h"
#include "Pusher/PusherOptionsInput.h"
#include <condition_variable>
#include <mutex>

namespace Enjin
{
namespace Sdk
{
namespace Pusher
{
/**
 * @brief Client for subscribing to Pusher channels and binding to events.
 */
class FPusherClient final
{
public:
	/**
	 * @brief Event for when the connection state of a Pusher client changes.
	 * @param State The new connection state.
	 */
	DECLARE_EVENT_OneParam(FPusherClient, FPusherConnectionStateChangedEvent, const EPusherConnectionState State);

	/**
	 * @brief Event for when an error is encountered by a Pusher client.
	 * @param Code The error code.
	 * @param Message The error message.
	 */
	DECLARE_EVENT_TwoParams(FPusherClient, FPusherErrorEvent, const int32 Code, const FString& Message);

	FPusherClient() = delete;

	/**τ
	 * @brief Constructs an instance of this class.
	 * @param Key The project key.
	 * @param Options The options.
	 * @param LoggerProvider The logger provider.
	 */
	FPusherClient(FString Key, FPusherOptionsInput Options, Util::FLoggerProviderPtr LoggerProvider = nullptr);

	/**
	 * @brief Destructor for this class. Attempts to close any open connections.
	 */
	~FPusherClient();

	/**
	 * @brief Binds a listener to the given event.
	 * @param EventName The name of the event.
	 * @param Listener The event listener.
	 */
	void Bind(const FString& EventName, TSharedRef<ISubscriptionEventListener, ESPMode::ThreadSafe> Listener);

	/**
	 * @brief Closes the connection between this client and the server.
	 * @return The future for this operation.
	 */
	TFuture<bool> Close();

	/**
	 * @brief Connects this client to the server.
	 * @return The future for this operation.
	 */
	TFuture<bool> Connect();

	/**
	 * @brief Returns the connection state of this client.
	 * @return The connection state.
	 */
	EPusherConnectionState GetConnectionState() const;

	/**
	 * @brief Subscribes to start receiving events for the given channel.
	 * @param ChannelName The channel name.
	 */
	void Subscribe(const FString& ChannelName);

	/**
	 * @brief Returns whether this client is connected to a server.
	 * @return Whether this client is connected to a server.
	 */
	bool IsConnected() const;

	/**
	 * @brief Determines whether this client has been properly initialized.
	 * @return Whether this client is initialized.
	 * @remarks Possible issues which may prevent initialization may include bad input options, the Websockets module
	 * being unable to load, or being unable to create a websocket.
	 */
	bool IsInitialized() const;

	/**
	 * @brief Returns whether this client is subscribed to the given channel.
	 * @param ChannelName The channel name.
	 * @return Whether this client is subscribed.
	 */
	bool IsSubscribed(const FString& ChannelName) const;

	/**
	 * @brief Returns whether this client is subscribed or has a pending subscription to the given channel.
	 * @param ChannelName The channel name.
	 * @return Whether this client is subscribed or has a pending subscription.
	 */
	bool IsSubscribedOrPending(const FString& ChannelName) const;

	/**
	 * @brief Returns whether this client has a pending subscription to the given channel.
	 * @param ChannelName The channel name.
	 * @return Whether this client has a pending subscription.
	 */
	bool IsSubscriptionPending(const FString& ChannelName) const;

	/**
	 * @brief Returns the event delegate used to emit events for when this client's connection state changes.
	 * @return The event delegate.
	 */
	FPusherConnectionStateChangedEvent& OnConnectionStateChanged();

	/**
	 * @brief Returns the event delegate used to emit events for when this client encounters an error.
	 * @return The event delegate.
	 */
	FPusherErrorEvent& OnError();

	/**
	 * @brief Unbinds all listeners for the given event.
	 * @param EventName The name of the event.
	 */
	void Unbind(const FString& EventName);

	/**
	 * @brief Unsubscribes from the given channel.
	 * @param ChannelName The channel name.
	 */
	void Unsubscribe(const FString& ChannelName);

private:
	const FString Key;
	const FPusherOptionsInput Options;
	const Util::FLoggerProviderPtr LoggerProvider;
	bool bIsInitialized = false;

	TSharedPtr<IWebSocket> WebSocket; // Cannot be TSharedRef due to build errors between ref and websocket interface
	EPusherConnectionState ConnectionState = EPusherConnectionState::Disconnected;
	int32 ReconnectAttempt;

	TMap<FString, TSet<TSharedRef<ISubscriptionEventListener, ESPMode::ThreadSafe>>> EventListeners;
	TMap<FString, bool> Channels;
	TSet<FString> PendingChannels;

	// Event delegates
	FPusherConnectionStateChangedEvent OnConnectionStateChangedEvent;
	FPusherErrorEvent OnErrorEvent;

	// Condition variables
	std::condition_variable ConnectionCv;
	std::condition_variable WebsocketModuleCv;

	// Mutexes
	mutable std::mutex ChannelMutex;
	mutable std::mutex ConnectionMutex;
	mutable std::mutex EventListenerMutex;
	mutable std::mutex ReconnectMutex;
	mutable std::mutex WebsocketModuleMutex;

	static constexpr int32 MaxReconnectAttempts = 5;

	/**
	 * @brief Emits a Pusher event to all necessary bound listeners.
	 * @param Event The event.
	 */
	void EmitEvent(const FPusherEvent& Event);

	/**
	 * @brief Initializes this client.
	 */
	void Init();

	/**
	 * @brief Tries to load the Websockets module if it has not already been loaded.
	 * @return Whether the module has been loaded.
	 */
	bool LoadWebsocketsModule();

	/**
	 * @brief Attempts to reconnect this client to the server.
	 */
	void Reconnect();

	/**
	 * @brief Sets the connection state for this client.
	 * @param State The connection state.
	 * @remarks This member-function should not be called within a critical section to avoid any potential deadlocks
	 * from operations performed within @link OnConnectionStateChangedEvent @endlink.
	 */
	void SetConnectionState(const EPusherConnectionState State);

	/**
	 * @brief Processes successful subscription for a channel.
	 * @param ChannelName The channel name.
	 */
	void SubscriptionSucceeded(const FString& ChannelName);

	/**
	 * @brief Handles closure messages from the server.
	 * @param Code The closure code.
	 * @param Reason The closure reason.
	 */
	void WebsocketClosed(const int32 Code, const FString& Reason);

	/**
	 * @brief Handles connection messages from the server.
	 */
	void WebsocketConnected();

	/**
	 * @brief Handles connection error messages from the server.
	 * @param Error The error message.
	 */
	void WebsocketConnectionError(const FString& Error);

	/**
	 * @brief Handles websocket messages from the server.
	 * @param Message The message.
	 */
	void WebsocketMessage(const FString& Message);

	/**
	 * @brief Returns the message payload to be sent to a Pusher server to subscribe for events on the given channel.
	 * @param ChannelName The channel name.
	 * @return The message payload.
	 */
	static FString GetSubscriptionMessageForChannelName(const FString& ChannelName);

	/**
	 * @brief Returns the message payload to be sent to a Pusher server to unsubscribe from events on the given channel.
	 * @param ChannelName The channel name.
	 * @return The message payload.
	 */
	static FString GetUnsubscriptionMessageForChannelName(const FString& ChannelName);
};
}
}
}
