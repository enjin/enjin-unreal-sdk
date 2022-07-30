// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetTransferFeeType.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetTransferFeeTypeSpec,
                  "Enjin.Sdk.Model.AssetTransferFeeType",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FAssetTransferFeeTypeSpec)

void FAssetTransferFeeTypeSpec::Define()
{
	Describe("ToAssetTransferFeeType returns correct value for given parameter", [this]()
	{
		TArray<TPair<FString, EAssetTransferFeeType>> Params =
		{
			TPair<FString, EAssetTransferFeeType>(TEXT(""), EAssetTransferFeeType::Unknown),
			TPair<FString, EAssetTransferFeeType>(TEXT("NONE"), EAssetTransferFeeType::None),
			TPair<FString, EAssetTransferFeeType>(TEXT("PER_TRANSFER"), EAssetTransferFeeType::PerTransfer),
			TPair<FString, EAssetTransferFeeType>(TEXT("PER_CRYPTO_ITEM"), EAssetTransferFeeType::PerCryptoItem),
			TPair<FString, EAssetTransferFeeType>(TEXT("RATIO_CUT"), EAssetTransferFeeType::RatioCut),
			TPair<FString, EAssetTransferFeeType>(TEXT("RATIO_EXTRA"), EAssetTransferFeeType::RatioExtra),
		};

		for (const TPair<FString, EAssetTransferFeeType> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Key), [this, Param]()
			{
				// Arrange
				const EAssetTransferFeeType Expected = Param.Value;
				const FString Input = Param.Key;

				// Act
				const EAssetTransferFeeType Actual = ToAssetTransferFeeType(Input);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});

	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<EAssetTransferFeeType, FString>> Params =
		{
			TPair<EAssetTransferFeeType, FString>(EAssetTransferFeeType::Unknown, TEXT("")),
			TPair<EAssetTransferFeeType, FString>(EAssetTransferFeeType::None, TEXT("NONE")),
			TPair<EAssetTransferFeeType, FString>(EAssetTransferFeeType::PerTransfer, TEXT("PER_TRANSFER")),
			TPair<EAssetTransferFeeType, FString>(EAssetTransferFeeType::PerCryptoItem, TEXT("PER_CRYPTO_ITEM")),
			TPair<EAssetTransferFeeType, FString>(EAssetTransferFeeType::RatioCut, TEXT("RATIO_CUT")),
			TPair<EAssetTransferFeeType, FString>(EAssetTransferFeeType::RatioExtra, TEXT("RATIO_EXTRA")),
		};

		for (const TPair<EAssetTransferFeeType, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const EAssetTransferFeeType EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
