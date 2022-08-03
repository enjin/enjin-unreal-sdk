// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Player/UnlinkWallet.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler

BEGIN_DEFINE_SPEC(FPlayerUnlinkWalletSpec,
                  "Enjin.Sdk.Player.UnlinkWallet",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString Json = TEXT(R"({})");

	static Enjin::Sdk::Player::FUnlinkWallet CreateDefaultClass()
	{
		return Enjin::Sdk::Player::FUnlinkWallet();
	}

END_DEFINE_SPEC(FPlayerUnlinkWalletSpec)

void FPlayerUnlinkWalletSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce expected JSON"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const Enjin::Sdk::Player::FUnlinkWallet ClassUnderTest = Enjin::Sdk::Player::FUnlinkWallet();

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Player::FUnlinkWallet Lhs;
			const Enjin::Sdk::Player::FUnlinkWallet Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
