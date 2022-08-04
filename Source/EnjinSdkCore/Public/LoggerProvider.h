// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ILogger.h"
#include "LogLevel.h"

namespace Enjin
{
namespace Sdk
{
namespace Util
{
class FLoggerProvider;

/**
 * @brief Alias for a shared-reference to a logger.
 */
using FLoggerRef = TSharedRef<ILogger>;

/**
 * @brief Alias for a shared-pointer to a logger provider.
 */
using FLoggerProviderPtr = TSharedPtr<FLoggerProvider>;

/**
 * @brief Provider class for an instance of @link ILogger @endlink.
 */
class ENJINSDKCORE_API FLoggerProvider final
{
public:
	FLoggerProvider() = delete;

	/**
	 * @brief Constructs an instance of this class.
	 * @param Logger The logger.
	 * @param DefaultLevel The default log level.
	 * @param DebugLevel The log level for debugging.
	 */
	explicit FLoggerProvider(FLoggerRef Logger,
	                         const ELogLevel DefaultLevel = ELogLevel::Info,
	                         const ELogLevel DebugLevel = ELogLevel::Debug);

	/**
	 * @brief Class destructor.
	 */
	~FLoggerProvider() = default;

	/**
	 * @brief Logs the message at the debug log level.
	 * @param Message The message.
	 */
	void Debug(const FString& Message);

	/**
	 * @brief Returns the log level used for debugging.
	 * @return The log level.
	 */
	ELogLevel GetDebugVerbosity() const;

	/**
	 * @brief Returns the log level used by default.
	 * @return The log level.
	 */
	ELogLevel GetDefaultVerbosity() const;

	/**
	 * @brief Returns the logger stored within this provider.
	 * @return The logger.
	 */
	const FLoggerRef& GetLogger() const;

	/**
	 * @brief Logs the message at the default log level.
	 * @param Message The message.
	 */
	void Log(const FString& Message);

	/**
	 * @brief Logs the message at the given log level.
	 * @param Level The log level.
	 * @param Message The message.
	 */
	void Log(const ELogLevel Level, const FString& Message);

	/**
	 * @brief Creates a logger provider using a basic logger and the default log level settings.
	 * @return The logger provider.
	 */
	static FLoggerProviderPtr CreateDefaultProvider();

private:
	const FLoggerRef Logger;
	const ELogLevel DefaultLevel;
	const ELogLevel DebugLevel;
};
}
}
}
