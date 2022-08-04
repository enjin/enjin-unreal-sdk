// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/AssetFragmentArguments.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;

class FTestableAssetFragmentArguments final : public TAssetFragmentArguments<FTestableAssetFragmentArguments>
{
public:
	FTestableAssetFragmentArguments() : TAssetFragmentArguments()
	{
	}
};

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetAssetIdFormat(EAssetIdFormat AssetIdFormat);

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithAssetBlocks();

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithAssetVariantMode();

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithAssetVariants();

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithConfigData();

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithCreator();

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithMeltDetails();

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithMetadataUri();

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithStateData();

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithSupplyDetails();

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithTransferSettings();

template FTestableAssetFragmentArguments&
TAssetFragmentArguments<FTestableAssetFragmentArguments>::SetWithVariantMetadata();

BEGIN_DEFINE_SPEC(FSharedAssetFragmentArgumentsSpec,
                  "Enjin.Sdk.Shared.AssetFragmentArguments",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"assetIdFormat":"hex64","withAssetBlocks":true,"withAssetVariantMode":true,"withAssetVariants":true,"withConfigData":true,"withCreator":true,"withMeltDetails":true,"withMetadataURI":true,"withStateData":true,"withSupplyDetails":true,"withTransferSettings":true,"withVariantMetadata":true})");

	static FTestableAssetFragmentArguments CreateDefaultClass()
	{
		return FTestableAssetFragmentArguments().SetAssetIdFormat(EAssetIdFormat::Hex64)
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

END_DEFINE_SPEC(FSharedAssetFragmentArgumentsSpec)

void FSharedAssetFragmentArgumentsSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FTestableAssetFragmentArguments ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FTestableAssetFragmentArguments ClassUnderTest = FTestableAssetFragmentArguments()
			                                                       .SetAssetIdFormat(EAssetIdFormat::Hex64)
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
			const FTestableAssetFragmentArguments Lhs;
			const FTestableAssetFragmentArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FTestableAssetFragmentArguments Lhs = CreateDefaultClass();
			const FTestableAssetFragmentArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTestableAssetFragmentArguments Lhs;
			const FTestableAssetFragmentArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FTestableAssetFragmentArguments Lhs = CreateDefaultClass();
			const FTestableAssetFragmentArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
