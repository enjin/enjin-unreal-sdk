// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/Project.h"
#include "Model/Wallet.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
// Forward declaration of classes that have a circular-dependency with FBalance.
class FWallet;

/**
 * @brief Models a asset balance.
 */
class ENJINSDK_API FBalance final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FBalance();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FBalance(const FBalance& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FBalance(FBalance&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FBalance() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the asset ID for this balance.
	 * @return The asset ID.
	 */
	const TOptional<FString>& GetId() const;

	/**
	 * @brief Returns the asset index for this balance.
	 * @return The asset index.
	 */
	const TOptional<FString>& GetIndex() const;

	/**
	 * @brief Returns the project the asset of this balance belongs to.
	 * @return The project.
	 */
	const TOptional<FProject>& GetProject() const;

	/**
	 * @brief Returns the amount of the asset in this balance.
	 * @return The amount of this asset.
	 */
	const TOptional<int32>& GetValue() const;

	/**
	 * @brief Returns the wallet this balance belongs to.
	 * @return The wallet.
	 */
	const TOptional<FWallet>& GetWallet() const;

	bool operator==(const FBalance& Rhs) const;

	bool operator!=(const FBalance& Rhs) const;

	FBalance& operator=(const FBalance& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
