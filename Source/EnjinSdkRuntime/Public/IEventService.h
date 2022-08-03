// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "EventListenerRegistration.h"
#include "IEventListener.h"
#include "Model/EventType.h"
#include "Model/Platform.h"

namespace Enjin
{
namespace Sdk
{
namespace Event
{
/**
 * @brief Interface for event service used to register listeners and subscribe to events from the Enjin Cloud.
 */
class ENJINSDKRUNTIME_API IEventService
{
public:
	/**
	 * @brief Event for when the service has connected.
	 */
	DECLARE_EVENT(IEventService, FEventServiceConnectedEvent);

	/**
	 * @brief Event for when the service has disconnected.
	 */
	DECLARE_EVENT(IEventService, FEventServiceDisconnectedEvent);

	/**
	 * @brief Event for when the service has encountered an error.
	 * @param ErrorMessage The error message.
	 */
	DECLARE_EVENT_OneParam(IEventService, FEventServiceErrorEvent, const FString& ErrorMessage);

	/**
	 * @brief Class destructor.
	 */
	virtual ~IEventService() = default;

	/**
	 * @brief Determines whether this service is connected for receiving events.
	 * @return Whether this service is connected for receiving events.
	 */
	virtual bool IsConnected() const = 0;

	/**
	 * @brief Returns the event delegate used to emit events for when this service connects to the server.
	 * @return The event delegate.
	 */
	virtual FEventServiceConnectedEvent& OnConnected() = 0;

	/**
	 * @brief Returns the event delegate used to emit events for when this service disconnects from the server.
	 * @return The event delegate.
	 */
	virtual FEventServiceDisconnectedEvent& OnDisconnected() = 0;

	/**
	 * @brief Returns the event delegate used to emit events for when this service encounters an error.
	 * @return The event delegate.
	 */
	virtual FEventServiceErrorEvent& OnError() = 0;

	/**
	 * @brief Shuts down this service.
	 * @return The future for this operation.
	 */
	virtual TFuture<bool> Shutdown() = 0;

	/**
	 * @brief Starts this service.
	 * @return The future for this operation.
	 */
	virtual TFuture<bool> Start() = 0;

	/**
	 * @brief Starts this service with the provided platform details.
	 * @param NewPlatform The platform details.
	 * @return The future for this operation.
	 */
	virtual TFuture<bool> Start(Model::FPlatform NewPlatform) = 0;

	// region Listener Registration

	/**
	 * @brief Determines if the given listener is already registered with this service.
	 * @param Listener The listener.
	 * @return Whether the listener is already registered with this service.
	 */
	virtual bool IsRegistered(const IEventListener& Listener) const = 0;

	/**
	 * @brief Registers the listener with this event service.
	 * @param Listener The listener.
	 * @return The registration for the listener.
	 * @remarks If the listener is already registered, then the returned registration will be the oldest registration
	 * stored for the given listener.
	 */
	virtual FEventListenerRegistrationRef RegisterListener(FEventListenerRef Listener) = 0;

	/**
	 * @brief Registers the listener with a matcher that excludes the given event types.
	 * @param Listener The listener.
	 * @param Types The event types.
	 * @return The registration for the listener.
	 * @remarks If the listener is already registered, then the returned registration will be the oldest registration
	 * stored for the given listener.
	 */
	virtual FEventListenerRegistrationRef RegisterListenerExcludingTypes(FEventListenerRef Listener,
	                                                                     TArray<Model::EEventType> Types) = 0;

	/**
	 * @brief Registers the listener with a matcher that includes the given event types.
	 * @param Listener The listener.
	 * @param Types The event types.
	 * @return The registration for the listener.
	 * @remarks If the listener is already registered, then the returned registration will be the oldest registration
	 * stored for the given listener.
	 */
	virtual FEventListenerRegistrationRef RegisterListenerIncludingTypes(FEventListenerRef Listener,
	                                                                     TArray<Model::EEventType> Types) = 0;

	/**
	 * @brief Registers the listener with the given matcher.
	 * @param Listener The listener.
	 * @param Matcher The matcher.
	 * @return The registration for the listener.
	 * @remarks If the listener is already registered, then the returned registration will be the oldest registration
	 * stored for the given listener.
	 */
	virtual FEventListenerRegistrationRef RegisterListenerWithMatcher(FEventListenerRef Listener,
	                                                                  FEventMatcher Matcher) = 0;

	/**
	 * @brief Unregisters the given listener from this service.
	 * @param Listener The listener.
	 */
	virtual void UnregisterListener(const IEventListener& Listener) = 0;

	// endregion Listener Registration

	// region Event Channel Subscription

	/**
	 * @brief Determines whether this service is subscribed to the channel.
	 * @param Asset The asset ID.
	 * @return Whether this service is subscribed to the channel.
	 */
	virtual bool IsSubscribedToAsset(const FString& Asset) const = 0;

	/**
	 * @brief Determines whether this service is subscribed to the channel.
	 * @param Project The project UUID.
	 * @param Player The player ID.
	 * @return Whether this service is subscribed to the channel.
	 */
	virtual bool IsSubscribedToPlayer(const FString& Project, const FString& Player) const = 0;

	/**
	 * @brief Determines whether this service is subscribed to the channel.
	 * @param Project The project UUID.
	 * @return Whether this service is subscribed to the channel.
	 */
	virtual bool IsSubscribedToProject(const FString& Project) const = 0;

	/**
	 * @brief Determines whether this service is subscribed to the channel.
	 * @param Wallet The wallet address.
	 * @return Whether this service is subscribed to the channel.
	 */
	virtual bool IsSubscribedToWallet(const FString& Wallet) const = 0;

	/**
	 * @brief Opens a channel for the specified asset, allowing listeners to receive events for it.
	 * @param Asset The asset ID.
	 */
	virtual void SubscribeToAsset(const FString& Asset) = 0;

	/**
	 * @brief Opens a channel for the specified player, allowing listeners to receive events for it.
	 * @param Project The project UUID.
	 * @param Player The player ID.
	 */
	virtual void SubscribeToPlayer(const FString& Project, const FString& Player) = 0;

	/**
	 * @brief Opens a channel for the specified project, allowing listeners to receive events for it.
	 * @param Project The project UUID.
	 */
	virtual void SubscribeToProject(const FString& Project) = 0;

	/**
	 * @brief Opens a channel for the specified wallet, allowing listeners to receive events for it.
	 * @param Wallet The wallet address.
	 */
	virtual void SubscribeToWallet(const FString& Wallet) = 0;

	/**
	 * @brief Closes a channel for the specified asset, preventing listeners from receiving events for it.
	 * @param Asset The asset ID.
	 */
	virtual void UnsubscribeToAsset(const FString& Asset) = 0;

	/**
	 * @brief Closes a channel for the specified player, preventing listeners from receiving events for it.
	 * @param Project The project UUID.
	 * @param Player The player ID.
	 */
	virtual void UnsubscribeToPlayer(const FString& Project, const FString& Player) = 0;

	/**
	 * @brief Closes a channel for the specified project, preventing listeners from receiving events for it.
	 * @param Project The project UUID.
	 */
	virtual void UnsubscribeToProject(const FString& Project) = 0;

	/**
	 * @brief Closes a channel for the specified wallet, preventing listeners from receiving events for it.
	 * @param Wallet The wallet address.
	 */
	virtual void UnsubscribeToWallet(const FString& Wallet) = 0;

	// endregion Event Channel Subscription
};
}
}
}
