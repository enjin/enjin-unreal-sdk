// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/GetTransaction.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;

BEGIN_DEFINE_SPEC(FSharedGetTransactionSpec,
                  "Enjin.Sdk.Shared.GetTransaction",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"id":1,"transactionId":"1"})");

	static FGetTransaction CreateDefaultClass()
	{
		return FGetTransaction().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
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

END_DEFINE_SPEC(FSharedGetTransactionSpec)

void FSharedGetTransactionSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FGetTransaction ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FGetTransaction ClassUnderTest = FGetTransaction()
			                                       .SetId(1)
			                                       .SetTransactionId(TEXT("1"));

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
			const FGetTransaction Lhs;
			const FGetTransaction Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FGetTransaction Lhs = CreateDefaultClass();
			const FGetTransaction Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FGetTransaction Lhs;
			const FGetTransaction Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FGetTransaction Lhs = CreateDefaultClass();
			const FGetTransaction Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
