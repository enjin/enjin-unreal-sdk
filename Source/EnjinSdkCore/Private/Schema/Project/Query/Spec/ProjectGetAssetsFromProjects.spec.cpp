// Copyright 2023 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/GetAssetsFromProjects.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectGetAssetsFromProjectsSpec,
                  "Enjin.Sdk.Project.GetAssetsFromProjects",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"filter":{},"projects":[],"sort":{}})");

	static FGetAssetsFromProjects CreateDefaultClass()
	{
		return FGetAssetsFromProjects().SetAssetIdFormat(EAssetIdFormat::Hex64)
		                               .SetFilter({})
		                               .SetPagination(1, 1)
		                               .SetProjects({})
		                               .SetSort({})
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

END_DEFINE_SPEC(FProjectGetAssetsFromProjectsSpec)

void FProjectGetAssetsFromProjectsSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FGetAssetsFromProjects ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FGetAssetsFromProjects ClassUnderTest = FGetAssetsFromProjects()
			                                              .SetFilter({})
			                                              .SetProjects({})
			                                              .SetSort({});

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
			const FGetAssetsFromProjects Lhs;
			const FGetAssetsFromProjects Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FGetAssetsFromProjects Lhs = CreateDefaultClass();
			const FGetAssetsFromProjects Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FGetAssetsFromProjects Lhs;
			const FGetAssetsFromProjects Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FGetAssetsFromProjects Lhs = CreateDefaultClass();
			const FGetAssetsFromProjects Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
