// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Player/AdvancedSendAsset.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPlayerAdvancedSendAssetSpec,
                  "Enjin.Sdk.Player.AdvancedSendAsset",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"data":"1","transfers":[]})");

	static Enjin::Sdk::Player::FAdvancedSendAsset CreateDefaultClass()
	{
		return Enjin::Sdk::Player::FAdvancedSendAsset().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                                               .SetData(TEXT("1"))
		                                               .SetTransfers({})
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

END_DEFINE_SPEC(FPlayerAdvancedSendAssetSpec)

void FPlayerAdvancedSendAssetSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const Enjin::Sdk::Player::FAdvancedSendAsset ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const Enjin::Sdk::Player::FAdvancedSendAsset ClassUnderTest = Enjin::Sdk::Player::FAdvancedSendAsset()
			                                                              .SetData(TEXT("1"))
			                                                              .SetTransfers({});

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
			const Enjin::Sdk::Player::FAdvancedSendAsset Lhs;
			const Enjin::Sdk::Player::FAdvancedSendAsset Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FAdvancedSendAsset Lhs = CreateDefaultClass();
			const Enjin::Sdk::Player::FAdvancedSendAsset Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FAdvancedSendAsset Lhs;
			const Enjin::Sdk::Player::FAdvancedSendAsset Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FAdvancedSendAsset Lhs = CreateDefaultClass();
			const Enjin::Sdk::Player::FAdvancedSendAsset Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
