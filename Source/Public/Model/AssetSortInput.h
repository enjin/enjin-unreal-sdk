// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"
#include "Model/AssetField.h"
#include "Model/SortDirection.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models sorting input for assets.
 */
class ENJINSDK_API FAssetSortInput final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAssetSortInput();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FAssetSortInput(const FAssetSortInput& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FAssetSortInput(FAssetSortInput&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FAssetSortInput() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the direction to sort by.
	 * @param Direction The direction.
	 * @return This input for chaining.
	 */
	FAssetSortInput& SetDirection(const ESortDirection Direction);

	/**
	 * @brief Sets the field to sort by.
	 * @param Field The field.
	 * @return This input for chaining.
	 */
	FAssetSortInput& SetField(const EAssetField Field);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FAssetSortInput& Rhs) const;

	bool operator!=(const FAssetSortInput& Rhs) const;

	FAssetSortInput& operator=(const FAssetSortInput& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
