// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Player/ApproveMaxEnj.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPlayerApproveMaxEnjSpec,
                  "Enjin.Sdk.Player.ApproveMaxEnj",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString Json = TEXT(R"({})");

	static Enjin::Sdk::Player::FApproveMaxEnj CreateDefaultClass()
	{
		return Enjin::Sdk::Player::FApproveMaxEnj().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
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

END_DEFINE_SPEC(FPlayerApproveMaxEnjSpec)

void FPlayerApproveMaxEnjSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce expected JSON"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const Enjin::Sdk::Player::FApproveMaxEnj ClassUnderTest;

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
			const Enjin::Sdk::Player::FApproveMaxEnj Lhs;
			const Enjin::Sdk::Player::FApproveMaxEnj Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FApproveMaxEnj Lhs = CreateDefaultClass();
			const Enjin::Sdk::Player::FApproveMaxEnj Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FApproveMaxEnj Lhs;
			const Enjin::Sdk::Player::FApproveMaxEnj Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FApproveMaxEnj Lhs = CreateDefaultClass();
			const Enjin::Sdk::Player::FApproveMaxEnj Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
