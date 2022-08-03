// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/GetPlayers.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectGetPlayersSpec,
                  "Enjin.Sdk.Project.GetPlayers",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"filter":{}})");

	static FGetPlayers CreateDefaultClass()
	{
		return FGetPlayers().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                    .SetFilter({})
		                    .SetLinkingCodeQrSize(1)
		                    .SetPagination(1, 1)
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

END_DEFINE_SPEC(FProjectGetPlayersSpec)

void FProjectGetPlayersSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FGetPlayers ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FGetPlayers ClassUnderTest = FGetPlayers()
				.SetFilter({});

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
			const FGetPlayers Lhs;
			const FGetPlayers Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FGetPlayers Lhs = CreateDefaultClass();
			const FGetPlayers Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FGetPlayers Lhs;
			const FGetPlayers Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FGetPlayers Lhs = CreateDefaultClass();
			const FGetPlayers Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
