// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Wallet.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FWalletSpec,
                  "Enjin.Sdk.Model.Wallet",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"ethAddress":"1","enjAllowance":1.0,"enjBalance":1.0,"ethBalance":1.0,"assetsCreated":[{}],"balances":[{}],"transactions":[{}]})");

END_DEFINE_SPEC(FWalletSpec)

void FWalletSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FWallet ClassUnderTest;

			// Assert
			TestFalse(TEXT("AssetsCreated is not set"), ClassUnderTest.GetAssetsCreated().IsSet());
			TestFalse(TEXT("Balances is not set"), ClassUnderTest.GetBalances().IsSet());
			TestFalse(TEXT("EnjAllowance is not set"), ClassUnderTest.GetEnjAllowance().IsSet());
			TestFalse(TEXT("EnjBalance is not set"), ClassUnderTest.GetEnjBalance().IsSet());
			TestFalse(TEXT("EthAddress is not set"), ClassUnderTest.GetEthAddress().IsSet());
			TestFalse(TEXT("EthBalance is not set"), ClassUnderTest.GetEthBalance().IsSet());
			TestFalse(TEXT("Transactions is not set"), ClassUnderTest.GetTransactions().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FWallet ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("AssetsCreated is set"), ClassUnderTest.GetAssetsCreated().IsSet());
			TestTrue(TEXT("Balances is set"), ClassUnderTest.GetBalances().IsSet());
			TestTrue(TEXT("EnjAllowance is set"), ClassUnderTest.GetEnjAllowance().IsSet());
			TestTrue(TEXT("EnjBalance is set"), ClassUnderTest.GetEnjBalance().IsSet());
			TestTrue(TEXT("EthAddress is set"), ClassUnderTest.GetEthAddress().IsSet());
			TestTrue(TEXT("EthBalance is set"), ClassUnderTest.GetEthBalance().IsSet());
			TestTrue(TEXT("Transactions is set"), ClassUnderTest.GetTransactions().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FWallet ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume AssetsCreated is set"), ClassUnderTest.GetAssetsCreated().IsSet());
			TestTrue(TEXT("Assume Balances is set"), ClassUnderTest.GetBalances().IsSet());
			TestTrue(TEXT("Assume EnjAllowance is set"), ClassUnderTest.GetEnjAllowance().IsSet());
			TestTrue(TEXT("Assume EnjBalance is set"), ClassUnderTest.GetEnjBalance().IsSet());
			TestTrue(TEXT("Assume EthAddress is set"), ClassUnderTest.GetEthAddress().IsSet());
			TestTrue(TEXT("Assume EthBalance is set"), ClassUnderTest.GetEthBalance().IsSet());
			TestTrue(TEXT("Assume Transactions is set"), ClassUnderTest.GetTransactions().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("AssetsCreated is not set"), ClassUnderTest.GetAssetsCreated().IsSet());
			TestFalse(TEXT("Balances is not set"), ClassUnderTest.GetBalances().IsSet());
			TestFalse(TEXT("EnjAllowance is not set"), ClassUnderTest.GetEnjAllowance().IsSet());
			TestFalse(TEXT("EnjBalance is not set"), ClassUnderTest.GetEnjBalance().IsSet());
			TestFalse(TEXT("EthAddress is not set"), ClassUnderTest.GetEthAddress().IsSet());
			TestFalse(TEXT("EthBalance is not set"), ClassUnderTest.GetEthBalance().IsSet());
			TestFalse(TEXT("Transactions is not set"), ClassUnderTest.GetTransactions().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FWallet Lhs;
			const FWallet Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FWallet Lhs;
			const FWallet Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FWallet Lhs;
			FWallet Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FWallet Lhs;
			FWallet Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
