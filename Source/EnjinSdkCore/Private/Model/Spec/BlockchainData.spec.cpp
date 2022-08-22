// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/BlockchainData.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FBlockchainDataSpec,
                  "Enjin.Sdk.Model.BlockchainData",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"encodedData":"1","signedTransaction":"1","signedBackupTransaction":"1","signedCancelTransaction":"1","receipt":{},"error":"1","nonce":"1"})");
END_DEFINE_SPEC(FBlockchainDataSpec)

void FBlockchainDataSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FBlockchainData ClassUnderTest;

			// Assert
			TestFalse(TEXT("EncodedData is not set"), ClassUnderTest.GetEncodedData().IsSet());
			TestFalse(TEXT("Error is not set"), ClassUnderTest.GetError().IsSet());
			TestFalse(TEXT("Nonce is not set"), ClassUnderTest.GetNonce().IsSet());
			TestFalse(TEXT("Receipt is not set"), ClassUnderTest.GetReceipt().IsSet());
			TestFalse(TEXT("SignedBackupTransaction is not set"), ClassUnderTest.GetSignedBackupTransaction().IsSet());
			TestFalse(TEXT("SignedCancelTransaction is not set"), ClassUnderTest.GetSignedCancelTransaction().IsSet());
			TestFalse(TEXT("SignedTransaction is not set"), ClassUnderTest.GetSignedTransaction().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FBlockchainData ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("EncodedData is set"), ClassUnderTest.GetEncodedData().IsSet());
			TestTrue(TEXT("Error is set"), ClassUnderTest.GetError().IsSet());
			TestTrue(TEXT("Nonce is set"), ClassUnderTest.GetNonce().IsSet());
			TestTrue(TEXT("Receipt is set"), ClassUnderTest.GetReceipt().IsSet());
			TestTrue(TEXT("SignedBackupTransaction is set"), ClassUnderTest.GetSignedBackupTransaction().IsSet());
			TestTrue(TEXT("SignedCancelTransaction is set"), ClassUnderTest.GetSignedCancelTransaction().IsSet());
			TestTrue(TEXT("SignedTransaction is set"), ClassUnderTest.GetSignedTransaction().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FBlockchainData ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume EncodedData is set"), ClassUnderTest.GetEncodedData().IsSet());
			TestTrue(TEXT("Assume Error is set"), ClassUnderTest.GetError().IsSet());
			TestTrue(TEXT("Assume Nonce is set"), ClassUnderTest.GetNonce().IsSet());
			TestTrue(TEXT("Assume Receipt is set"), ClassUnderTest.GetReceipt().IsSet());
			TestTrue(TEXT("Assume SignedBackupTransaction is set"),
			         ClassUnderTest.GetSignedBackupTransaction().IsSet());
			TestTrue(TEXT("Assume SignedCancelTransaction is set"),
			         ClassUnderTest.GetSignedCancelTransaction().IsSet());
			TestTrue(TEXT("Assume SignedTransaction is set"), ClassUnderTest.GetSignedTransaction().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("EncodedData is not set"), ClassUnderTest.GetEncodedData().IsSet());
			TestFalse(TEXT("Error is not set"), ClassUnderTest.GetError().IsSet());
			TestFalse(TEXT("Nonce is not set"), ClassUnderTest.GetNonce().IsSet());
			TestFalse(TEXT("Receipt is not set"), ClassUnderTest.GetReceipt().IsSet());
			TestFalse(TEXT("SignedBackupTransaction is not set"), ClassUnderTest.GetSignedBackupTransaction().IsSet());
			TestFalse(TEXT("SignedCancelTransaction is not set"), ClassUnderTest.GetSignedCancelTransaction().IsSet());
			TestFalse(TEXT("SignedTransaction is not set"), ClassUnderTest.GetSignedTransaction().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FBlockchainData Lhs;
			const FBlockchainData Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FBlockchainData Lhs;
			const FBlockchainData Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FBlockchainData Lhs;
			FBlockchainData Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FBlockchainData Lhs;
			FBlockchainData Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
