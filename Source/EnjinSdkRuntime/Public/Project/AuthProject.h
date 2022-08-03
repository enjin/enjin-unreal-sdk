// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for getting a access token for a project.
 */
class ENJINSDKRUNTIME_API FAuthProject final : public GraphQl::IGraphQlRequest
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAuthProject();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FAuthProject() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the project secret.
	 * @param Secret The secret.
	 * @return This request for chaining.
	 */
	FAuthProject& SetSecret(FString Secret);

	/**
	 * @brief Sets the project UUID.
	 * @param Uuid The UUID.
	 * @return This request for chaining.
	 */
	FAuthProject& SetUuid(FString Uuid);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FAuthProject& Rhs) const;

	bool operator!=(const FAuthProject& Rhs) const;

private:
	TOptional<FString> SecretOpt;
	TOptional<FString> UuidOpt;
};
}
}
}
