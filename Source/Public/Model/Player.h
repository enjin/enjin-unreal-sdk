// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/LinkingInfo.h"
#include "Model/Wallet.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a player on the platform.
 */
class ENJINSDK_API FPlayer final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FPlayer();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FPlayer(const FPlayer& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FPlayer(FPlayer&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPlayer() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the datetime when this player was created.
	 * @return The datetime
	 * @remarks The datetime is formatted using the ISO 8601 date format.
	 */
	const TOptional<FString>& GetCreatedAt() const;

	/**
	 * @brief Returns the ID of this player.
	 * @return The player ID.
	 */
	const TOptional<FString>& GetId() const;

	/**
	 * @brief Returns the linking information for this player.
	 * @return The linking information.
	 */
	const TOptional<FLinkingInfo>& GetLinkingInfo() const;

	/**
	 * @brief Returns the datetime when this player was last updated.
	 * @return The datetime.
	 * @remarks The datetime is formatted using the ISO 8601 date format.
	 */
	const TOptional<FString>& GetUpdatedAt() const;

	/**
	 * @brief Returns the wallet for this player.
	 * @return The wallet.
	 */
	const TOptional<FWallet>& GetWallet() const;

	bool operator==(const FPlayer& Rhs) const;

	bool operator!=(const FPlayer& Rhs) const;

	FPlayer& operator=(const FPlayer& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
