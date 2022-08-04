// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetFilter.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetFilterSpec,
                  "Enjin.Sdk.Model.AssetFilter",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"and":[],"id_in":[],"id":"1","name_contains":"1","name_ends_with":"1","name_in":[],"name":"1","name_starts_with":"1","or":[],"wallet_in":[],"wallet":"1"})");

	static FAssetFilter CreateDefaultClass()
	{
		return FAssetFilter().SetAnd({})
		                     .SetIdIn({})
		                     .SetId(TEXT("1"))
		                     .SetNameContains(TEXT("1"))
		                     .SetNameEndsWith(TEXT("1"))
		                     .SetNameIn({})
		                     .SetName(TEXT("1"))
		                     .SetNameStartsWith(TEXT("1"))
		                     .SetOr({})
		                     .SetWalletIn({})
		                     .SetWallet(TEXT("1"));
	}

END_DEFINE_SPEC(FAssetFilterSpec)

void FAssetFilterSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FAssetFilter ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FAssetFilter ClassUnderTest = CreateDefaultClass();

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
			const FAssetFilter Lhs;
			const FAssetFilter Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FAssetFilter Lhs = CreateDefaultClass();
			const FAssetFilter Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FAssetFilter Lhs;
			const FAssetFilter Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FAssetFilter Lhs = CreateDefaultClass();
			const FAssetFilter Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
