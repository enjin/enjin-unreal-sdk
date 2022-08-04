// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Operator.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FOperatorSpec,
                  "Enjin.Sdk.Model.Operator",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FOperatorSpec)

void FOperatorSpec::Define()
{
	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<EOperator, FString>> Params =
		{
			TPair<EOperator, FString>(EOperator::GreaterThan, TEXT("GREATER_THAN")),
			TPair<EOperator, FString>(EOperator::GreaterThanOrEqual, TEXT("GREATER_THAN_OR_EQUAL")),
			TPair<EOperator, FString>(EOperator::LessThan, TEXT("LESS_THAN")),
			TPair<EOperator, FString>(EOperator::LessThanOrEqual, TEXT("LESS_THAN_OR_EQUAL")),
		};

		for (const TPair<EOperator, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const EOperator EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
