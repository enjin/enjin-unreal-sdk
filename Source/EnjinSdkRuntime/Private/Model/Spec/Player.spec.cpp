// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Player.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPlayerSpec,
                  "Enjin.Sdk.Model.Player",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"id":"1","linkingInfo":{},"wallet":{},"createdAt":"1","updatedAt":"1"})");
END_DEFINE_SPEC(FPlayerSpec)

void FPlayerSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FPlayer ClassUnderTest;

			// Assert
			TestFalse(TEXT("CreatedAt is not set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("LinkingInfo is not set"), ClassUnderTest.GetLinkingInfo().IsSet());
			TestFalse(TEXT("UpdatedAt is not set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestFalse(TEXT("Wallet is not set"), ClassUnderTest.GetWallet().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FPlayer ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("CreatedAt is set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestTrue(TEXT("Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("LinkingInfo is set"), ClassUnderTest.GetLinkingInfo().IsSet());
			TestTrue(TEXT("UpdatedAt is set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestTrue(TEXT("Wallet is set"), ClassUnderTest.GetWallet().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FPlayer ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume CreatedAt is set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestTrue(TEXT("Assume Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("Assume LinkingInfo is set"), ClassUnderTest.GetLinkingInfo().IsSet());
			TestTrue(TEXT("Assume UpdatedAt is set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestTrue(TEXT("Assume Wallet is set"), ClassUnderTest.GetWallet().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("CreatedAt is not set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("LinkingInfo is not set"), ClassUnderTest.GetLinkingInfo().IsSet());
			TestFalse(TEXT("UpdatedAt is not set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestFalse(TEXT("Wallet is not set"), ClassUnderTest.GetWallet().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FPlayer Lhs;
			const FPlayer Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FPlayer Lhs;
			const FPlayer Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FPlayer Lhs;
			FPlayer Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FPlayer Lhs;
			FPlayer Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
