// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Platform.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPlatformSpec,
                  "Enjin.Sdk.Model.Platform",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"id":1,"name":"1","network":"1","contracts":{},"notifications":{}})");
END_DEFINE_SPEC(FPlatformSpec)

void FPlatformSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FPlatform ClassUnderTest;

			// Assert
			TestFalse(TEXT("Contracts is not set"), ClassUnderTest.GetContracts().IsSet());
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("Name is not set"), ClassUnderTest.GetName().IsSet());
			TestFalse(TEXT("Network is not set"), ClassUnderTest.GetNetwork().IsSet());
			TestFalse(TEXT("Notifications is not set"), ClassUnderTest.GetNotifications().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FPlatform ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("Contracts is set"), ClassUnderTest.GetContracts().IsSet());
			TestTrue(TEXT("Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("Name is set"), ClassUnderTest.GetName().IsSet());
			TestTrue(TEXT("Network is set"), ClassUnderTest.GetNetwork().IsSet());
			TestTrue(TEXT("Notifications is set"), ClassUnderTest.GetNotifications().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FPlatform ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume Contracts is set"), ClassUnderTest.GetContracts().IsSet());
			TestTrue(TEXT("Assume Id is set"), ClassUnderTest.GetId().IsSet());
			TestTrue(TEXT("Assume Name is set"), ClassUnderTest.GetName().IsSet());
			TestTrue(TEXT("Assume Network is set"), ClassUnderTest.GetNetwork().IsSet());
			TestTrue(TEXT("Assume Notifications is set"), ClassUnderTest.GetNotifications().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("Contracts is not set"), ClassUnderTest.GetContracts().IsSet());
			TestFalse(TEXT("Id is not set"), ClassUnderTest.GetId().IsSet());
			TestFalse(TEXT("Name is not set"), ClassUnderTest.GetName().IsSet());
			TestFalse(TEXT("Network is not set"), ClassUnderTest.GetNetwork().IsSet());
			TestFalse(TEXT("Notifications is not set"), ClassUnderTest.GetNotifications().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FPlatform Lhs;
			const FPlatform Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FPlatform Lhs;
			const FPlatform Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FPlatform Lhs;
			FPlatform Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FPlatform Lhs;
			FPlatform Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
