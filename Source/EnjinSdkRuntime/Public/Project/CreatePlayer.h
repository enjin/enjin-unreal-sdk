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
 * @brief Request for creating a player for the project.
 */
class ENJINSDKRUNTIME_API FCreatePlayer final : public GraphQl::IGraphQlRequest
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FCreatePlayer();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FCreatePlayer() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the ID of the player.
	 * @param Id The ID.
	 * @return This request for chaining.
	 */
	FCreatePlayer& SetId(FString Id);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FCreatePlayer& Rhs) const;

	bool operator!=(const FCreatePlayer& Rhs) const;

private:
	TOptional<FString> IdOpt;
};
}
}
}
