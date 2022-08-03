// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Enum for sort direction in sorting inputs.
 */
enum class ESortDirection
{
	Ascending,
	Descending,
};

/**
 * @brief Serializes the sort direction into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDKCORE_API const TCHAR* ToString(const ESortDirection Value);
}
}
}
