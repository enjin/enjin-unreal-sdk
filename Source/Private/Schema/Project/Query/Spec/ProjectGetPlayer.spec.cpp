// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/GetPlayer.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FProjectGetPlayerSpec,
                  "Enjin.Sdk.Project.GetPlayer",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"id":"1"})");

	static Enjin::Sdk::Project::FGetPlayer CreateDefaultClass()
	{
		return Enjin::Sdk::Project::FGetPlayer().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                                        .SetId(TEXT("1"))
		                                        .SetLinkingCodeQrSize(1)
		                                        .SetWithAssetBlocks()
		                                        .SetWithAssetVariantMode()
		                                        .SetWithAssetVariants()
		                                        .SetWithAssetsCreated()
		                                        .SetWithConfigData()
		                                        .SetWithCreator()
		                                        .SetWithLinkingInfo()
		                                        .SetWithMeltDetails()
		                                        .SetWithMetadataUri()
		                                        .SetWithPlayerWallet()
		                                        .SetWithStateData()
		                                        .SetWithSupplyDetails()
		                                        .SetWithTransferSettings()
		                                        .SetWithVariantMetadata();
	}

END_DEFINE_SPEC(FProjectGetPlayerSpec)

void FProjectGetPlayerSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const Enjin::Sdk::Project::FGetPlayer ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const Enjin::Sdk::Project::FGetPlayer ClassUnderTest = Enjin::Sdk::Project::FGetPlayer()
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
			const Enjin::Sdk::Project::FGetPlayer Lhs;
			const Enjin::Sdk::Project::FGetPlayer Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FGetPlayer Lhs = CreateDefaultClass();
			const Enjin::Sdk::Project::FGetPlayer Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FGetPlayer Lhs;
			const Enjin::Sdk::Project::FGetPlayer Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FGetPlayer Lhs = CreateDefaultClass();
			const Enjin::Sdk::Project::FGetPlayer Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
