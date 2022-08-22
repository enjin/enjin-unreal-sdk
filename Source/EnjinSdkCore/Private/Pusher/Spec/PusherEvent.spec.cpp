// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Pusher/PusherEvent.h"

using namespace Enjin::Sdk::Pusher;

BEGIN_DEFINE_SPEC(FPusherEventSpec,
                  "Enjin.Sdk.Pusher.PusherEvent",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"channel":"xyz","data":"{}","event":"xyz","user_id":"xyz"})");
END_DEFINE_SPEC(FPusherEventSpec)

void FPusherEventSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FPusherEvent ClassUnderTest;

			// Assert
			TestFalse(TEXT("ChannelName is not set"), ClassUnderTest.GetChannelName().IsSet());
			TestFalse(TEXT("Data is not set"), ClassUnderTest.GetData().IsSet());
			TestFalse(TEXT("EventName is not set"), ClassUnderTest.GetEventName().IsSet());
			TestFalse(TEXT("UserId is not set"), ClassUnderTest.GetUserId().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FPusherEvent ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("ChannelName is set"), ClassUnderTest.GetChannelName().IsSet());
			TestTrue(TEXT("Data is set"), ClassUnderTest.GetData().IsSet());
			TestTrue(TEXT("EventName is set"), ClassUnderTest.GetEventName().IsSet());
			TestTrue(TEXT("UserId is set"), ClassUnderTest.GetUserId().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FPusherEvent ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume ChannelName is set"), ClassUnderTest.GetChannelName().IsSet());
			TestTrue(TEXT("Assume Data is set"), ClassUnderTest.GetData().IsSet());
			TestTrue(TEXT("Assume EventName is set"), ClassUnderTest.GetEventName().IsSet());
			TestTrue(TEXT("Assume UserId is set"), ClassUnderTest.GetUserId().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("ChannelName was reset"), ClassUnderTest.GetChannelName().IsSet());
			TestFalse(TEXT("Data was reset"), ClassUnderTest.GetData().IsSet());
			TestFalse(TEXT("EventName was reset"), ClassUnderTest.GetEventName().IsSet());
			TestFalse(TEXT("UserId was reset"), ClassUnderTest.GetUserId().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FPusherEvent Lhs;
			const FPusherEvent Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FPusherEvent Lhs;
			const FPusherEvent Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FPusherEvent Lhs;
			FPusherEvent Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FPusherEvent Lhs;
			FPusherEvent Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
