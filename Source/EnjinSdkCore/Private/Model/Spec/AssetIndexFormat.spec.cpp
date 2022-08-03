// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetIndexFormat.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetIndexFormatSpec,
                  "Enjin.Sdk.Model.AssetIndexFormat",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FAssetIndexFormatSpec)

void FAssetIndexFormatSpec::Define()
{
	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<EAssetIndexFormat, FString>> Params =
		{
			TPair<EAssetIndexFormat, FString>(EAssetIndexFormat::Hex64, TEXT("hex64")),
			TPair<EAssetIndexFormat, FString>(EAssetIndexFormat::UInt64, TEXT("uint64")),
		};

		for (const TPair<EAssetIndexFormat, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const EAssetIndexFormat EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
