// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "JsonUtil.h"
#include "Model/BalanceFilter.h"
#include "Shared/AssetFragmentArguments.h"
#include "Shared/BalanceFragmentArguments.h"
#include "Shared/TransactionFragmentArguments.h"
#include <type_traits>

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Fragment interface to request certain information from wallets returned by the platform.
 * @tparam T The type of the implementing class.
 */
template <class T>
class ENJINSDKRUNTIME_API TWalletFragmentArguments : public TAssetFragmentArguments<T>,
                                              public TBalanceFragmentArguments<T>,
                                              public TTransactionFragmentArguments<T>
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~TWalletFragmentArguments() override = default;

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override
	{
		return Util::FJsonUtil::SerializeJsonObject(ToJson());
	}

	/**
	 * @brief Sets the balance filter when used with @link SetWithWalletBalances @endlink.
	 * @param Filter The filter.
	 * @return This request for chaining.
	 */
	T& SetWalletBalanceFilter(Model::FBalanceFilter Filter)
	{
		WalletBalanceFilterOpt = MoveTemp(Filter);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the assets created by the wallet.
	 * @return This request for chaining.
	 */
	T& SetWithAssetsCreated()
	{
		WithAssetsCreatedOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the asset balances of the wallet.
	 * @return This request for chaining.
	 */
	T& SetWithWalletBalances()
	{
		WithWalletBalancesOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the transactions the wallet has signed.
	 * @return This request for chaining.
	 */
	T& SetWithWalletTransactions()
	{
		WithWalletTransactionsOpt = true;
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

		Util::FJsonUtil::JoinObject(JsonRef, TAssetFragmentArguments<T>::ToJson());
		Util::FJsonUtil::JoinObject(JsonRef, TBalanceFragmentArguments<T>::ToJson());
		Util::FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<T>::ToJson());
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("walletBalanceFilter"), WalletBalanceFilterOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withAssetsCreated"), WithAssetsCreatedOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withWalletBalances"), WithWalletBalancesOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withWalletTransactions"), WithWalletTransactionsOpt);

		return JsonRef;
	}

	bool operator==(const TWalletFragmentArguments& Rhs) const
	{
		return static_cast<const TAssetFragmentArguments<T>&>(*this) == Rhs
			&& static_cast<const TBalanceFragmentArguments<T>&>(*this) == Rhs
			&& static_cast<const TTransactionFragmentArguments<T>&>(*this) == Rhs
			&& WalletBalanceFilterOpt == Rhs.WalletBalanceFilterOpt
			&& WithAssetsCreatedOpt == Rhs.WithAssetsCreatedOpt
			&& WithWalletBalancesOpt == Rhs.WithWalletBalancesOpt
			&& WithWalletTransactionsOpt == Rhs.WithWalletTransactionsOpt;
	}

	bool operator!=(const TWalletFragmentArguments& Rhs) const
	{
		return !(*this == Rhs);
	}

protected:
	/**
	 * @brief Constructor for this interface. Asserts that the T parameter implements this interface.
	 */
	TWalletFragmentArguments()
		: TAssetFragmentArguments<T>(), TBalanceFragmentArguments<T>(), TTransactionFragmentArguments<T>()
	{
		static_assert(std::is_base_of<TWalletFragmentArguments, T>::value,
			"Class T must inherit from TWalletFragmentArguments");
	}

private:
	TOptional<Model::FBalanceFilter> WalletBalanceFilterOpt;
	TOptional<bool> WithAssetsCreatedOpt;
	TOptional<bool> WithWalletBalancesOpt;
	TOptional<bool> WithWalletTransactionsOpt;
};
}
}
}
