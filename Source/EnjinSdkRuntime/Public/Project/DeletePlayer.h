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
 * @brief Request for deleting a player for the project.
 */
class ENJINSDKRUNTIME_API FDeletePlayer final : public GraphQl::IGraphQlRequest
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FDeletePlayer();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FDeletePlayer() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the player ID.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FDeletePlayer& SetId(FString Id);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FDeletePlayer& Rhs) const;

	bool operator!=(const FDeletePlayer& Rhs) const;

private:
	TOptional<FString> IdOpt;
};
}
}
}
