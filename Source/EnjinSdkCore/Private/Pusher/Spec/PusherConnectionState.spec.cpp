// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Pusher/PusherConnectionState.h"

using namespace Enjin::Sdk::Pusher;

BEGIN_DEFINE_SPEC(FPusherConnectionStateSpec,
                  "Enjin.Sdk.Pusher.PusherConnectionState",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FPusherConnectionStateSpec)

void FPusherConnectionStateSpec::Define()
{
	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<EPusherConnectionState, FString>> Params =
		{
			TPair<EPusherConnectionState, FString>(EPusherConnectionState::All, TEXT("all")),
			TPair<EPusherConnectionState, FString>(EPusherConnectionState::Connected, TEXT("connected")),
			TPair<EPusherConnectionState, FString>(EPusherConnectionState::Connecting, TEXT("connecting")),
			TPair<EPusherConnectionState, FString>(EPusherConnectionState::Disconnected, TEXT("disconnected")),
			TPair<EPusherConnectionState, FString>(EPusherConnectionState::Disconnecting, TEXT("disconnecting")),
			TPair<EPusherConnectionState, FString>(EPusherConnectionState::Reconnecting, TEXT("reconnecting")),
		};

		for (const TPair<EPusherConnectionState, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const EPusherConnectionState EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
