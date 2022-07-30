// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/MeltAsset.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FProjectMeltAssetSpec,
                  "Enjin.Sdk.Project.MeltAsset",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"melts":[]})");

	static Enjin::Sdk::Project::FMeltAsset CreateDefaultClass()
	{
		return Enjin::Sdk::Project::FMeltAsset().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                                        .SetEthAddress(TEXT("1"))
		                                        .SetMelts({})
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

END_DEFINE_SPEC(FProjectMeltAssetSpec)

void FProjectMeltAssetSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const Enjin::Sdk::Project::FMeltAsset ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const Enjin::Sdk::Project::FMeltAsset ClassUnderTest = Enjin::Sdk::Project::FMeltAsset()
				.SetMelts({});

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
			const Enjin::Sdk::Project::FMeltAsset Lhs;
			const Enjin::Sdk::Project::FMeltAsset Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FMeltAsset Lhs = CreateDefaultClass();
			const Enjin::Sdk::Project::FMeltAsset Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FMeltAsset Lhs;
			const Enjin::Sdk::Project::FMeltAsset Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Project::FMeltAsset Lhs = CreateDefaultClass();
			const Enjin::Sdk::Project::FMeltAsset Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
