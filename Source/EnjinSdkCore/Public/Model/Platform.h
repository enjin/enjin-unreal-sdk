// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/Contracts.h"
#include "Model/Notifications.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models data about the platform.
 */
class ENJINSDKCORE_API FPlatform final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FPlatform();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FPlatform(const FPlatform& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FPlatform(FPlatform&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPlatform() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the smart contracts used by this platform.
	 * @return The contracts
	 */
	const TOptional<FContracts>& GetContracts() const;

	/**
	 * @brief Returns the ID of this platform.
	 * @return The ID.
	 */
	const TOptional<int32>& GetId() const;

	/**
	 * @brief Returns the name of this platform.
	 * @return The name.
	 */
	const TOptional<FString>& GetName() const;

	/**
	 * @brief Returns the current network this platform is using.
	 * @return The network.
	 */
	const TOptional<FString>& GetNetwork() const;

	/**
	 * @brief Returns the notification drivers that this platform is using.
	 * @return The notification drivers.
	 */
	const TOptional<FNotifications>& GetNotifications() const;

	bool operator==(const FPlatform& Rhs) const;

	bool operator!=(const FPlatform& Rhs) const;

	FPlatform& operator=(const FPlatform& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
