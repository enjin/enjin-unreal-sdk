// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/GetAsset.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;

BEGIN_DEFINE_SPEC(FSharedGetAssetSpec,
                  "Enjin.Sdk.Shared.GetAsset",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"id":"1"})");

	static FGetAsset CreateDefaultClass()
	{
		return FGetAsset().SetAssetIdFormat(EAssetIdFormat::Hex64)
		                  .SetId(TEXT("1"))
		                  .SetWithAssetBlocks()
		                  .SetWithAssetVariantMode()
		                  .SetWithAssetVariants()
		                  .SetWithConfigData()
		                  .SetWithCreator()
		                  .SetWithMeltDetails()
		                  .SetWithMetadataUri()
		                  .SetWithStateData()
		                  .SetWithSupplyDetails()
		                  .SetWithTransferSettings()
		                  .SetWithVariantMetadata();
	}

END_DEFINE_SPEC(FSharedGetAssetSpec)

void FSharedGetAssetSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FGetAsset ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FGetAsset ClassUnderTest = FGetAsset().SetId(TEXT("1"));

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
			const FGetAsset Lhs;
			const FGetAsset Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FGetAsset Lhs = CreateDefaultClass();
			const FGetAsset Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FGetAsset Lhs;
			const FGetAsset Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FGetAsset Lhs = CreateDefaultClass();
			const FGetAsset Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
