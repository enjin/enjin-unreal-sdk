// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "EventListenerRegistration.h"
#include "Misc/AutomationTest.h"
#include "Model/EventType.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FEventListenerRegistrationSpec,
                  "Enjin.Sdk.Event.EventListenerRegistration",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	const TArray<EEventType> Types =
	{
		EEventType::Unknown,
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

END_DEFINE_SPEC(FEventListenerRegistrationSpec)

void FEventListenerRegistrationSpec::Define()
{
	Describe(TEXT("Allow all matcher"), [this]()
	{
		for (const EEventType Param : Types)
		{
			const FString EnumName = ToString(Param);

			It(FString::Printf(TEXT("should resolve '%s' as true"), *EnumName), [this, Param]()
			{
				// Arrange
				const EEventType Type = Param;
				const FEventMatcher Matcher = FEventListenerRegistration::AllowAllMatcher;

				// Act
				const bool Actual = Matcher(Type);

				// Assert
				TestTrue(TEXT("Matcher returned false"), Actual);
			});
		}
	});
}
