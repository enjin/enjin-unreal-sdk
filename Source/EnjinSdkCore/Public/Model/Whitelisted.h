// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Represents the whitelist settings.
 */
enum class EWhitelisted
{
	Address,
	NoFees,
	None,
	Receive,
	Send,
	SendAndReceive,
};

/**
 * @brief Serializes the whitelist setting into a string.
 * @param Value The enum value.
 * @return The serialized value.
 */
ENJINSDKCORE_API const TCHAR* ToString(const EWhitelisted Value);
}
}
}
