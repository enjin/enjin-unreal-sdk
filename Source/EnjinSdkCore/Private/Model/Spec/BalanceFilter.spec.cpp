// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/BalanceFilter.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FBalanceFilterSpec,
                  "Enjin.Sdk.Model.BalanceFilter",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"and":[],"assetId_in":[],"assetId":"1","or":[],"value_is":"GREATER_THAN","value":1,"wallet_in":[],"wallet":"1"})");

	static FBalanceFilter CreateDefaultClass()
	{
		return FBalanceFilter().SetAnd({})
		                       .SetAssetIdIn({})
		                       .SetAssetId(TEXT("1"))
		                       .SetOr({})
		                       .SetValue(1)
		                       .SetValueIs(EOperator::GreaterThan)
		                       .SetWalletIn({})
		                       .SetWallet(TEXT("1"));
	}

END_DEFINE_SPEC(FBalanceFilterSpec)

void FBalanceFilterSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FBalanceFilter ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FBalanceFilter ClassUnderTest = CreateDefaultClass();

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
			const FBalanceFilter Lhs;
			const FBalanceFilter Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FBalanceFilter Lhs = CreateDefaultClass();
			const FBalanceFilter Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FBalanceFilter Lhs;
			const FBalanceFilter Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FBalanceFilter Lhs = CreateDefaultClass();
			const FBalanceFilter Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
