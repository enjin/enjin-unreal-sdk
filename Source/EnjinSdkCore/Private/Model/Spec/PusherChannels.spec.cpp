// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/PusherChannels.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FPusherChannelsSpec,
                  "Enjin.Sdk.Model.PusherChannels",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"project":"1","player":"1","asset":"1","wallet":"1"})");
END_DEFINE_SPEC(FPusherChannelsSpec)

void FPusherChannelsSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FPusherChannels ClassUnderTest;

			// Assert
			TestFalse(TEXT("Asset is not set"), ClassUnderTest.GetAsset().IsSet());
			TestFalse(TEXT("Player is not set"), ClassUnderTest.GetPlayer().IsSet());
			TestFalse(TEXT("Project is not set"), ClassUnderTest.GetProject().IsSet());
			TestFalse(TEXT("Wallet is not set"), ClassUnderTest.GetWallet().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FPusherChannels ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("Asset is set"), ClassUnderTest.GetAsset().IsSet());
			TestTrue(TEXT("Player is set"), ClassUnderTest.GetPlayer().IsSet());
			TestTrue(TEXT("Project is set"), ClassUnderTest.GetProject().IsSet());
			TestTrue(TEXT("Wallet is set"), ClassUnderTest.GetWallet().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FPusherChannels ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume Asset is set"), ClassUnderTest.GetAsset().IsSet());
			TestTrue(TEXT("Assume Player is set"), ClassUnderTest.GetPlayer().IsSet());
			TestTrue(TEXT("Assume Project is set"), ClassUnderTest.GetProject().IsSet());
			TestTrue(TEXT("Assume Wallet is set"), ClassUnderTest.GetWallet().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("Asset is not set"), ClassUnderTest.GetAsset().IsSet());
			TestFalse(TEXT("Player is not set"), ClassUnderTest.GetPlayer().IsSet());
			TestFalse(TEXT("Project is not set"), ClassUnderTest.GetProject().IsSet());
			TestFalse(TEXT("Wallet is not set"), ClassUnderTest.GetWallet().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FPusherChannels Lhs;
			const FPusherChannels Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FPusherChannels Lhs;
			const FPusherChannels Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FPusherChannels Lhs;
			FPusherChannels Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FPusherChannels Lhs;
			FPusherChannels Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
