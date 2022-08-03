// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "EventListenerRegistration.h"
#include "Misc/AutomationTest.h"
#include "Test/DummyEventListener.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Test;

using FRegistrationListenerConfiguration = FEventListenerRegistration::FRegistrationListenerConfiguration;

BEGIN_DEFINE_SPEC(FRegistrationListenerConfigurationSpec,
                  "Enjin.Sdk.Event.RegistrationListenerConfiguration",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	const TArray<EEventType> Types =
	{
		EEventType::Unknown,
		EEventType::AssetCreated,
		EEventType::AssetMelted,
		EEventType::AssetMinted,
		EEventType::AssetTransferred,
		EEventType::AssetUpdated,
		EEventType::BlockchainLogProcessed,
		EEventType::MessageProcessed,
		EEventType::PlayerCreated,
		EEventType::PlayerDeleted,
		EEventType::PlayerLinked,
		EEventType::PlayerUnlinked,
		EEventType::PlayerUpdated,
		EEventType::ProjectCreated,
		EEventType::ProjectDeleted,
		EEventType::ProjectLinked,
		EEventType::ProjectLocked,
		EEventType::ProjectUnlinked,
		EEventType::ProjectUpdated,
		EEventType::TradeAssetCompleted,
		EEventType::TradeAssetCreated,
		EEventType::TransactionBroadcast,
		EEventType::TransactionCanceled,
		EEventType::TransactionDropped,
		EEventType::TransactionExecuted,
		EEventType::TransactionFailed,
		EEventType::TransactionPending,
		EEventType::TransactionProcessing,
		EEventType::TransactionUpdated,
	};

END_DEFINE_SPEC(FRegistrationListenerConfigurationSpec)

void FRegistrationListenerConfigurationSpec::Define()
{
	Describe(TEXT("Setting event listener"), [this]()
	{
		It(TEXT("should create registration with that holds the same listener"), [this]()
		{
			// Arrange
			const FEventListenerRef Expected = MakeShared<FDummyEventListener, ESPMode::ThreadSafe>();
			const FRegistrationListenerConfiguration Config(Expected);

			// Act
			const FEventListenerRegistrationRef Registration = Config.Create();

			// Assert
			TestEqual(TEXT("Registration did not have the expected listener"), Registration->GetListener(), Expected);
		});
	});

	Describe(TEXT("Setting event matcher"), [this]()
	{
		It(TEXT("should create registration with the allow all matcher when no matcher is provided"), [this]()
		{
			// Arrange
			const FEventListenerRef DummyListener = MakeShared<FDummyEventListener, ESPMode::ThreadSafe>();
			const FRegistrationListenerConfiguration Config(DummyListener);

			// Act
			const FEventListenerRegistrationRef Registration = Config.Create();

			// Assert
			for (const EEventType Type : Types)
			{
				TestTrue(TEXT("Matcher did not produce expected result"), Registration->GetMatcher()(Type));
			}
		});

		It(TEXT("should create registration with correct matcher when provided one"), [this]()
		{
			// Arrange
			const FEventMatcher Matcher = [](const EEventType)
			{
				return false; // Always false
			};
			const FEventListenerRef DummyListener = MakeShared<FDummyEventListener, ESPMode::ThreadSafe>();
			FRegistrationListenerConfiguration Config(DummyListener);

			// Act
			const FEventListenerRegistrationRef Registration = Config.WithMatcher(Matcher).Create();

			// Assert
			for (const EEventType Type : Types)
			{
				TestFalse(TEXT("Matcher did not produce expected result"), Registration->GetMatcher()(Type));
			}
		});

		It(TEXT("should create registration with correct matcher when provided allowed events types"), [this]()
		{
			// Arrange
			const TArray<EEventType> AllowedTypes =
			{
				EEventType::AssetMelted,
				EEventType::AssetMinted,
				EEventType::AssetTransferred,
			};
			const FEventListenerRef DummyListener = MakeShared<FDummyEventListener, ESPMode::ThreadSafe>();
			FRegistrationListenerConfiguration Config(DummyListener);

			// Act
			const FEventListenerRegistrationRef Registration = Config.WithAllowedEvents(AllowedTypes).Create();

			// Assert
			for (const EEventType Type : Types)
			{
				if (AllowedTypes.Contains(Type))
				{
					TestTrue(TEXT("Matcher did not produce expected result"), Registration->GetMatcher()(Type));
				}
				else
				{
					TestFalse(TEXT("Matcher did not produce expected result"), Registration->GetMatcher()(Type));
				}
			}
		});

		It(TEXT("should create registration with correct matcher when provided ignored events types"), [this]()
		{
			// Arrange
			const TArray<EEventType> IgnoredTypes =
			{
				EEventType::AssetMelted,
				EEventType::AssetMinted,
				EEventType::AssetTransferred,
			};
			const FEventListenerRef DummyListener = MakeShared<FDummyEventListener, ESPMode::ThreadSafe>();
			FRegistrationListenerConfiguration Config(DummyListener);

			// Act
			const FEventListenerRegistrationRef Registration = Config.WithIgnoredEvents(IgnoredTypes).Create();

			// Assert
			for (const EEventType Type : Types)
			{
				if (IgnoredTypes.Contains(Type))
				{
					TestFalse(TEXT("Matcher did not produce expected result"), Registration->GetMatcher()(Type));
				}
				else
				{
					TestTrue(TEXT("Matcher did not produce expected result"), Registration->GetMatcher()(Type));
				}
			}
		});
	});
}
