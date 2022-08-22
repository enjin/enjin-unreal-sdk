// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/TransactionEvent.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FTransactionEventSpec,
                  "Enjin.Sdk.Model.TransactionEvent",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"name":"1","inputs":[],"nonIndexedInputs":[],"indexedInputs":[],"signature":"1","encodedSignature":"1"})");
END_DEFINE_SPEC(FTransactionEventSpec)

void FTransactionEventSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FTransactionEvent ClassUnderTest;

			// Assert
			TestFalse(TEXT("EncodedSignature is not set"), ClassUnderTest.GetEncodedSignature().IsSet());
			TestFalse(TEXT("IndexedInputs is not set"), ClassUnderTest.GetIndexedInputs().IsSet());
			TestFalse(TEXT("Inputs is not set"), ClassUnderTest.GetInputs().IsSet());
			TestFalse(TEXT("Name is not set"), ClassUnderTest.GetName().IsSet());
			TestFalse(TEXT("NonIndexedInputs is not set"), ClassUnderTest.GetNonIndexedInputs().IsSet());
			TestFalse(TEXT("Signature is not set"), ClassUnderTest.GetSignature().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FTransactionEvent ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("EncodedSignature is set"), ClassUnderTest.GetEncodedSignature().IsSet());
			TestTrue(TEXT("IndexedInputs is set"), ClassUnderTest.GetIndexedInputs().IsSet());
			TestTrue(TEXT("Inputs is set"), ClassUnderTest.GetInputs().IsSet());
			TestTrue(TEXT("Name is set"), ClassUnderTest.GetName().IsSet());
			TestTrue(TEXT("NonIndexedInputs is set"), ClassUnderTest.GetNonIndexedInputs().IsSet());
			TestTrue(TEXT("Signature is set"), ClassUnderTest.GetSignature().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FTransactionEvent ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume EncodedSignature is set"), ClassUnderTest.GetEncodedSignature().IsSet());
			TestTrue(TEXT("Assume IndexedInputs is set"), ClassUnderTest.GetIndexedInputs().IsSet());
			TestTrue(TEXT("Assume Inputs is set"), ClassUnderTest.GetInputs().IsSet());
			TestTrue(TEXT("Assume Name is set"), ClassUnderTest.GetName().IsSet());
			TestTrue(TEXT("Assume NonIndexedInputs is set"), ClassUnderTest.GetNonIndexedInputs().IsSet());
			TestTrue(TEXT("Assume Signature is set"), ClassUnderTest.GetSignature().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("EncodedSignature is not set"), ClassUnderTest.GetEncodedSignature().IsSet());
			TestFalse(TEXT("IndexedInputs is not set"), ClassUnderTest.GetIndexedInputs().IsSet());
			TestFalse(TEXT("Inputs is not set"), ClassUnderTest.GetInputs().IsSet());
			TestFalse(TEXT("Name is not set"), ClassUnderTest.GetName().IsSet());
			TestFalse(TEXT("NonIndexedInputs is not set"), ClassUnderTest.GetNonIndexedInputs().IsSet());
			TestFalse(TEXT("Signature is not set"), ClassUnderTest.GetSignature().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FTransactionEvent Lhs;
			const FTransactionEvent Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FTransactionEvent Lhs;
			const FTransactionEvent Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTransactionEvent Lhs;
			FTransactionEvent Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FTransactionEvent Lhs;
			FTransactionEvent Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
