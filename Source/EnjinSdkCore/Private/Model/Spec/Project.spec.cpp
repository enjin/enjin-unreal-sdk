// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Project.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FProjectSpec,
                  "Enjin.Sdk.Model.Project",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"uuid":"1","name":"1","description":"1","image":"1","createdAt":"1","updatedAt":"1"})");
END_DEFINE_SPEC(FProjectSpec)

void FProjectSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FProject ClassUnderTest;

			// Assert
			TestFalse(TEXT("CreatedAt is not set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestFalse(TEXT("Description is not set"), ClassUnderTest.GetDescription().IsSet());
			TestFalse(TEXT("Image is not set"), ClassUnderTest.GetImage().IsSet());
			TestFalse(TEXT("Name is not set"), ClassUnderTest.GetName().IsSet());
			TestFalse(TEXT("UpdatedAt is not set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestFalse(TEXT("Uuid is not set"), ClassUnderTest.GetUuid().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FProject ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("CreatedAt is set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestTrue(TEXT("Description is set"), ClassUnderTest.GetDescription().IsSet());
			TestTrue(TEXT("Image is set"), ClassUnderTest.GetImage().IsSet());
			TestTrue(TEXT("Name is set"), ClassUnderTest.GetName().IsSet());
			TestTrue(TEXT("UpdatedAt is set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestTrue(TEXT("Uuid is set"), ClassUnderTest.GetUuid().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FProject ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume CreatedAt is set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestTrue(TEXT("Assume Description is set"), ClassUnderTest.GetDescription().IsSet());
			TestTrue(TEXT("Assume Image is set"), ClassUnderTest.GetImage().IsSet());
			TestTrue(TEXT("Assume Name is set"), ClassUnderTest.GetName().IsSet());
			TestTrue(TEXT("Assume UpdatedAt is set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestTrue(TEXT("Assume Uuid is set"), ClassUnderTest.GetUuid().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("CreatedAt is not set"), ClassUnderTest.GetCreatedAt().IsSet());
			TestFalse(TEXT("Description is not set"), ClassUnderTest.GetDescription().IsSet());
			TestFalse(TEXT("Image is not set"), ClassUnderTest.GetImage().IsSet());
			TestFalse(TEXT("Name is not set"), ClassUnderTest.GetName().IsSet());
			TestFalse(TEXT("UpdatedAt is not set"), ClassUnderTest.GetUpdatedAt().IsSet());
			TestFalse(TEXT("Uuid is not set"), ClassUnderTest.GetUuid().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FProject Lhs;
			const FProject Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FProject Lhs;
			const FProject Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FProject Lhs;
			FProject Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FProject Lhs;
			FProject Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
