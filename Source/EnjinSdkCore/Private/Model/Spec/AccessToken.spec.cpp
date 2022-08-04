// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AccessToken.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAccessTokenSpec,
                  "Enjin.Sdk.Model.AccessToken",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"accessToken":"xyz","expiresIn":1})");
END_DEFINE_SPEC(FAccessTokenSpec)

void FAccessTokenSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FAccessToken ClassUnderTest;

			// Assert
			TestFalse(TEXT("ExpiresIn is not set"), ClassUnderTest.GetExpiresIn().IsSet());
			TestFalse(TEXT("Token is not set"), ClassUnderTest.GetToken().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FAccessToken ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("ExpiresIn is set"), ClassUnderTest.GetExpiresIn().IsSet());
			TestTrue(TEXT("Token is set"), ClassUnderTest.GetToken().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FAccessToken ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume ExpiresIn is set"), ClassUnderTest.GetExpiresIn().IsSet());
			TestTrue(TEXT("Assume Token is set"), ClassUnderTest.GetToken().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("ExpiresIn is not set"), ClassUnderTest.GetExpiresIn().IsSet());
			TestFalse(TEXT("Token is not set"), ClassUnderTest.GetToken().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FAccessToken Lhs;
			const FAccessToken Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FAccessToken Lhs;
			const FAccessToken Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FAccessToken Lhs;
			FAccessToken Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FAccessToken Lhs;
			FAccessToken Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
