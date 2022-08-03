// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ILogger.h"

namespace Enjin
{
namespace Sdk
{
namespace Util
{
/**
 * @brief Basic logger class for logging messages in Unreal Engine.
 */
class ENJINSDKCORE_API FLogger final : public ILogger
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FLogger() = default;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FLogger() override = default;

	/**
	 * @brief Determines if the given log level is enabled for this logger.
	 * @param Level The log level.
	 * @return Whether this logger is enabled for the given log level.
	 */
	virtual bool IsLoggable(const ELogLevel Level) const override;

	/**
	 * @brief Logs the message with the given log level.
	 * @param Level The log level.
	 * @param Message The message.
	 */
	virtual void Log(const ELogLevel Level, const FString& Message) override;
};
}
}
}
