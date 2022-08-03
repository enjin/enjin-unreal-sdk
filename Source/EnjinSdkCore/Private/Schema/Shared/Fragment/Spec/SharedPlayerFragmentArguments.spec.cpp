// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/PlayerFragmentArguments.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;

class FTestablePlayerFragmentArguments final : public TPlayerFragmentArguments<FTestablePlayerFragmentArguments>
{
public:
	FTestablePlayerFragmentArguments() : TPlayerFragmentArguments()
	{
	}
};

// region TAssetFragmentArguments

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetAssetIdFormat(const EAssetIdFormat AssetIdFormat);

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithAssetBlocks();

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithAssetVariantMode();

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithAssetVariants();

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithConfigData();

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithCreator();

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithMeltDetails();

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithMetadataUri();

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithStateData();

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithSupplyDetails();

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithTransferSettings();

template FTestablePlayerFragmentArguments&
TAssetFragmentArguments<FTestablePlayerFragmentArguments>::SetWithVariantMetadata();

// endregion TAssetFragmentArguments

// region TBalanceFragmentArguments

template FTestablePlayerFragmentArguments&
TBalanceFragmentArguments<FTestablePlayerFragmentArguments>::SetBalIdFormat(const EAssetIdFormat Format);

template FTestablePlayerFragmentArguments&
TBalanceFragmentArguments<FTestablePlayerFragmentArguments>::SetBalIndexFormat(const EAssetIndexFormat Format);

template FTestablePlayerFragmentArguments&
TBalanceFragmentArguments<FTestablePlayerFragmentArguments>::SetWithBalProjectUuid();

template FTestablePlayerFragmentArguments&
TBalanceFragmentArguments<FTestablePlayerFragmentArguments>::SetWithBalWalletAddress();

// endregion TBalanceFragmentArguments

// region TPlayerFragmentArguments

template FTestablePlayerFragmentArguments&
TPlayerFragmentArguments<FTestablePlayerFragmentArguments>::SetLinkingCodeQrSize(const int32 Size);

template FTestablePlayerFragmentArguments&
TPlayerFragmentArguments<FTestablePlayerFragmentArguments>::SetWithLinkingInfo();

template FTestablePlayerFragmentArguments&
TPlayerFragmentArguments<FTestablePlayerFragmentArguments>::SetWithPlayerWallet();

// endregion TPlayerFragmentArguments

// region TTransactionFragmentArguments

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetTransactionAssetIdFormat(
	const EAssetIdFormat Format);

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithAssetData();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithBlockchainData();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithEncodedData();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithError();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithLogEvent();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithMeta();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithNonce();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithReceipt();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithReceiptLogs();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithSignedTxs();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithState();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithTransactionProjectUuid();

template FTestablePlayerFragmentArguments&
TTransactionFragmentArguments<FTestablePlayerFragmentArguments>::SetWithTransactionWalletAddress();

// endregion TTransactionFragmentArguments

// region TWalletFragmentArguments

template FTestablePlayerFragmentArguments&
TWalletFragmentArguments<FTestablePlayerFragmentArguments>::SetWalletBalanceFilter(FBalanceFilter Filter);

template FTestablePlayerFragmentArguments&
TWalletFragmentArguments<FTestablePlayerFragmentArguments>::SetWithAssetsCreated();

template FTestablePlayerFragmentArguments&
TWalletFragmentArguments<FTestablePlayerFragmentArguments>::SetWithWalletBalances();

template FTestablePlayerFragmentArguments&
TWalletFragmentArguments<FTestablePlayerFragmentArguments>::SetWithWalletTransactions();

// endregion TWalletFragmentArguments

BEGIN_DEFINE_SPEC(FSharedPlayerFragmentArgumentsSpec,
                  "Enjin.Sdk.Shared.PlayerFragmentArguments",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"linkingCodeQrSize":1,"withLinkingInfo":true,"withPlayerWallet":true})");

	static FTestablePlayerFragmentArguments CreateDefaultClass()
	{
		return FTestablePlayerFragmentArguments()
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
		       .SetLinkingCodeQrSize(1) // TPlayerFragmentArguments
		       .SetWithLinkingInfo()
		       .SetWithPlayerWallet()
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

END_DEFINE_SPEC(FSharedPlayerFragmentArgumentsSpec)

void FSharedPlayerFragmentArgumentsSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FTestablePlayerFragmentArguments ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FTestablePlayerFragmentArguments ClassUnderTest = FTestablePlayerFragmentArguments()
			                                                        .SetLinkingCodeQrSize(1)
			                                                        .SetWithLinkingInfo()
			                                                        .SetWithPlayerWallet();

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
			const FTestablePlayerFragmentArguments Lhs;
			const FTestablePlayerFragmentArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FTestablePlayerFragmentArguments Lhs = CreateDefaultClass();
			const FTestablePlayerFragmentArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTestablePlayerFragmentArguments Lhs;
			const FTestablePlayerFragmentArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FTestablePlayerFragmentArguments Lhs = CreateDefaultClass();
			const FTestablePlayerFragmentArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
