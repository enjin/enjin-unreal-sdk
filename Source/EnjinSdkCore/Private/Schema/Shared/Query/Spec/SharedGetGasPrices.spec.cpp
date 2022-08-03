// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/GetGasPrices.h"

using namespace Enjin::Sdk::Shared;

BEGIN_DEFINE_SPEC(FSharedGetGasPricesSpec,
                  "Enjin.Sdk.Shared.GetGasPrices",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString Json = TEXT(R"({})");

END_DEFINE_SPEC(FSharedGetGasPricesSpec)

void FSharedGetGasPricesSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce expected JSON"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FGetGasPrices ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true"), [this]()
		{
			// Arrange
			const FGetGasPrices Lhs;
			const FGetGasPrices Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
