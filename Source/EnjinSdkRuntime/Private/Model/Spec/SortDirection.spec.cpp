// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/SortDirection.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FSortDirectionSpec,
                  "Enjin.Sdk.Model.SortDirection",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FSortDirectionSpec)

void FSortDirectionSpec::Define()
{
	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<ESortDirection, FString>> Params =
		{
			TPair<ESortDirection, FString>(ESortDirection::Ascending, TEXT("asc")),
			TPair<ESortDirection, FString>(ESortDirection::Descending, TEXT("desc")),
		};

		for (const TPair<ESortDirection, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const ESortDirection EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
