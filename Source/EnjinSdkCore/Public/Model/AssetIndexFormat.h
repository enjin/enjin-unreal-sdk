// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Represents the values used to specify the format to render an asset's index in.
 */
enum class EAssetIndexFormat
{
	Hex64,
	UInt64,
};

/**
 * @brief Serializes the asset index format into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDKCORE_API const TCHAR* ToString(const EAssetIndexFormat Value);
}
}
}
