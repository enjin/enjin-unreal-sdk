// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "LogLevel.h"

namespace Enjin
{
namespace Sdk
{
namespace Util
{
/**
 * @brief Logger interface to be implemented for use within the SDK.
 */
class ENJINSDKCORE_API ILogger
{
public:
	/**
	 * @brief Class destructor.
	 */
	virtual ~ILogger() = default;

	/**
	 * @brief Determines if the given log level is enabled for this logger.
	 * @param Level The log level.
	 * @return Whether this logger is enabled for the given log level.
	 */
	virtual bool IsLoggable(const ELogLevel Level) const = 0;

	/**
	 * @brief Logs the message with the given log level.
	 * @param Level The log level.
	 * @param Message The message.
	 */
	virtual void Log(const ELogLevel Level, const FString& Message) = 0;
};
}
}
}
