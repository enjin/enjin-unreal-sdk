// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/SetTransferFee.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectSetTransferFeeSpec,
                  "Enjin.Sdk.Project.SetTransferFee",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"assetId":"1","transferFee":"1"})");

	static FSetTransferFee CreateDefaultClass()
	{
		return FSetTransferFee().SetAssetId(TEXT("1"))
		                        .SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                        .SetEthAddress(TEXT("1"))
		                        .SetTransferFee(TEXT("1"))
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

END_DEFINE_SPEC(FProjectSetTransferFeeSpec)

void FProjectSetTransferFeeSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FSetTransferFee ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FSetTransferFee ClassUnderTest = FSetTransferFee()
			                                       .SetAssetId(TEXT("1"))
			                                       .SetTransferFee(TEXT("1"));

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
			const FSetTransferFee Lhs;
			const FSetTransferFee Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FSetTransferFee Lhs = CreateDefaultClass();
			const FSetTransferFee Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FSetTransferFee Lhs;
			const FSetTransferFee Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FSetTransferFee Lhs = CreateDefaultClass();
			const FSetTransferFee Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
