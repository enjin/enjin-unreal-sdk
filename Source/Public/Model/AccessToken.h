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
 * @brief Models an authentication object from the platform.
 */
class ENJINSDK_API FAccessToken final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAccessToken();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FAccessToken(const FAccessToken& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FAccessToken(FAccessToken&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FAccessToken() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the number of seconds until the authentication token expires.
	 * @return The number of seconds until the authentication token expires.
	 */
	const TOptional<int64>& GetExpiresIn() const;

	/**
	 * @brief Returns the authentication token.
	 * @return The authentication token.
	 */
	const TOptional<FString>& GetToken() const;

	bool operator==(const FAccessToken& Rhs) const;

	bool operator!=(const FAccessToken& Rhs) const;

	FAccessToken& operator=(const FAccessToken& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
