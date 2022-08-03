// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Represents the values used to specify the supply model for a asset.
 */
enum class EAssetSupplyModel
{
	/**
	 * @brief SDK value for unknown values from the platform.
	 */
	Unknown,

	AnnualPercentage,
	AnnualValue,
	Collapsing,
	Fixed,
	Infinite,
	Settable,
};

/**
 * @brief Deserializes the asset supply model from a string.
 * @param String The serialized string.
 * @return The asset supply model.
 */
ENJINSDKRUNTIME_API EAssetSupplyModel ToAssetSupplyModel(const FString& String);

/**
 * @brief Serializes the asset supply model into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDKRUNTIME_API const TCHAR* ToString(const EAssetSupplyModel Value);
}
}
}
