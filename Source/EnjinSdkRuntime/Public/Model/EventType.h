// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Enums defining the different types of notifications that may be received from the platform.
 */
enum class EEventType
{
	/**
	 * @brief SDK value for unknown event types.
	 */
	Unknown,

	AssetCreated,
	AssetMelted,
	AssetMinted,
	AssetTransferred,
	AssetUpdated,
	BlockchainLogProcessed,
	MessageProcessed,
	PlayerCreated,
	PlayerDeleted,
	PlayerLinked,
	PlayerUnlinked,
	PlayerUpdated,
	ProjectCreated,
	ProjectDeleted,
	ProjectLinked,
	ProjectLocked,
	ProjectUnlinked,
	ProjectUnlocked,
	ProjectUpdated,
	TradeAssetCompleted,
	TradeAssetCreated,
	TransactionBroadcast,
	TransactionCanceled,
	TransactionDropped,
	TransactionExecuted,
	TransactionFailed,
	TransactionPending,
	TransactionProcessing,
	TransactionUpdated,
};

/**
 * @brief Deserializes the event type from a string.
 * @param String The serialized string.
 * @return The event type.
 */
ENJINSDKRUNTIME_API EEventType ToEventType(const FString& String);

/**
 * @brief Serializes the event type into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDKRUNTIME_API const TCHAR* ToString(const EEventType Value);
}
}
}
