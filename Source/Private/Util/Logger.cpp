// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Logger.h"

using namespace Enjin::Sdk::Util;

bool FLogger::IsLoggable(const ELogLevel Level) const
{
	switch (Level)
	{
		case ELogLevel::Info:
		case ELogLevel::Warn:
		case ELogLevel::Error:
		case ELogLevel::Severe:
		case ELogLevel::Debug:
		case ELogLevel::Trace:
			return true;

		default:
			return false;
	}
}

void FLogger::Log(const ELogLevel Level, const FString& Message)
{
	switch (Level)
	{
		case ELogLevel::Info:
			UE_LOG(LogTemp, Display, TEXT("%s"), *Message);
			break;

		case ELogLevel::Warn:
			UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
			break;

		case ELogLevel::Error:
			UE_LOG(LogTemp, Error, TEXT("%s"), *Message);
			break;

		case ELogLevel::Severe:
			UE_LOG(LogTemp, Fatal, TEXT("%s"), *Message);
			break;

		case ELogLevel::Debug:
			UE_LOG(LogTemp, Verbose, TEXT("%s"), *Message);
			break;

		case ELogLevel::Trace:
			UE_LOG(LogTemp, VeryVerbose, TEXT("%s"), *Message);
			break;

		default:
			break;
	}
}
