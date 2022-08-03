// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"
#include "Model/Operator.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a filter input for balance queries.
 */
class ENJINSDK_API FBalanceFilter final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FBalanceFilter();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FBalanceFilter(const FBalanceFilter& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FBalanceFilter(FBalanceFilter&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FBalanceFilter() override;

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
	FBalanceFilter& SetAnd(TArray<FBalanceFilter> Others);

	/**
	 * @brief Sets the asset ID to filter for.
	 * @param Id The asset ID.
	 * @return This input for chaining.
	 */
	FBalanceFilter& SetAssetId(FString Id);

	/**
	 * @brief Sets the asset IDs to filter for.
	 * @param Ids The asset IDs.
	 * @return This input for chaining.
	 */
	FBalanceFilter& SetAssetIdIn(TArray<FString> Ids);

	/**
	 * @brief Sets this filter to include other filters to union with.
	 * @param Others The other filters.
	 * @return This input for chaining.
	 */
	FBalanceFilter& SetOr(TArray<FBalanceFilter> Others);

	/**
	 * @brief Sets this filter to include balances compared to the given value.
	 * @param Value The value to compare by.
	 * @return This input for chaining.
	 */
	FBalanceFilter& SetValue(const int32 Value);

	/**
	 * @brief Sets the filter operator type for values.
	 * @param ValueIs The operator for comparison.
	 * @return This input for chaining.
	 */
	FBalanceFilter& SetValueIs(const EOperator ValueIs);

	/**
	 * @brief Sets the wallet to filter for.
	 * @param Wallet The wallet address.
	 * @return This input for chaining.
	 */
	FBalanceFilter& SetWallet(FString Wallet);

	/**
	 * @brief Sets the wallets to filter for.
	 * @param Wallets The wallet addresses.
	 * @return This input for chaining.
	 */
	FBalanceFilter& SetWalletIn(TArray<FString> Wallets);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FBalanceFilter& Rhs) const;

	bool operator!=(const FBalanceFilter& Rhs) const;

	FBalanceFilter& operator=(const FBalanceFilter& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
