// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetTransferFeeSettings.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetTransferFeeSettingsSpec,
                  "Enjin.Sdk.Model.AssetTransferFeeSettings",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"type":"NONE","assetId":"1","value":"1"})");
END_DEFINE_SPEC(FAssetTransferFeeSettingsSpec)

void FAssetTransferFeeSettingsSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FAssetTransferFeeSettings ClassUnderTest;

			// Assert
			TestFalse(TEXT("BlockHeight is not set"), ClassUnderTest.GetAssetId().IsSet());
			TestFalse(TEXT("Type is not set"), ClassUnderTest.GetType().IsSet());
			TestFalse(TEXT("Value is not set"), ClassUnderTest.GetValue().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FAssetTransferFeeSettings ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("BlockHeight is set"), ClassUnderTest.GetAssetId().IsSet());
			TestTrue(TEXT("Type is set"), ClassUnderTest.GetType().IsSet());
			TestTrue(TEXT("Value is set"), ClassUnderTest.GetValue().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FAssetTransferFeeSettings ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume BlockHeight is set"), ClassUnderTest.GetAssetId().IsSet());
			TestTrue(TEXT("Assume Type is set"), ClassUnderTest.GetType().IsSet());
			TestTrue(TEXT("Assume Value is set"), ClassUnderTest.GetValue().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("BlockHeight is not set"), ClassUnderTest.GetAssetId().IsSet());
			TestFalse(TEXT("Type is not set"), ClassUnderTest.GetType().IsSet());
			TestFalse(TEXT("Value is not set"), ClassUnderTest.GetValue().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FAssetTransferFeeSettings Lhs;
			const FAssetTransferFeeSettings Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FAssetTransferFeeSettings Lhs;
			const FAssetTransferFeeSettings Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FAssetTransferFeeSettings Lhs;
			FAssetTransferFeeSettings Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FAssetTransferFeeSettings Lhs;
			FAssetTransferFeeSettings Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
