// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/GasPrices.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FGasPricesSpec,
                  "Enjin.Sdk.Model.GasPrices",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"safeLow":1.0,"average":1.0,"fast":1.0,"fastest":1.0})");
END_DEFINE_SPEC(FGasPricesSpec)

void FGasPricesSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FGasPrices ClassUnderTest;

			// Assert
			TestFalse(TEXT("Average is not set"), ClassUnderTest.GetAverage().IsSet());
			TestFalse(TEXT("Fast is not set"), ClassUnderTest.GetFast().IsSet());
			TestFalse(TEXT("Fastest is not set"), ClassUnderTest.GetFastest().IsSet());
			TestFalse(TEXT("SafeLow is not set"), ClassUnderTest.GetSafeLow().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FGasPrices ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("Average is set"), ClassUnderTest.GetAverage().IsSet());
			TestTrue(TEXT("Fast is set"), ClassUnderTest.GetFast().IsSet());
			TestTrue(TEXT("Fastest is set"), ClassUnderTest.GetFastest().IsSet());
			TestTrue(TEXT("SafeLow is set"), ClassUnderTest.GetSafeLow().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FGasPrices ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume Average is set"), ClassUnderTest.GetAverage().IsSet());
			TestTrue(TEXT("Assume Fast is set"), ClassUnderTest.GetFast().IsSet());
			TestTrue(TEXT("Assume Fastest is set"), ClassUnderTest.GetFastest().IsSet());
			TestTrue(TEXT("Assume SafeLow is set"), ClassUnderTest.GetSafeLow().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("Average is not set"), ClassUnderTest.GetAverage().IsSet());
			TestFalse(TEXT("Fast is not set"), ClassUnderTest.GetFast().IsSet());
			TestFalse(TEXT("Fastest is not set"), ClassUnderTest.GetFastest().IsSet());
			TestFalse(TEXT("SafeLow is not set"), ClassUnderTest.GetSafeLow().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FGasPrices Lhs;
			const FGasPrices Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FGasPrices Lhs;
			const FGasPrices Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FGasPrices Lhs;
			FGasPrices Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FGasPrices Lhs;
			FGasPrices Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
