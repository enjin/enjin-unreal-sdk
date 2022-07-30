// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Player/GetWallet.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPlayerGetWalletSpec,
                  "Enjin.Sdk.Player.GetWallet",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString Json = TEXT(R"({})");

	static Enjin::Sdk::Player::FGetWallet CreateDefaultClass()
	{
		return Enjin::Sdk::Player::FGetWallet().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                                       .SetWithAssetBlocks()
		                                       .SetWithAssetVariantMode()
		                                       .SetWithAssetVariants()
		                                       .SetWithAssetsCreated()
		                                       .SetWithConfigData()
		                                       .SetWithCreator()
		                                       .SetWithMeltDetails()
		                                       .SetWithMetadataUri()
		                                       .SetWithStateData()
		                                       .SetWithSupplyDetails()
		                                       .SetWithTransferSettings()
		                                       .SetWithVariantMetadata();
	}

END_DEFINE_SPEC(FPlayerGetWalletSpec)

void FPlayerGetWalletSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce expected JSON"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const Enjin::Sdk::Player::FGetWallet ClassUnderTest = Enjin::Sdk::Player::FGetWallet();

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
			const Enjin::Sdk::Player::FGetWallet Lhs;
			const Enjin::Sdk::Player::FGetWallet Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FGetWallet Lhs = CreateDefaultClass();
			const Enjin::Sdk::Player::FGetWallet Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FGetWallet Lhs;
			const Enjin::Sdk::Player::FGetWallet Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FGetWallet Lhs = CreateDefaultClass();
			const Enjin::Sdk::Player::FGetWallet Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
