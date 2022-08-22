// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/GetBalances.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;

BEGIN_DEFINE_SPEC(FSharedGetBalancesSpec,
                  "Enjin.Sdk.Shared.GetBalances",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"filter":{}})");

	static FGetBalances CreateDefaultClass()
	{
		return FGetBalances()
		       .SetBalIdFormat(EAssetIdFormat::Hex64)
		       .SetBalIndexFormat(EAssetIndexFormat::Hex64)
		       .SetFilter({})
		       .SetPagination(1, 1)
		       .SetWithBalProjectUuid()
		       .SetWithBalWalletAddress();
	}

END_DEFINE_SPEC(FSharedGetBalancesSpec)

void FSharedGetBalancesSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FGetBalances ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FGetBalances ClassUnderTest = FGetBalances()
				.SetFilter({});

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
			const FGetBalances Lhs;
			const FGetBalances Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FGetBalances Lhs = CreateDefaultClass();
			const FGetBalances Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FGetBalances Lhs;
			const FGetBalances Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FGetBalances Lhs = CreateDefaultClass();
			const FGetBalances Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
