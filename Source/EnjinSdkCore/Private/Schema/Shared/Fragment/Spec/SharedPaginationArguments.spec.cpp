// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/PaginationArguments.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;

class FTestablePaginationArguments final : public TPaginationArguments<FTestablePaginationArguments>
{
public:
	FTestablePaginationArguments() : TPaginationArguments()
	{
	}
};

template FTestablePaginationArguments&
TPaginationArguments<FTestablePaginationArguments>::SetPagination(FPaginationInput Pagination);

template FTestablePaginationArguments&
TPaginationArguments<FTestablePaginationArguments>::SetPagination(const int32 Page, const int32 Limit);

BEGIN_DEFINE_SPEC(FSharedPaginationArgumentsSpec,
                  "Enjin.Sdk.Shared.PaginationArguments",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"pagination":{"limit":1,"page":1}})");

	static FTestablePaginationArguments CreateDefaultClass()
	{
		return FTestablePaginationArguments().SetPagination(1, 1);
	}

END_DEFINE_SPEC(FSharedPaginationArgumentsSpec)

void FSharedPaginationArgumentsSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FTestablePaginationArguments ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FTestablePaginationArguments ClassUnderTest = FTestablePaginationArguments()
				.SetPagination(1, 1);

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
			const FTestablePaginationArguments Lhs;
			const FTestablePaginationArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FTestablePaginationArguments Lhs = CreateDefaultClass();
			const FTestablePaginationArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTestablePaginationArguments Lhs;
			const FTestablePaginationArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FTestablePaginationArguments Lhs = CreateDefaultClass();
			const FTestablePaginationArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
