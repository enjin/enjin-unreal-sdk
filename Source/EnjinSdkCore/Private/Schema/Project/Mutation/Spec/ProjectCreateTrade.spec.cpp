// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/CreateTrade.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectCreateTradeSpec,
                  "Enjin.Sdk.Project.CreateTrade",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"askingAssets":[],"offeringAssets":[],"recipientAddress":"1"})");

	static FCreateTrade CreateDefaultClass()
	{
		return FCreateTrade().SetAskingAssets({})
		                     .SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                     .SetEthAddress(TEXT("1"))
		                     .SetOfferingAssets({})
		                     .SetRecipientAddress(TEXT("1"))
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

END_DEFINE_SPEC(FProjectCreateTradeSpec)

void FProjectCreateTradeSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FCreateTrade ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FCreateTrade ClassUnderTest = FCreateTrade()
			                                    .SetAskingAssets({})
			                                    .SetOfferingAssets({})
			                                    .SetRecipientAddress(TEXT("1"));

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
			const FCreateTrade Lhs;
			const FCreateTrade Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FCreateTrade Lhs = CreateDefaultClass();
			const FCreateTrade Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FCreateTrade Lhs;
			const FCreateTrade Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FCreateTrade Lhs = CreateDefaultClass();
			const FCreateTrade Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
