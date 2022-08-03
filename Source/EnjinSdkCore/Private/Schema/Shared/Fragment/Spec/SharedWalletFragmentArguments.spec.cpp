// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/WalletFragmentArguments.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;

class FTestableWalletFragmentArguments final : public TWalletFragmentArguments<FTestableWalletFragmentArguments>
{
public:
	FTestableWalletFragmentArguments() : TWalletFragmentArguments()
	{
	}
};

// region TAssetFragmentArguments

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetAssetIdFormat(const EAssetIdFormat AssetIdFormat);

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithAssetBlocks();

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithAssetVariantMode();

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithAssetVariants();

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithConfigData();

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithCreator();

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithMeltDetails();

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithMetadataUri();

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithStateData();

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithSupplyDetails();

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithTransferSettings();

template FTestableWalletFragmentArguments&
TAssetFragmentArguments<FTestableWalletFragmentArguments>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template FTestableWalletFragmentArguments&
TBalanceFragmentArguments<FTestableWalletFragmentArguments>::SetBalIdFormat(const EAssetIdFormat Format);

template FTestableWalletFragmentArguments&
TBalanceFragmentArguments<FTestableWalletFragmentArguments>::SetBalIndexFormat(const EAssetIndexFormat Format);

template FTestableWalletFragmentArguments&
TBalanceFragmentArguments<FTestableWalletFragmentArguments>::SetWithBalProjectUuid();

template FTestableWalletFragmentArguments&
TBalanceFragmentArguments<FTestableWalletFragmentArguments>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TTransactionFragmentArguments

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetTransactionAssetIdFormat(
	const EAssetIdFormat Format);

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithAssetData();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithBlockchainData();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithEncodedData();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithError();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithLogEvent();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithMeta();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithNonce();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithReceipt();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithReceiptLogs();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithSignedTxs();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithState();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithTransactionProjectUuid();

template FTestableWalletFragmentArguments&
TTransactionFragmentArguments<FTestableWalletFragmentArguments>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template FTestableWalletFragmentArguments&
TWalletFragmentArguments<FTestableWalletFragmentArguments>::SetWalletBalanceFilter(FBalanceFilter Filter);

template FTestableWalletFragmentArguments&
TWalletFragmentArguments<FTestableWalletFragmentArguments>::SetWithAssetsCreated();

template FTestableWalletFragmentArguments&
TWalletFragmentArguments<FTestableWalletFragmentArguments>::SetWithWalletBalances();

template FTestableWalletFragmentArguments&
TWalletFragmentArguments<FTestableWalletFragmentArguments>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments

BEGIN_DEFINE_SPEC(FSharedWalletFragmentArgumentsSpec,
                  "Enjin.Sdk.Shared.WalletFragmentArguments",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"walletBalanceFilter":{},"withAssetsCreated":true,"withWalletBalances":true,"withWalletTransactions":true})");

	static FTestableWalletFragmentArguments CreateDefaultClass()
	{
		return FTestableWalletFragmentArguments()
		       .SetTransactionAssetIdFormat(EAssetIdFormat::Hex64) // TAssetFragmentArguments
		       .SetWithAssetBlocks()
		       .SetWithAssetVariantMode()
		       .SetWithAssetVariants()
		       .SetWithConfigData()
		       .SetWithCreator()
		       .SetWithMeltDetails()
		       .SetWithMetadataUri()
		       .SetWithStateData()
		       .SetWithSupplyDetails()
		       .SetWithTransferSettings()
		       .SetWithVariantMetadata()
		       .SetBalIdFormat(EAssetIdFormat::Hex64) // TBalanceFragmentArguments
		       .SetBalIndexFormat(EAssetIndexFormat::Hex64)
		       .SetWithBalProjectUuid()
		       .SetWithBalWalletAddress()
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
		       .SetWithTransactionWalletAddress()
		       .SetWalletBalanceFilter({}) // TWalletFragmentArguments
		       .SetWithAssetsCreated()
		       .SetWithWalletBalances()
		       .SetWithWalletTransactions();
	}

END_DEFINE_SPEC(FSharedWalletFragmentArgumentsSpec)

void FSharedWalletFragmentArgumentsSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FTestableWalletFragmentArguments ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FTestableWalletFragmentArguments ClassUnderTest = FTestableWalletFragmentArguments()
			                                                        .SetWalletBalanceFilter({})
			                                                        .SetWithAssetsCreated()
			                                                        .SetWithWalletBalances()
			                                                        .SetWithWalletTransactions();

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
			const FTestableWalletFragmentArguments Lhs;
			const FTestableWalletFragmentArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FTestableWalletFragmentArguments Lhs = CreateDefaultClass();
			const FTestableWalletFragmentArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTestableWalletFragmentArguments Lhs;
			const FTestableWalletFragmentArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FTestableWalletFragmentArguments Lhs = CreateDefaultClass();
			const FTestableWalletFragmentArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
