// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/GetWallets.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectGetWalletsSpec,
                  "Enjin.Sdk.Project.GetWallets",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"ethAddresses":[],"userIds":[]})");

	static FGetWallets CreateDefaultClass()
	{
		return FGetWallets().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                    .SetEthAddresses({})
		                    .SetUserIds({})
		                    .SetWithAssetBlocks()
		                    .SetWithAssetVariantMode()
		                    .SetWithAssetVariants()
		                    .SetWithAssetsCreated()
		                    .SetWithConfigData()
		                    .SetWithCreator()
		                    .SetWithMeltDetails()
		                    .SetWithMetadataUri()
		                    .SetWithStateData()
		                    .SetWithSupplyDetails()
		                    .SetWithTransferSettings()
		                    .SetWithVariantMetadata();
	}

END_DEFINE_SPEC(FProjectGetWalletsSpec)

void FProjectGetWalletsSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FGetWallets ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FGetWallets ClassUnderTest = FGetWallets()
			                                   .SetEthAddresses({})
			                                   .SetUserIds({});

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
			const FGetWallets Lhs;
			const FGetWallets Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FGetWallets Lhs = CreateDefaultClass();
			const FGetWallets Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FGetWallets Lhs;
			const FGetWallets Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FGetWallets Lhs = CreateDefaultClass();
			const FGetWallets Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
