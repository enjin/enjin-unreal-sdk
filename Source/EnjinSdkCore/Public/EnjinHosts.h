// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "HAL/Platform.h"

namespace Enjin
{
namespace Sdk
{
/**
 * @brief The network hosts used by the Enjin Platform.
 */
class ENJINSDKCORE_API FEnjinHosts final
{
public:
	FEnjinHosts() = delete;

	~FEnjinHosts() = delete;

	/**
	 * @brief Returns the URL for the Enjin Platform on the Goerli test network.
	 * @return The URL.
	 */
	static const TCHAR* Goerli();

	/**
	 * @brief Returns the URL for the Enjin Platform on the main network.
	 * @return The URL.
	 */
	static const TCHAR* MainNet();

	/**
	 * @brief Returns the URL for the Enjin Platform on the JumpNet network.
	 * @return The URL.
	 */
	static const TCHAR* JumpNet();
};
}
}
