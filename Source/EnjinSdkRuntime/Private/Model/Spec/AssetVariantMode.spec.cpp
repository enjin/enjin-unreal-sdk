// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetVariantMode.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetVariantModeSpec,
                  "Enjin.Sdk.Model.AssetVariantMode",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FAssetVariantModeSpec)

void FAssetVariantModeSpec::Define()
{
	Describe("ToAssetVariantMode returns correct value for given parameter", [this]()
	{
		TArray<TPair<FString, EAssetVariantMode>> Params =
		{
			TPair<FString, EAssetVariantMode>(TEXT(""), EAssetVariantMode::Unknown),
			TPair<FString, EAssetVariantMode>(TEXT("NONE"), EAssetVariantMode::None),
			TPair<FString, EAssetVariantMode>(TEXT("BEAM"), EAssetVariantMode::Beam),
			TPair<FString, EAssetVariantMode>(TEXT("ONCE"), EAssetVariantMode::Once),
			TPair<FString, EAssetVariantMode>(TEXT("ALWAYS"), EAssetVariantMode::Always),
		};

		for (const TPair<FString, EAssetVariantMode> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Key), [this, Param]()
			{
				// Arrange
				const EAssetVariantMode Expected = Param.Value;
				const FString Input = Param.Key;

				// Act
				const EAssetVariantMode Actual = ToAssetVariantMode(Input);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
