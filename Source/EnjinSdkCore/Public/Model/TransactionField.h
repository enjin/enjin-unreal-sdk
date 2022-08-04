// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief The fields of a Transaction type for sorting.
 */
enum class ETransactionField
{
	CreatedAt,
	Id,
	State,
	Title,
	UpdatedAt,
};

/**
 * @brief Serializes the transaction field into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDKCORE_API const TCHAR* ToString(const ETransactionField Value);
}
}
}
