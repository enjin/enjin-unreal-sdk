// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/Asset.h"
#include "Model/BlockchainData.h"
#include "Model/Project.h"
#include "Model/TransactionState.h"
#include "Model/TransactionType.h"
#include "Model/Wallet.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
// Forward declaration of classes that have a circular-dependency with FTransaction.
class FWallet;

/**
 * @brief Models a transaction on the platform.
 */
class ENJINSDK_API FTransaction final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FTransaction();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FTransaction(const FTransaction& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FTransaction(FTransaction&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FTransaction() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns whether the this transaction has been accepted or not.
	 * @return Whether the this transaction has been accepted or not.
	 */
	const TOptional<bool>& GetAccepted() const;

	/**
	 * @brief Returns the asset for this transaction.
	 * @return The asset.
	 */
	const TOptional<FAsset>& GetAsset() const;

	/**
	 * @brief Returns the blockchain data of this transaction.
	 * @return The blockchain data.
	 */
	const TOptional<FBlockchainData>& GetBlockchainData() const;

	/**
	 * @brief Returns the contract address of this transaction.
	 * @return The contract address.
	 */
	const TOptional<FString>& GetContract() const;

	/**
	 * @brief Returns the datetime when this transaction was created.
	 * @return The datetime.
	 * @remarks The datetime is formatted using the ISO 8601 date format.
	 */
	const TOptional<FString>& GetCreatedAt() const;

	/**
	 * @brief Returns the ID of this request.
	 * @return The ID.
	 */
	const TOptional<int32>& GetId() const;

	/**
	 * @brief Returns the project of this request.
	 * @return The project.
	 */
	const TOptional<FProject>& GetProject() const;

	/**
	 * @brief Returns whether the wallet of the transaction is a project wallet.
	 * @return Whether the wallet is a project wallet.
	 */
	const TOptional<bool>& GetProjectWallet() const;

	/**
	 * @brief Returns the retry state of this transaction.
	 * @return The retry state.
	 */
	const TOptional<FString>& GetRetryState() const;

	/**
	 * @brief Returns the state of this transaction.
	 * @return The state.
	 */
	const TOptional<ETransactionState>& GetState() const;

	/**
	 * @brief Returns the title of this transaction.
	 * @return The title.
	 */
	const TOptional<FString>& GetTitle() const;

	/**
	 * @brief Returns the hash ID of this transaction.
	 * @return The hash ID.
	 */
	const TOptional<FString>& GetTransactionId() const;

	/**
	 * @brief Returns the type of this transaction.
	 * @return The type.
	 */
	const TOptional<ETransactionType>& GetType() const;

	/**
	 * @brief Returns the datetime when this transaction was last updated.
	 * @return The datetime.
	 * @remarks The datetime is formatted using the ISO 8601 date format.
	 */
	const TOptional<FString>& GetUpdatedAt() const;

	/**
	 * @brief Returns the value of this transaction.
	 * @return The value.
	 */
	const TOptional<FString>& GetValue() const;

	/**
	 * @brief Returns the wallet of this request.
	 * @return The wallet.
	 */
	const TOptional<FWallet>& GetWallet() const;

	bool operator==(const FTransaction& Rhs) const;

	bool operator!=(const FTransaction& Rhs) const;

	FTransaction& operator=(const FTransaction& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
