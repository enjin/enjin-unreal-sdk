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
 * @brief Request for canceling a transaction on the platform.
 */
class ENJINSDKCORE_API FCancelTransaction final : public GraphQl::IGraphQlRequest
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FCancelTransaction();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FCancelTransaction() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the ID of the transaction to cancel.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FCancelTransaction& SetId(const int32 Id);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FCancelTransaction& Rhs) const;

	bool operator!=(const FCancelTransaction& Rhs) const;

private:
	TOptional<int32> IdOpt;
};
}
}
}
