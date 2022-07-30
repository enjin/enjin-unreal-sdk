// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief The operator type for filters.
 */
enum class EOperator
{
	GreaterThan,
	GreaterThanOrEqual,
	LessThan,
	LessThanOrEqual,
};

/**
 * @brief Serializes the operator into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDK_API const TCHAR* ToString(const EOperator Value);
}
}
}
