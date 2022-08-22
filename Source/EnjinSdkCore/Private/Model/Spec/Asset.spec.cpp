// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Asset.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetSpec,
                  "Enjin.Sdk.Model.Asset",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"id":"1","name":"1","stateData":{},"configData":{},"variantMode":"NONE","variants":[],"createdAt":"1","updatedAt":"1"})");
END_DEFINE_SPEC(FAssetSpec)

void FAssetSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FAsset ClassUnderTest;

			// Assert
			TestFalse(TEXT("ConfigData is not set"), ClassUnderTest.GetConfigData().IsSet());
			TestFalse(TEXT("CreatedAt is not set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("Name is not set"), ClassUnderTest.GetName().IsSet());
			TestFalse(TEXT("StateData is not set"), ClassUnderTest.GetStateData().IsSet());
			TestFalse(TEXT("UpdatedAt is not set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestFalse(TEXT("VariantMode is not set"), ClassUnderTest.GetVariantMode().IsSet());
			TestFalse(TEXT("Variants is not set"), ClassUnderTest.GetVariants().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FAsset ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("ConfigData is set"), ClassUnderTest.GetConfigData().IsSet());
			TestTrue(TEXT("CreatedAt is set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestTrue(TEXT("Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("Name is set"), ClassUnderTest.GetName().IsSet());
			TestTrue(TEXT("StateData is set"), ClassUnderTest.GetStateData().IsSet());
			TestTrue(TEXT("UpdatedAt is set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestTrue(TEXT("VariantMode is set"), ClassUnderTest.GetVariantMode().IsSet());
			TestTrue(TEXT("Variants is set"), ClassUnderTest.GetVariants().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FAsset ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume ConfigData is set"), ClassUnderTest.GetConfigData().IsSet());
			TestTrue(TEXT("Assume CreatedAt is set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestTrue(TEXT("Assume Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("Assume Name is set"), ClassUnderTest.GetName().IsSet());
			TestTrue(TEXT("Assume StateData is set"), ClassUnderTest.GetStateData().IsSet());
			TestTrue(TEXT("Assume UpdatedAt is set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestTrue(TEXT("Assume VariantMode is set"), ClassUnderTest.GetVariantMode().IsSet());
			TestTrue(TEXT("Assume Variants is set"), ClassUnderTest.GetVariants().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("ConfigData is not set"), ClassUnderTest.GetConfigData().IsSet());
			TestFalse(TEXT("CreatedAt is not set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("Name is not set"), ClassUnderTest.GetName().IsSet());
			TestFalse(TEXT("StateData is not set"), ClassUnderTest.GetStateData().IsSet());
			TestFalse(TEXT("UpdatedAt is not set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestFalse(TEXT("VariantMode is not set"), ClassUnderTest.GetVariantMode().IsSet());
			TestFalse(TEXT("Variants is not set"), ClassUnderTest.GetVariants().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FAsset Lhs;
			const FAsset Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FAsset Lhs;
			const FAsset Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FAsset Lhs;
			FAsset Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FAsset Lhs;
			FAsset Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
