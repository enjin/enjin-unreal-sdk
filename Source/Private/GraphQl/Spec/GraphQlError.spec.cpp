// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "GraphQlError.h"
#include "Misc/AutomationTest.h"

using namespace Enjin::Sdk::GraphQl;

BEGIN_DEFINE_SPEC(FGraphQlErrorSpec,
                  "Enjin.Sdk.GraphQl.GraphQlError",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"code":1,"details":"xyz","locations":[{"key":1}],"message":"xyz"})");
END_DEFINE_SPEC(FGraphQlErrorSpec)

void FGraphQlErrorSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FGraphQlError ClassUnderTest;

			// Assert
			TestFalse(TEXT("Code is not set"), ClassUnderTest.GetCode().IsSet());
			TestFalse(TEXT("Details is not set"), ClassUnderTest.GetDetails().IsSet());
			TestFalse(TEXT("Locations is not set"), ClassUnderTest.GetLocations().IsSet());
			TestFalse(TEXT("Message is not set"), ClassUnderTest.GetMessage().IsSet());
		});

		It(TEXT("should be populated when given with data"), [this]()
		{
			// Arrange
			FGraphQlError ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("Code is set"), ClassUnderTest.GetCode().IsSet());
			TestTrue(TEXT("Details is set"), ClassUnderTest.GetDetails().IsSet());
			TestTrue(TEXT("Locations is set"), ClassUnderTest.GetLocations().IsSet());
			TestTrue(TEXT("Message is set"), ClassUnderTest.GetMessage().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FGraphQlError ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume Code is set"), ClassUnderTest.GetCode().IsSet());
			TestTrue(TEXT("Assume Details is set"), ClassUnderTest.GetDetails().IsSet());
			TestTrue(TEXT("Assume Locations is set"), ClassUnderTest.GetLocations().IsSet());
			TestTrue(TEXT("Assume Message is set"), ClassUnderTest.GetMessage().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("Code is not set"), ClassUnderTest.GetCode().IsSet());
			TestFalse(TEXT("Details is not set"), ClassUnderTest.GetDetails().IsSet());
			TestFalse(TEXT("Locations is not set"), ClassUnderTest.GetLocations().IsSet());
			TestFalse(TEXT("Message is not set"), ClassUnderTest.GetMessage().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FGraphQlError Lhs;
			const FGraphQlError Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FGraphQlError Lhs;
			const FGraphQlError Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FGraphQlError Lhs;
			FGraphQlError Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FGraphQlError Lhs;
			FGraphQlError Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
