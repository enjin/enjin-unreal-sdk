// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PusherEventService.h"

#include "Event/EventTypeDef.h"
#include "Event/PusherEventListener.h"
#include "Event/Channel/AssetChannel.h"
#include "Event/Channel/PlayerChannel.h"
#include "Event/Channel/ProjectChannel.h"
#include "Event/Channel/WalletChannel.h"
#include "Pusher/PusherClient.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Pusher;
using namespace Enjin::Sdk::Util;

/**
 * @brief Convenience alias for nested builder class in @link FPusherEventService @endlink.
 */
using FPusherEventServiceBuilder = FPusherEventService::FPusherEventServiceBuilder;

/**
 * @brief Convenience alias for shared-reference to @link FPusherEventListener @endlink used by the event service.
 */
using FPusherEventListenerRef = TSharedRef<FPusherEventListener, ESPMode::ThreadSafe>;

/**
 * @brief Convenience alias for nested config class in @link FEventListenerRegistration @endlink.
 */
using FRegistrationListenerConfiguration = FEventListenerRegistration::FRegistrationListenerConfiguration;

class FPusherEventService::FImpl final : public IEventService
{
public:
	FImpl() = delete;

	FImpl(FPlatform Platform, FLoggerProviderPtr LoggerProvider, FPusherEventListenerRef Listener)
		: Platform(MoveTemp(Platform)),
		  LoggerProvider(MoveTemp(LoggerProvider)),
		  PusherListener(MoveTemp(Listener))
	{
	}

	virtual ~FImpl() override
	{
		if (PusherClient.IsValid())
		{
			PusherClient->OnConnectionStateChanged().Clear();
			PusherClient->OnError().Clear();
		}
	}

	const FLoggerProviderPtr& GetLoggerProvider() const
	{
		return LoggerProvider;
	}

	const TArray<FEventListenerRegistrationRef>& GetRegistrations() const
	{
		return Listeners;
	}

	virtual bool IsConnected() const override
	{
		return PusherClient.IsValid() && PusherClient->IsConnected();
	}

	virtual FEventServiceConnectedEvent& OnConnected() override
	{
		return OnConnectedEvent;
	}

	virtual FEventServiceDisconnectedEvent& OnDisconnected() override
	{
		return OnDisconnectedEvent;
	}

	virtual FEventServiceErrorEvent& OnError() override
	{
		return OnErrorEvent;
	}

	virtual TFuture<bool> Shutdown() override
	{
		if (IsConnected())
		{
			return PusherClient->Close();
		}

		return Async(EAsyncExecution::Thread, []()
		{
			return true;
		});
	}

	virtual TFuture<bool> Start() override
	{
		if (IsConnected())
		{
			return Async(EAsyncExecution::Thread, []()
			{
				return true;
			});
		}

		PusherClient.Reset();

		if (!Platform.GetNotifications().IsSet())
		{
			OnErrorEvent.Broadcast(TEXT("Tried starting Pusher event service with no set notification details"));
			return Async(EAsyncExecution::Thread, []()
			{
				return false;
			});
		}

		const FNotifications& Notifications = Platform.GetNotifications().GetValue();
		if (!Notifications.GetPusher().IsSet())
		{
			OnErrorEvent.Broadcast(TEXT("Tried starting Pusher event service with no set Pusher details"));
			return Async(EAsyncExecution::Thread, []()
			{
				return false;
			});
		}

		const FPusher& Pusher = Notifications.GetPusher().GetValue();
		if (!Pusher.GetKey().IsSet() || !Pusher.GetOptions().IsSet())
		{
			OnErrorEvent.Broadcast(TEXT("Tried starting Pusher event service with no set key and/or Pusher options"));
			return Async(EAsyncExecution::Thread, []()
			{
				return false;
			});
		}

		const FPusherOptions& Options = Pusher.GetOptions().GetValue();
		if (!Options.GetCluster().IsSet() || !Options.GetEncrypted().IsSet())
		{
			OnErrorEvent.Broadcast(TEXT("Tried starting Pusher event service with no set cluster and/or encryption"));
			return Async(EAsyncExecution::Thread, []()
			{
				return false;
			});
		}

		const FString& Key = Pusher.GetKey().GetValue();
		FPusherOptionsInput OptionsInput = FPusherOptionsInput().SetCluster(Options.GetCluster().GetValue())
		                                                        .SetEncrypted(Options.GetEncrypted().GetValue());

		PusherClient = MakeUnique<FPusherClient>(Key, MoveTemp(OptionsInput));
		if (!PusherClient->IsInitialized())
		{
			OnErrorEvent.Broadcast(TEXT("Pusher client failed to initialize properly"));
			return Async(EAsyncExecution::Thread, []()
			{
				return false;
			});
		}

		PusherClient->OnConnectionStateChanged().AddLambda([this](const EPusherConnectionState State)
		{
			if (LoggerProvider.IsValid() && State != EPusherConnectionState::All)
			{
				LoggerProvider->Log(ELogLevel::Info,
				                    FString::Printf(TEXT("Pusher client connection: %s"), ToString(State)));
			}

			switch (State)
			{
				case EPusherConnectionState::Connected:
					OnConnectedEvent.Broadcast();
					break;

				case EPusherConnectionState::Disconnected:
					OnDisconnectedEvent.Broadcast();
					break;

				default:
					break;
			}
		});

		PusherClient->OnError().AddLambda([this](const int32 Code, const FString Message)
		{
			const FString ErrorMessage = FString::Printf(TEXT("[%d] %s"), Code, *Message);

			if (LoggerProvider.IsValid())
			{
				LoggerProvider->Log(ELogLevel::Error,
				                    FString::Printf(TEXT("Error on Pusher client: %s"), *ErrorMessage));
			}

			OnErrorEvent.Broadcast(ErrorMessage);
		});

		ResubscribeToChannels();
		return PusherClient->Connect();
	}

	virtual TFuture<bool> Start(FPlatform NewPlatform) override
	{
		Platform = MoveTemp(NewPlatform);

		return Start();
	}

	// region Listener Registration

	virtual bool IsRegistered(const IEventListener& Listener) const override
	{
		for (const auto& Registration : Listeners)
		{
			if (&Registration->GetListener().Get() == &Listener)
			{
				return true;
			}
		}

		return false;
	}

	virtual FEventListenerRegistrationRef RegisterListener(FEventListenerRef Listener) override
	{
		const FRegistrationListenerConfiguration Config(MoveTemp(Listener));

		return CacheRegistration(Config);
	}

	virtual FEventListenerRegistrationRef RegisterListenerExcludingTypes(FEventListenerRef Listener,
	                                                                     TArray<Model::EEventType> Types) override
	{
		FRegistrationListenerConfiguration Config(MoveTemp(Listener));
		Config.WithIgnoredEvents(MoveTemp(Types));

		return CacheRegistration(Config);
	}

	virtual FEventListenerRegistrationRef RegisterListenerIncludingTypes(FEventListenerRef Listener,
	                                                                     TArray<Model::EEventType> Types) override
	{
		FRegistrationListenerConfiguration Config(MoveTemp(Listener));
		Config.WithAllowedEvents(MoveTemp(Types));

		return CacheRegistration(Config);
	}

	virtual FEventListenerRegistrationRef RegisterListenerWithMatcher(FEventListenerRef Listener,
	                                                                  FEventMatcher Matcher) override
	{
		FRegistrationListenerConfiguration Config(MoveTemp(Listener));
		Config.WithMatcher(MoveTemp(Matcher));

		return CacheRegistration(Config);
	}

	virtual void UnregisterListener(const IEventListener& Listener) override
	{
		for (int i = 0; i < Listeners.Num(); i++)
		{
			const FEventListenerRegistrationRef& Registration = Listeners[i];

			if (&Registration->GetListener().Get() == &Listener)
			{
				Listeners.RemoveAt(i);
				return;
			}
		}
	}

	// endregion Listener Registration

	// region Event Channel Subscription

	virtual bool IsSubscribedToAsset(const FString& Asset) const override
	{
		return IsSubscribed(FAssetChannel(Platform, Asset).GetChannel());
	}

	virtual bool IsSubscribedToPlayer(const FString& Project, const FString& Player) const override
	{
		return IsSubscribed(FPlayerChannel(Platform, Project, Player).GetChannel());
	}

	virtual bool IsSubscribedToProject(const FString& Project) const override
	{
		return IsSubscribed(FProjectChannel(Platform, Project).GetChannel());
	}

	virtual bool IsSubscribedToWallet(const FString& Wallet) const override
	{
		return IsSubscribed(FWalletChannel(Platform, Wallet).GetChannel());
	}

	virtual void SubscribeToAsset(const FString& Asset) override
	{
		Subscribe(FAssetChannel(Platform, Asset).GetChannel());
	}

	virtual void SubscribeToPlayer(const FString& Project, const FString& Player) override
	{
		Subscribe(FPlayerChannel(Platform, Project, Player).GetChannel());
	}

	virtual void SubscribeToProject(const FString& Project) override
	{
		Subscribe(FProjectChannel(Platform, Project).GetChannel());
	}

	virtual void SubscribeToWallet(const FString& Wallet) override
	{
		Subscribe(FWalletChannel(Platform, Wallet).GetChannel());
	}

	virtual void UnsubscribeToAsset(const FString& Asset) override
	{
		Unsubscribe(FAssetChannel(Platform, Asset).GetChannel());
	}

	virtual void UnsubscribeToPlayer(const FString& Project, const FString& Player) override
	{
		Unsubscribe(FPlayerChannel(Platform, Project, Player).GetChannel());
	}

	virtual void UnsubscribeToProject(const FString& Project) override
	{
		Unsubscribe(FProjectChannel(Platform, Project).GetChannel());
	}

	virtual void UnsubscribeToWallet(const FString& Wallet) override
	{
		Unsubscribe(FWalletChannel(Platform, Wallet).GetChannel());
	}

	// endregion Event Channel Subscription

private:
	FPlatform Platform;
	TSet<FString> SubscribedChannels;
	TArray<FEventListenerRegistrationRef> Listeners;

	const FLoggerProviderPtr LoggerProvider;
	TUniquePtr<FPusherClient> PusherClient;
	const TSharedRef<FPusherEventListener, ESPMode::ThreadSafe> PusherListener;

	// Event delegates
	FEventServiceConnectedEvent OnConnectedEvent;
	FEventServiceDisconnectedEvent OnDisconnectedEvent;
	FEventServiceErrorEvent OnErrorEvent;

	/**
	 * @brief Tries to cache the registration for a event listener if one is not already present.
	 * @param Config The registration configuration.
	 * @return The registration for the event listener that is currently cached.
	 */
	FEventListenerRegistrationRef CacheRegistration(const FRegistrationListenerConfiguration& Config)
	{
		// Check if a registration for the listener already exists
		for (const auto& Reg : Listeners)
		{
			if (&Reg->GetListener().Get() == &Config.GetListener().Get())
			{
				return Reg;
			}
		}

		Listeners.Add(Config.Create());

		return Listeners.Last();
	}

	// region Event Channel Subscription

	/**
	 * @brief Binds the Pusher event listener to all events for the given channel.
	 * @param Channel The channel.
	 */
	// ReSharper disable once CppMemberFunctionMayBeConst
	void Bind(const FString& Channel)
	{
		for (const FEventTypeDef& Def : FEventTypeDef::FilterByChannel(Channel))
		{
			PusherClient->Bind(Def.GetKey(), PusherListener);
		}
	}

	/**
	 * @brief Determines whether this service is subscribed to the channel.
	 * @param Channel The channel.
	 * @return Whether this service is subscribed to the channel.
	 */
	bool IsSubscribed(const FString& Channel) const
	{
		return SubscribedChannels.Contains(Channel);
	}

	/**
	 * @brief Resubscribes the Pusher client to all channels cached within this service.
	 */
	void ResubscribeToChannels()
	{
		if (SubscribedChannels.Num() == 0)
		{
			return;
		}

		TSet<FString> Channels(SubscribedChannels);
		SubscribedChannels.Empty(SubscribedChannels.Num());

		for (const FString& Channel : Channels)
		{
			Subscribe(Channel);
		}
	}

	/**
	 * @brief Opens the specified channel, allowing listeners to receive events for it.
	 * @param Channel The channel.
	 */
	void Subscribe(const FString& Channel)
	{
		if (IsSubscribed(Channel))
		{
			return;
		}

		SubscribedChannels.Add(Channel);

		if (!PusherClient.IsValid())
		{
			return;
		}

		PusherClient->Subscribe(Channel);
		Bind(Channel);
	}

	/**
	 * @brief Closes the specified channel, preventing listeners from receiving events for it.
	 * @param Channel The channel.
	 */
	void Unsubscribe(const FString& Channel)
	{
		if (!IsSubscribed(Channel))
		{
			return;
		}

		SubscribedChannels.Remove(Channel);

		if (!PusherClient.IsValid())
		{
			return;
		}

		PusherClient->Unsubscribe(Channel);
	}

	// endregion Event Channel Subscription
};

FPusherEventService::FPusherEventService(FPlatform Platform, FLoggerProviderPtr LoggerProvider)
	: Pimpl(MakeUnique<FImpl>(MoveTemp(Platform),
	                          MoveTemp(LoggerProvider),
	                          MakeShared<FPusherEventListener, ESPMode::ThreadSafe>(*this)))
{
}

FPusherEventService::~FPusherEventService() = default;

const FLoggerProviderPtr& FPusherEventService::GetLoggerProvider() const
{
	return Pimpl->GetLoggerProvider();
}

const TArray<FEventListenerRegistrationRef>& FPusherEventService::GetRegistrations() const
{
	return Pimpl->GetRegistrations();
}

bool FPusherEventService::IsConnected() const
{
	return Pimpl->IsConnected();
}

IEventService::FEventServiceConnectedEvent& FPusherEventService::OnConnected()
{
	return Pimpl->OnConnected();
}

IEventService::FEventServiceDisconnectedEvent& FPusherEventService::OnDisconnected()
{
	return Pimpl->OnDisconnected();
}

IEventService::FEventServiceErrorEvent& FPusherEventService::OnError()
{
	return Pimpl->OnError();
}

TFuture<bool> FPusherEventService::Shutdown()
{
	return Pimpl->Shutdown();
}

TFuture<bool> FPusherEventService::Start()
{
	return Pimpl->Start();
}

TFuture<bool> FPusherEventService::Start(FPlatform NewPlatform)
{
	return Pimpl->Start(MoveTemp(NewPlatform));
}

// region Listener Registration

bool FPusherEventService::IsRegistered(const IEventListener& Listener) const
{
	return Pimpl->IsRegistered(Listener);
}

FEventListenerRegistrationRef FPusherEventService::RegisterListener(FEventListenerRef Listener)
{
	return Pimpl->RegisterListener(MoveTemp(Listener));
}

FEventListenerRegistrationRef
FPusherEventService::RegisterListenerExcludingTypes(FEventListenerRef Listener, TArray<EEventType> Types)
{
	return Pimpl->RegisterListenerExcludingTypes(MoveTemp(Listener), MoveTemp(Types));
}

FEventListenerRegistrationRef
FPusherEventService::RegisterListenerIncludingTypes(FEventListenerRef Listener, TArray<EEventType> Types)
{
	return Pimpl->RegisterListenerIncludingTypes(MoveTemp(Listener), MoveTemp(Types));
}

FEventListenerRegistrationRef
FPusherEventService::RegisterListenerWithMatcher(FEventListenerRef Listener, FEventMatcher Matcher)
{
	return Pimpl->RegisterListenerWithMatcher(MoveTemp(Listener), MoveTemp(Matcher));
}

void FPusherEventService::UnregisterListener(const IEventListener& Listener)
{
	Pimpl->UnregisterListener(Listener);
}

// endregion Listener Registration

// region Event Channel Subscription

bool FPusherEventService::IsSubscribedToAsset(const FString& Asset) const
{
	return Pimpl->IsSubscribedToAsset(Asset);
}

bool FPusherEventService::IsSubscribedToPlayer(const FString& Project, const FString& Player) const
{
	return Pimpl->IsSubscribedToPlayer(Project, Player);
}

bool FPusherEventService::IsSubscribedToProject(const FString& Project) const
{
	return Pimpl->IsSubscribedToProject(Project);
}

bool FPusherEventService::IsSubscribedToWallet(const FString& Wallet) const
{
	return Pimpl->IsSubscribedToWallet(Wallet);
}

void FPusherEventService::SubscribeToAsset(const FString& Asset)
{
	Pimpl->SubscribeToAsset(Asset);
}

void FPusherEventService::SubscribeToPlayer(const FString& Project, const FString& Player)
{
	Pimpl->SubscribeToPlayer(Project, Player);
}

void FPusherEventService::SubscribeToProject(const FString& Project)
{
	Pimpl->SubscribeToProject(Project);
}

void FPusherEventService::SubscribeToWallet(const FString& Wallet)
{
	Pimpl->SubscribeToWallet(Wallet);
}

void FPusherEventService::UnsubscribeToAsset(const FString& Asset)
{
	Pimpl->UnsubscribeToAsset(Asset);
}

void FPusherEventService::UnsubscribeToPlayer(const FString& Project, const FString& Player)
{
	Pimpl->UnsubscribeToPlayer(Project, Player);
}

void FPusherEventService::UnsubscribeToProject(const FString& Project)
{
	Pimpl->UnsubscribeToProject(Project);
}

void FPusherEventService::UnsubscribeToWallet(const FString& Wallet)
{
	Pimpl->UnsubscribeToWallet(Wallet);
}

// endregion Event Channel Subscription

FPusherEventServiceBuilder FPusherEventService::Builder()
{
	return FPusherEventServiceBuilder();
}

TUniquePtr<FPusherEventService> FPusherEventServiceBuilder::Build() const
{
	if (!PlatformOpt.IsSet())
	{
		return nullptr;
	}

	return TUniquePtr<FPusherEventService>(new FPusherEventService(PlatformOpt.GetValue(),
	                                                               LoggerProviderOpt.Get(nullptr)));
}

FPusherEventServiceBuilder& FPusherEventServiceBuilder::LoggerProvider(FLoggerProviderPtr LoggerProvider)
{
	LoggerProviderOpt = MoveTemp(LoggerProvider);
	return *this;
}

FPusherEventServiceBuilder& FPusherEventServiceBuilder::Platform(FPlatform Platform)
{
	PlatformOpt = MoveTemp(Platform);
	return *this;
}
