// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/UnlinkWallet.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler

BEGIN_DEFINE_SPEC(FProjectUnlinkWalletSpec,
                  "Enjin.Sdk.Project.UnlinkWallet",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"ethAddress":"1"})");

	static Enjin::Sdk::Project::FUnlinkWallet CreateDefaultClass()
	{
		return Enjin::Sdk::Project::FUnlinkWallet().SetEthAddress(TEXT("1"));
	}

END_DEFINE_SPEC(FProjectUnlinkWalletSpec)

void FProjectUnlinkWalletSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const Enjin::Sdk::Project::FUnlinkWallet ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const Enjin::Sdk::Project::FUnlinkWallet ClassUnderTest = Enjin::Sdk::Project::FUnlinkWallet()
				.SetEthAddress(TEXT("1"));

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
			const Enjin::Sdk::Project::FUnlinkWallet Lhs;
			const Enjin::Sdk::Project::FUnlinkWallet Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FUnlinkWallet Lhs = CreateDefaultClass();
			const Enjin::Sdk::Project::FUnlinkWallet Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FUnlinkWallet Lhs;
			const Enjin::Sdk::Project::FUnlinkWallet Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FUnlinkWallet Lhs = CreateDefaultClass();
			const Enjin::Sdk::Project::FUnlinkWallet Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
