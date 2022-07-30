// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetIdFormat.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetIdFormatSpec,
                  "Enjin.Sdk.Model.AssetIdFormat",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FAssetIdFormatSpec)

void FAssetIdFormatSpec::Define()
{
	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<EAssetIdFormat, FString>> Params =
		{
			TPair<EAssetIdFormat, FString>(EAssetIdFormat::Hex64, TEXT("hex64")),
			TPair<EAssetIdFormat, FString>(EAssetIdFormat::Hex256, TEXT("hex256")),
			TPair<EAssetIdFormat, FString>(EAssetIdFormat::UInt256, TEXT("uint256")),
		};

		for (const TPair<EAssetIdFormat, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const EAssetIdFormat EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
