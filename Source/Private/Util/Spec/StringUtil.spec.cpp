// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "StringUtil.h"
#include "Misc/AutomationTest.h"

using namespace Enjin::Sdk::Util;

BEGIN_DEFINE_SPEC(FStringUtilSpec,
                  "Enjin.Sdk.Util.StringUtil",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FStringUtilSpec)

void FStringUtilSpec::Define()
{
	Describe("IsWhitespace", [this]()
	{
		It(TEXT("should return false for non-whitespace string"), [this]()
		{
			// Arrange
			const FString String = TEXT("abc xyz");

			// Act
			const bool Actual = FStringUtil::IsEmptyOrWhitespace(String);

			// Assert
			TestFalse(TEXT("Expect actual is false"), Actual);
		});

		It(TEXT("should return true for whitespace string"), [this]()
		{
			// Arrange
			const FString String = TEXT("   ");

			// Act
			const bool Actual = FStringUtil::IsEmptyOrWhitespace(String);

			// Assert
			TestTrue(TEXT("Expect actual is true"), Actual);
		});
	});

	Describe("IsEmptyOrWhitespace", [this]()
	{
		It(TEXT("should return false for non-empty non-whitespace string"), [this]()
		{
			// Arrange
			const FString String = TEXT("abc xyz");

			// Act
			const bool Actual = FStringUtil::IsEmptyOrWhitespace(String);

			// Assert
			TestFalse(TEXT("Expect actual is false"), Actual);
		});

		TArray<FString> Strings =
		{
			TEXT(""),
			TEXT("   "),
		};

		for (const FString& String : Strings)
		{
			It(FString::Printf(TEXT("should resolve true for '%s'"), *String), [this, String]()
			{
				// Act
				const bool Actual = FStringUtil::IsEmptyOrWhitespace(String);

				// Assert
				TestTrue(TEXT("Expect actual is true"), Actual);
			});
		}
	});
}
