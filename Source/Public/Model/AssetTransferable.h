// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Represents the transferable types of a asset.
 */
enum class EAssetTransferable
{
	/**
	 * @brief SDK value for unknown values from the platform.
	 */
	Unknown,

	Bound,
	Permanent,
	Temporary,
};

/**
 * @brief Deserializes the asset transferable from a string.
 * @param String The serialized string.
 * @return The asset transferable.
 */
ENJINSDK_API EAssetTransferable ToAssetTransferable(const FString& String);

/**
 * @brief Serializes the asset transferable into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDK_API const TCHAR* ToString(const EAssetTransferable Value);
}
}
}
