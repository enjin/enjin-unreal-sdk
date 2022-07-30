// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/Message.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FProjectMessageSpec,
                  "Enjin.Sdk.Project.Message",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"message":"1"})");

	static Enjin::Sdk::Project::FMessage CreateDefaultClass()
	{
		return Enjin::Sdk::Project::FMessage().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                                      .SetEthAddress(TEXT("1"))
		                                      .SetMessage(TEXT("1"))
		                                      .SetWithAssetData()
		                                      .SetWithBlockchainData()
		                                      .SetWithEncodedData()
		                                      .SetWithError()
		                                      .SetWithLogEvent()
		                                      .SetWithMeta()
		                                      .SetWithNonce()
		                                      .SetWithReceiptLogs()
		                                      .SetWithReceipt()
		                                      .SetWithSignedTxs()
		                                      .SetWithState()
		                                      .SetWithTransactionProjectUuid();
	}

END_DEFINE_SPEC(FProjectMessageSpec)

void FProjectMessageSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const Enjin::Sdk::Project::FMessage ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const Enjin::Sdk::Project::FMessage ClassUnderTest = Enjin::Sdk::Project::FMessage()
				.SetMessage(TEXT("1"));

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
			const Enjin::Sdk::Project::FMessage Lhs;
			const Enjin::Sdk::Project::FMessage Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FMessage Lhs = CreateDefaultClass();
			const Enjin::Sdk::Project::FMessage Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FMessage Lhs;
			const Enjin::Sdk::Project::FMessage Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FMessage Lhs = CreateDefaultClass();
			const Enjin::Sdk::Project::FMessage Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
