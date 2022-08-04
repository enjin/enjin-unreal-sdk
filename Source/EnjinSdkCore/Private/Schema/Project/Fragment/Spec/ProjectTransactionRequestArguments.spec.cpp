// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Project/TransactionRequestArguments.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Shared;

class FTestableTransactionRequestArguments final
	: public TTransactionRequestArguments<FTestableTransactionRequestArguments>
{
public:
	FTestableTransactionRequestArguments() : TTransactionRequestArguments()
	{
	}
};

template FTestableTransactionRequestArguments&
TTransactionRequestArguments<FTestableTransactionRequestArguments>::SetEthAddress(FString Address);

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetTransactionAssetIdFormat(const EAssetIdFormat Format);

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithAssetData();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithBlockchainData();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithEncodedData();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithError();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithLogEvent();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithMeta();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithNonce();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithReceipt();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithReceiptLogs();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithSignedTxs();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithState();

template FTestableTransactionRequestArguments&
TTransactionFragmentArguments<FTestableTransactionRequestArguments>::SetWithTransactionProjectUuid();

BEGIN_DEFINE_SPEC(FProjectTransactionRequestArgumentsSpec,
                  "Enjin.Sdk.Project.TransactionRequestArguments",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"ethAddress":"1"})");

	static FTestableTransactionRequestArguments CreateDefaultClass()
	{
		return FTestableTransactionRequestArguments().SetTransactionAssetIdFormat(EAssetIdFormat::Hex64)
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

END_DEFINE_SPEC(FProjectTransactionRequestArgumentsSpec)

void FProjectTransactionRequestArgumentsSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FTestableTransactionRequestArguments ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FTestableTransactionRequestArguments ClassUnderTest = FTestableTransactionRequestArguments()
				.SetEthAddress(TEXT("1"));

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
			const FTestableTransactionRequestArguments Lhs;
			const FTestableTransactionRequestArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FTestableTransactionRequestArguments Lhs = CreateDefaultClass();
			const FTestableTransactionRequestArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTestableTransactionRequestArguments Lhs;
			const FTestableTransactionRequestArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FTestableTransactionRequestArguments Lhs = CreateDefaultClass();
			const FTestableTransactionRequestArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
