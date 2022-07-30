// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/SetMeltFee.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectSetMeltFeeSpec,
                  "Enjin.Sdk.Project.SetMeltFee",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"assetId":"1","meltFee":1})");

	static FSetMeltFee CreateDefaultClass()
	{
		return FSetMeltFee().SetAssetId(TEXT("1"))
		                    .SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                    .SetEthAddress(TEXT("1"))
		                    .SetMeltFee(1)
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

END_DEFINE_SPEC(FProjectSetMeltFeeSpec)

void FProjectSetMeltFeeSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FSetMeltFee ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FSetMeltFee ClassUnderTest = FSetMeltFee()
			                                   .SetAssetId(TEXT("1"))
			                                   .SetMeltFee(1);

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
			const FSetMeltFee Lhs;
			const FSetMeltFee Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FSetMeltFee Lhs = CreateDefaultClass();
			const FSetMeltFee Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FSetMeltFee Lhs;
			const FSetMeltFee Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FSetMeltFee Lhs = CreateDefaultClass();
			const FSetMeltFee Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
