// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "Shared/WalletFragmentArguments.h"
#include <type_traits>

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Fragment interface to request certain information from players returned by the platform.
 * @tparam T The type of the implementing class.
 */
template <class T>
class ENJINSDKRUNTIME_API TPlayerFragmentArguments : public TWalletFragmentArguments<T>
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~TPlayerFragmentArguments() override = default;

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
	 * @brief Sets the size of the QR image in pixels when used with @link SetWithLinkingInfo @endlink.
	 * @param Size The size in pixels.
	 * @return This request for chaining.
	 */
	T& SetLinkingCodeQrSize(const int32 Size)
	{
		QrSizeOpt.Emplace(Size);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the linking information with the player.
	 * @return This request for chaining.
	 */
	T& SetWithLinkingInfo()
	{
		WithLinkingInfoOpt.Emplace(true);
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the wallet with the player.
	 * @return This request for chaining.
	 */
	T& SetWithPlayerWallet()
	{
		WithWalletOpt.Emplace(true);
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

		Util::FJsonUtil::JoinObject(JsonRef, TWalletFragmentArguments<T>::ToJson());
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("linkingCodeQrSize"), QrSizeOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withLinkingInfo"), WithLinkingInfoOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withPlayerWallet"), WithWalletOpt);

		return JsonRef;
	}

	bool operator==(const TPlayerFragmentArguments& Rhs) const
	{
		return static_cast<const TWalletFragmentArguments<T>&>(*this) == Rhs
			&& QrSizeOpt == Rhs.QrSizeOpt
			&& WithLinkingInfoOpt == Rhs.WithLinkingInfoOpt
			&& WithWalletOpt == Rhs.WithWalletOpt;
	}

	bool operator!=(const TPlayerFragmentArguments& Rhs) const
	{
		return !(*this == Rhs);
	}

protected:
	/**
	 * @brief Constructor for this interface. Asserts that the T parameter implements this interface.
	 */
	TPlayerFragmentArguments() : TWalletFragmentArguments<T>()
	{
		static_assert(std::is_base_of<TPlayerFragmentArguments, T>::value,
			"Class T must inherit from TPlayerFragmentArguments");
	}

private:
	TOptional<int32> QrSizeOpt;
	TOptional<bool> WithLinkingInfoOpt;
	TOptional<bool> WithWalletOpt;
};
}
}
}
