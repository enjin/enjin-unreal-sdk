// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief The fields of a Asset type for sorting.
 */
enum class EAssetField
{
	CirculatingSupply,
	CreatedAt,
	Id,
	Name,
	NonFungible,
	Reserve,
	TotalSupply,
};

/**
 * @brief Serializes the asset field into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDK_API const TCHAR* ToString(const EAssetField Value);
}
}
}
