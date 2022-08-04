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
 * @brief Models a filter input for asset queries.
 */
class ENJINSDKCORE_API FAssetFilter final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAssetFilter();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FAssetFilter(const FAssetFilter& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FAssetFilter(FAssetFilter&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FAssetFilter() override;

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
	FAssetFilter& SetAnd(TArray<FAssetFilter> Others);

	/**
	 * @brief Sets the asset ID to filter for.
	 * @param Id The ID.
	 * @return This input for chaining.
	 */
	FAssetFilter& SetId(FString Id);

	/**
	 * @brief Sets the asset IDs to filter for.
	 * @param Ids The IDs.
	 * @return This input for chaining.
	 */
	FAssetFilter& SetIdIn(TArray<FString> Ids);

	/**
	 * @brief Sets the name to filter for.
	 * @param Name The name.
	 * @return This input for chaining.
	 */
	FAssetFilter& SetName(FString Name);

	/**
	 * @brief Sets this filter to include include assets with names which contain the passed text.
	 * @param Text The text.
	 * @return This input for chaining.
	 */
	FAssetFilter& SetNameContains(FString Text);

	/**
	 * @brief Sets this filter to include assets with names which start with passed suffix.
	 * @param Suffix The suffix.
	 * @return This input for chaining.
	 */
	FAssetFilter& SetNameEndsWith(FString Suffix);

	/**
	 * @brief Sets the names to filter for.
	 * @param Names The names.
	 * @return This input for chaining.
	 */
	FAssetFilter& SetNameIn(TArray<FString> Names);

	/**
	 * @brief Sets this filter to include assets with names which start with the passed prefix.
	 * @param Prefix The prefix.
	 * @return This input for chaining.
	 */
	FAssetFilter& SetNameStartsWith(FString Prefix);

	/**
	 * @brief Sets this filter to include other filters to union with.
	 * @param Others The other filters.
	 * @return This input for chaining.
	 */
	FAssetFilter& SetOr(TArray<FAssetFilter> Others);

	/**
	 * @brief Sets the wallet to filter for.
	 * @param Wallet The wallet address.
	 * @return This input for chaining.
	 */
	FAssetFilter& SetWallet(FString Wallet);

	/**
	 * @brief Sets the wallets to filter for.
	 * @param Wallets The wallet addresses.
	 * @return This input for chaining.
	 */
	FAssetFilter& SetWalletIn(TArray<FString> Wallets);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FAssetFilter& Rhs) const;

	bool operator!=(const FAssetFilter& Rhs) const;

	FAssetFilter& operator=(const FAssetFilter& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
