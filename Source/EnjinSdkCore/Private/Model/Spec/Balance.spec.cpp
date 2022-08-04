// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Balance.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FBalanceSpec,
                  "Enjin.Sdk.Model.Balance",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"id":"1","index":"1","value":1,"project":{},"wallet":{}})");
END_DEFINE_SPEC(FBalanceSpec)

void FBalanceSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FBalance ClassUnderTest;

			// Assert
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("Index is not set"), ClassUnderTest.GetIndex().IsSet());
			TestFalse(TEXT("Value is not set"), ClassUnderTest.GetValue().IsSet());
			TestFalse(TEXT("Wallet is not set"), ClassUnderTest.GetWallet().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FBalance ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("Index is set"), ClassUnderTest.GetIndex().IsSet());
			TestTrue(TEXT("Value is set"), ClassUnderTest.GetValue().IsSet());
			TestTrue(TEXT("Wallet is set"), ClassUnderTest.GetWallet().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FBalance ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("Assume Index is set"), ClassUnderTest.GetIndex().IsSet());
			TestTrue(TEXT("Assume Value is set"), ClassUnderTest.GetValue().IsSet());
			TestTrue(TEXT("Assume Wallet is set"), ClassUnderTest.GetWallet().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("Index is not set"), ClassUnderTest.GetIndex().IsSet());
			TestFalse(TEXT("Value is not set"), ClassUnderTest.GetValue().IsSet());
			TestFalse(TEXT("Wallet is not set"), ClassUnderTest.GetWallet().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FBalance Lhs;
			const FBalance Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FBalance Lhs;
			const FBalance Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FBalance Lhs;
			FBalance Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FBalance Lhs;
			FBalance Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
