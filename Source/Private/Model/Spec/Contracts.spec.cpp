// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Contracts.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FContractsSpec,
                  "Enjin.Sdk.Model.Contracts",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"enj":"1","cryptoItems":"1","platformRegistry":"1","supplyModels":{}})");
END_DEFINE_SPEC(FContractsSpec)

void FContractsSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FContracts ClassUnderTest;

			// Assert
			TestFalse(TEXT("CryptoItems is not set"), ClassUnderTest.GetCryptoItems().IsSet());
			TestFalse(TEXT("Enj is not set"), ClassUnderTest.GetEnj().IsSet());
			TestFalse(TEXT("PlatformRegistry is not set"), ClassUnderTest.GetPlatformRegistry().IsSet());
			TestFalse(TEXT("SupplyModels is not set"), ClassUnderTest.GetSupplyModels().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FContracts ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("CryptoItems is set"), ClassUnderTest.GetCryptoItems().IsSet());
			TestTrue(TEXT("Enj is set"), ClassUnderTest.GetEnj().IsSet());
			TestTrue(TEXT("PlatformRegistry is set"), ClassUnderTest.GetPlatformRegistry().IsSet());
			TestTrue(TEXT("SupplyModels is set"), ClassUnderTest.GetSupplyModels().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FContracts ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume CryptoItems is set"), ClassUnderTest.GetCryptoItems().IsSet());
			TestTrue(TEXT("Assume Enj is set"), ClassUnderTest.GetEnj().IsSet());
			TestTrue(TEXT("Assume PlatformRegistry is set"), ClassUnderTest.GetPlatformRegistry().IsSet());
			TestTrue(TEXT("Assume SupplyModels is set"), ClassUnderTest.GetSupplyModels().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("CryptoItems is not set"), ClassUnderTest.GetCryptoItems().IsSet());
			TestFalse(TEXT("Enj is not set"), ClassUnderTest.GetEnj().IsSet());
			TestFalse(TEXT("PlatformRegistry is not set"), ClassUnderTest.GetPlatformRegistry().IsSet());
			TestFalse(TEXT("SupplyModels is not set"), ClassUnderTest.GetSupplyModels().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FContracts Lhs;
			const FContracts Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FContracts Lhs;
			const FContracts Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FContracts Lhs;
			FContracts Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FContracts Lhs;
			FContracts Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
