// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Represents the values used to specify the format to render an asset's ID in.
 */
enum class EAssetIdFormat
{
	Hex64,
	Hex256,
	UInt256,
};

/**
 * @brief Serializes the asset ID format into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDKRUNTIME_API const TCHAR* ToString(const EAssetIdFormat Value);
}
}
}
