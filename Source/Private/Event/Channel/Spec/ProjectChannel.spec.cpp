// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Event/Channel/ProjectChannel.h"
#include "Misc/AutomationTest.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FProjectChannelSpec,
                  "Enjin.Sdk.Event.ProjectChannel",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	static FPlatform CreateDefaultPlatform()
	{
		FPlatform Platform;
		Platform.Deserialize(TEXT("{\"network\":\"test\"}"));

		return Platform;
	}

END_DEFINE_SPEC(FProjectChannelSpec)

void FProjectChannelSpec::Define()
{
	Describe(TEXT("Channel"), [this]()
	{
		It(TEXT("should return expected channel string"), [this]()
		{
			// Arrange
			const FString Expected = TEXT("enjincloud.test.project.1");
			const FProjectChannel Channel(CreateDefaultPlatform(), TEXT("1"));

			// Act
			const FString Actual = Channel.GetChannel();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});
}
