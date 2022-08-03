// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/TransactionField.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FTransactionFieldSpec,
                  "Enjin.Sdk.Model.TransactionField",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FTransactionFieldSpec)

void FTransactionFieldSpec::Define()
{
	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<ETransactionField, FString>> Params =
		{
			TPair<ETransactionField, FString>(ETransactionField::CreatedAt, TEXT("createdAt")),
			TPair<ETransactionField, FString>(ETransactionField::Id, TEXT("id")),
			TPair<ETransactionField, FString>(ETransactionField::State, TEXT("state")),
			TPair<ETransactionField, FString>(ETransactionField::Title, TEXT("title")),
			TPair<ETransactionField, FString>(ETransactionField::UpdatedAt, TEXT("updatedAt")),
		};

		for (const TPair<ETransactionField, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const ETransactionField EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
