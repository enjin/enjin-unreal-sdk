// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/EventType.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FEventTypeSpec,
                  "Enjin.Sdk.Model.EventType",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FEventTypeSpec)

void FEventTypeSpec::Define()
{
	Describe("ToEventType returns correct value for given parameter", [this]()
	{
		TArray<TPair<FString, EEventType>> Params =
		{
			TPair<FString, EEventType>(TEXT(""), EEventType::Unknown),
			TPair<FString, EEventType>(TEXT("ASSET_CREATED"), EEventType::AssetCreated),
			TPair<FString, EEventType>(TEXT("ASSET_MELTED"), EEventType::AssetMelted),
			TPair<FString, EEventType>(TEXT("ASSET_MINTED"), EEventType::AssetMinted),
			TPair<FString, EEventType>(TEXT("ASSET_TRANSFERRED"), EEventType::AssetTransferred),
			TPair<FString, EEventType>(TEXT("ASSET_UPDATED"), EEventType::AssetUpdated),
			TPair<FString, EEventType>(TEXT("BLOCKCHAIN_LOG_PROCESSED"), EEventType::BlockchainLogProcessed),
			TPair<FString, EEventType>(TEXT("MESSAGE_PROCESSED"), EEventType::MessageProcessed),
			TPair<FString, EEventType>(TEXT("PLAYER_CREATED"), EEventType::PlayerCreated),
			TPair<FString, EEventType>(TEXT("PLAYER_DELETED"), EEventType::PlayerDeleted),
			TPair<FString, EEventType>(TEXT("PLAYER_LINKED"), EEventType::PlayerLinked),
			TPair<FString, EEventType>(TEXT("PLAYER_UNLINKED"), EEventType::PlayerUnlinked),
			TPair<FString, EEventType>(TEXT("PLAYER_UPDATED"), EEventType::PlayerUpdated),
			TPair<FString, EEventType>(TEXT("PROJECT_CREATED"), EEventType::ProjectCreated),
			TPair<FString, EEventType>(TEXT("PROJECT_DELETED"), EEventType::ProjectDeleted),
			TPair<FString, EEventType>(TEXT("PROJECT_LINKED"), EEventType::ProjectLinked),
			TPair<FString, EEventType>(TEXT("PROJECT_LOCKED"), EEventType::ProjectLocked),
			TPair<FString, EEventType>(TEXT("PROJECT_UNLINKED"), EEventType::ProjectUnlinked),
			TPair<FString, EEventType>(TEXT("PROJECT_UNLOCKED"), EEventType::ProjectUnlocked),
			TPair<FString, EEventType>(TEXT("PROJECT_UPDATED"), EEventType::ProjectUpdated),
			TPair<FString, EEventType>(TEXT("TRADE_ASSET_COMPLETED"), EEventType::TradeAssetCompleted),
			TPair<FString, EEventType>(TEXT("TRADE_ASSET_CREATED"), EEventType::TradeAssetCreated),
			TPair<FString, EEventType>(TEXT("TRANSACTION_BROADCAST"), EEventType::TransactionBroadcast),
			TPair<FString, EEventType>(TEXT("TRANSACTION_CANCELED"), EEventType::TransactionCanceled),
			TPair<FString, EEventType>(TEXT("TRANSACTION_DROPPED"), EEventType::TransactionDropped),
			TPair<FString, EEventType>(TEXT("TRANSACTION_EXECUTED"), EEventType::TransactionExecuted),
			TPair<FString, EEventType>(TEXT("TRANSACTION_FAILED"), EEventType::TransactionFailed),
			TPair<FString, EEventType>(TEXT("TRANSACTION_PENDING"), EEventType::TransactionPending),
			TPair<FString, EEventType>(TEXT("TRANSACTION_PROCESSING"), EEventType::TransactionProcessing),
			TPair<FString, EEventType>(TEXT("TRANSACTION_UPDATED"), EEventType::TransactionUpdated),
		};

		for (const TPair<FString, EEventType> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Key), [this, Param]()
			{
				// Arrange
				const EEventType Expected = Param.Value;
				const FString Input = Param.Key;

				// Act
				const EEventType Actual = ToEventType(Input);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});

	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<EEventType, FString>> Params =
		{
			TPair<EEventType, FString>(EEventType::Unknown, TEXT("")),
			TPair<EEventType, FString>(EEventType::AssetCreated, TEXT("ASSET_CREATED")),
			TPair<EEventType, FString>(EEventType::AssetMelted, TEXT("ASSET_MELTED")),
			TPair<EEventType, FString>(EEventType::AssetMinted, TEXT("ASSET_MINTED")),
			TPair<EEventType, FString>(EEventType::AssetTransferred, TEXT("ASSET_TRANSFERRED")),
			TPair<EEventType, FString>(EEventType::AssetUpdated, TEXT("ASSET_UPDATED")),
			TPair<EEventType, FString>(EEventType::BlockchainLogProcessed, TEXT("BLOCKCHAIN_LOG_PROCESSED")),
			TPair<EEventType, FString>(EEventType::MessageProcessed, TEXT("MESSAGE_PROCESSED")),
			TPair<EEventType, FString>(EEventType::PlayerCreated, TEXT("PLAYER_CREATED")),
			TPair<EEventType, FString>(EEventType::PlayerDeleted, TEXT("PLAYER_DELETED")),
			TPair<EEventType, FString>(EEventType::PlayerLinked, TEXT("PLAYER_LINKED")),
			TPair<EEventType, FString>(EEventType::PlayerUnlinked, TEXT("PLAYER_UNLINKED")),
			TPair<EEventType, FString>(EEventType::PlayerUpdated, TEXT("PLAYER_UPDATED")),
			TPair<EEventType, FString>(EEventType::ProjectCreated, TEXT("PROJECT_CREATED")),
			TPair<EEventType, FString>(EEventType::ProjectDeleted, TEXT("PROJECT_DELETED")),
			TPair<EEventType, FString>(EEventType::ProjectLinked, TEXT("PROJECT_LINKED")),
			TPair<EEventType, FString>(EEventType::ProjectLocked, TEXT("PROJECT_LOCKED")),
			TPair<EEventType, FString>(EEventType::ProjectUnlinked, TEXT("PROJECT_UNLINKED")),
			TPair<EEventType, FString>(EEventType::ProjectUnlocked, TEXT("PROJECT_UNLOCKED")),
			TPair<EEventType, FString>(EEventType::ProjectUpdated, TEXT("PROJECT_UPDATED")),
			TPair<EEventType, FString>(EEventType::TradeAssetCompleted, TEXT("TRADE_ASSET_COMPLETED")),
			TPair<EEventType, FString>(EEventType::TradeAssetCreated, TEXT("TRADE_ASSET_CREATED")),
			TPair<EEventType, FString>(EEventType::TransactionBroadcast, TEXT("TRANSACTION_BROADCAST")),
			TPair<EEventType, FString>(EEventType::TransactionCanceled, TEXT("TRANSACTION_CANCELED")),
			TPair<EEventType, FString>(EEventType::TransactionDropped, TEXT("TRANSACTION_DROPPED")),
			TPair<EEventType, FString>(EEventType::TransactionExecuted, TEXT("TRANSACTION_EXECUTED")),
			TPair<EEventType, FString>(EEventType::TransactionFailed, TEXT("TRANSACTION_FAILED")),
			TPair<EEventType, FString>(EEventType::TransactionPending, TEXT("TRANSACTION_PENDING")),
			TPair<EEventType, FString>(EEventType::TransactionProcessing, TEXT("TRANSACTION_PROCESSING")),
			TPair<EEventType, FString>(EEventType::TransactionUpdated, TEXT("TRANSACTION_UPDATED")),
		};

		for (const TPair<EEventType, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const EEventType EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
