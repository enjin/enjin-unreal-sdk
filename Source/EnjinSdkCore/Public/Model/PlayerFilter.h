// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a filter input for player queries.
 */
class ENJINSDKCORE_API FPlayerFilter final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FPlayerFilter();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FPlayerFilter(const FPlayerFilter& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FPlayerFilter(FPlayerFilter&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPlayerFilter() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets this filter to include other filters to intersect with.
	 * @param Others The other filters.
	 * @return This input for chaining.
	 */
	FPlayerFilter& SetAnd(TArray<FPlayerFilter> Others);

	/**
	 * @brief Sets the player ID to filter for.
	 * @param Id The player ID.
	 * @return This input for chaining.
	 */
	FPlayerFilter& SetId(FString Id);

	/**
	 * @brief Sets the player IDs to filter for.
	 * @param Ids The player IDs.
	 * @return This input for chaining.
	 */
	FPlayerFilter& SetIdIn(TArray<FString> Ids);

	/**
	 * @brief Sets this filter to include other filters to union with.
	 * @param Others The other filters.
	 * @return This input for chaining.
	 */
	FPlayerFilter& SetOr(TArray<FPlayerFilter> Others);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FPlayerFilter& Rhs) const;

	bool operator!=(const FPlayerFilter& Rhs) const;

	FPlayerFilter& operator=(const FPlayerFilter& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
