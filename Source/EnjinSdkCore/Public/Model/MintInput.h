// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a mint input for mint requests.
 */
class ENJINSDKCORE_API FMintInput final : public Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FMintInput();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FMintInput(const FMintInput& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FMintInput(FMintInput&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FMintInput() override;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the Ethereum address to mint to.
	 * @param To The address.
	 * @return This input for chaining.
	 */
	FMintInput& SetTo(FString To);

	/**
	 * @brief Sets the amount of assets to mint.
	 * @param Value The amount.
	 * @return This input for chaining.
	 */
	FMintInput& SetValue(FString Value);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FMintInput& Rhs) const;

	bool operator!=(const FMintInput& Rhs) const;

	FMintInput& operator=(const FMintInput& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
