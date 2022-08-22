// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/TransactionReceipt.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FTransactionReceiptSpec,
                  "Enjin.Sdk.Model.TransactionReceipt",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"blockHash":"1","blockNumber":1,"cumulativeGasUsed":1,"gasUsed":1,"from":"1","to":"1","transactionHash":"1","transactionIndex":1,"status":true,"logs":[]})");
END_DEFINE_SPEC(FTransactionReceiptSpec)

void FTransactionReceiptSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FTransactionReceipt ClassUnderTest;

			// Assert
			TestFalse(TEXT("BlockHash is not set"), ClassUnderTest.GetBlockHash().IsSet());
			TestFalse(TEXT("BlockNumber is not set"), ClassUnderTest.GetBlockNumber().IsSet());
			TestFalse(TEXT("CumulativeGasUsed is not set"), ClassUnderTest.GetCumulativeGasUsed().IsSet());
			TestFalse(TEXT("From is not set"), ClassUnderTest.GetFrom().IsSet());
			TestFalse(TEXT("GasUsed is not set"), ClassUnderTest.GetGasUsed().IsSet());
			TestFalse(TEXT("Logs is not set"), ClassUnderTest.GetLogs().IsSet());
			TestFalse(TEXT("Status is not set"), ClassUnderTest.GetStatus().IsSet());
			TestFalse(TEXT("To is not set"), ClassUnderTest.GetTo().IsSet());
			TestFalse(TEXT("TransactionHash is not set"), ClassUnderTest.GetTransactionHash().IsSet());
			TestFalse(TEXT("TransactionIndex is not set"), ClassUnderTest.GetTransactionIndex().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FTransactionReceipt ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("BlockHash is set"), ClassUnderTest.GetBlockHash().IsSet());
			TestTrue(TEXT("BlockNumber is set"), ClassUnderTest.GetBlockNumber().IsSet());
			TestTrue(TEXT("CumulativeGasUsed is set"), ClassUnderTest.GetCumulativeGasUsed().IsSet());
			TestTrue(TEXT("From is set"), ClassUnderTest.GetFrom().IsSet());
			TestTrue(TEXT("GasUsed is set"), ClassUnderTest.GetGasUsed().IsSet());
			TestTrue(TEXT("Logs is set"), ClassUnderTest.GetLogs().IsSet());
			TestTrue(TEXT("Status is set"), ClassUnderTest.GetStatus().IsSet());
			TestTrue(TEXT("To is set"), ClassUnderTest.GetTo().IsSet());
			TestTrue(TEXT("TransactionHash is set"), ClassUnderTest.GetTransactionHash().IsSet());
			TestTrue(TEXT("TransactionIndex is set"), ClassUnderTest.GetTransactionIndex().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FTransactionReceipt ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume BlockHash is set"), ClassUnderTest.GetBlockHash().IsSet());
			TestTrue(TEXT("Assume BlockNumber is set"), ClassUnderTest.GetBlockNumber().IsSet());
			TestTrue(TEXT("Assume CumulativeGasUsed is set"), ClassUnderTest.GetCumulativeGasUsed().IsSet());
			TestTrue(TEXT("Assume From is set"), ClassUnderTest.GetFrom().IsSet());
			TestTrue(TEXT("Assume GasUsed is set"), ClassUnderTest.GetGasUsed().IsSet());
			TestTrue(TEXT("Assume Logs is set"), ClassUnderTest.GetLogs().IsSet());
			TestTrue(TEXT("Assume Status is set"), ClassUnderTest.GetStatus().IsSet());
			TestTrue(TEXT("Assume To is set"), ClassUnderTest.GetTo().IsSet());
			TestTrue(TEXT("Assume TransactionHash is set"), ClassUnderTest.GetTransactionHash().IsSet());
			TestTrue(TEXT("Assume TransactionIndex is set"), ClassUnderTest.GetTransactionIndex().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("BlockHash is not set"), ClassUnderTest.GetBlockHash().IsSet());
			TestFalse(TEXT("BlockNumber is not set"), ClassUnderTest.GetBlockNumber().IsSet());
			TestFalse(TEXT("CumulativeGasUsed is not set"), ClassUnderTest.GetCumulativeGasUsed().IsSet());
			TestFalse(TEXT("From is not set"), ClassUnderTest.GetFrom().IsSet());
			TestFalse(TEXT("GasUsed is not set"), ClassUnderTest.GetGasUsed().IsSet());
			TestFalse(TEXT("Logs is not set"), ClassUnderTest.GetLogs().IsSet());
			TestFalse(TEXT("Status is not set"), ClassUnderTest.GetStatus().IsSet());
			TestFalse(TEXT("To is not set"), ClassUnderTest.GetTo().IsSet());
			TestFalse(TEXT("TransactionHash is not set"), ClassUnderTest.GetTransactionHash().IsSet());
			TestFalse(TEXT("TransactionIndex is not set"), ClassUnderTest.GetTransactionIndex().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FTransactionReceipt Lhs;
			const FTransactionReceipt Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FTransactionReceipt Lhs;
			const FTransactionReceipt Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTransactionReceipt Lhs;
			FTransactionReceipt Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FTransactionReceipt Lhs;
			FTransactionReceipt Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
