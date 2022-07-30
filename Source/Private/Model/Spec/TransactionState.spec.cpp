// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/TransactionState.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FTransactionStateSpec,
				  "Enjin.Sdk.Model.TransactionState",
				  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FTransactionStateSpec)

void FTransactionStateSpec::Define()
{
	Describe("ToTransactionState returns correct value for given parameter", [this]()
	{
		TArray<TPair<FString, ETransactionState>> Params =
		{
			TPair<FString, ETransactionState>(TEXT(""), ETransactionState::Unknown),
			TPair<FString, ETransactionState>(TEXT("BROADCAST"), ETransactionState::Broadcast),
			TPair<FString, ETransactionState>(TEXT("CANCELED_PLATFORM"), ETransactionState::CanceledPlatform),
			TPair<FString, ETransactionState>(TEXT("CANCELED_USER"), ETransactionState::CanceledUser),
			TPair<FString, ETransactionState>(TEXT("DROPPED"), ETransactionState::Dropped),
			TPair<FString, ETransactionState>(TEXT("EXECUTED"), ETransactionState::Executed),
			TPair<FString, ETransactionState>(TEXT("FAILED"), ETransactionState::Failed),
			TPair<FString, ETransactionState>(TEXT("PENDING"), ETransactionState::Pending),
			TPair<FString, ETransactionState>(TEXT("TP_PROCESSING"), ETransactionState::TpProcessing),
		};

		for (const TPair<FString, ETransactionState> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Key), [this, Param]()
			{
				// Arrange
				const ETransactionState Expected = Param.Value;
				const FString Input = Param.Key;

				// Act
				const ETransactionState Actual = ToTransactionState(Input);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});

	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<ETransactionState, FString>> Params =
		{
			TPair<ETransactionState, FString>(ETransactionState::Unknown, TEXT("")),
			TPair<ETransactionState, FString>(ETransactionState::Broadcast, TEXT("BROADCAST")),
			TPair<ETransactionState, FString>(ETransactionState::CanceledPlatform, TEXT("CANCELED_PLATFORM")),
			TPair<ETransactionState, FString>(ETransactionState::CanceledUser, TEXT("CANCELED_USER")),
			TPair<ETransactionState, FString>(ETransactionState::Dropped, TEXT("DROPPED")),
			TPair<ETransactionState, FString>(ETransactionState::Executed, TEXT("EXECUTED")),
			TPair<ETransactionState, FString>(ETransactionState::Failed, TEXT("FAILED")),
			TPair<ETransactionState, FString>(ETransactionState::Pending, TEXT("PENDING")),
			TPair<ETransactionState, FString>(ETransactionState::TpProcessing, TEXT("TP_PROCESSING")),
		};

		for (const TPair<ETransactionState, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const ETransactionState EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
