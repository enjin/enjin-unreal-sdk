// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/InvalidateAssetMetadata.h"

using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectInvalidateAssetMetadataSpec,
                  "Enjin.Sdk.Project.InvalidateAssetMetadata",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"id":"1"})");

	static FInvalidateAssetMetadata CreateDefaultClass()
	{
		return FInvalidateAssetMetadata().SetId(TEXT("1"));
	}

END_DEFINE_SPEC(FProjectInvalidateAssetMetadataSpec)

void FProjectInvalidateAssetMetadataSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FInvalidateAssetMetadata ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FInvalidateAssetMetadata ClassUnderTest = FInvalidateAssetMetadata()
				.SetId(TEXT("1"));

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
			const FInvalidateAssetMetadata Lhs;
			const FInvalidateAssetMetadata Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FInvalidateAssetMetadata Lhs = CreateDefaultClass();
			const FInvalidateAssetMetadata Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FInvalidateAssetMetadata Lhs;
			const FInvalidateAssetMetadata Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FInvalidateAssetMetadata Lhs = CreateDefaultClass();
			const FInvalidateAssetMetadata Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
