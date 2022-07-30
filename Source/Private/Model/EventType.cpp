// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/EventType.h"

using namespace Enjin::Sdk::Model;

EEventType Enjin::Sdk::Model::ToEventType(const FString& String)
{
	const FString S = String.ToUpper();

	if (S.Equals(TEXT("ASSET_CREATED")))
	{
		return EEventType::AssetCreated;
	}

	if (S.Equals(TEXT("ASSET_MELTED")))
	{
		return EEventType::AssetMelted;
	}

	if (S.Equals(TEXT("ASSET_MINTED")))
	{
		return EEventType::AssetMinted;
	}

	if (S.Equals(TEXT("ASSET_TRANSFERRED")))
	{
		return EEventType::AssetTransferred;
	}

	if (S.Equals(TEXT("ASSET_UPDATED")))
	{
		return EEventType::AssetUpdated;
	}

	if (S.Equals(TEXT("BLOCKCHAIN_LOG_PROCESSED")))
	{
		return EEventType::BlockchainLogProcessed;
	}

	if (S.Equals(TEXT("MESSAGE_PROCESSED")))
	{
		return EEventType::MessageProcessed;
	}

	if (S.Equals(TEXT("PLAYER_CREATED")))
	{
		return EEventType::PlayerCreated;
	}

	if (S.Equals(TEXT("PLAYER_DELETED")))
	{
		return EEventType::PlayerDeleted;
	}

	if (S.Equals(TEXT("PLAYER_LINKED")))
	{
		return EEventType::PlayerLinked;
	}

	if (S.Equals(TEXT("PLAYER_UNLINKED")))
	{
		return EEventType::PlayerUnlinked;
	}

	if (S.Equals(TEXT("PLAYER_UPDATED")))
	{
		return EEventType::PlayerUpdated;
	}

	if (S.Equals(TEXT("PROJECT_CREATED")))
	{
		return EEventType::ProjectCreated;
	}

	if (S.Equals(TEXT("PROJECT_DELETED")))
	{
		return EEventType::ProjectDeleted;
	}

	if (S.Equals(TEXT("PROJECT_LINKED")))
	{
		return EEventType::ProjectLinked;
	}

	if (S.Equals(TEXT("PROJECT_LOCKED")))
	{
		return EEventType::ProjectLocked;
	}

	if (S.Equals(TEXT("PROJECT_UNLINKED")))
	{
		return EEventType::ProjectUnlinked;
	}

	if (S.Equals(TEXT("PROJECT_UNLOCKED")))
	{
		return EEventType::ProjectUnlocked;
	}

	if (S.Equals(TEXT("PROJECT_UPDATED")))
	{
		return EEventType::ProjectUpdated;
	}

	if (S.Equals(TEXT("TRADE_ASSET_COMPLETED")))
	{
		return EEventType::TradeAssetCompleted;
	}

	if (S.Equals(TEXT("TRADE_ASSET_CREATED")))
	{
		return EEventType::TradeAssetCreated;
	}

	if (S.Equals(TEXT("TRANSACTION_BROADCAST")))
	{
		return EEventType::TransactionBroadcast;
	}

	if (S.Equals(TEXT("TRANSACTION_CANCELED")))
	{
		return EEventType::TransactionCanceled;
	}

	if (S.Equals(TEXT("TRANSACTION_DROPPED")))
	{
		return EEventType::TransactionDropped;
	}

	if (S.Equals(TEXT("TRANSACTION_EXECUTED")))
	{
		return EEventType::TransactionExecuted;
	}

	if (S.Equals(TEXT("TRANSACTION_FAILED")))
	{
		return EEventType::TransactionFailed;
	}

	if (S.Equals(TEXT("TRANSACTION_PENDING")))
	{
		return EEventType::TransactionPending;
	}

	if (S.Equals(TEXT("TRANSACTION_PROCESSING")))
	{
		return EEventType::TransactionProcessing;
	}

	if (S.Equals(TEXT("TRANSACTION_UPDATED")))
	{
		return EEventType::TransactionUpdated;
	}

	return EEventType::Unknown;
}

const TCHAR* Enjin::Sdk::Model::ToString(const EEventType Value)
{
	switch (Value)
	{
		case EEventType::AssetCreated:
			return TEXT("ASSET_CREATED");

		case EEventType::AssetMelted:
			return TEXT("ASSET_MELTED");

		case EEventType::AssetMinted:
			return TEXT("ASSET_MINTED");

		case EEventType::AssetTransferred:
			return TEXT("ASSET_TRANSFERRED");

		case EEventType::AssetUpdated:
			return TEXT("ASSET_UPDATED");

		case EEventType::BlockchainLogProcessed:
			return TEXT("BLOCKCHAIN_LOG_PROCESSED");

		case EEventType::MessageProcessed:
			return TEXT("MESSAGE_PROCESSED");

		case EEventType::PlayerCreated:
			return TEXT("PLAYER_CREATED");

		case EEventType::PlayerDeleted:
			return TEXT("PLAYER_DELETED");

		case EEventType::PlayerLinked:
			return TEXT("PLAYER_LINKED");

		case EEventType::PlayerUnlinked:
			return TEXT("PLAYER_UNLINKED");

		case EEventType::PlayerUpdated:
			return TEXT("PLAYER_UPDATED");

		case EEventType::ProjectCreated:
			return TEXT("PROJECT_CREATED");

		case EEventType::ProjectDeleted:
			return TEXT("PROJECT_DELETED");

		case EEventType::ProjectLinked:
			return TEXT("PROJECT_LINKED");

		case EEventType::ProjectLocked:
			return TEXT("PROJECT_LOCKED");

		case EEventType::ProjectUnlinked:
			return TEXT("PROJECT_UNLINKED");

		case EEventType::ProjectUnlocked:
			return TEXT("PROJECT_UNLOCKED");

		case EEventType::ProjectUpdated:
			return TEXT("PROJECT_UPDATED");

		case EEventType::TradeAssetCompleted:
			return TEXT("TRADE_ASSET_COMPLETED");

		case EEventType::TradeAssetCreated:
			return TEXT("TRADE_ASSET_CREATED");

		case EEventType::TransactionBroadcast:
			return TEXT("TRANSACTION_BROADCAST");

		case EEventType::TransactionCanceled:
			return TEXT("TRANSACTION_CANCELED");

		case EEventType::TransactionDropped:
			return TEXT("TRANSACTION_DROPPED");

		case EEventType::TransactionExecuted:
			return TEXT("TRANSACTION_EXECUTED");

		case EEventType::TransactionFailed:
			return TEXT("TRANSACTION_FAILED");

		case EEventType::TransactionPending:
			return TEXT("TRANSACTION_PENDING");

		case EEventType::TransactionProcessing:
			return TEXT("TRANSACTION_PROCESSING");

		case EEventType::TransactionUpdated:
			return TEXT("TRANSACTION_UPDATED");

		default:
			return TEXT("");
	}
}
