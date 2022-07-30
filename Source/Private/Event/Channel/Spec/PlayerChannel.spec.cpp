// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Event/Channel/PlayerChannel.h"
#include "Misc/AutomationTest.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPlayerChannelSpec,
                  "Enjin.Sdk.Event.PlayerChannel",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	static FPlatform CreateDefaultPlatform()
	{
		FPlatform Platform;
		Platform.Deserialize(TEXT("{\"network\":\"test\"}"));

		return Platform;
	}

END_DEFINE_SPEC(FPlayerChannelSpec)

void FPlayerChannelSpec::Define()
{
	Describe(TEXT("Channel"), [this]()
	{
		It(TEXT("should return expected channel string"), [this]()
		{
			// Arrange
			const FString Expected = TEXT("enjincloud.test.project.1.player.xyz");
			const FPlayerChannel Channel(CreateDefaultPlatform(), TEXT("1"), TEXT("xyz"));

			// Act
			const FString Actual = Channel.GetChannel();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});
}
