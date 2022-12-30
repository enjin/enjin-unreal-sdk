// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/UpdateName.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectUpdateNameSpec,
                  "Enjin.Sdk.Project.UpdateName",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"assetId":"1","name":"1"})");

	static FUpdateName CreateDefaultClass()
	{
		return FUpdateName().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                    .SetAssetId(TEXT("1"))
		                    .SetEthAddress(TEXT("1"))
		                    .SetName(TEXT("1"))
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

END_DEFINE_SPEC(FProjectUpdateNameSpec)

void FProjectUpdateNameSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FUpdateName ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FUpdateName ClassUnderTest = FUpdateName()
			                                   .SetAssetId(TEXT("1"))
			                                   .SetName(TEXT("1"));

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
			const FUpdateName Lhs;
			const FUpdateName Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FUpdateName Lhs = CreateDefaultClass();
			const FUpdateName Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FUpdateName Lhs;
			const FUpdateName Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FUpdateName Lhs = CreateDefaultClass();
			const FUpdateName Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
