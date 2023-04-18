// Copyright 2023 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/GetBalancesFromProjects.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;

BEGIN_DEFINE_SPEC(FSharedGetBalancesFromProjectsSpec,
                  "Enjin.Sdk.Shared.GetBalancesFromProjects",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"filter":{},"projects":[]})");

	static FGetBalancesFromProjects CreateDefaultClass()
	{
		return FGetBalancesFromProjects()
		       .SetBalIdFormat(EAssetIdFormat::Hex64)
		       .SetBalIndexFormat(EAssetIndexFormat::Hex64)
		       .SetFilter({})
		       .SetPagination(1, 1)
		       .SetProjects({})
		       .SetWithBalProjectUuid()
		       .SetWithBalWalletAddress();
	}

END_DEFINE_SPEC(FSharedGetBalancesFromProjectsSpec)

void FSharedGetBalancesFromProjectsSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FGetBalancesFromProjects ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FGetBalancesFromProjects ClassUnderTest = FGetBalancesFromProjects()
			                                                .SetFilter({})
			                                                .SetProjects({});

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
			const FGetBalancesFromProjects Lhs;
			const FGetBalancesFromProjects Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FGetBalancesFromProjects Lhs = CreateDefaultClass();
			const FGetBalancesFromProjects Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FGetBalancesFromProjects Lhs;
			const FGetBalancesFromProjects Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FGetBalancesFromProjects Lhs = CreateDefaultClass();
			const FGetBalancesFromProjects Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
