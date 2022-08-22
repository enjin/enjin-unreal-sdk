// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/TransferInput.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FTransferInputSpec,
                  "Enjin.Sdk.Model.TransferInput",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"assetId":"1","assetIndex":"1","from":"1","to":"1","value":"1"})");

	static FTransferInput CreateDefaultClass()
	{
		return FTransferInput().SetAssetId(TEXT("1"))
		                       .SetAssetIndex(TEXT("1"))
		                       .SetFrom(TEXT("1"))
		                       .SetTo(TEXT("1"))
		                       .SetValue(TEXT("1"));
	}

END_DEFINE_SPEC(FTransferInputSpec)

void FTransferInputSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FTransferInput ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FTransferInput ClassUnderTest = CreateDefaultClass();

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
			const FTransferInput Lhs;
			const FTransferInput Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FTransferInput Lhs = CreateDefaultClass();
			const FTransferInput Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTransferInput Lhs;
			const FTransferInput Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FTransferInput Lhs = CreateDefaultClass();
			const FTransferInput Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
