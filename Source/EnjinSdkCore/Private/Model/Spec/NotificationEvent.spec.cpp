// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/NotificationEvent.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FNotificationEventSpec,
                  "Enjin.Sdk.Event.NotificationEvent",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FNotificationEventSpec)

void FNotificationEventSpec::Define()
{
	Describe(TEXT("Getting deserialized data"), [this]()
	{
		It(TEXT("should return non-null pointer for data"), [this]()
		{
			// Arrange
			constexpr EEventType DummyType = EEventType::ProjectCreated;
			const FString DummyChannel = TEXT("project");
			const FString FakeMessage = TEXT("{\"key\":\"value\"}");
			const FNotificationEvent NotificationEvent = FNotificationEvent(DummyType, DummyChannel, FakeMessage);

			// Act
			const TSharedPtr<const FJsonObject>& Actual = NotificationEvent.GetData();

			// Assert
			TestNotNull(TEXT("Data pointer is not null"), Actual.Get());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides have same event type, channel, message"), [this]()
		{
			// Arrange
			constexpr EEventType Type = EEventType::ProjectCreated;
			const FString Channel = TEXT("project");
			const FString Message = TEXT("{\"key\":\"value\"}");
			const FNotificationEvent Lhs = FNotificationEvent(Type, Channel, Message);
			const FNotificationEvent Rhs = FNotificationEvent(Type, Channel, Message);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when both sides have different event type"), [this]()
		{
			// Arrange
			constexpr EEventType LhsType = EEventType::ProjectCreated;
			constexpr EEventType RhsType = EEventType::PlayerCreated;
			const FString Channel = TEXT("project");
			const FString Message = TEXT("{\"key\":\"value\"}");
			const FNotificationEvent Lhs = FNotificationEvent(LhsType, Channel, Message);
			const FNotificationEvent Rhs = FNotificationEvent(RhsType, Channel, Message);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when both sides have different channel"), [this]()
		{
			// Arrange
			const FString LhsChannel = TEXT("project");
			const FString RhsChannel = TEXT("player");
			constexpr EEventType Type = EEventType::ProjectCreated;
			const FString Message = TEXT("{\"key\":\"value\"}");
			const FNotificationEvent Lhs = FNotificationEvent(Type, LhsChannel, Message);
			const FNotificationEvent Rhs = FNotificationEvent(Type, RhsChannel, Message);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when both sides have different message"), [this]()
		{
			// Arrange
			const FString LhsMessage = TEXT("{\"side\":\"left\"}");
			const FString RhsMessage = TEXT("{\"side\":\"right\"}");
			constexpr EEventType Type = EEventType::ProjectCreated;
			const FString Channel = TEXT("project");
			const FNotificationEvent Lhs = FNotificationEvent(Type, Channel, LhsMessage);
			const FNotificationEvent Rhs = FNotificationEvent(Type, Channel, RhsMessage);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});
	});
}
