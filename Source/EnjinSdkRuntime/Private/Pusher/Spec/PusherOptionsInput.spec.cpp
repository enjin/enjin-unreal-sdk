// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Pusher/PusherOptionsInput.h"

using namespace Enjin::Sdk::Pusher;

BEGIN_DEFINE_SPEC(FPusherOptionsInputSpec,
                  "Enjin.Sdk.Pusher.PusherOptionsInput",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FPusherOptionsInputSpec)

void FPusherOptionsInputSpec::Define()
{
	Describe(TEXT("Host"), [this]()
	{
		It(TEXT("should return the expected host string"), [this]()
		{
			// Arrange
			const FString Expected = TEXT("ws-TestCluster.pusher.com");
			const FString FakeCluster = TEXT("TestCluster");
			FPusherOptionsInput ClassUnderTest;
			ClassUnderTest.SetCluster(FakeCluster);

			// Act
			const FString Actual = ClassUnderTest.Host();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});
}
