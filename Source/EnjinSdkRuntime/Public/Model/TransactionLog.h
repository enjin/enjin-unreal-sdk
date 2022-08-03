// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/TransactionEvent.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a blockchain transaction log.
 */
class ENJINSDKRUNTIME_API FTransactionLog final : Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FTransactionLog();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FTransactionLog(const FTransactionLog& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FTransactionLog(FTransactionLog&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FTransactionLog() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the originating address.
	 * @return The address.
	 */
	const TOptional<FString>& GetAddress() const;

	/**
	 * @brief Returns the block number.
	 * @return The block number.
	 */
	const TOptional<int32>& GetBlockNumber() const;

	/**
	 * @brief Returns the serialized data objects.
	 * @return The serialized data.
	 */
	const TOptional<TArray<FString>>& GetData() const;

	/**
	 * @brief Returns the transaction event.
	 * @return The transaction event.
	 */
	const TOptional<FTransactionEvent>& GetEvent() const;

	/**
	 * @brief Returns the serialized topics.
	 * @return The serialized topics.
	 */
	const TOptional<TArray<FString>>& GetTopics() const;

	/**
	 * @brief Returns the hash for the transaction.
	 * @return The hash.
	 */
	const TOptional<FString>& GetTransactionHash() const;

	bool operator==(const FTransactionLog& Rhs) const;

	bool operator!=(const FTransactionLog& Rhs) const;

	FTransactionLog& operator=(const FTransactionLog& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
