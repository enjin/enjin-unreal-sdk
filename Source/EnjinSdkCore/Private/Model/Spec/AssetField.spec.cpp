// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetField.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetFieldSpec,
                  "Enjin.Sdk.Model.AssetField",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FAssetFieldSpec)

void FAssetFieldSpec::Define()
{
	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<EAssetField, FString>> Params =
		{
			TPair<EAssetField, FString>(EAssetField::Id, TEXT("id")),
			TPair<EAssetField, FString>(EAssetField::Name, TEXT("name")),
			TPair<EAssetField, FString>(EAssetField::CirculatingSupply, TEXT("circulatingSupply")),
			TPair<EAssetField, FString>(EAssetField::NonFungible, TEXT("nonFungible")),
			TPair<EAssetField, FString>(EAssetField::Reserve, TEXT("reserve")),
			TPair<EAssetField, FString>(EAssetField::TotalSupply, TEXT("totalSupply")),
			TPair<EAssetField, FString>(EAssetField::CreatedAt, TEXT("createdAt")),
		};

		for (const TPair<EAssetField, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const EAssetField EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
