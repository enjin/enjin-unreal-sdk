// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/TransactionFilter.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FTransactionFilterSpec,
                  "Enjin.Sdk.Model.TransactionFilter",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"and":[],"assetId_in":[],"assetId":"1","id_in":[],"id":"1","or":[],"state_in":[],"state":"PENDING","transactionId_in":[],"transactionId":"1","type_in":[],"type":"APPROVE","value_gt":1,"value_gte":1,"value_lt":1,"value_lte":1,"value":1,"wallet_in":[],"wallet":"1"})");

	static FTransactionFilter CreateDefaultClass()
	{
		return FTransactionFilter().SetAnd({})
		                           .SetAssetIdIn({})
		                           .SetAssetId(TEXT("1"))
		                           .SetIdIn({})
		                           .SetId(TEXT("1"))
		                           .SetOr({})
		                           .SetStateIn({})
		                           .SetState(ETransactionState::Pending)
		                           .SetTransactionIdIn({})
		                           .SetTransactionId(TEXT("1"))
		                           .SetTypeIn({})
		                           .SetType(ETransactionType::Approve)
		                           .SetValueGreaterThan(1)
		                           .SetValueGreaterThanOrEqual(1)
		                           .SetValueLessThan(1)
		                           .SetValueLessThanOrEqual(1)
		                           .SetValue(1)
		                           .SetWalletIn({})
		                           .SetWallet(TEXT("1"));
	}

END_DEFINE_SPEC(FTransactionFilterSpec)

void FTransactionFilterSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FTransactionFilter ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FTransactionFilter ClassUnderTest = CreateDefaultClass();

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
			const FTransactionFilter Lhs;
			const FTransactionFilter Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FTransactionFilter Lhs = CreateDefaultClass();
			const FTransactionFilter Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTransactionFilter Lhs;
			const FTransactionFilter Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FTransactionFilter Lhs = CreateDefaultClass();
			const FTransactionFilter Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
