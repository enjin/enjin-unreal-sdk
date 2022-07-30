// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/TransactionReceipt.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models the blockchain data of a transaction.
 */
class ENJINSDK_API FBlockchainData final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FBlockchainData();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FBlockchainData(const FBlockchainData& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FBlockchainData(FBlockchainData&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FBlockchainData() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the encoded data of the transaction.
	 * @return The encoded data.
	 */
	const TOptional<FString>& GetEncodedData() const;

	/**
	 * @brief Returns the error message of the transaction.
	 * @return The error message.
	 */
	const TOptional<FString>& GetError() const;

	/**
	 * @brief Returns the nonce of the transaction.
	 * @return The nonce.
	 */
	const TOptional<FString>& GetNonce() const;

	/**
	 * @brief Returns the receipt of the transaction.
	 * @return The receipt.
	 */
	const TOptional<FTransactionReceipt>& GetReceipt() const;

	/**
	 * @brief Returns the signed backup string of the transaction.
	 * @return The signed backup string.
	 */
	const TOptional<FString>& GetSignedBackupTransaction() const;

	/**
	 * @brief Returns the signed cancel string of the transaction.
	 * @return The signed cancel string.
	 */
	const TOptional<FString>& GetSignedCancelTransaction() const;

	/**
	 * @brief Returns the signed string of the transaction.
	 * @return The signed string.
	 */
	const TOptional<FString>& GetSignedTransaction() const;

	bool operator==(const FBlockchainData& Rhs) const;

	bool operator!=(const FBlockchainData& Rhs) const;

	FBlockchainData& operator=(const FBlockchainData& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
