﻿// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetTransferFeeSettingsInput.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetTransferFeeSettingsInputSpec,
                  "Enjin.Sdk.Model.AssetTransferFeeSettingsInput",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"assetId":"1","type":"NONE","value":"1"})");

	static FAssetTransferFeeSettingsInput CreateDefaultClass()
	{
		return FAssetTransferFeeSettingsInput().SetAssetId(TEXT("1"))
		                                       .SetType(EAssetTransferFeeType::None)
		                                       .SetValue(TEXT("1"));
	}

END_DEFINE_SPEC(FAssetTransferFeeSettingsInputSpec)

void FAssetTransferFeeSettingsInputSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FAssetTransferFeeSettingsInput ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FAssetTransferFeeSettingsInput ClassUnderTest = CreateDefaultClass();

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FAssetTransferFeeSettingsInput Lhs;
			const FAssetTransferFeeSettingsInput Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FAssetTransferFeeSettingsInput Lhs = CreateDefaultClass();
			const FAssetTransferFeeSettingsInput Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FAssetTransferFeeSettingsInput Lhs;
			const FAssetTransferFeeSettingsInput Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FAssetTransferFeeSettingsInput Lhs = CreateDefaultClass();
			const FAssetTransferFeeSettingsInput Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
