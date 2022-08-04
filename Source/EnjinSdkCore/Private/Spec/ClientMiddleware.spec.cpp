// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "ClientMiddleware.h"
#include "Misc/AutomationTest.h"

using namespace Enjin::Sdk;

BEGIN_DEFINE_SPEC(FClientMiddlewareSpec,
                  "Enjin.Sdk.ClientMiddleware",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString DummyUrl = TEXT("https://test.cloud.enjin.io");
END_DEFINE_SPEC(FClientMiddlewareSpec)

void FClientMiddlewareSpec::Define()
{
	Describe(TEXT("Authenitication"), [this]()
	{
		It(TEXT("should return false when no auth token has been set"), [this]()
		{
			// Arrange
			const FClientMiddleware ClassUnderTest(DummyUrl);

			// Act
			const bool Actual = ClassUnderTest.IsAuthenticated();

			// Assert
			TestFalse(TEXT("Middleware is not authenticated"), Actual);
		});

		It(TEXT("should return false when auth token is empty string"), [this]()
		{
			// Arrange
			const FString Token = TEXT("       ");
			FClientMiddleware ClassUnderTest(DummyUrl);
			ClassUnderTest.SetAuthToken(Token);

			// Act
			const bool Actual = ClassUnderTest.IsAuthenticated();

			// Assert
			TestFalse(TEXT("Middleware is not authenticated"), Actual);
		});

		It(TEXT("should return true when a valid auth token has been set"), [this]()
		{
			// Arrange
			const FString Token = TEXT("TestToken");
			FClientMiddleware ClassUnderTest(DummyUrl);
			ClassUnderTest.SetAuthToken(Token);

			// Act
			const bool Actual = ClassUnderTest.IsAuthenticated();

			// Assert
			TestTrue(TEXT("Middleware is authenticated"), Actual);
		});
	});

	Describe(TEXT("Creating a request"), [this]()
	{
		It(TEXT("should not have authorization header when not authenticated"), [this]()
		{
			// Arrange
			const FString ExpectedKey = TEXT("Authorization");
			const FClientMiddleware ClassUnderTest(DummyUrl);

			// Assumptions
			TestFalse(TEXT("Assume middleware is not authenticated"), ClassUnderTest.IsAuthenticated());

			// Act
			const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Req = ClassUnderTest.CreateRequest();

			// Assert
			TestTrue(TEXT("Request does not have authorization"), Req->GetHeader(ExpectedKey).IsEmpty());
		});

		It(TEXT("should have authorization header when authenticated"), [this]()
		{
			// Arrange
			const FString Token = TEXT("TestToken");
			const FString ExpectedKey = TEXT("Authorization");
			const FString ExpectedValue = FString::Printf(TEXT("Bearer %s"), *Token);
			FClientMiddleware ClassUnderTest(DummyUrl);
			ClassUnderTest.SetAuthToken(Token);

			// Assumptions
			TestTrue(TEXT("Assume middleware is authenticated"), ClassUnderTest.IsAuthenticated());

			// Act
			const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Req = ClassUnderTest.CreateRequest();

			// Assert
			TestEqual(TEXT("Request has authorization"), Req->GetHeader(ExpectedKey), ExpectedValue);
		});
	});
}
