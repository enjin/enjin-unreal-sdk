// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Event/PusherEventListener.h"
#include "Misc/AutomationTest.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Pusher;

class FMockEventListener;

/**
 * @brief Alias for a shared-reference to a mock event listener.
 */
using FMockListenerRef = TSharedRef<FMockEventListener, ESPMode::ThreadSafe>;

/**
 * @brief Simple mock event listener for verifying call count of member-function processing notifications.
 */
class FMockEventListener final : public IEventListener
{
public:
	FMockEventListener() = default;

	virtual ~FMockEventListener() override = default;

	int GetCallCount() const
	{
		return CallCount;
	}

	virtual void NotificationReceived(const FNotificationEvent& Event) override
	{
		CallCount++;
	}

private:
	int CallCount = 0;
};

BEGIN_DEFINE_SPEC(FPusherEventListenerSpec,
                  "Enjin.Sdk.Event.PusherEventListener",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	static constexpr EEventType DefaultEventType = EEventType::AssetCreated;

	static FPusherEvent CreateDefaultPusherEvent()
	{
		const FString Json = TEXT(
			R"({"channel":"enjincloud.test.asset.1","event":"EnjinCloud\\Events\\AssetCreated","data":"{}"})");

		FPusherEvent Event;
		Event.Deserialize(Json);

		return Event;
	}

	static TUniquePtr<FPusherEventService> CreateFakeEventService()
	{
		FPlatform Platform;
		Platform.Deserialize(TEXT(R"({"network":"test"})"));

		return FPusherEventService::Builder().Platform(Platform).Build();
	}

END_DEFINE_SPEC(FPusherEventListenerSpec)

void FPusherEventListenerSpec::Define()
{
	Describe(TEXT("On event received for different listener configurations"), [this]()
	{
		It(TEXT("should call event listener once for allowed event"), [this]()
		{
			// Arrange
			const FPusherEvent FakePusherEvent = CreateDefaultPusherEvent();
			const TUniquePtr<FPusherEventService> FakeService = CreateFakeEventService();
			const FMockListenerRef MockListener = MakeShared<FMockEventListener, ESPMode::ThreadSafe>();
			FPusherEventListener PusherEventListener(*FakeService.Get());
			FakeService->RegisterListenerIncludingTypes(MockListener, {DefaultEventType});

			// Assumptions
			TestTrue(TEXT("Assume listener was registered"), FakeService->IsRegistered(MockListener.Get()));

			// Act
			PusherEventListener.OnEvent(FakePusherEvent);

			// Verify
			TestEqual(TEXT("Verify mock-listener was called once"), MockListener->GetCallCount(), 1);
		});

		It(TEXT("should not call event listener for ignored event"), [this]()
		{
			// Arrange
			const FPusherEvent FakePusherEvent = CreateDefaultPusherEvent();
			const TUniquePtr<FPusherEventService> FakeService = CreateFakeEventService();
			const FMockListenerRef MockListener = MakeShared<FMockEventListener, ESPMode::ThreadSafe>();
			FPusherEventListener PusherEventListener(*FakeService.Get());
			FakeService->RegisterListenerExcludingTypes(MockListener, {DefaultEventType});

			// Assumptions
			TestTrue(TEXT("Assume listener was registered"), FakeService->IsRegistered(MockListener.Get()));

			// Act
			PusherEventListener.OnEvent(FakePusherEvent);

			// Verify
			TestEqual(TEXT("Verify mock-listener was not called"), MockListener->GetCallCount(), 0);
		});

		It(TEXT("should not call event listener for unknown event"), [this]()
		{
			// Arrange
			const FPusherEvent FakePusherEvent;
			const TUniquePtr<FPusherEventService> FakeService = CreateFakeEventService();
			const FMockListenerRef MockListener = MakeShared<FMockEventListener, ESPMode::ThreadSafe>();
			FPusherEventListener PusherEventListener(*FakeService.Get());
			FakeService->RegisterListenerIncludingTypes(MockListener, {DefaultEventType});

			// Assumptions
			TestTrue(TEXT("Assume listener was registered"), FakeService->IsRegistered(MockListener.Get()));

			// Act
			PusherEventListener.OnEvent(FakePusherEvent);

			// Verify
			TestEqual(TEXT("Verify mock-listener was not called"), MockListener->GetCallCount(), 0);
		});
	});
}
