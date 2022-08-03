// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/SupplyModels.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FSupplyModelsSpec,
                  "Enjin.Sdk.Model.SupplyModels",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"fixed":"1","settable":"1","infinite":"1","collapsing":"1","annualValue":"1","annualPercentage":"1"})");
END_DEFINE_SPEC(FSupplyModelsSpec)

void FSupplyModelsSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FSupplyModels ClassUnderTest;

			// Assert
			TestFalse(TEXT("AnnualPercentage is not set"), ClassUnderTest.GetAnnualPercentage().IsSet());
			TestFalse(TEXT("AnnualValue is not set"), ClassUnderTest.GetAnnualValue().IsSet());
			TestFalse(TEXT("Collapsing is not set"), ClassUnderTest.GetCollapsing().IsSet());
			TestFalse(TEXT("Fixed is not set"), ClassUnderTest.GetFixed().IsSet());
			TestFalse(TEXT("Infinite is not set"), ClassUnderTest.GetInfinite().IsSet());
			TestFalse(TEXT("Settable is not set"), ClassUnderTest.GetSettable().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FSupplyModels ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("AnnualPercentage is set"), ClassUnderTest.GetAnnualPercentage().IsSet());
			TestTrue(TEXT("AnnualValue is set"), ClassUnderTest.GetAnnualValue().IsSet());
			TestTrue(TEXT("Collapsing is set"), ClassUnderTest.GetCollapsing().IsSet());
			TestTrue(TEXT("Fixed is set"), ClassUnderTest.GetFixed().IsSet());
			TestTrue(TEXT("Infinite is set"), ClassUnderTest.GetInfinite().IsSet());
			TestTrue(TEXT("Settable is set"), ClassUnderTest.GetSettable().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FSupplyModels ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume AnnualPercentage is set"), ClassUnderTest.GetAnnualPercentage().IsSet());
			TestTrue(TEXT("Assume AnnualValue is set"), ClassUnderTest.GetAnnualValue().IsSet());
			TestTrue(TEXT("Assume Collapsing is set"), ClassUnderTest.GetCollapsing().IsSet());
			TestTrue(TEXT("Assume Fixed is set"), ClassUnderTest.GetFixed().IsSet());
			TestTrue(TEXT("Assume Infinite is set"), ClassUnderTest.GetInfinite().IsSet());
			TestTrue(TEXT("Assume Settable is set"), ClassUnderTest.GetSettable().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("AnnualPercentage is not set"), ClassUnderTest.GetAnnualPercentage().IsSet());
			TestFalse(TEXT("AnnualValue is not set"), ClassUnderTest.GetAnnualValue().IsSet());
			TestFalse(TEXT("Collapsing is not set"), ClassUnderTest.GetCollapsing().IsSet());
			TestFalse(TEXT("Fixed is not set"), ClassUnderTest.GetFixed().IsSet());
			TestFalse(TEXT("Infinite is not set"), ClassUnderTest.GetInfinite().IsSet());
			TestFalse(TEXT("Settable is not set"), ClassUnderTest.GetSettable().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FSupplyModels Lhs;
			const FSupplyModels Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FSupplyModels Lhs;
			const FSupplyModels Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FSupplyModels Lhs;
			FSupplyModels Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FSupplyModels Lhs;
			FSupplyModels Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
