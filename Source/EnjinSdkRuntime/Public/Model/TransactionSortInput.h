// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"
#include "Model/SortDirection.h"
#include "Model/TransactionField.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models sorting input for transactions
 */
class ENJINSDKRUNTIME_API FTransactionSortInput final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FTransactionSortInput();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FTransactionSortInput(const FTransactionSortInput& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FTransactionSortInput(FTransactionSortInput&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FTransactionSortInput() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the direction to sort by.
	 * @param Direction The direction.
	 * @return This input for chaining.
	 */
	FTransactionSortInput& SetDirection(const ESortDirection Direction);

	/**
	 * @brief Sets the field to sort by.
	 * @param Field The field.
	 * @return This input for chaining.
	 */
	FTransactionSortInput& SetField(const ETransactionField Field);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FTransactionSortInput& Rhs) const;

	bool operator!=(const FTransactionSortInput& Rhs) const;

	FTransactionSortInput& operator=(const FTransactionSortInput& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
