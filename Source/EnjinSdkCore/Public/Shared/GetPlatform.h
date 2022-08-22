// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Request for getting the platform details.
 */
class ENJINSDKCORE_API FGetPlatform final : public GraphQl::IGraphQlRequest
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGetPlatform();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGetPlatform() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets this request to include the contracts with the platform.
	 * @return This request for chaining.
	 */
	FGetPlatform& SetWithContracts();

	/**
	 * @brief Sets this request to include the notification drivers with the platform.
	 * @return This request for chaining.
	 */
	FGetPlatform& SetWithNotifications();

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FGetPlatform& Rhs) const;

	bool operator!=(const FGetPlatform& Rhs) const;

private:
	TOptional<bool> WithContractsOpt;
	TOptional<bool> WithNotificationsOpt;
};
}
}
}
