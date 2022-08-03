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
 * @brief Models the supply models used by the platform.
 */
class ENJINSDKRUNTIME_API FSupplyModels final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FSupplyModels();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FSupplyModels(const FSupplyModels& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FSupplyModels(FSupplyModels&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FSupplyModels() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the annual percentage model.
	 * @return The annual percentage model.
	 */
	const TOptional<FString>& GetAnnualPercentage() const;

	/**
	 * @brief Returns the annual value model.
	 * @return The annual value model.
	 */
	const TOptional<FString>& GetAnnualValue() const;

	/**
	 * @brief Returns the collapsing model.
	 * @return The collapsing model.
	 */
	const TOptional<FString>& GetCollapsing() const;

	/**
	 * @brief Returns the fixed model.
	 * @return The fixed model.
	 */
	const TOptional<FString>& GetFixed() const;

	/**
	 * @brief Returns the infinite model.
	 * @return The infinite model.
	 */
	const TOptional<FString>& GetInfinite() const;

	/**
	 * @brief Returns the settable model.
	 * @return The settable model.
	 */
	const TOptional<FString>& GetSettable() const;

	bool operator==(const FSupplyModels& Rhs) const;

	bool operator!=(const FSupplyModels& Rhs) const;

	FSupplyModels& operator=(const FSupplyModels& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
