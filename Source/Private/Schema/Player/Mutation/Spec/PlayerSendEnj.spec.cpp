// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Player/SendEnj.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPlayerSendEnjSpec,
                  "Enjin.Sdk.Player.SendEnj",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"recipientAddress":"1","value":"1"})");

	static Enjin::Sdk::Player::FSendEnj CreateDefaultClass()
	{
		return Enjin::Sdk::Player::FSendEnj().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                                     .SetRecipientAddress(TEXT("1"))
		                                     .SetValue(TEXT("1"))
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

END_DEFINE_SPEC(FPlayerSendEnjSpec)

void FPlayerSendEnjSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const Enjin::Sdk::Player::FSendEnj ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const Enjin::Sdk::Player::FSendEnj ClassUnderTest = Enjin::Sdk::Player::FSendEnj()
			                                                    .SetRecipientAddress(TEXT("1"))
			                                                    .SetValue(TEXT("1"));

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
			const Enjin::Sdk::Player::FSendEnj Lhs;
			const Enjin::Sdk::Player::FSendEnj Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FSendEnj Lhs = CreateDefaultClass();
			const Enjin::Sdk::Player::FSendEnj Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FSendEnj Lhs;
			const Enjin::Sdk::Player::FSendEnj Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FSendEnj Lhs = CreateDefaultClass();
			const Enjin::Sdk::Player::FSendEnj Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
