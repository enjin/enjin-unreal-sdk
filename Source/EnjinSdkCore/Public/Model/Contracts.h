// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/SupplyModels.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a smart contract used by the platform.
 */
class ENJINSDKCORE_API FContracts final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FContracts();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FContracts(const FContracts& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FContracts(FContracts&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FContracts() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the crypto items contract address.
	 * @return The contract address.
	 */
	const TOptional<FString>& GetCryptoItems() const;

	/**
	 * @brief Returns the ENJ contract address.
	 * @return The contract address.
	 */
	const TOptional<FString>& GetEnj() const;

	/**
	 * @brief Returns the platform registry contract address.
	 * @return The contract address.
	 */
	const TOptional<FString>& GetPlatformRegistry() const;

	/**
	 * @brief Returns the supply models used by the platform.
	 * @return The supply models
	 */
	const TOptional<FSupplyModels>& GetSupplyModels() const;

	bool operator==(const FContracts& Rhs) const;

	bool operator!=(const FContracts& Rhs) const;

	FContracts& operator=(const FContracts& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
