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
 * @brief Fragment interface to request certain information from transactions returned by the platform.
 * @tparam T The type of the implementing class.
 */
template <class T>
class ENJINSDKCORE_API TTransactionFragmentArguments : public Serialization::ISerializable
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~TTransactionFragmentArguments() override = default;

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
	T& SetTransactionAssetIdFormat(const Model::EAssetIdFormat Format)
	{
		TransactionAssetIdFormatOpt = Format;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the asset data with the transaction.
	 * @return This request for chaining.
	 */
	T& SetWithAssetData()
	{
		WithAssetDataOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the blockchain data with the transaction.
	 * @return This request for chaining.
	 */
	T& SetWithBlockchainData()
	{
		WithBlockchainDataOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the encoded data with the transaction when used with
	 * @link SetWithBlockchainData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithEncodedData()
	{
		WithEncodedDataOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the error with the transaction when used with
	 * @link SetWithBlockchainData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithError()
	{
		WithErrorOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the event data in the receipt logs when used with
	 * @link SetWithReceiptLogs @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithLogEvent()
	{
		WithLogEventOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the metadata with the transaction.
	 * @return This request for chaining.
	 */
	T& SetWithMeta()
	{
		WithMetaOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the nonce with the transaction when used with
	 * @link SetWithBlockchainData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithNonce()
	{
		WithNonceOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the receipt with the transaction when used with
	 * @link SetWithBlockchainData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithReceipt()
	{
		WithReceiptOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the receipt logs with the transaction receipt when used with
	 * @link SetWithReceipt @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithReceiptLogs()
	{
		WithReceiptLogsOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the signed transactions with the transaction when used with
	 * @link SetWithBlockchainData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithSignedTxs()
	{
		WithSignedTxsOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the state with the transaction when used with
	 * @link SetWithBlockchainData @endlink.
	 * @return This request for chaining.
	 */
	T& SetWithState()
	{
		WithStateOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets this request to include the project with its UUID field with the transaction.
	 * @return This request for chaining.
	 */
	T& SetWithTransactionProjectUuid()
	{
		WithTransactionProjectUuidOpt = true;
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets the request to include the wallet with its Ethereum address that belongs to the transaction.
	 * @return This request for chaining.
	 */
	T& SetWithTransactionWalletAddress()
	{
		WithTransactionWalletAddressOpt = true;
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

		Util::FJsonUtil::TrySetField(JsonRef, TEXT("transactionAssetIdFormat"), TransactionAssetIdFormatOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withAssetData"), WithAssetDataOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withBlockchainData"), WithBlockchainDataOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withEncodedData"), WithEncodedDataOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withError"), WithErrorOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withLogEvent"), WithLogEventOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withMeta"), WithMetaOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withNonce"), WithNonceOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withReceiptLogs"), WithReceiptLogsOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withReceipt"), WithReceiptOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withSignedTxs"), WithSignedTxsOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withState"), WithStateOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withTransactionProjectUuid"), WithTransactionProjectUuidOpt);
		Util::FJsonUtil::TrySetField(JsonRef, TEXT("withTransactionWalletAddress"), WithTransactionWalletAddressOpt);

		return JsonRef;
	}

	bool operator==(const TTransactionFragmentArguments& Rhs) const
	{
		return TransactionAssetIdFormatOpt == Rhs.TransactionAssetIdFormatOpt
			&& WithAssetDataOpt == Rhs.WithAssetDataOpt
			&& WithBlockchainDataOpt == Rhs.WithBlockchainDataOpt
			&& WithEncodedDataOpt == Rhs.WithEncodedDataOpt
			&& WithErrorOpt == Rhs.WithErrorOpt
			&& WithLogEventOpt == Rhs.WithLogEventOpt
			&& WithMetaOpt == Rhs.WithMetaOpt
			&& WithNonceOpt == Rhs.WithNonceOpt
			&& WithReceiptLogsOpt == Rhs.WithReceiptLogsOpt
			&& WithReceiptOpt == Rhs.WithReceiptOpt
			&& WithSignedTxsOpt == Rhs.WithSignedTxsOpt
			&& WithStateOpt == Rhs.WithStateOpt
			&& WithTransactionProjectUuidOpt == Rhs.WithTransactionProjectUuidOpt
			&& WithTransactionWalletAddressOpt == Rhs.WithTransactionWalletAddressOpt;
	}

	bool operator!=(const TTransactionFragmentArguments& Rhs) const
	{
		return !(*this == Rhs);
	}

protected:
	/**
	 * @brief Constructor for this interface. Asserts that the T parameter implements this interface.
	 */
	TTransactionFragmentArguments()
	{
		static_assert(std::is_base_of<TTransactionFragmentArguments, T>::value,
			"Class T must inherit from TTransactionFragmentArguments");
	}

private:
	TOptional<Model::EAssetIdFormat> TransactionAssetIdFormatOpt;
	TOptional<bool> WithAssetDataOpt;
	TOptional<bool> WithBlockchainDataOpt;
	TOptional<bool> WithEncodedDataOpt;
	TOptional<bool> WithErrorOpt;
	TOptional<bool> WithLogEventOpt;
	TOptional<bool> WithMetaOpt;
	TOptional<bool> WithNonceOpt;
	TOptional<bool> WithReceiptLogsOpt;
	TOptional<bool> WithReceiptOpt;
	TOptional<bool> WithSignedTxsOpt;
	TOptional<bool> WithStateOpt;
	TOptional<bool> WithTransactionProjectUuidOpt;
	TOptional<bool> WithTransactionWalletAddressOpt;
};
}
}
}
