// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/CompleteTrade.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectCompleteTradeSpec,
                  "Enjin.Sdk.Project.CompleteTrade",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"tradeId":"1"})");

	static FCompleteTrade CreateDefaultClass()
	{
		return FCompleteTrade().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                       .SetEthAddress(TEXT("1"))
		                       .SetTradeId(TEXT("1"))
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

END_DEFINE_SPEC(FProjectCompleteTradeSpec)

void FProjectCompleteTradeSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FCompleteTrade ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FCompleteTrade ClassUnderTest = FCompleteTrade()
				.SetTradeId(TEXT("1"));

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
			const FCompleteTrade Lhs;
			const FCompleteTrade Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FCompleteTrade Lhs = CreateDefaultClass();
			const FCompleteTrade Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FCompleteTrade Lhs;
			const FCompleteTrade Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FCompleteTrade Lhs = CreateDefaultClass();
			const FCompleteTrade Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
