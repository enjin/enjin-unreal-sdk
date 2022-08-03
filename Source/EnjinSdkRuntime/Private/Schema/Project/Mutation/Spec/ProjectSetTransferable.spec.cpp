// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/SetTransferable.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectSetTransferableSpec,
                  "Enjin.Sdk.Project.SetTransferable",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"assetId":"1","assetIndex":"1","transferable":"PERMANENT"})");

	static FSetTransferable CreateDefaultClass()
	{
		return FSetTransferable().SetAssetId(TEXT("1"))
		                         .SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                         .SetAssetIndex(TEXT("1"))
		                         .SetEthAddress(TEXT("1"))
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

END_DEFINE_SPEC(FProjectSetTransferableSpec)

void FProjectSetTransferableSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FSetTransferable ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FSetTransferable ClassUnderTest = FSetTransferable()
			                                        .SetAssetId(TEXT("1"))
			                                        .SetAssetIndex(TEXT("1"))
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
			const FSetTransferable Lhs;
			const FSetTransferable Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FSetTransferable Lhs = CreateDefaultClass();
			const FSetTransferable Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FSetTransferable Lhs;
			const FSetTransferable Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FSetTransferable Lhs = CreateDefaultClass();
			const FSetTransferable Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
