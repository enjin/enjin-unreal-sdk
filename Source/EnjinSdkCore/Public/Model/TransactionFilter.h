// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"
#include "Model/TransactionState.h"
#include "Model/TransactionType.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a filter input for transaction queries.
 */
class ENJINSDKCORE_API FTransactionFilter final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FTransactionFilter();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FTransactionFilter(const FTransactionFilter& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FTransactionFilter(FTransactionFilter&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FTransactionFilter() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets this filter to include other filters to intersect with.
	 * @param Others The other filters.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetAnd(TArray<FTransactionFilter> Others);

	/**
	 * @brief Sets the asset ID to filter for.
	 * @param Id The ID.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetAssetId(FString Id);

	/**
	 * @brief Sets the asset IDs to filter for.
	 * @param Ids The IDs.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetAssetIdIn(TArray<FString> Ids);

	/**
	 * @brief Sets the ID to filter for.
	 * @param Id The ID.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetId(FString Id);

	/**
	 * @brief Sets the IDs to filter for
	 * @param Ids The IDs.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetIdIn(TArray<FString> Ids);

	/**
	 * @brief Sets this filter to include other filters to union with.
	 * @param Others The other filters.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetOr(TArray<FTransactionFilter> Others);

	/**
	 * @brief Sets the transaction state to filter for.
	 * @param State The state.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetState(const ETransactionState State);

	/**
	 * @brief Sets the transaction states to filter for.
	 * @param States The states.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetStateIn(TArray<ETransactionState> States);

	/**
	 * @brief Sets the hash ID to filter for.
	 * @param Id The hash ID.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetTransactionId(FString Id);

	/**
	 * @brief Sets the hash IDs to filter for.
	 * @param Ids The hash IDs.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetTransactionIdIn(TArray<FString> Ids);

	/**
	 * @brief Sets the transaction type to filter for.
	 * @param Type The type.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetType(const ETransactionType Type);

	/**
	 * @brief Sets the transaction types to filter for.
	 * @param Types The types.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetTypeIn(TArray<ETransactionType> Types);

	/**
	 * @brief Sets this filter to include transactions equal to the given value.
	 * @param Value The value to compare by.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetValue(const int32 Value);

	/**
	 * @brief Sets this filter to include transactions greater than the given value.
	 * @param Value The value to compare by.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetValueGreaterThan(const int32 Value);

	/**
	 * @brief Sets this filter to include transactions greater than or equal to the given value.
	 * @param Value The value to compare by.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetValueGreaterThanOrEqual(const int32 Value);

	/**
	 * @brief Sets this filter to include transactions less than the given value.
	 * @param Value The value to compare by.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetValueLessThan(const int32 Value);

	/**
	 * @brief Sets this filter to include transactions less than or equal to the given value.
	 * @param Value The value to compare by.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetValueLessThanOrEqual(const int32 Value);

	/**
	 * @brief Sets the wallet address to filter for.
	 * @param Address The address.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetWallet(FString Address);

	/**
	 * @brief Sets the wallet addresses to filter for.
	 * @param Addresses The addresses.
	 * @return This input for chaining.
	 */
	FTransactionFilter& SetWalletIn(TArray<FString> Addresses);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FTransactionFilter& Rhs) const;

	bool operator!=(const FTransactionFilter& Rhs) const;

	FTransactionFilter& operator=(const FTransactionFilter& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
