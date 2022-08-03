// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetVariant.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetVariantSpec,
                  "Enjin.Sdk.Model.AssetVariant",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"id":1,"assetId":"1","variantMetadata":{},"usageCount":1,"createdAt":"1","updatedAt":"1"})");
END_DEFINE_SPEC(FAssetVariantSpec)

void FAssetVariantSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FAssetVariant ClassUnderTest;

			// Assert
			TestFalse(TEXT("AssetId is not set"), ClassUnderTest.GetAssetId().IsSet());
			TestFalse(TEXT("CreatedAt is not set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("UpdatedAt is not set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestFalse(TEXT("UsageCount is not set"), ClassUnderTest.GetUsageCount().IsSet());
			TestFalse(TEXT("VariantMetadata is not set"), ClassUnderTest.GetVariantMetadata().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FAssetVariant ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("AssetId is set"), ClassUnderTest.GetAssetId().IsSet());
			TestTrue(TEXT("CreatedAt is set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestTrue(TEXT("Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("UpdatedAt is set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestTrue(TEXT("UsageCount is set"), ClassUnderTest.GetUsageCount().IsSet());
			TestTrue(TEXT("VariantMetadata is set"), ClassUnderTest.GetVariantMetadata().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FAssetVariant ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume AssetId is set"), ClassUnderTest.GetAssetId().IsSet());
			TestTrue(TEXT("Assume CreatedAt is set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestTrue(TEXT("Assume Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("Assume UpdatedAt is set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestTrue(TEXT("Assume UsageCount is set"), ClassUnderTest.GetUsageCount().IsSet());
			TestTrue(TEXT("Assume VariantMetadata is set"), ClassUnderTest.GetVariantMetadata().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("AssetId is not set"), ClassUnderTest.GetAssetId().IsSet());
			TestFalse(TEXT("CreatedAt is not set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("UpdatedAt is not set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestFalse(TEXT("UsageCount is not set"), ClassUnderTest.GetUsageCount().IsSet());
			TestFalse(TEXT("VariantMetadata is not set"), ClassUnderTest.GetVariantMetadata().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FAssetVariant Lhs;
			const FAssetVariant Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FAssetVariant Lhs;
			const FAssetVariant Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FAssetVariant Lhs;
			FAssetVariant Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FAssetVariant Lhs;
			FAssetVariant Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
