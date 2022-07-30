// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PusherEventService.h"
#include "Misc/AutomationTest.h"
#include "Test/DummyEventListener.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Test;

BEGIN_DEFINE_SPEC(FPusherEventServiceSpec,
                  "Enjin.Sdk.Event.PusherEventService",
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

	static TUniquePtr<FPusherEventService> CreateDefaultEventService()
	{
		FPlatform Platform;
		Platform.Deserialize(TEXT(
			R"({"network":"test","notifications":{"pusher":{"key":"xyz","options":{"cluster":"mt1","encrypted":true}}}})"));

		return FPusherEventService::Builder().Platform(Platform).Build();
	}

END_DEFINE_SPEC(FPusherEventServiceSpec)

void FPusherEventServiceSpec::Define()
{
	Describe(TEXT("Is listener registered"), [this]()
	{
		It(TEXT("should return false when listener has not been registered"), [this]()
		{
			// Arrange
			const TUniquePtr<FPusherEventService> Service = CreateDefaultEventService();
			const FEventListenerRef DummyListener = MakeShared<FDummyEventListener, ESPMode::ThreadSafe>();

			// Act
			const bool Actual = Service->IsRegistered(DummyListener.Get());

			// Assert
			TestFalse(TEXT("Listener is not registered"), Actual);
		});

		It(TEXT("should return true when listener has been registered"), [this]()
		{
			// Arrange
			const TUniquePtr<FPusherEventService> Service = CreateDefaultEventService();
			const FEventListenerRef DummyListener = MakeShared<FDummyEventListener, ESPMode::ThreadSafe>();
			Service->RegisterListener(DummyListener);

			// Act
			const bool Actual = Service->IsRegistered(DummyListener.Get());

			// Assert
			TestTrue(TEXT("Listener is registered"), Actual);
		});

		It(TEXT("should return false when listener has been unregistered"), [this]()
		{
			// Arrange
			const TUniquePtr<FPusherEventService> Service = CreateDefaultEventService();
			const FEventListenerRef DummyListener = MakeShared<FDummyEventListener, ESPMode::ThreadSafe>();
			Service->RegisterListener(DummyListener);
			Service->UnregisterListener(DummyListener.Get());

			// Act
			const bool Actual = Service->IsRegistered(DummyListener.Get());

			// Assert
			TestFalse(TEXT("Listener is not registered"), Actual);
		});
	});
}
