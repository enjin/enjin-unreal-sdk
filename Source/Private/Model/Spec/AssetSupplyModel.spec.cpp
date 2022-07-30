// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetSupplyModel.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetSupplyModelSpec,
                  "Enjin.Sdk.Model.AssetSupplyModel",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FAssetSupplyModelSpec)

void FAssetSupplyModelSpec::Define()
{
	Describe("ToAssetSupplyModel returns correct value for given parameter", [this]()
	{
		TArray<TPair<FString, EAssetSupplyModel>> Params =
		{
			TPair<FString, EAssetSupplyModel>(TEXT(""), EAssetSupplyModel::Unknown),
			TPair<FString, EAssetSupplyModel>(TEXT("FIXED"), EAssetSupplyModel::Fixed),
			TPair<FString, EAssetSupplyModel>(TEXT("SETTABLE"), EAssetSupplyModel::Settable),
			TPair<FString, EAssetSupplyModel>(TEXT("INFINITE"), EAssetSupplyModel::Infinite),
			TPair<FString, EAssetSupplyModel>(TEXT("COLLAPSING"), EAssetSupplyModel::Collapsing),
			TPair<FString, EAssetSupplyModel>(TEXT("ANNUAL_VALUE"), EAssetSupplyModel::AnnualValue),
			TPair<FString, EAssetSupplyModel>(TEXT("ANNUAL_PERCENTAGE"), EAssetSupplyModel::AnnualPercentage),
		};

		for (const TPair<FString, EAssetSupplyModel> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Key), [this, Param]()
			{
				// Arrange
				const EAssetSupplyModel Expected = Param.Value;
				const FString Input = Param.Key;

				// Act
				const EAssetSupplyModel Actual = ToAssetSupplyModel(Input);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});

	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<EAssetSupplyModel, FString>> Params =
		{
			TPair<EAssetSupplyModel, FString>(EAssetSupplyModel::Unknown, TEXT("")),
			TPair<EAssetSupplyModel, FString>(EAssetSupplyModel::AnnualPercentage, TEXT("ANNUAL_PERCENTAGE")),
			TPair<EAssetSupplyModel, FString>(EAssetSupplyModel::AnnualValue, TEXT("ANNUAL_VALUE")),
			TPair<EAssetSupplyModel, FString>(EAssetSupplyModel::Collapsing, TEXT("COLLAPSING")),
			TPair<EAssetSupplyModel, FString>(EAssetSupplyModel::Fixed, TEXT("FIXED")),
			TPair<EAssetSupplyModel, FString>(EAssetSupplyModel::Infinite, TEXT("INFINITE")),
			TPair<EAssetSupplyModel, FString>(EAssetSupplyModel::Settable, TEXT("SETTABLE")),
		};

		for (const TPair<EAssetSupplyModel, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const EAssetSupplyModel EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
