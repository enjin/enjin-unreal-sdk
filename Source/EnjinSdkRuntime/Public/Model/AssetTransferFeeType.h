// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Represents the different transfer types for assets.
 */
enum class EAssetTransferFeeType
{
	/**
	 * @brief SDK value for unknown values from the platform.
	 */
	Unknown,

	PerCryptoItem,
	PerTransfer,
	None,
	RatioCut,
	RatioExtra,
};

/**
 * @brief Deserializes the asset transfer fee type from a string.
 * @param String The serialized string.
 * @return The asset transfer fee type.
 */
ENJINSDK_API EAssetTransferFeeType ToAssetTransferFeeType(const FString& String);

/**
 * @brief Serializes the asset transfer fee type into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDK_API const TCHAR* ToString(const EAssetTransferFeeType Value);
}
}
}
