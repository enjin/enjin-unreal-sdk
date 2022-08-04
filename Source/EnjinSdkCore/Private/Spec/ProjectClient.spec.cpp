// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "ProjectClient.h"
#include "Misc/AutomationTest.h"

using namespace Enjin::Sdk;
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FProjectClientSpec,
                  "Enjin.Sdk.ProjectClient",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString DummyUrl = TEXT("https://test.cloud.enjin.io");
END_DEFINE_SPEC(FProjectClientSpec)

void FProjectClientSpec::Define()
{
	Describe(TEXT("Client builder"), [this]()
	{
		It(TEXT("should return invalid pointer when attempting to build without providing the base URL"), [this]()
		{
			// Arrange
			const FProjectClient::FProjectClientBuilder Builder = FProjectClient::Builder();

			// Act
			const TUniquePtr<FProjectClient> Client = Builder.Build();

			// Assert
			TestFalse(TEXT("Test not implemeneted"), Client.IsValid());
		});

		It(TEXT("should return valid pointer when attempting to build after providing the base URL"), [this]()
		{
			// Arrange
			FProjectClient::FProjectClientBuilder Builder = FProjectClient::Builder();
			Builder.BaseUrl(DummyUrl);

			// Act
			const TUniquePtr<FProjectClient> Client = Builder.Build();

			// Assert
			TestTrue(TEXT("Test not implemeneted"), Client.IsValid());
		});

		It(TEXT("should not produce client enabled for automatic reauthentication when not using option"), [this]()
		{
			// Arrange
			FProjectClient::FProjectClientBuilder Builder = FProjectClient::Builder();
			Builder.BaseUrl(DummyUrl);

			// Act
			const TUniquePtr<FProjectClient> Client = Builder.Build();

			// Assert
			TestFalse(TEXT("Client is not enabled for automatic reauthentication"),
			          Client->IsAutomaticReauthenticationEnabled());
		});

		It(TEXT("should produce client enabled for automatic reauthentication when using option"), [this]()
		{
			// Arrange
			FProjectClient::FProjectClientBuilder Builder = FProjectClient::Builder();
			Builder.BaseUrl(DummyUrl)
			       .EnableAutomaticReauthentication();

			// Act
			const TUniquePtr<FProjectClient> Client = Builder.Build();

			// Assert
			TestTrue(TEXT("Client is enabled for automatic reauthentication"),
			         Client->IsAutomaticReauthenticationEnabled());
		});
	});

	Describe(TEXT("Auth"), [this]()
	{
		It(TEXT("should not call authentication failed handler when given valid access token"), [this]()
		{
			// Arrange
			FAccessToken FakeAccessToken;
			FakeAccessToken.Deserialize(TEXT("{\"accessToken\":\"xyz\",\"expiresIn\":100}"));
			bool bFlag = false;
			TFunction<void()> Handler = [&bFlag]()
			{
				bFlag = true;
			};
			const TUniquePtr<FProjectClient> Client = FProjectClient::Builder()
			                                          .BaseUrl(DummyUrl)
			                                          .AuthenticationFailedHandler(MoveTemp(Handler))
			                                          .Build();

			// Act
			Client->Auth(FakeAccessToken);

			// Assert
			TestFalse(TEXT("Authentication failed handler was not called"), bFlag);
		});

		It(TEXT("should call authentication failed handler when given malformed access token"), [this]()
		{
			// Arrange
			FAccessToken FakeAccessToken;
			FakeAccessToken.Deserialize(TEXT("{\"accessToken\":\"xyz\"}"));
			bool bFlag = false;
			TFunction<void()> Handler = [&bFlag]()
			{
				bFlag = true;
			};
			const TUniquePtr<FProjectClient> Client = FProjectClient::Builder()
			                                          .BaseUrl(DummyUrl)
			                                          .AuthenticationFailedHandler(MoveTemp(Handler))
			                                          .Build();

			// Act
			Client->Auth(FakeAccessToken);

			// Assert
			TestTrue(TEXT("Authentication failed handler was called"), bFlag);
		});
	});
}
