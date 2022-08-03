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
 * @brief Models Pusher options used by the platform.
 */
class ENJINSDKRUNTIME_API FPusherOptions final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FPusherOptions();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FPusherOptions(const FPusherOptions& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FPusherOptions(FPusherOptions&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPusherOptions() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the cluster the platform is in.
	 * @return The cluster.
	 */
	const TOptional<FString>& GetCluster() const;

	/**
	 * @brief Returns whether encryption is used or not by the platform.
	 * @return Whether encryption is used or not.
	 */
	const TOptional<bool>& GetEncrypted() const;

	bool operator==(const FPusherOptions& Rhs) const;

	bool operator!=(const FPusherOptions& Rhs) const;

	FPusherOptions& operator=(const FPusherOptions& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
