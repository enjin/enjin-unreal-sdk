// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Event/EventTypeDef.h"
#include "Misc/AutomationTest.h"
#include "Model/EventType.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FEventTypeDefSpec,
                  "Enjin.Sdk.Event.EventTypeDef",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FEventTypeDefSpec)

void FEventTypeDefSpec::Define()
{
	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should return true when both sides are the same definition"), [this]()
		{
			// Arrange
			const FString Name = ToString(EEventType::AssetCreated);
			const FEventTypeDef Lhs = FEventTypeDef::GetFromName(Name);
			const FEventTypeDef Rhs = FEventTypeDef::GetFromName(Name);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should return false when both sides are not the same definition"), [this]()
		{
			// Arrange
			const FString LhsName = ToString(EEventType::AssetCreated);
			const FString RhsName = ToString(EEventType::PlayerCreated);
			const FEventTypeDef Lhs = FEventTypeDef::GetFromName(LhsName);
			const FEventTypeDef Rhs = FEventTypeDef::GetFromName(RhsName);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});
	});

	Describe(TEXT("Get definition from event key"), [this]()
	{
		TArray<TPair<FString, EEventType>> Params =
		{
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\AssetCreated"),
			                           EEventType::AssetCreated),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\AssetMelted"),
			                           EEventType::AssetMelted),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\AssetMinted"),
			                           EEventType::AssetMinted),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\AssetTransferred"),
			                           EEventType::AssetTransferred),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\AssetUpdated"),
			                           EEventType::AssetUpdated),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\BlockchainLogProcessed"),
			                           EEventType::BlockchainLogProcessed),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\MessageProcessed"),
			                           EEventType::MessageProcessed),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\PlayerCreated"),
			                           EEventType::PlayerCreated),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\PlayerDeleted"),
			                           EEventType::PlayerDeleted),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\PlayerLinked"),
			                           EEventType::PlayerLinked),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\PlayerUnlinked"),
			                           EEventType::PlayerUnlinked),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\PlayerUpdated"),
			                           EEventType::PlayerUpdated),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\ProjectCreated"),
			                           EEventType::ProjectCreated),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\ProjectDeleted"),
			                           EEventType::ProjectDeleted),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\ProjectLinked"),
			                           EEventType::ProjectLinked),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\ProjectLocked"),
			                           EEventType::ProjectLocked),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\ProjectUnlinked"),
			                           EEventType::ProjectUnlinked),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\ProjectUnlocked"),
			                           EEventType::ProjectUnlocked),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\ProjectUpdated"),
			                           EEventType::ProjectUpdated),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\TradeAssetCompleted"),
			                           EEventType::TradeAssetCompleted),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\TradeAssetCreated"),
			                           EEventType::TradeAssetCreated),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\TransactionBroadcast"),
			                           EEventType::TransactionBroadcast),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\TransactionCanceled"),
			                           EEventType::TransactionCanceled),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\TransactionDropped"),
			                           EEventType::TransactionDropped),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\TransactionExecuted"),
			                           EEventType::TransactionExecuted),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\TransactionFailed"),
			                           EEventType::TransactionFailed),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\TransactionPending"),
			                           EEventType::TransactionPending),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\TransactionProcessing"),
			                           EEventType::TransactionProcessing),
			TPair<FString, EEventType>(TEXT("EnjinCloud\\Events\\TransactionUpdated"),
			                           EEventType::TransactionUpdated),
		};

		// Checks if there are more definitions than types arranged (ignores presumed definition for 'Unknown' type)
		if (FEventTypeDef::Values().Num() - 1 > Params.Num())
		{
			UE_LOG(LogTemp, Warning, TEXT("More definitions detected than event types arranged for test"));
		}

		for (const TPair<FString, EEventType>& Param : Params)
		{
			const FString TypeName = ToString(Param.Value);

			It(FString::Printf(TEXT("should resolve for '%s'"), *TypeName), [this, Param]()
			{
				// Arrange
				const FString Key = Param.Key;
				const EEventType Expected = Param.Value;

				// Act
				const EEventType Actual = FEventTypeDef::GetFromKey(Key).GetType();

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});

	Describe(TEXT("Get definition from event name"), [this]()
	{
		TArray<EEventType> Types =
		{
			EEventType::AssetCreated,
			EEventType::AssetMelted,
			EEventType::AssetMinted,
			EEventType::AssetTransferred,
			EEventType::AssetUpdated,
			EEventType::BlockchainLogProcessed,
			EEventType::MessageProcessed,
			EEventType::PlayerCreated,
			EEventType::PlayerDeleted,
			EEventType::PlayerLinked,
			EEventType::PlayerUnlinked,
			EEventType::PlayerUpdated,
			EEventType::ProjectCreated,
			EEventType::ProjectDeleted,
			EEventType::ProjectLinked,
			EEventType::ProjectLocked,
			EEventType::ProjectUnlinked,
			EEventType::ProjectUnlocked,
			EEventType::ProjectUpdated,
			EEventType::TradeAssetCompleted,
			EEventType::TradeAssetCreated,
			EEventType::TransactionBroadcast,
			EEventType::TransactionCanceled,
			EEventType::TransactionDropped,
			EEventType::TransactionExecuted,
			EEventType::TransactionFailed,
			EEventType::TransactionPending,
			EEventType::TransactionProcessing,
			EEventType::TransactionUpdated,
		};

		// Checks if there are more definitions than types arranged (ignores presumed definition for 'Unknown' type)
		if (FEventTypeDef::Values().Num() - 1 > Types.Num())
		{
			UE_LOG(LogTemp, Warning, TEXT("More definitions detected than event types arranged for test"));
		}

		for (const EEventType Type : Types)
		{
			const FString TypeName = ToString(Type);
			const TPair<FString, EEventType> Param(TypeName, Type);

			It(FString::Printf(TEXT("should resolve for '%s'"), *TypeName), [this, Param]()
			{
				// Arrange
				const FString Name = Param.Key;
				const EEventType Expected = Param.Value;

				// Act
				const EEventType Actual = FEventTypeDef::GetFromName(Name).GetType();

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
