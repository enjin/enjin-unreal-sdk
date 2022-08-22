// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Represents the state of a transaction.
 */
enum class ETransactionState
{
	/**
	 * @brief SDK value for unknown values from the platform.
	 */
	Unknown,

	Broadcast,
	CanceledPlatform,
	CanceledUser,
	Dropped,
	Executed,
	Failed,
	Pending,
	TpProcessing,
};

/**
 * @brief Serializes the transaction state into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDKCORE_API const TCHAR* ToString(const ETransactionState Value);

/**
 * @brief Deserializes the transaction state from a string.
 * @param String The serialized string.
 * @return The transaction state.
 */
ENJINSDKCORE_API ETransactionState ToTransactionState(const FString& String);
}
}
}
