// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/AssetStateData.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FAssetStateDataSpec,
                  "Enjin.Sdk.Model.AssetStateData",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(
		R"({"nonFungible":true,"blockHeight":1,"creator":"1","firstBlock":1,"reserve":"1","supplyModel":"FIXED","circulatingSupply":"1","mintableSupply":"1","totalSupply":"1"})");
END_DEFINE_SPEC(FAssetStateDataSpec)

void FAssetStateDataSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FAssetStateData ClassUnderTest;

			// Assert
			TestFalse(TEXT("BlockHeight is not set"), ClassUnderTest.GetBlockHeight().IsSet());
			TestFalse(TEXT("CirculatingSupply is not set"), ClassUnderTest.GetCirculatingSupply().IsSet());
			TestFalse(TEXT("Creator is not set"), ClassUnderTest.GetCreator().IsSet());
			TestFalse(TEXT("FirstBlock is not set"), ClassUnderTest.GetFirstBlock().IsSet());
			TestFalse(TEXT("MintableSupply is not set"), ClassUnderTest.GetMintableSupply().IsSet());
			TestFalse(TEXT("NonFungible is not set"), ClassUnderTest.GetNonFungible().IsSet());
			TestFalse(TEXT("Reserve is not set"), ClassUnderTest.GetReserve().IsSet());
			TestFalse(TEXT("SupplyModel is not set"), ClassUnderTest.GetSupplyModel().IsSet());
			TestFalse(TEXT("TotalSupply is not set"), ClassUnderTest.GetTotalSupply().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FAssetStateData ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("BlockHeight is set"), ClassUnderTest.GetBlockHeight().IsSet());
			TestTrue(TEXT("CirculatingSupply is set"), ClassUnderTest.GetCirculatingSupply().IsSet());
			TestTrue(TEXT("Creator is set"), ClassUnderTest.GetCreator().IsSet());
			TestTrue(TEXT("FirstBlock is set"), ClassUnderTest.GetFirstBlock().IsSet());
			TestTrue(TEXT("MintableSupply is set"), ClassUnderTest.GetMintableSupply().IsSet());
			TestTrue(TEXT("NonFungible is set"), ClassUnderTest.GetNonFungible().IsSet());
			TestTrue(TEXT("Reserve is set"), ClassUnderTest.GetReserve().IsSet());
			TestTrue(TEXT("SupplyModel is set"), ClassUnderTest.GetSupplyModel().IsSet());
			TestTrue(TEXT("TotalSupply is set"), ClassUnderTest.GetTotalSupply().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FAssetStateData ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume BlockHeight is set"), ClassUnderTest.GetBlockHeight().IsSet());
			TestTrue(TEXT("Assume CirculatingSupply is set"), ClassUnderTest.GetCirculatingSupply().IsSet());
			TestTrue(TEXT("Assume Creator is set"), ClassUnderTest.GetCreator().IsSet());
			TestTrue(TEXT("Assume FirstBlock is set"), ClassUnderTest.GetFirstBlock().IsSet());
			TestTrue(TEXT("Assume MintableSupply is set"), ClassUnderTest.GetMintableSupply().IsSet());
			TestTrue(TEXT("Assume NonFungible is set"), ClassUnderTest.GetNonFungible().IsSet());
			TestTrue(TEXT("Assume Reserve is set"), ClassUnderTest.GetReserve().IsSet());
			TestTrue(TEXT("Assume SupplyModel is set"), ClassUnderTest.GetSupplyModel().IsSet());
			TestTrue(TEXT("Assume TotalSupply is set"), ClassUnderTest.GetTotalSupply().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("BlockHeight is not set"), ClassUnderTest.GetBlockHeight().IsSet());
			TestFalse(TEXT("CirculatingSupply is not set"), ClassUnderTest.GetCirculatingSupply().IsSet());
			TestFalse(TEXT("Creator is not set"), ClassUnderTest.GetCreator().IsSet());
			TestFalse(TEXT("FirstBlock is not set"), ClassUnderTest.GetFirstBlock().IsSet());
			TestFalse(TEXT("MintableSupply is not set"), ClassUnderTest.GetMintableSupply().IsSet());
			TestFalse(TEXT("NonFungible is not set"), ClassUnderTest.GetNonFungible().IsSet());
			TestFalse(TEXT("Reserve is not set"), ClassUnderTest.GetReserve().IsSet());
			TestFalse(TEXT("SupplyModel is not set"), ClassUnderTest.GetSupplyModel().IsSet());
			TestFalse(TEXT("TotalSupply is not set"), ClassUnderTest.GetTotalSupply().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FAssetStateData Lhs;
			const FAssetStateData Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FAssetStateData Lhs;
			const FAssetStateData Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FAssetStateData Lhs;
			FAssetStateData Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FAssetStateData Lhs;
			FAssetStateData Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
