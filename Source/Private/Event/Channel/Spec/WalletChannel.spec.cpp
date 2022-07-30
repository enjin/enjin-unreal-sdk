// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Event/Channel/WalletChannel.h"
#include "Misc/AutomationTest.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FWalletChannelSpec,
                  "Enjin.Sdk.Event.WalletChannel",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	static FPlatform CreateDefaultPlatform()
	{
		FPlatform Platform;
		Platform.Deserialize(TEXT("{\"network\":\"test\"}"));

		return Platform;
	}

END_DEFINE_SPEC(FWalletChannelSpec)

void FWalletChannelSpec::Define()
{
	Describe(TEXT("Channel"), [this]()
	{
		It(TEXT("should return expected channel string"), [this]()
		{
			// Arrange
			const FString Expected = TEXT("enjincloud.test.wallet.0x1");
			const FWalletChannel Channel(CreateDefaultPlatform(), TEXT("0x1"));

			// Act
			const FString Actual = Channel.GetChannel();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});
}
