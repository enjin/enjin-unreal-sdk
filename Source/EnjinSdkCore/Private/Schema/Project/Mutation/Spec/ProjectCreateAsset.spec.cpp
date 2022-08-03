// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/CreateAsset.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectCreateAssetSpec,
                  "Enjin.Sdk.Project.CreateAsset",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"initialReserve":"1","meltFeeRatio":1,"meltValue":"1","name":"1","nonFungible":true,"supplyModel":"FIXED","totalSupply":"1","transferFeeSettings":{},"transferable":"PERMANENT"})");

	static FCreateAsset CreateDefaultClass()
	{
		return FCreateAsset().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                     .SetEthAddress(TEXT("1"))
		                     .SetInitialReserve(TEXT("1"))
		                     .SetMeltFeeRatio(1)
		                     .SetMeltValue(TEXT("1"))
		                     .SetName(TEXT("1"))
		                     .SetNonFungible(true)
		                     .SetSupplyModel(EAssetSupplyModel::Fixed)
		                     .SetTotalSupply(TEXT("1"))
		                     .SetTransferFeeSettings({})
		                     .SetTransferable(EAssetTransferable::Permanent)
		                     .SetWithAssetData()
		                     .SetWithBlockchainData()
		                     .SetWithEncodedData()
		                     .SetWithError()
		                     .SetWithLogEvent()
		                     .SetWithMeta()
		                     .SetWithNonce()
		                     .SetWithReceiptLogs()
		                     .SetWithReceipt()
		                     .SetWithSignedTxs()
		                     .SetWithState()
		                     .SetWithTransactionProjectUuid();
	}

END_DEFINE_SPEC(FProjectCreateAssetSpec)

void FProjectCreateAssetSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FCreateAsset ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FCreateAsset ClassUnderTest = FCreateAsset()
			                                    .SetInitialReserve(TEXT("1"))
			                                    .SetMeltFeeRatio(1)
			                                    .SetMeltValue(TEXT("1"))
			                                    .SetName(TEXT("1"))
			                                    .SetNonFungible(true)
			                                    .SetSupplyModel(EAssetSupplyModel::Fixed)
			                                    .SetTotalSupply(TEXT("1"))
			                                    .SetTransferFeeSettings({})
			                                    .SetTransferable(EAssetTransferable::Permanent);

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
			const FCreateAsset Lhs;
			const FCreateAsset Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FCreateAsset Lhs = CreateDefaultClass();
			const FCreateAsset Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FCreateAsset Lhs;
			const FCreateAsset Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FCreateAsset Lhs = CreateDefaultClass();
			const FCreateAsset Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
