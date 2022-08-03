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
 * @brief Models gas prices on the platform.
 */
class ENJINSDKRUNTIME_API FGasPrices final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGasPrices();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FGasPrices(const FGasPrices& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FGasPrices(FGasPrices&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FGasPrices() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the recommended average gas price in Gwei.
	 * @return The gas price.
	 * @remarks Expected to be mined in less than 5 minutes.
	 */
	const TOptional<double>& GetAverage() const;

	/**
	 * @brief Returns the recommended fast gas price in Gwei.
	 * @return The gas price.
	 * @remarks Expected to be mined in less than 2 minutes.
	 */
	const TOptional<double>& GetFast() const;

	/**
	 * @brief Returns the recommended fastest gas price in Gwei.
	 * @return The gas price.
	 * @remarks Expected to be mined in less than 30 seconds.
	 */
	const TOptional<double>& GetFastest() const;

	/**
	 * @brief Returns the recommended safe gas price in Gwei.
	 * @return The gas price.
	 * @remarks Expected to be mined in less than 30 minutes.
	 */
	const TOptional<double>& GetSafeLow() const;

	bool operator==(const FGasPrices& Rhs) const;

	bool operator!=(const FGasPrices& Rhs) const;

	FGasPrices& operator=(const FGasPrices& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
