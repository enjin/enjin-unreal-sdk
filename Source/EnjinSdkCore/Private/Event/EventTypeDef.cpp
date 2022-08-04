// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "EventTypeDef.h"

#include "Model/EventType.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

struct FEventTypeDef::FStaticFields
{
	/**
	 * @brief Mapping for event type enums and their definitions.
	 */
	TMap<EEventType, FEventTypeDef> DefsMap;

	/**
	 * @brief Array holding the mapped event type definition values.
	 */
	TArray<FEventTypeDef> MappedValues;

	/**
	 * @brief Constructs an instance of this struct.
	 */
	FStaticFields()
	{
		const FString AssetChannel = TEXT("asset");
		const FString PlayerChannel = TEXT("player");
		const FString ProjectChannel = TEXT("project");
		const FString WalletChannel = TEXT("wallet");

		DefsMap.Add(EEventType::Unknown,
		            FEventTypeDef(EEventType::Unknown,
		                          TEXT(""),
		                          {}));
		DefsMap.Add(EEventType::AssetCreated,
		            FEventTypeDef(EEventType::AssetCreated,
		                          TEXT("EnjinCloud\\Events\\AssetCreated"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::AssetMelted,
		            FEventTypeDef(EEventType::AssetMelted,
		                          TEXT("EnjinCloud\\Events\\AssetMelted"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::AssetMinted,
		            FEventTypeDef(EEventType::AssetMinted,
		                          TEXT("EnjinCloud\\Events\\AssetMinted"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::AssetTransferred,
		            FEventTypeDef(EEventType::AssetTransferred,
		                          TEXT("EnjinCloud\\Events\\AssetTransferred"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::AssetUpdated,
		            FEventTypeDef(EEventType::AssetUpdated,
		                          TEXT("EnjinCloud\\Events\\AssetUpdated"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::BlockchainLogProcessed,
		            FEventTypeDef(EEventType::BlockchainLogProcessed,
		                          TEXT("EnjinCloud\\Events\\BlockchainLogProcessed"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::MessageProcessed,
		            FEventTypeDef(EEventType::MessageProcessed,
		                          TEXT("EnjinCloud\\Events\\MessageProcessed"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::PlayerCreated,
		            FEventTypeDef(EEventType::PlayerCreated,
		                          TEXT("EnjinCloud\\Events\\PlayerCreated"),
		                          {PlayerChannel, ProjectChannel}));
		DefsMap.Add(EEventType::PlayerDeleted,
		            FEventTypeDef(EEventType::PlayerDeleted,
		                          TEXT("EnjinCloud\\Events\\PlayerDeleted"),
		                          {PlayerChannel, ProjectChannel}));
		DefsMap.Add(EEventType::PlayerLinked,
		            FEventTypeDef(EEventType::PlayerLinked,
		                          TEXT("EnjinCloud\\Events\\PlayerLinked"),
		                          {PlayerChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::PlayerUnlinked,
		            FEventTypeDef(EEventType::PlayerUnlinked,
		                          TEXT("EnjinCloud\\Events\\PlayerUnlinked"),
		                          {PlayerChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::PlayerUpdated,
		            FEventTypeDef(EEventType::PlayerUpdated,
		                          TEXT("EnjinCloud\\Events\\PlayerUpdated"),
		                          {PlayerChannel, ProjectChannel}));
		DefsMap.Add(EEventType::ProjectCreated,
		            FEventTypeDef(EEventType::ProjectCreated,
		                          TEXT("EnjinCloud\\Events\\ProjectCreated"),
		                          {ProjectChannel}));
		DefsMap.Add(EEventType::ProjectDeleted,
		            FEventTypeDef(EEventType::ProjectDeleted,
		                          TEXT("EnjinCloud\\Events\\ProjectDeleted"),
		                          {ProjectChannel}));
		DefsMap.Add(EEventType::ProjectLinked,
		            FEventTypeDef(EEventType::ProjectLinked,
		                          TEXT("EnjinCloud\\Events\\ProjectLinked"),
		                          {ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::ProjectLocked,
		            FEventTypeDef(EEventType::ProjectLocked,
		                          TEXT("EnjinCloud\\Events\\ProjectLocked"),
		                          {ProjectChannel}));
		DefsMap.Add(EEventType::ProjectUnlinked,
		            FEventTypeDef(EEventType::ProjectUnlinked,
		                          TEXT("EnjinCloud\\Events\\ProjectUnlinked"),
		                          {ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::ProjectUnlocked,
		            FEventTypeDef(EEventType::ProjectUnlocked,
		                          TEXT("EnjinCloud\\Events\\ProjectUnlocked"),
		                          {ProjectChannel}));
		DefsMap.Add(EEventType::ProjectUpdated,
		            FEventTypeDef(EEventType::ProjectUpdated,
		                          TEXT("EnjinCloud\\Events\\ProjectUpdated"),
		                          {ProjectChannel}));
		DefsMap.Add(EEventType::TradeAssetCompleted,
		            FEventTypeDef(EEventType::TradeAssetCompleted,
		                          TEXT("EnjinCloud\\Events\\TradeAssetCompleted"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::TradeAssetCreated,
		            FEventTypeDef(EEventType::TradeAssetCreated,
		                          TEXT("EnjinCloud\\Events\\TradeAssetCreated"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::TransactionBroadcast,
		            FEventTypeDef(EEventType::TransactionBroadcast,
		                          TEXT("EnjinCloud\\Events\\TransactionBroadcast"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::TransactionCanceled,
		            FEventTypeDef(EEventType::TransactionCanceled,
		                          TEXT("EnjinCloud\\Events\\TransactionCanceled"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::TransactionDropped,
		            FEventTypeDef(EEventType::TransactionDropped,
		                          TEXT("EnjinCloud\\Events\\TransactionDropped"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::TransactionExecuted,
		            FEventTypeDef(EEventType::TransactionExecuted,
		                          TEXT("EnjinCloud\\Events\\TransactionExecuted"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::TransactionFailed,
		            FEventTypeDef(EEventType::TransactionFailed,
		                          TEXT("EnjinCloud\\Events\\TransactionFailed"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::TransactionPending,
		            FEventTypeDef(EEventType::TransactionPending,
		                          TEXT("EnjinCloud\\Events\\TransactionPending"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::TransactionProcessing,
		            FEventTypeDef(EEventType::TransactionProcessing,
		                          TEXT("EnjinCloud\\Events\\TransactionProcessing"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));
		DefsMap.Add(EEventType::TransactionUpdated,
		            FEventTypeDef(EEventType::TransactionUpdated,
		                          TEXT("EnjinCloud\\Events\\TransactionUpdated"),
		                          {AssetChannel, ProjectChannel, WalletChannel}));

		DefsMap.GenerateValueArray(MappedValues);
	}
};

const TUniquePtr<FEventTypeDef::FStaticFields> FEventTypeDef::StaticFieldsPtr =
	MakeUnique<FEventTypeDef::FStaticFields>();

FEventTypeDef::FEventTypeDef()
	: Type(EEventType::Unknown),
	  Channels({}),
	  Name(ToString(Type))
{
}

FEventTypeDef::FEventTypeDef(const EEventType Type, FString Key, TArray<FString> Channels)
	: Type(Type),
	  Channels(MoveTemp(Channels)),
	  Key(MoveTemp(Key)),
	  Name(ToString(Type))
{
}

const TArray<FString>& FEventTypeDef::GetChannels() const
{
	return Channels;
}

const FString& FEventTypeDef::GetKey() const
{
	return Key;
}

const FString& FEventTypeDef::GetName() const
{
	return Name;
}

EEventType FEventTypeDef::GetType() const
{
	return Type;
}

bool FEventTypeDef::operator==(const FEventTypeDef& Rhs) const
{
	return Type == Rhs.Type
		&& Channels == Rhs.Channels
		&& Key == Rhs.Key
		&& Name == Rhs.Name;
}

bool FEventTypeDef::operator!=(const FEventTypeDef& Rhs) const
{
	return !(*this == Rhs);
}

TArray<FEventTypeDef> FEventTypeDef::FilterByChannel(const FString& Channel)
{
	TArray<FEventTypeDef> DefsArray;

	for (const FEventTypeDef& Def : StaticFieldsPtr->MappedValues)
	{
		for (const FString& C : Def.Channels)
		{
			if (Channel.Contains(C))
			{
				DefsArray.Add(Def);
				break;
			}
		}
	}

	return DefsArray;
}

const FEventTypeDef& FEventTypeDef::GetFromKey(const FString& Key)
{
	for (const FEventTypeDef& Def : StaticFieldsPtr->MappedValues)
	{
		if (Def.Key.Equals(Key))
		{
			return Def;
		}
	}

	return StaticFieldsPtr->DefsMap[EEventType::Unknown];
}

const FEventTypeDef& FEventTypeDef::GetFromName(const FString& Name)
{
	for (const FEventTypeDef& Def : StaticFieldsPtr->MappedValues)
	{
		if (Def.Name.Equals(Name))
		{
			return Def;
		}
	}

	return StaticFieldsPtr->DefsMap[EEventType::Unknown];
}

const TArray<FEventTypeDef>& FEventTypeDef::Values()
{
	return StaticFieldsPtr->MappedValues;
}
