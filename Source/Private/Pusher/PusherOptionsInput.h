// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

namespace Enjin
{
namespace Sdk
{
namespace Pusher
{
/**
 * @brief Input for options for a Pusher client.
 */
class FPusherOptionsInput final
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FPusherOptionsInput() = default;

	/**
	 * @brief Default destructor.
	 */
	~FPusherOptionsInput() = default;

	/**
	 * @brief Returns the cluster if set, otherwise returns 'mt1' for the cluster.
	 * @return The cluster.
	 */
	FString GetCluster() const;

	/**
	 * @brief Returns the websocket host to be used by the client.
	 * @return The host.
	 */
	FString Host() const;

	/**
	 * @brief Returns whether encryption is to be used by the client.
	 * @return Whether encryption is to be used.
	 */
	bool IsEncrypted() const;

	/**
	 * @brief Sets the cluster to be used by the client.
	 * @param Cluster The cluster.
	 * @return This for chaining.
	 */
	FPusherOptionsInput& SetCluster(FString Cluster);

	/**
	 * @brief Sets whether encryption is to be used by the client. Is true by default.
	 * @param bIsEncrypted The encryption state.
	 * @return This for chaining.
	 */
	FPusherOptionsInput& SetEncrypted(const bool bIsEncrypted);

private:
	TOptional<FString> ClusterOpt;
	TOptional<bool> EncryptedOpt;
};
}
}
}
