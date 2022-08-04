// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Dom/JsonObject.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a asset variant.
 */
class ENJINSDKCORE_API FAssetVariant final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAssetVariant();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FAssetVariant(const FAssetVariant& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FAssetVariant(FAssetVariant&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FAssetVariant() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the ID of the asset this variant belongs to.
	 * @return The asset ID.
	 */
	const TOptional<FString>& GetAssetId() const;

	/**
	 * @brief Returns the datetime when this variant was created.
	 * @return The datetime.
	 * @remarks The datetime is formatted using the ISO 8601 date format.
	 */
	const TOptional<FString>& GetCreatedAt() const;

	/**
	 * @brief Returns the ID of this variant.
	 * @return The ID.
	 */
	const TOptional<int32>& GetId() const;

	/**
	 * @brief Returns the datetime when this variant was last updated.
	 * @return The datetime.
	 * @remarks The datetime is formatted using the ISO 8601 date format.
	 */
	const TOptional<FString>& GetUpdatedAt() const;

	/**
	 * @brief Returns the usage count of this variant.
	 * @return The usage count.
	 */
	const TOptional<int32>& GetUsageCount() const;

	/**
	 * @brief Returns the metadata of this variant.
	 * @return The metadata.
	 */
	const TOptional<TSharedRef<FJsonObject>>& GetVariantMetadata() const;

	bool operator==(const FAssetVariant& Rhs) const;

	bool operator!=(const FAssetVariant& Rhs) const;

	FAssetVariant& operator=(const FAssetVariant& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
