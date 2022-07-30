// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Represents the mode that determines variant behavior.
 */
enum class EAssetVariantMode
{
	/**
	 * @brief SDK value for unknown values from the platform.
	 */
	Unknown,

	Always,
	Beam,
	None,
	Once,
};

/**
 * @brief Deserializes the asset variant mode from a string.
 * @param String The serialized string.
 * @return The asset variant mode.
 */
ENJINSDK_API EAssetVariantMode ToAssetVariantMode(const FString& String);
}
}
}
