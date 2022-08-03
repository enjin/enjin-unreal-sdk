// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"
#include "JsonUtil.h"
#include "Model/AssetIdFormat.h"
#include "Model/AssetIndexFormat.h"
#include <type_traits>

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Fragment interface to request certain information from balances returned by the platform.
 * @tparam T The type of the implementing class.
 */
template <class T>
class ENJINSDKRUNTIME_API TBalanceFragmentArguments : public Serialization::ISerializable
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~TBalanceFragmentArguments() override = default;

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
	 * @param Format The format.
	 * @return This request for chaining.
	 */
	T& SetBalIdFormat(const Model::EAssetIdFormat Format)
	{
		BalIdFormatOpt.Emplace(Format);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets the format the asset index will be displayed in.
	 * @param Format The format.
	 * @return This request for chaining.
	 */
	T& SetBalIndexFormat(const Model::EAssetIndexFormat Format)
	{
		BalIndexFormatOpt.Emplace(Format);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the project UUID with the balance.
	 * @return This request for chaining.
	 */
	T& SetWithBalProjectUuid()
	{
		WithBalProjectUuidOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the wallet address with the balance.
	 * @return This request for chaining.
	 */
	T& SetWithBalWalletAddress()
	{
		WithBalWalletAddressOpt.Emplace(true);
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

		Util::FJsonUtil::TrySetField(JsonRef, TEXT("balIdFormat"), BalIdFormatOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("balIndexFormat"), BalIndexFormatOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withBalProjectUuid"), WithBalProjectUuidOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withBalWalletAddress"), WithBalWalletAddressOpt);

		return JsonRef;
	}

	bool operator==(const TBalanceFragmentArguments& Rhs) const
	{
		return BalIdFormatOpt == Rhs.BalIdFormatOpt
			&& BalIndexFormatOpt == Rhs.BalIndexFormatOpt
			&& WithBalProjectUuidOpt == Rhs.WithBalProjectUuidOpt
			&& WithBalWalletAddressOpt == Rhs.WithBalWalletAddressOpt;
	}

	bool operator!=(const TBalanceFragmentArguments& Rhs) const
	{
		return !(*this == Rhs);
	}

protected:
	/**
	 * @brief Constructor for this interface. Asserts that the T parameter implements this interface.
	 */
	TBalanceFragmentArguments()
	{
		static_assert(std::is_base_of<TBalanceFragmentArguments, T>::value,
			"Class T must inherit from TBalanceFragmentArguments");
	}

private:
	TOptional<Model::EAssetIdFormat> BalIdFormatOpt;
	TOptional<Model::EAssetIndexFormat> BalIndexFormatOpt;
	TOptional<bool> WithBalProjectUuidOpt;
	TOptional<bool> WithBalWalletAddressOpt;
};
}
}
}
