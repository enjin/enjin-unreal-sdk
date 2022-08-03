// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/Asset.h"
#include "Model/Balance.h"
#include "Model/Transaction.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
// Forward declaration of classes that have a circular-dependency with FWallet.
class FBalance;
class FTransaction;

/**
 * @brief Models a wallet on the platform.
 */
class ENJINSDK_API FWallet final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FWallet();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FWallet(const FWallet& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FWallet(FWallet&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FWallet() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the assets this wallet has created.
	 * @return The assets this wallet has created.
	 */
	const TOptional<TArray<FAsset>>& GetAssetsCreated() const;

	/**
	 * @brief Returns the balances of this wallet.
	 * @return The balances.
	 */
	const TOptional<TArray<FBalance>>& GetBalances() const;

	/**
	 * @brief Returns the ENJ allowance given for crypto-items.
	 * @return The ENJ allowance.
	 */
	const TOptional<double>& GetEnjAllowance() const;

	/**
	 * @brief Returns the ENJ balance of this wallet.
	 * @return The ENJ balance.
	 */
	const TOptional<double>& GetEnjBalance() const;

	/**
	 * @brief Returns the Ethereum address of this wallet.
	 * @return The Ethereum address.
	 */
	const TOptional<FString>& GetEthAddress() const;

	/**
	 * @brief Returns the ETH balance of this wallet.
	 * @return The ETH balance.
	 */
	const TOptional<double>& GetEthBalance() const;

	/**
	 * @brief Returns the transactions this wallet has signed.
	 * @return The transactions.
	 */
	const TOptional<TArray<FTransaction>>& GetTransactions() const;

	bool operator==(const FWallet& Rhs) const;

	bool operator!=(const FWallet& Rhs) const;

	FWallet& operator=(const FWallet& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
