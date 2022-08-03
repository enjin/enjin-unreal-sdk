// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/ApproveMaxEnj.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FProjectApproveMaxEnjSpec,
                  "Enjin.Sdk.Project.ApproveMaxEnj",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString Json = TEXT(R"({})");

	static Enjin::Sdk::Project::FApproveMaxEnj CreateDefaultClass()
	{
		return Enjin::Sdk::Project::FApproveMaxEnj().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                                            .SetEthAddress(TEXT("1"))
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

END_DEFINE_SPEC(FProjectApproveMaxEnjSpec)

void FProjectApproveMaxEnjSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce expected JSON"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const Enjin::Sdk::Project::FApproveMaxEnj ClassUnderTest;

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
			const Enjin::Sdk::Project::FApproveMaxEnj Lhs;
			const Enjin::Sdk::Project::FApproveMaxEnj Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FApproveMaxEnj Lhs = CreateDefaultClass();
			const Enjin::Sdk::Project::FApproveMaxEnj Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FApproveMaxEnj Lhs;
			const Enjin::Sdk::Project::FApproveMaxEnj Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FApproveMaxEnj Lhs = CreateDefaultClass();
			const Enjin::Sdk::Project::FApproveMaxEnj Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
