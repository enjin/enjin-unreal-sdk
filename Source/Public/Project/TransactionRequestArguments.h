// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "JsonUtil.h"
#include "Shared/TransactionFragmentArguments.h"
#include <type_traits>

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Fragment interface to set options for a transaction on the project schema.
 * @tparam T The type of the implementing class.
 */
template <class T>
class ENJINSDK_API TTransactionRequestArguments : public Shared::TTransactionFragmentArguments<T>
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~TTransactionRequestArguments() override = default;

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
	 * @brief Sets the Ethereum address of the sender.
	 * @param Address The address.
	 * @return This request for chaining.
	 */
	T& SetEthAddress(FString Address)
	{
		EthAddressOpt.Emplace(MoveTemp(Address));
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

		Util::FJsonUtil::JoinObject(JsonRef, Shared::TTransactionFragmentArguments<T>::ToJson());
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("ethAddress"), EthAddressOpt);

		return JsonRef;
	}

	bool operator==(const TTransactionRequestArguments& Rhs) const
	{
		return static_cast<const Shared::TTransactionFragmentArguments<T>&>(*this) == Rhs
			&& EthAddressOpt == Rhs.EthAddressOpt;
	}

	bool operator!=(const TTransactionRequestArguments& Rhs) const
	{
		return !(*this == Rhs);
	}

protected:
	/**
	 * @brief Constructor for this interface. Asserts that the T parameter implements this interface.
	 */
	TTransactionRequestArguments() : Shared::TTransactionFragmentArguments<T>()
	{
		static_assert(std::is_base_of<TTransactionRequestArguments, T>::value,
			"Class T must inherit from TProjectTransactionRequestArguments");
	}

private:
	TOptional<FString> EthAddressOpt;
};
}
}
}
