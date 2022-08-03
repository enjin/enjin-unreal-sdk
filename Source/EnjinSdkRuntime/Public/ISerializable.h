// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "Dom/JsonObject.h"

namespace Enjin
{
namespace Sdk
{
namespace Serialization
{
/**
 * @brief Interface for serialization.
 */
class ENJINSDK_API ISerializable
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~ISerializable() = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const = 0;

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const = 0;
};
}
}
}
