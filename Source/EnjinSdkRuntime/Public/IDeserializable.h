// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Serialization
{
/**
 * @brief Interface for deserialization.
 */
class ENJINSDK_API IDeserializable
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~IDeserializable() = default;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) = 0;
};
}
}
}
