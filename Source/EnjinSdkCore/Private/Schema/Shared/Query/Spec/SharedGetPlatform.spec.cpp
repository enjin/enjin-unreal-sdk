// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/GetPlatform.h"

using namespace Enjin::Sdk::Shared;

BEGIN_DEFINE_SPEC(FSharedGetPlatformSpec,
                  "Enjin.Sdk.Shared.GetPlatform",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"withContracts":true,"withNotificationDrivers":true})");

	static FGetPlatform CreateDefaultClass()
	{
		return FGetPlatform().SetWithContracts()
		                     .SetWithNotifications();
	}

END_DEFINE_SPEC(FSharedGetPlatformSpec)

void FSharedGetPlatformSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FGetPlatform ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FGetPlatform ClassUnderTest = FGetPlatform()
			                                    .SetWithContracts()
			                                    .SetWithNotifications();

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
			const FGetPlatform Lhs;
			const FGetPlatform Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FGetPlatform Lhs = CreateDefaultClass();
			const FGetPlatform Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FGetPlatform Lhs;
			const FGetPlatform Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FGetPlatform Lhs = CreateDefaultClass();
			const FGetPlatform Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
