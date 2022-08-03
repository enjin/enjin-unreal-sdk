// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Represents the transaction type when creating or updating a transaction.
 */
enum class ETransactionType
{
	/**
	 * @brief SDK value for unknown values from the platform.
	 */
	Unknown,

	AcceptAssignment,
	AddLog,
	AdvancedSend,
	Approve,
	Assign,
	CancelTrade,
	Create,
	CreateTrade,
	DecreaseMaxMeltFee,
	DecreaseMaxTransferFee,
	ManageUpdate,
	Melt,
	Message,
	Mint,
	ReleaseReserve,
	Send,
	SendEnj,
	SetApprovalForAll,
	SetDecimals,
	SetItemUri,
	SetMeltFee,
	SetSymbol,
	SetTransferFee,
	SetTransferable,
	SetWhitelisted,
	UpdateName,
};

/**
 * @brief Serializes the transaction type into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDKRUNTIME_API const TCHAR* ToString(const ETransactionType Value);

/**
 * @brief Deserializes the transaction type from a string.
 * @param String The serialized string.
 * @return The transaction type.
 */
ENJINSDKRUNTIME_API ETransactionType ToTransactionType(const FString& String);
}
}
}
