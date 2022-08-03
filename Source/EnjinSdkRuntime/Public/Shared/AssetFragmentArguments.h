// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"
#include "JsonUtil.h"
#include "Model/AssetIdFormat.h"
#include <type_traits>

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Fragment interface to request certain information from assets returned by the platform.
 * @tparam T The type of the implementing class.
 */
template <class T>
class ENJINSDK_API TAssetFragmentArguments : public Serialization::ISerializable
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~TAssetFragmentArguments() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override
	{
		return Util::FJsonUtil::SerializeJsonObject(ToJson());
	}

	/**
	 * @brief Sets the format the asset ID will be displayed in.
	 * @param AssetIdFormat The format.
	 * @return This request for chaining.
	 */
	T& SetAssetIdFormat(const Model::EAssetIdFormat AssetIdFormat)
	{
		AssetIdFormatOpt.Emplace(AssetIdFormat);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the block data with the asset when used with @link SetWithStateData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithAssetBlocks()
	{
		WithAssetBlocksOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the variant mode with the asset.
	 * @return This request for chaining.
	 */
	T& SetWithAssetVariantMode()
	{
		WithAssetVariantModeOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the variants with the asset.
	 * @return This request for chaining.
	 */
	T& SetWithAssetVariants()
	{
		WithAssetVariantsOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the configuration data with the asset.
	 * @return This request for chaining.
	 */
	T& SetWithConfigData()
	{
		WithConfigDataOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the creator with the asset when used with @link SetWithStateData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithCreator()
	{
		WithCreatorOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the melt details with the asset when used with
	 * @link SetWithConfigData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithMeltDetails()
	{
		WithMeltDetailsOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the metadata URI with the asset when used with
	 * @link SetWithConfigData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithMetadataUri()
	{
		WithMetadataUriOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the state data with the asset.
	 * @return This request for chaining.
	 */
	T& SetWithStateData()
	{
		WithStateDataOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the supply details with the asset when used with
	 * @link SetWithStateData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithSupplyDetails()
	{
		WithSupplyDetailsOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include transfer settings with the asset when used with
	 * @link SetWithConfigData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithTransferSettings()
	{
		WithTransferSettingsOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the metadata for variants with the asset when used with
	 * @link SetWithAssetVariants @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithVariantMetadata()
	{
		WithVariantMetadataOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override
	{
		TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

		Util::FJsonUtil::TrySetField(JsonRef, TEXT("assetIdFormat"), AssetIdFormatOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withAssetBlocks"), WithAssetBlocksOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withAssetVariantMode"), WithAssetVariantModeOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withAssetVariants"), WithAssetVariantsOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withConfigData"), WithConfigDataOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withCreator"), WithCreatorOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withMeltDetails"), WithMeltDetailsOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withMetadataUri"), WithMetadataUriOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withStateData"), WithStateDataOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withSupplyDetails"), WithSupplyDetailsOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withTransferSettings"), WithTransferSettingsOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withVariantMetadata"), WithVariantMetadataOpt);

		return JsonRef;
	}

	bool operator==(const TAssetFragmentArguments<T>& Rhs) const
	{
		return AssetIdFormatOpt == Rhs.AssetIdFormatOpt
			&& WithAssetBlocksOpt == Rhs.WithAssetBlocksOpt
			&& WithAssetVariantModeOpt == Rhs.WithAssetVariantModeOpt
			&& WithAssetVariantsOpt == Rhs.WithAssetVariantsOpt
			&& WithConfigDataOpt == Rhs.WithConfigDataOpt
			&& WithCreatorOpt == Rhs.WithCreatorOpt
			&& WithMeltDetailsOpt == Rhs.WithMeltDetailsOpt
			&& WithMetadataUriOpt == Rhs.WithMetadataUriOpt
			&& WithStateDataOpt == Rhs.WithStateDataOpt
			&& WithSupplyDetailsOpt == Rhs.WithSupplyDetailsOpt
			&& WithTransferSettingsOpt == Rhs.WithTransferSettingsOpt
			&& WithVariantMetadataOpt == Rhs.WithVariantMetadataOpt;
	}

	bool operator!=(const TAssetFragmentArguments<T>& Rhs) const
	{
		return !(*this == Rhs);
	}

protected:
	/**
	 * @brief Constructor for this interface. Asserts that the T parameter implements this interface.
	 */
	TAssetFragmentArguments()
	{
		static_assert(std::is_base_of<TAssetFragmentArguments, T>::value,
			"Class T must inherit from TAssetFragmentArguments");
	}

private:
	TOptional<Model::EAssetIdFormat> AssetIdFormatOpt;
	TOptional<bool> WithAssetBlocksOpt;
	TOptional<bool> WithAssetVariantModeOpt;
	TOptional<bool> WithAssetVariantsOpt;
	TOptional<bool> WithConfigDataOpt;
	TOptional<bool> WithCreatorOpt;
	TOptional<bool> WithMeltDetailsOpt;
	TOptional<bool> WithMetadataUriOpt;
	TOptional<bool> WithStateDataOpt;
	TOptional<bool> WithSupplyDetailsOpt;
	TOptional<bool> WithTransferSettingsOpt;
	TOptional<bool> WithVariantMetadataOpt;
};
}
}
}
