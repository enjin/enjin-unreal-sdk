// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/TransactionLog.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a receipt for a blockchain transaction.
 */
class ENJINSDKCORE_API FTransactionReceipt final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FTransactionReceipt();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FTransactionReceipt(const FTransactionReceipt& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FTransactionReceipt(FTransactionReceipt&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FTransactionReceipt() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the hash of the block for the transaction.
	 * @return The block hash.
	 */
	const TOptional<FString>& GetBlockHash() const;

	/**
	 * @brief Returns the block number where the transaction is.
	 * @return The block number.
	 */
	const TOptional<int32>& GetBlockNumber() const;

	/**
	 * @brief Returns the total amount of gas used when the transaction was executed.
	 * @return The total gas used.
	 */
	const TOptional<int32>& GetCumulativeGasUsed() const;

	/**
	 * @brief Returns the sender address for the transaction.
	 * @return The sender address.
	 */
	const TOptional<FString>& GetFrom() const;

	/**
	 * @brief Returns the gas used by the specific request alone.
	 * @return The gas used.
	 */
	const TOptional<int32>& GetGasUsed() const;

	/**
	 * @brief Returns the transaction logs generated for the transaction.
	 * @return The transaction logs.
	 */
	const TOptional<TArray<FTransactionLog>>& GetLogs() const;

	/**
	 * @brief Returns the status of the transaction.
	 * @return The status.
	 */
	const TOptional<bool>& GetStatus() const;

	/**
	 * @brief Returns the receiver address for the transaction.
	 * @return The receiver address.
	 * @remarks If the transaction was for contract creation, then the optional will not be set.
	 */
	const TOptional<FString>& GetTo() const;

	/**
	 * @brief Returns the hash of the transaction.
	 * @return The hash.
	 */
	const TOptional<FString>& GetTransactionHash() const;

	/**
	 * @brief Returns the index position in the block for the transaction.
	 * @return The index position.
	 */
	const TOptional<int32>& GetTransactionIndex() const;

	bool operator==(const FTransactionReceipt& Rhs) const;

	bool operator!=(const FTransactionReceipt& Rhs) const;

	FTransactionReceipt& operator=(const FTransactionReceipt& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
