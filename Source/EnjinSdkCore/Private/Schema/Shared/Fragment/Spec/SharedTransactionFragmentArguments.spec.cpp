// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/TransactionFragmentArguments.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;

class FTestableTransactionFragmentArguments final
	: public TTransactionFragmentArguments<FTestableTransactionFragmentArguments>
{
public:
	FTestableTransactionFragmentArguments() : TTransactionFragmentArguments()
	{
	}
};

// region TTransactionFragmentArguments

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetTransactionAssetIdFormat(
	const EAssetIdFormat Format);

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithAssetData();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithBlockchainData();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithEncodedData();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithError();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithLogEvent();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithMeta();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithNonce();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithReceipt();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithReceiptLogs();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithSignedTxs();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithState();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithTransactionProjectUuid();

template FTestableTransactionFragmentArguments&
TTransactionFragmentArguments<FTestableTransactionFragmentArguments>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

BEGIN_DEFINE_SPEC(FSharedTransactionFragmentArgumentsSpec,
                  "Enjin.Sdk.Shared.TransactionFragmentArguments",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"transactionAssetIdFormat":"hex64","withAssetData":true,"withBlockchainData":true,"withEncodedData":true,"withError":true,"withLogEvent":true,"withMeta":true,"withNonce":true,"withReceiptLogs":true,"withReceipt":true,"withSignedTxs":true,"withState":true,"withTransactionProjectUuid":true,"withTransactionWalletAddress":true})");

	static FTestableTransactionFragmentArguments CreateDefaultClass()
	{
		return FTestableTransactionFragmentArguments()
		       .SetTransactionAssetIdFormat(EAssetIdFormat::Hex64) // TTransactionFragmentArguments
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
		       .SetWithTransactionProjectUuid()
		       .SetWithTransactionWalletAddress();
	}

END_DEFINE_SPEC(FSharedTransactionFragmentArgumentsSpec)

void FSharedTransactionFragmentArgumentsSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FTestableTransactionFragmentArguments ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FTestableTransactionFragmentArguments ClassUnderTest = FTestableTransactionFragmentArguments()
			                                                             .SetTransactionAssetIdFormat(
				                                                             EAssetIdFormat::Hex64)
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
			                                                             .SetWithTransactionProjectUuid()
			                                                             .SetWithTransactionWalletAddress();

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
			const FTestableTransactionFragmentArguments Lhs;
			const FTestableTransactionFragmentArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FTestableTransactionFragmentArguments Lhs = CreateDefaultClass();
			const FTestableTransactionFragmentArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTestableTransactionFragmentArguments Lhs;
			const FTestableTransactionFragmentArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FTestableTransactionFragmentArguments Lhs = CreateDefaultClass();
			const FTestableTransactionFragmentArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
