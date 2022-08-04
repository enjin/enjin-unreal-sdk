// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace GraphQl
{
/**
 * @brief Static class containing a mapping of GraphQL templates to be used when sending requests to the platform.
 */
class FTemplateConstants final
{
public:
	FTemplateConstants() = delete;

	~FTemplateConstants() = delete;

	/**
	 * @brief The mapping of template namespaces and static bodies.
	 */
	static const TMap<FString, FString> Templates;
};
}
}
}
