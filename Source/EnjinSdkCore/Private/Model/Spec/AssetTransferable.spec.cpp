// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetTransferable.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetTransferableSpec,
                  "Enjin.Sdk.Model.AssetTransferable",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FAssetTransferableSpec)

void FAssetTransferableSpec::Define()
{
	Describe("DeserializeAssetTransferable returns correct value for given parameter", [this]()
	{
		TArray<TPair<FString, EAssetTransferable>> Params =
		{
			TPair<FString, EAssetTransferable>(TEXT(""), EAssetTransferable::Unknown),
			TPair<FString, EAssetTransferable>(TEXT("PERMANENT"), EAssetTransferable::Permanent),
			TPair<FString, EAssetTransferable>(TEXT("TEMPORARY"), EAssetTransferable::Temporary),
			TPair<FString, EAssetTransferable>(TEXT("BOUND"), EAssetTransferable::Bound),
		};

		for (const TPair<FString, EAssetTransferable> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Key), [this, Param]()
			{
				// Arrange
				const EAssetTransferable Expected = Param.Value;
				const FString Input = Param.Key;

				// Act
				const EAssetTransferable Actual = ToAssetTransferable(Input);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});

	Describe("SerializeAssetTransferable returns correct value for given parameter", [this]()
	{
		TArray<TPair<EAssetTransferable, FString>> Params =
		{
			TPair<EAssetTransferable, FString>(EAssetTransferable::Unknown, TEXT("")),
			TPair<EAssetTransferable, FString>(EAssetTransferable::Permanent, TEXT("PERMANENT")),
			TPair<EAssetTransferable, FString>(EAssetTransferable::Temporary, TEXT("TEMPORARY")),
			TPair<EAssetTransferable, FString>(EAssetTransferable::Bound, TEXT("BOUND")),
		};

		for (const TPair<EAssetTransferable, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const EAssetTransferable EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
