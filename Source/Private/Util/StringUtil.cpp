// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "StringUtil.h"

using namespace Enjin::Sdk::Util;

bool FStringUtil::IsEmptyOrWhitespace(const FString& String)
{
	return String.IsEmpty() || IsWhitespace(String);
}

bool FStringUtil::IsWhitespace(const FString& String)
{
	constexpr auto WhiteSpaceChar = static_cast<TCHAR>(' ');
	for (const TCHAR Char : String)
	{
		if (Char != WhiteSpaceChar)
		{
			return false;
		}
	}

	return true;
}
