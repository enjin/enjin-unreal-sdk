// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/TransactionLog.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FTransactionLogSpec,
                  "Enjin.Sdk.Model.TransactionLog",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"blockNumber":1,"address":"1","transactionHash":"1","data":[],"topics":[],"event":{}})");
END_DEFINE_SPEC(FTransactionLogSpec)

void FTransactionLogSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FTransactionLog ClassUnderTest;

			// Assert
			TestFalse(TEXT("Address is not set"), ClassUnderTest.GetAddress().IsSet());
			TestFalse(TEXT("BlockNumber is not set"), ClassUnderTest.GetBlockNumber().IsSet());
			TestFalse(TEXT("Data is not set"), ClassUnderTest.GetData().IsSet());
			TestFalse(TEXT("Event is not set"), ClassUnderTest.GetEvent().IsSet());
			TestFalse(TEXT("Topics is not set"), ClassUnderTest.GetTopics().IsSet());
			TestFalse(TEXT("TransactionHash is not set"), ClassUnderTest.GetTransactionHash().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FTransactionLog ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("Address is set"), ClassUnderTest.GetAddress().IsSet());
			TestTrue(TEXT("BlockNumber is set"), ClassUnderTest.GetBlockNumber().IsSet());
			TestTrue(TEXT("Data is set"), ClassUnderTest.GetData().IsSet());
			TestTrue(TEXT("Event is set"), ClassUnderTest.GetEvent().IsSet());
			TestTrue(TEXT("Topics is set"), ClassUnderTest.GetTopics().IsSet());
			TestTrue(TEXT("TransactionHash is set"), ClassUnderTest.GetTransactionHash().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FTransactionLog ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume Address is set"), ClassUnderTest.GetAddress().IsSet());
			TestTrue(TEXT("Assume BlockNumber is set"), ClassUnderTest.GetBlockNumber().IsSet());
			TestTrue(TEXT("Assume Data is set"), ClassUnderTest.GetData().IsSet());
			TestTrue(TEXT("Assume Event is set"), ClassUnderTest.GetEvent().IsSet());
			TestTrue(TEXT("Assume Topics is set"), ClassUnderTest.GetTopics().IsSet());
			TestTrue(TEXT("Assume TransactionHash is set"), ClassUnderTest.GetTransactionHash().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("Address is not set"), ClassUnderTest.GetAddress().IsSet());
			TestFalse(TEXT("BlockNumber is not set"), ClassUnderTest.GetBlockNumber().IsSet());
			TestFalse(TEXT("Data is not set"), ClassUnderTest.GetData().IsSet());
			TestFalse(TEXT("Event is not set"), ClassUnderTest.GetEvent().IsSet());
			TestFalse(TEXT("Topics is not set"), ClassUnderTest.GetTopics().IsSet());
			TestFalse(TEXT("TransactionHash is not set"), ClassUnderTest.GetTransactionHash().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FTransactionLog Lhs;
			const FTransactionLog Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FTransactionLog Lhs;
			const FTransactionLog Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTransactionLog Lhs;
			FTransactionLog Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FTransactionLog Lhs;
			FTransactionLog Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
