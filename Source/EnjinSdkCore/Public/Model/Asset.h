// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/AssetConfigData.h"
#include "Model/AssetStateData.h"
#include "Model/AssetVariant.h"
#include "Model/AssetVariantMode.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a asset on the platform.
 */
class ENJINSDKCORE_API FAsset final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAsset();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FAsset(const FAsset& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FAsset(FAsset&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FAsset() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the configuration data of this asset.
	 * @return The configuration data.
	 */
	const TOptional<FAssetConfigData>& GetConfigData() const;

	/**
	 * @brief Returns the datetime when this asset was created.
	 * @return The datetime.
	 * @remarks The datetime is formatted using the ISO 8601 date format.
	 */
	const TOptional<FString>& GetCreatedAt() const;

	/**
	 * @brief Returns the ID of this asset.
	 * @return The ID.
	 */
	const TOptional<FString>& GetId() const;

	/**
	 * @brief Returns the name of this asset.
	 * @return The name.
	 */
	const TOptional<FString>& GetName() const;

	/**
	 * @brief Returns the state data of this asset.
	 * @return The state data.
	 */
	const TOptional<FAssetStateData>& GetStateData() const;

	/**
	 * @brief Returns the datetime when this asset was last updated.
	 * @return The datetime.
	 * @remarks The datetime is formatted using the ISO 8601 date format.
	 */
	const TOptional<FString>& GetUpdatedAt() const;

	/**
	 * @brief Returns the variant mode of this asset.
	 * @return The variant mode.
	 */
	const TOptional<EAssetVariantMode>& GetVariantMode() const;

	/**
	 * @brief Returns the variants of this asset.
	 * @return The variants
	 */
	const TOptional<TArray<FAssetVariant>>& GetVariants() const;

	bool operator==(const FAsset& Rhs) const;

	bool operator!=(const FAsset& Rhs) const;

	FAsset& operator=(const FAsset& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
