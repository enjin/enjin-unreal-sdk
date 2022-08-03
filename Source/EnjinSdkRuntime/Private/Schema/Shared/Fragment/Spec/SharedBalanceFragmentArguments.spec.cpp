// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/BalanceFragmentArguments.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;

class FTestableBalanceFragmentArguments final : public TBalanceFragmentArguments<FTestableBalanceFragmentArguments>
{
public:
	FTestableBalanceFragmentArguments() : TBalanceFragmentArguments()
	{
	}
};

template FTestableBalanceFragmentArguments&
TBalanceFragmentArguments<FTestableBalanceFragmentArguments>::SetBalIdFormat(const EAssetIdFormat Format);

template FTestableBalanceFragmentArguments&
TBalanceFragmentArguments<FTestableBalanceFragmentArguments>::SetBalIndexFormat(const EAssetIndexFormat Format);

template FTestableBalanceFragmentArguments&
TBalanceFragmentArguments<FTestableBalanceFragmentArguments>::SetWithBalProjectUuid();

template FTestableBalanceFragmentArguments&
TBalanceFragmentArguments<FTestableBalanceFragmentArguments>::SetWithBalWalletAddress();

BEGIN_DEFINE_SPEC(FSharedBalanceFragmentArgumentsSpec,
                  "Enjin.Sdk.Shared.BalanceFragmentArguments",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"balIdFormat":"hex64","balIndexFormat":"hex64","withBalProjectUuid":true,"withBalWalletAddress":true})");

	static FTestableBalanceFragmentArguments CreateDefaultClass()
	{
		return FTestableBalanceFragmentArguments().SetBalIdFormat(EAssetIdFormat::Hex64)
		                                          .SetBalIndexFormat(EAssetIndexFormat::Hex64)
		                                          .SetWithBalProjectUuid()
		                                          .SetWithBalWalletAddress();
	}

END_DEFINE_SPEC(FSharedBalanceFragmentArgumentsSpec)

void FSharedBalanceFragmentArgumentsSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce empty JSON when not populated"), [this]()
		{
			// Arrange
			const FString Expected = EmptyJson;
			const FTestableBalanceFragmentArguments ClassUnderTest;

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should produce populated JSON when populated"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FTestableBalanceFragmentArguments ClassUnderTest = FTestableBalanceFragmentArguments()
			                                                         .SetBalIdFormat(EAssetIdFormat::Hex64)
			                                                         .SetBalIndexFormat(EAssetIndexFormat::Hex64)
			                                                         .SetWithBalProjectUuid()
			                                                         .SetWithBalWalletAddress();

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
			const FTestableBalanceFragmentArguments Lhs;
			const FTestableBalanceFragmentArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			const FTestableBalanceFragmentArguments Lhs = CreateDefaultClass();
			const FTestableBalanceFragmentArguments Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FTestableBalanceFragmentArguments Lhs;
			const FTestableBalanceFragmentArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			const FTestableBalanceFragmentArguments Lhs = CreateDefaultClass();
			const FTestableBalanceFragmentArguments Rhs = CreateDefaultClass();

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
