// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetConfigData.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetConfigDataSpec,
                  "Enjin.Sdk.Model.AssetConfigData",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"meltFeeRatio":1,"meltFeeMaxRatio":1,"meltValue":"1","metadataURI":"1","transferable":"PERMANENT","transferFeeSettings":{}})");
END_DEFINE_SPEC(FAssetConfigDataSpec)

void FAssetConfigDataSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FAssetConfigData ClassUnderTest;

			// Assert
			TestFalse(TEXT("MeltFeeMaxRatio is not set"), ClassUnderTest.GetMeltFeeMaxRatio().IsSet());
			TestFalse(TEXT("MeltFeeRatio is not set"), ClassUnderTest.GetMeltFeeRatio().IsSet());
			TestFalse(TEXT("MeltValue is not set"), ClassUnderTest.GetMeltValue().IsSet());
			TestFalse(TEXT("MetadataUri is not set"), ClassUnderTest.GetMetadataUri().IsSet());
			TestFalse(TEXT("TransferFeeSettings is not set"), ClassUnderTest.GetTransferFeeSettings().IsSet());
			TestFalse(TEXT("Transferable is not set"), ClassUnderTest.GetTransferable().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FAssetConfigData ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("MeltFeeMaxRatio is set"), ClassUnderTest.GetMeltFeeMaxRatio().IsSet());
			TestTrue(TEXT("MeltFeeRatio is set"), ClassUnderTest.GetMeltFeeRatio().IsSet());
			TestTrue(TEXT("MeltValue is set"), ClassUnderTest.GetMeltValue().IsSet());
			TestTrue(TEXT("MetadataUri is set"), ClassUnderTest.GetMetadataUri().IsSet());
			TestTrue(TEXT("TransferFeeSettings is set"), ClassUnderTest.GetTransferFeeSettings().IsSet());
			TestTrue(TEXT("Transferable is set"), ClassUnderTest.GetTransferable().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FAssetConfigData ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume MeltFeeMaxRatio is set"), ClassUnderTest.GetMeltFeeMaxRatio().IsSet());
			TestTrue(TEXT("Assume MeltFeeRatio is set"), ClassUnderTest.GetMeltFeeRatio().IsSet());
			TestTrue(TEXT("Assume MeltValue is set"), ClassUnderTest.GetMeltValue().IsSet());
			TestTrue(TEXT("Assume MetadataUri is set"), ClassUnderTest.GetMetadataUri().IsSet());
			TestTrue(TEXT("Assume TransferFeeSettings is set"), ClassUnderTest.GetTransferFeeSettings().IsSet());
			TestTrue(TEXT("Assume Transferable is set"), ClassUnderTest.GetTransferable().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("MeltFeeMaxRatio is not set"), ClassUnderTest.GetMeltFeeMaxRatio().IsSet());
			TestFalse(TEXT("MeltFeeRatio is not set"), ClassUnderTest.GetMeltFeeRatio().IsSet());
			TestFalse(TEXT("MeltValue is not set"), ClassUnderTest.GetMeltValue().IsSet());
			TestFalse(TEXT("MetadataUri is not set"), ClassUnderTest.GetMetadataUri().IsSet());
			TestFalse(TEXT("TransferFeeSettings is not set"), ClassUnderTest.GetTransferFeeSettings().IsSet());
			TestFalse(TEXT("Transferable is not set"), ClassUnderTest.GetTransferable().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FAssetConfigData Lhs;
			const FAssetConfigData Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FAssetConfigData Lhs;
			const FAssetConfigData Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FAssetConfigData Lhs;
			FAssetConfigData Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FAssetConfigData Lhs;
			FAssetConfigData Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
