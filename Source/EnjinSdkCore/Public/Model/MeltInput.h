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
 * @brief Models a melt input for melt requests.
 */
class ENJINSDKCORE_API FMeltInput final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FMeltInput();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FMeltInput(const FMeltInput& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FMeltInput(FMeltInput&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FMeltInput() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the asset ID to melt.
	 * @param Id The ID.
	 * @return This input for chaining.
	 */
	FMeltInput& SetAssetId(FString Id);

	/**
	 * @brief Sets the index of a non-fungible asset to melt.
	 * @param Index The index.
	 * @return This input for chaining.
	 */
	FMeltInput& SetAssetIndex(FString Index);

	/**
	 * @brief Sets the amount of assets to melt.
	 * @param Value The amount.
	 * @return This input for chaining.
	 */
	FMeltInput& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FMeltInput& Rhs) const;

	bool operator!=(const FMeltInput& Rhs) const;

	FMeltInput& operator=(const FMeltInput& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
