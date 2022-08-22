// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/PaginationCursor.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPaginationCursorSpec,
                  "Enjin.Sdk.Model.PaginationCursor",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString Json = TEXT(
		R"({"currentPage":1,"from":1,"hasMorePages":true,"hasPages":true,"lastPage":1,"perPage":1,"to":1,"total":1})");
END_DEFINE_SPEC(FPaginationCursorSpec)

void FPaginationCursorSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FPaginationCursor ClassUnderTest;

			// Assert
			TestFalse(TEXT("CurrentPage is not set"), ClassUnderTest.GetCurrentPage().IsSet());
			TestFalse(TEXT("From is not set"), ClassUnderTest.GetFrom().IsSet());
			TestFalse(TEXT("HasMorePages is not set"), ClassUnderTest.GetHasMorePages().IsSet());
			TestFalse(TEXT("HasPages is not set"), ClassUnderTest.GetHasPages().IsSet());
			TestFalse(TEXT("LastPage is not set"), ClassUnderTest.GetLastPage().IsSet());
			TestFalse(TEXT("PerPage is not set"), ClassUnderTest.GetPerPage().IsSet());
			TestFalse(TEXT("To is not set"), ClassUnderTest.GetTo().IsSet());
			TestFalse(TEXT("Total is not set"), ClassUnderTest.GetTotal().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FPaginationCursor ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("CurrentPage is set"), ClassUnderTest.GetCurrentPage().IsSet());
			TestTrue(TEXT("From is set"), ClassUnderTest.GetFrom().IsSet());
			TestTrue(TEXT("HasMorePages is set"), ClassUnderTest.GetHasMorePages().IsSet());
			TestTrue(TEXT("HasPages is set"), ClassUnderTest.GetHasPages().IsSet());
			TestTrue(TEXT("LastPage is set"), ClassUnderTest.GetLastPage().IsSet());
			TestTrue(TEXT("PerPage is set"), ClassUnderTest.GetPerPage().IsSet());
			TestTrue(TEXT("To is set"), ClassUnderTest.GetTo().IsSet());
			TestTrue(TEXT("Total is set"), ClassUnderTest.GetTotal().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			const FString EmptyJson = TEXT("{}");
			FPaginationCursor ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume CurrentPage is set"), ClassUnderTest.GetCurrentPage().IsSet());
			TestTrue(TEXT("Assume From is set"), ClassUnderTest.GetFrom().IsSet());
			TestTrue(TEXT("Assume HasMorePages is set"), ClassUnderTest.GetHasMorePages().IsSet());
			TestTrue(TEXT("Assume HasPages is set"), ClassUnderTest.GetHasPages().IsSet());
			TestTrue(TEXT("Assume LastPage is set"), ClassUnderTest.GetLastPage().IsSet());
			TestTrue(TEXT("Assume PerPage is set"), ClassUnderTest.GetPerPage().IsSet());
			TestTrue(TEXT("Assume To is set"), ClassUnderTest.GetTo().IsSet());
			TestTrue(TEXT("Assume Total is set"), ClassUnderTest.GetTotal().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("CurrentPage is not set"), ClassUnderTest.GetCurrentPage().IsSet());
			TestFalse(TEXT("From is not set"), ClassUnderTest.GetFrom().IsSet());
			TestFalse(TEXT("HasMorePages is not set"), ClassUnderTest.GetHasMorePages().IsSet());
			TestFalse(TEXT("HasPages is not set"), ClassUnderTest.GetHasPages().IsSet());
			TestFalse(TEXT("LastPage is not set"), ClassUnderTest.GetLastPage().IsSet());
			TestFalse(TEXT("PerPage is not set"), ClassUnderTest.GetPerPage().IsSet());
			TestFalse(TEXT("To is not set"), ClassUnderTest.GetTo().IsSet());
			TestFalse(TEXT("Total is not set"), ClassUnderTest.GetTotal().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FPaginationCursor Lhs;
			const FPaginationCursor Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FPaginationCursor Lhs;
			const FPaginationCursor Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FPaginationCursor Lhs;
			FPaginationCursor Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FPaginationCursor Lhs;
			FPaginationCursor Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
