// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/SetWhitelisted.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;

BEGIN_DEFINE_SPEC(FProjectSetWhitelistedSpec,
                  "Enjin.Sdk.Project.SetWhitelisted",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"accountAddress":"1","assetId":"1","on":true,"whitelistedAddress":"1","whitelisted":"NONE"})");

	static FSetWhitelisted CreateDefaultClass()
	{
		return FSetWhitelisted().SetAccountAddress(TEXT("1"))
		                        .SetAssetId(TEXT("1"))
		                        .SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
		                        .SetEthAddress(TEXT("1"))
		                        .SetOn(true)
		                        .SetWhitelistedAddress(TEXT("1"))
		                        .SetWhitelisted(EWhitelisted::None)
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

END_DEFINE_SPEC(FProjectSetWhitelistedSpec)

void FProjectSetWhitelistedSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FSetWhitelisted ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FSetWhitelisted ClassUnderTest = FSetWhitelisted()
			                                       .SetAccountAddress(TEXT("1"))
			                                       .SetAssetId(TEXT("1"))
			                                       .SetOn(true)
			                                       .SetWhitelistedAddress(TEXT("1"))
			                                       .SetWhitelisted(EWhitelisted::None);

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
			const FSetWhitelisted Lhs;
			const FSetWhitelisted Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FSetWhitelisted Lhs = CreateDefaultClass();
			const FSetWhitelisted Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FSetWhitelisted Lhs;
			const FSetWhitelisted Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FSetWhitelisted Lhs = CreateDefaultClass();
			const FSetWhitelisted Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
