// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Pusher.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPusherSpec,
                  "Enjin.Sdk.Model.Pusher",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"key":"1","namespace":"1","channels":{},"options":{}})");
END_DEFINE_SPEC(FPusherSpec)

void FPusherSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FPusher ClassUnderTest;

			// Assert
			TestFalse(TEXT("Channels is not set"), ClassUnderTest.GetChannels().IsSet());
			TestFalse(TEXT("Key is not set"), ClassUnderTest.GetKey().IsSet());
			TestFalse(TEXT("Namespace is not set"), ClassUnderTest.GetNamespace().IsSet());
			TestFalse(TEXT("Options is not set"), ClassUnderTest.GetOptions().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FPusher ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("Channels is set"), ClassUnderTest.GetChannels().IsSet());
			TestTrue(TEXT("Key is set"), ClassUnderTest.GetKey().IsSet());
			TestTrue(TEXT("Namespace is set"), ClassUnderTest.GetNamespace().IsSet());
			TestTrue(TEXT("Options is set"), ClassUnderTest.GetOptions().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FPusher ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume Channels is set"), ClassUnderTest.GetChannels().IsSet());
			TestTrue(TEXT("Assume Key is set"), ClassUnderTest.GetKey().IsSet());
			TestTrue(TEXT("Assume Namespace is set"), ClassUnderTest.GetNamespace().IsSet());
			TestTrue(TEXT("Assume Options is set"), ClassUnderTest.GetOptions().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("Channels is not set"), ClassUnderTest.GetChannels().IsSet());
			TestFalse(TEXT("Key is not set"), ClassUnderTest.GetKey().IsSet());
			TestFalse(TEXT("Namespace is not set"), ClassUnderTest.GetNamespace().IsSet());
			TestFalse(TEXT("Options is not set"), ClassUnderTest.GetOptions().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FPusher Lhs;
			const FPusher Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FPusher Lhs;
			const FPusher Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FPusher Lhs;
			FPusher Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FPusher Lhs;
			FPusher Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
