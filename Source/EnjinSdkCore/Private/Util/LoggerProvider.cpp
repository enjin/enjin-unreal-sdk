// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "LoggerProvider.h"

#include "Logger.h"

using namespace Enjin::Sdk::Util;

FLoggerProvider::FLoggerProvider(FLoggerRef Logger,
                                 const ELogLevel DefaultLevel,
                                 const ELogLevel DebugLevel)
	: Logger(MoveTemp(Logger)), DefaultLevel(DefaultLevel), DebugLevel(DebugLevel)
{
}

// ReSharper disable CppMemberFunctionMayBeConst

void FLoggerProvider::Debug(const FString& Message)
{
	Log(DebugLevel, Message);
}

ELogLevel FLoggerProvider::GetDebugVerbosity() const
{
	return DebugLevel;
}

ELogLevel FLoggerProvider::GetDefaultVerbosity() const
{
	return DefaultLevel;
}

const FLoggerRef& FLoggerProvider::GetLogger() const
{
	return Logger;
}

void FLoggerProvider::Log(const FString& Message)
{
	Log(DefaultLevel, Message);
}

void FLoggerProvider::Log(const ELogLevel Level, const FString& Message)
{
	if (Logger->IsLoggable(Level))
	{
		Logger->Log(Level, Message);
	}
}

FLoggerProviderPtr FLoggerProvider::CreateDefaultProvider()
{
	return MakeShared<FLoggerProvider>(MakeShared<FLogger>());
}
