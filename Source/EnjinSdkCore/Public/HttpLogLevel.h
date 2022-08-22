// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Http
{
/**
 * @brief Values for different logging levels of HTTP traffic.
 */
enum class EHttpLogLevel
{
	/**
	 * @brief No logging.
	 */
	None,

	/**
	 * @brief Logs request and response lines.
	 */
	Basic,

	/**
	 * @brief Logs request and response lines as well as their respective headers.
	 */
	Headers,

	/**
	 * @brief Logs request and response lines as well as their respective headers and bodies if present.
	 */
	Body,
};
}
}
}
