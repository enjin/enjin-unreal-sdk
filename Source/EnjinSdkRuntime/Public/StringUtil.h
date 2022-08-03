// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Util
{
/**
 * @brief Utility class for processing strings.
 */
class ENJINSDKRUNTIME_API FStringUtil final
{
public:
	FStringUtil() = delete;

	~FStringUtil() = delete;

	/**
	 * @brief Determines whether a string is empty or all whitespace.
	 * @param String The string.
	 * @return Whether a string is empty or all whitespace.
	 */
	static bool IsEmptyOrWhitespace(const FString& String);

	/**
	 * @brief Determines whether a string is all whitespace.
	 * @param String The string.
	 * @return Whether a string is all whitespace.
	 */
	static bool IsWhitespace(const FString& String);
};
}
}
}
