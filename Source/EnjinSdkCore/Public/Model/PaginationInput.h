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
 * @brief Models a pagination input for pagination requests.
 */
class ENJINSDKCORE_API FPaginationInput final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FPaginationInput();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FPaginationInput(const FPaginationInput& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FPaginationInput(FPaginationInput&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPaginationInput() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the number of items per page for the pagination.
	 * @param Limit The number of items per page.
	 * @return This input for chaining.
	 */
	FPaginationInput& SetLimit(int32 Limit);

	/**
	 * @brief Sets the page number to start at for pagination.
	 * @param Page The page number.
	 * @return This input for chaining.
	 */
	FPaginationInput& SetPage(int32 Page);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FPaginationInput& Rhs) const;

	bool operator!=(const FPaginationInput& Rhs) const;

	FPaginationInput& operator=(const FPaginationInput& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
