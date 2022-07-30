// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a blockchain transaction event.
 */
class ENJINSDK_API FTransactionEvent final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FTransactionEvent();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FTransactionEvent(const FTransactionEvent& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FTransactionEvent(FTransactionEvent&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FTransactionEvent() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the encoded signature.
	 * @return The encoded signature.
	 */
	const TOptional<FString>& GetEncodedSignature() const;

	/**
	 * @brief Returns the serialized indexed parameters for this event.
	 * @return The indexed parameters.
	 */
	const TOptional<TArray<FString>>& GetIndexedInputs() const;

	/**
	 * @brief Returns the serialized parameters for this event.
	 * @return The parameters.
	 */
	const TOptional<TArray<FString>>& GetInputs() const;

	/**
	 * @brief Returns the name of this event.
	 * @return The name.
	 */
	const TOptional<FString>& GetName() const;

	/**
	 * @brief Returns the serialized non-indexed parameters for this event.
	 * @return The non-indexed parameters.
	 */
	const TOptional<TArray<FString>>& GetNonIndexedInputs() const;

	/**
	 * @brief Returns the event signature.
	 * @return The signature.
	 * @remarks If the event was anonymous, then the optional will not be set.
	 */
	const TOptional<FString>& GetSignature() const;

	bool operator==(const FTransactionEvent& Rhs) const;

	bool operator!=(const FTransactionEvent& Rhs) const;

	FTransactionEvent& operator=(const FTransactionEvent& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
