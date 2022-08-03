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
 * @brief Models the linking information for a player.
 */
class ENJINSDKRUNTIME_API FLinkingInfo final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FLinkingInfo();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FLinkingInfo(const FLinkingInfo& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FLinkingInfo(FLinkingInfo&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FLinkingInfo() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the linking code used to link a wallet to the player this info belongs to.
	 * @return The linking code.
	 */
	const TOptional<FString>& GetCode() const;

	/**
	 * @brief Returns the URL for the QR image that links a wallet to the player this info belongs to.
	 * @return The URL for the image.
	 */
	const TOptional<FString>& GetQr() const;

	bool operator==(const FLinkingInfo& Rhs) const;

	bool operator!=(const FLinkingInfo& Rhs) const;

	FLinkingInfo& operator=(const FLinkingInfo& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
