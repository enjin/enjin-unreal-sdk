// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PlayerClient.h"
#include "Misc/AutomationTest.h"

using namespace Enjin::Sdk;

BEGIN_DEFINE_SPEC(FPlayerClientSpec,
                  "Enjin.Sdk.PlayerClient",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString DummyUrl = TEXT("https://test.cloud.enjin.io");
END_DEFINE_SPEC(FPlayerClientSpec)

void FPlayerClientSpec::Define()
{
	Describe(TEXT("Client builder"), [this]()
	{
		It(TEXT("should return invalid pointer when attempting to build without providing the base URL"), [this]()
		{
			// Arrange
			const FPlayerClient::FPlayerClientBuilder Builder = FPlayerClient::Builder();

			// Act
			const TUniquePtr<FPlayerClient> Client = Builder.Build();

			// Assert
			TestFalse(TEXT("Test not implemeneted"), Client.IsValid());
		});

		It(TEXT("should return valid pointer when attempting to build after providing the base URL"), [this]()
		{
			// Arrange
			FPlayerClient::FPlayerClientBuilder Builder = FPlayerClient::Builder();
			Builder.BaseUrl(DummyUrl);

			// Act
			const TUniquePtr<FPlayerClient> Client = Builder.Build();

			// Assert
			TestTrue(TEXT("Test not implemeneted"), Client.IsValid());
		});
	});
}
