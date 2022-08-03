// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IEventService.h"
#include "LoggerProvider.h"
#include "Model/Platform.h"

namespace Enjin
{
namespace Sdk
{
namespace Event
{
/**
 * @brief Implementation of @link IEventService @endlink for Pusher events.
 */
class ENJINSDKRUNTIME_API FPusherEventService final : public IEventService
{
public:
	class FPusherEventServiceBuilder;

	FPusherEventService() = delete;

	FPusherEventService(const FPusherEventService&) = delete;

	FPusherEventService(FPusherEventService&&) = delete;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPusherEventService() override;

	/**
	 * @brief Returns the logger provider used by this service.
	 * @return The logger provider.
	 */
	const Util::FLoggerProviderPtr& GetLoggerProvider() const;

	/**
	 * @brief Returns the registrations for listeners registered to this service.
	 * @return The listener registrations.
	 */
	const TArray<FEventListenerRegistrationRef>& GetRegistrations() const;

	/**
	 * @brief Determines whether this service is connected for receiving events.
	 * @return Whether this service is connected for receiving events.
	 */
	virtual bool IsConnected() const override;

	/**
	 * @brief Returns the event delegate used to emit events for when this service connects to the server.
	 * @return The event delegate.
	 */
	virtual FEventServiceConnectedEvent& OnConnected() override;

	/**
	 * @brief Returns the event delegate used to emit events for when this service disconnects from the server.
	 * @return The event delegate.
	 */
	virtual FEventServiceDisconnectedEvent& OnDisconnected() override;

	/**
	 * @brief Returns the event delegate used to emit events for when this service encounters an error.
	 * @return The event delegate.
	 */
	virtual FEventServiceErrorEvent& OnError() override;

	/**
	 * @brief Shuts down this service.
	 * @return The future for this operation.
	 */
	virtual TFuture<bool> Shutdown() override;

	/**
	 * @brief Starts this service.
	 * @return The future for this operation.
	 */
	virtual TFuture<bool> Start() override;

	/**
	 * @brief Starts this service with the provided platform details.
	 * @param NewPlatform The platform details.
	 * @return The future for this operation.
	 */
	virtual TFuture<bool> Start(Model::FPlatform NewPlatform) override;

	// region Listener Registration

	/**
	 * @brief Determines if the given listener is already registered with this service.
	 * @param Listener The listener.
	 * @return Whether the listener is already registered with this service.
	 */
	virtual bool IsRegistered(const IEventListener& Listener) const override;

	/**
	 * @brief Registers the listener with this event service.
	 * @param Listener The listener.
	 * @return The registration for the listener.
	 * @remarks If the listener is already registered, then the returned registration will be the oldest registration
	 * stored for the given listener.
	 */
	virtual FEventListenerRegistrationRef RegisterListener(FEventListenerRef Listener) override;

	/**
	 * @brief Registers the listener with a matcher that excludes the given event types.
	 * @param Listener The listener.
	 * @param Types The event types.
	 * @return The registration for the listener.
	 * @remarks If the listener is already registered, then the returned registration will be the oldest registration
	 * stored for the given listener.
	 */
	virtual FEventListenerRegistrationRef RegisterListenerExcludingTypes(FEventListenerRef Listener,
	                                                                     TArray<Model::EEventType> Types) override;

	/**
	 * @brief Registers the listener with a matcher that includes the given event types.
	 * @param Listener The listener.
	 * @param Types The event types.
	 * @return The registration for the listener.
	 * @remarks If the listener is already registered, then the returned registration will be the oldest registration
	 * stored for the given listener.
	 */
	virtual FEventListenerRegistrationRef RegisterListenerIncludingTypes(FEventListenerRef Listener,
	                                                                     TArray<Model::EEventType> Types) override;

	/**
	 * @brief Registers the listener with the given matcher.
	 * @param Listener The listener.
	 * @param Matcher The matcher.
	 * @return The registration for the listener.
	 * @remarks If the listener is already registered, then the returned registration will be the oldest registration
	 * stored for the given listener.
	 */
	virtual FEventListenerRegistrationRef RegisterListenerWithMatcher(FEventListenerRef Listener,
	                                                                  FEventMatcher Matcher) override;

	/**
	 * @brief Unregisters the given listener from this service.
	 * @param Listener The listener.
	 */
	virtual void UnregisterListener(const IEventListener& Listener) override;

	// endregion Listener Registration

	// region Event Channel Subscription

	/**
	 * @brief Determines whether this service is subscribed to the channel.
	 * @param Asset The asset ID.
	 * @return Whether this service is subscribed to the channel.
	 */
	virtual bool IsSubscribedToAsset(const FString& Asset) const override;

	/**
	 * @brief Determines whether this service is subscribed to the channel.
	 * @param Project The project UUID.
	 * @param Player The player ID.
	 * @return Whether this service is subscribed to the channel.
	 */
	virtual bool IsSubscribedToPlayer(const FString& Project, const FString& Player) const override;

	/**
	 * @brief Determines whether this service is subscribed to the channel.
	 * @param Project The project UUID.
	 * @return Whether this service is subscribed to the channel.
	 */
	virtual bool IsSubscribedToProject(const FString& Project) const override;

	/**
	 * @brief Determines whether this service is subscribed to the channel.
	 * @param Wallet The wallet address.
	 * @return Whether this service is subscribed to the channel.
	 */
	virtual bool IsSubscribedToWallet(const FString& Wallet) const override;

	/**
	 * @brief Opens a channel for the specified asset, allowing listeners to receive events for it.
	 * @param Asset The asset ID.
	 */
	virtual void SubscribeToAsset(const FString& Asset) override;

	/**
	 * @brief Opens a channel for the specified player, allowing listeners to receive events for it.
	 * @param Project The project UUID.
	 * @param Player The player ID.
	 */
	virtual void SubscribeToPlayer(const FString& Project, const FString& Player) override;

	/**
	 * @brief Opens a channel for the specified project, allowing listeners to receive events for it.
	 * @param Project The project UUID.
	 */
	virtual void SubscribeToProject(const FString& Project) override;

	/**
	 * @brief Opens a channel for the specified wallet, allowing listeners to receive events for it.
	 * @param Wallet The wallet address.
	 */
	virtual void SubscribeToWallet(const FString& Wallet) override;

	/**
	 * @brief Closes a channel for the specified asset, preventing listeners from receiving events for it.
	 * @param Asset The asset ID.
	 */
	virtual void UnsubscribeToAsset(const FString& Asset) override;

	/**
	 * @brief Closes a channel for the specified player, preventing listeners from receiving events for it.
	 * @param Project The project UUID.
	 * @param Player The player ID.
	 */
	virtual void UnsubscribeToPlayer(const FString& Project, const FString& Player) override;

	/**
	 * @brief Closes a channel for the specified project, preventing listeners from receiving events for it.
	 * @param Project The project UUID.
	 */
	virtual void UnsubscribeToProject(const FString& Project) override;

	/**
	 * @brief Closes a channel for the specified wallet, preventing listeners from receiving events for it.
	 * @param Wallet The wallet address.
	 */
	virtual void UnsubscribeToWallet(const FString& Wallet) override;

	// endregion Event Channel Subscription

	/**
	 * @brief Creates a builder for this class.
	 * @return The builder.
	 */
	static FPusherEventServiceBuilder Builder();

	/**
	 * @brief Builder class for @link FPusherEventService @endlink.
	 */
	class ENJINSDKRUNTIME_API FPusherEventServiceBuilder final
	{
	public:
		/**
		 * @brief Class destructor.
		 */
		~FPusherEventServiceBuilder() = default;

		/**
		 * @brief Builds the event service.
		 * @return The event service.
		 */
		TUniquePtr<FPusherEventService> Build() const;

		/**
		 * @brief Sets the logger provider the client will use.
		 * @param LoggerProvider The logger provider.
		 * @return This builder for chaining.
		 */
		FPusherEventServiceBuilder& LoggerProvider(Util::FLoggerProviderPtr LoggerProvider);

		/**
		 * @brief Sets the platform details that the service will be using.
		 * @param Platform The platform details.
		 * @return This builder for chaining.
		 */
		FPusherEventServiceBuilder& Platform(Model::FPlatform Platform);

	private:
		TOptional<Util::FLoggerProviderPtr> LoggerProviderOpt;
		TOptional<Model::FPlatform> PlatformOpt;

		/**
		 * @brief Constructs an instance of this class.
		 */
		FPusherEventServiceBuilder() = default;

		friend FPusherEventServiceBuilder FPusherEventService::Builder();
	};

private:
	/**
	 * @brief Implementation class for @link FPusherEventService @endlink.
	 */
	class FImpl;

	TUniquePtr<FImpl> Pimpl;

	/**
	 * @brief Constructs an instance of this class.
	 * @param Platform The platform details.
	 * @param LoggerProvider The logger provider.
	 */
	FPusherEventService(Model::FPlatform Platform, Util::FLoggerProviderPtr LoggerProvider);
};
}
}
}
