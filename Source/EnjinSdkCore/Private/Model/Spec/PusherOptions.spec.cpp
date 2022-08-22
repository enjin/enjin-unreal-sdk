// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/PusherOptions.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPusherOptionsSpec,
                  "Enjin.Sdk.Model.PusherOptions",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"cluster":"1","encrypted":true})");
END_DEFINE_SPEC(FPusherOptionsSpec)

void FPusherOptionsSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FPusherOptions ClassUnderTest;

			// Assert
			TestFalse(TEXT("Cluster is not set"), ClassUnderTest.GetCluster().IsSet());
			TestFalse(TEXT("Encrypted is not set"), ClassUnderTest.GetEncrypted().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FPusherOptions ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("Cluster is set"), ClassUnderTest.GetCluster().IsSet());
			TestTrue(TEXT("Encrypted is set"), ClassUnderTest.GetEncrypted().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FPusherOptions ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume Cluster is set"), ClassUnderTest.GetCluster().IsSet());
			TestTrue(TEXT("Assume Encrypted is set"), ClassUnderTest.GetEncrypted().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("Cluster is not set"), ClassUnderTest.GetCluster().IsSet());
			TestFalse(TEXT("Encrypted is not set"), ClassUnderTest.GetEncrypted().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FPusherOptions Lhs;
			const FPusherOptions Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FPusherOptions Lhs;
			const FPusherOptions Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FPusherOptions Lhs;
			FPusherOptions Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FPusherOptions Lhs;
			FPusherOptions Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
