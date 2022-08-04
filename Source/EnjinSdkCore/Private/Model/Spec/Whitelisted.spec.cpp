// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/Whitelisted.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FWhitelistedSpec,
                  "Enjin.Sdk.Model.Whitelisted",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FWhitelistedSpec)

void FWhitelistedSpec::Define()
{
	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<EWhitelisted, FString>> Params =
		{
			TPair<EWhitelisted, FString>(EWhitelisted::Address, TEXT("ADDRESS")),
			TPair<EWhitelisted, FString>(EWhitelisted::NoFees, TEXT("NO_FEES")),
			TPair<EWhitelisted, FString>(EWhitelisted::None, TEXT("NONE")),
			TPair<EWhitelisted, FString>(EWhitelisted::Receive, TEXT("RECEIVE")),
			TPair<EWhitelisted, FString>(EWhitelisted::Send, TEXT("SEND")),
			TPair<EWhitelisted, FString>(EWhitelisted::SendAndReceive, TEXT("SEND_AND_RECEIVE")),
		};

		for (const TPair<EWhitelisted, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const EWhitelisted EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
