// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/CancelTransaction.h"

using namespace Enjin::Sdk::Shared;

BEGIN_DEFINE_SPEC(FSharedCancelTransactionSpec,
                  "Enjin.Sdk.Shared.CancelTransaction",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"id":1})");

	static FCancelTransaction CreateDefaultClass()
	{
		return FCancelTransaction().SetId(1);
	}

END_DEFINE_SPEC(FSharedCancelTransactionSpec)

void FSharedCancelTransactionSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FCancelTransaction ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FCancelTransaction ClassUnderTest = FCancelTransaction()
				.SetId(1);

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FCancelTransaction Lhs;
			const FCancelTransaction Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FCancelTransaction Lhs = CreateDefaultClass();
			const FCancelTransaction Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FCancelTransaction Lhs;
			const FCancelTransaction Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FCancelTransaction Lhs = CreateDefaultClass();
			const FCancelTransaction Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
