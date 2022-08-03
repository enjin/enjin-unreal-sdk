// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Transaction.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FTransactionSpec,
                  "Enjin.Sdk.Model.Transaction",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"id":1,"transactionId":"1","title":"1","contract":"1","type":"APPROVE","value":"1","retryState":"1","state":"PENDING","accepted":true,"projectWallet":true,"blockchainData":{},"project":{},"asset":{},"createdAt":"1","updatedAt":"1","wallet":{}})");
END_DEFINE_SPEC(FTransactionSpec)

void FTransactionSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FTransaction ClassUnderTest;

			// Assert
			TestFalse(TEXT("Accepted is not set"), ClassUnderTest.GetAccepted().IsSet());
			TestFalse(TEXT("Asset is not set"), ClassUnderTest.GetAsset().IsSet());
			TestFalse(TEXT("BlockchainData is not set"), ClassUnderTest.GetBlockchainData().IsSet());
			TestFalse(TEXT("Contract is not set"), ClassUnderTest.GetContract().IsSet());
			TestFalse(TEXT("CreatedAt is not set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("Project is not set"), ClassUnderTest.GetProject().IsSet());
			TestFalse(TEXT("ProjectWallet is not set"), ClassUnderTest.GetProjectWallet().IsSet());
			TestFalse(TEXT("RetryState is not set"), ClassUnderTest.GetRetryState().IsSet());
			TestFalse(TEXT("State is not set"), ClassUnderTest.GetState().IsSet());
			TestFalse(TEXT("Title is not set"), ClassUnderTest.GetTitle().IsSet());
			TestFalse(TEXT("TransactionId is not set"), ClassUnderTest.GetTransactionId().IsSet());
			TestFalse(TEXT("Type is not set"), ClassUnderTest.GetType().IsSet());
			TestFalse(TEXT("UpdatedAt is not set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestFalse(TEXT("Value is not set"), ClassUnderTest.GetValue().IsSet());
			TestFalse(TEXT("Wallet is not set"), ClassUnderTest.GetWallet().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FTransaction ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("Accepted is set"), ClassUnderTest.GetAccepted().IsSet());
			TestTrue(TEXT("Asset is set"), ClassUnderTest.GetAsset().IsSet());
			TestTrue(TEXT("BlockchainData is set"), ClassUnderTest.GetBlockchainData().IsSet());
			TestTrue(TEXT("Contract is set"), ClassUnderTest.GetContract().IsSet());
			TestTrue(TEXT("CreatedAt is set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestTrue(TEXT("Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("Project is set"), ClassUnderTest.GetProject().IsSet());
			TestTrue(TEXT("ProjectWallet is set"), ClassUnderTest.GetProjectWallet().IsSet());
			TestTrue(TEXT("RetryState is set"), ClassUnderTest.GetRetryState().IsSet());
			TestTrue(TEXT("State is set"), ClassUnderTest.GetState().IsSet());
			TestTrue(TEXT("Title is set"), ClassUnderTest.GetTitle().IsSet());
			TestTrue(TEXT("TransactionId is set"), ClassUnderTest.GetTransactionId().IsSet());
			TestTrue(TEXT("Type is set"), ClassUnderTest.GetType().IsSet());
			TestTrue(TEXT("UpdatedAt is set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestTrue(TEXT("Value is set"), ClassUnderTest.GetValue().IsSet());
			TestTrue(TEXT("Wallet is set"), ClassUnderTest.GetWallet().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FTransaction ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume Accepted is set"), ClassUnderTest.GetAccepted().IsSet());
			TestTrue(TEXT("Assume Asset is set"), ClassUnderTest.GetAsset().IsSet());
			TestTrue(TEXT("Assume BlockchainData is set"), ClassUnderTest.GetBlockchainData().IsSet());
			TestTrue(TEXT("Assume Contract is set"), ClassUnderTest.GetContract().IsSet());
			TestTrue(TEXT("Assume CreatedAt is set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestTrue(TEXT("Assume Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("Assume Project is set"), ClassUnderTest.GetProject().IsSet());
			TestTrue(TEXT("Assume ProjectWallet is set"), ClassUnderTest.GetProjectWallet().IsSet());
			TestTrue(TEXT("Assume RetryState is set"), ClassUnderTest.GetRetryState().IsSet());
			TestTrue(TEXT("Assume State is set"), ClassUnderTest.GetState().IsSet());
			TestTrue(TEXT("Assume Title is set"), ClassUnderTest.GetTitle().IsSet());
			TestTrue(TEXT("Assume TransactionId is set"), ClassUnderTest.GetTransactionId().IsSet());
			TestTrue(TEXT("Assume Type is set"), ClassUnderTest.GetType().IsSet());
			TestTrue(TEXT("Assume UpdatedAt is set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestTrue(TEXT("Assume Value is set"), ClassUnderTest.GetValue().IsSet());
			TestTrue(TEXT("Assume Wallet is set"), ClassUnderTest.GetWallet().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("Accepted is not set"), ClassUnderTest.GetAccepted().IsSet());
			TestFalse(TEXT("Asset is not set"), ClassUnderTest.GetAsset().IsSet());
			TestFalse(TEXT("BlockchainData is not set"), ClassUnderTest.GetBlockchainData().IsSet());
			TestFalse(TEXT("Contract is not set"), ClassUnderTest.GetContract().IsSet());
			TestFalse(TEXT("CreatedAt is not set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("Project is not set"), ClassUnderTest.GetProject().IsSet());
			TestFalse(TEXT("ProjectWallet is not set"), ClassUnderTest.GetProjectWallet().IsSet());
			TestFalse(TEXT("RetryState is not set"), ClassUnderTest.GetRetryState().IsSet());
			TestFalse(TEXT("State is not set"), ClassUnderTest.GetState().IsSet());
			TestFalse(TEXT("Title is not set"), ClassUnderTest.GetTitle().IsSet());
			TestFalse(TEXT("TransactionId is not set"), ClassUnderTest.GetTransactionId().IsSet());
			TestFalse(TEXT("Type is not set"), ClassUnderTest.GetType().IsSet());
			TestFalse(TEXT("UpdatedAt is not set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestFalse(TEXT("Value is not set"), ClassUnderTest.GetValue().IsSet());
			TestFalse(TEXT("Wallet is not set"), ClassUnderTest.GetWallet().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FTransaction Lhs;
			const FTransaction Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FTransaction Lhs;
			const FTransaction Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTransaction Lhs;
			FTransaction Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FTransaction Lhs;
			FTransaction Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
