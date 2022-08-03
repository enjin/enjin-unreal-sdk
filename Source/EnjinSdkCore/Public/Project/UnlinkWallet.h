// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IGraphQlRequest.h"

namespace Enjin
{
namespace Sdk
{
namespace Project
{
/**
 * @brief Request for unlinking a wallet from the project.
 */
class ENJINSDKCORE_API FUnlinkWallet final : public GraphQl::IGraphQlRequest
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FUnlinkWallet();

	/**
	 * @brief Default destructor.
	 */
	virtual ~FUnlinkWallet() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Sets the Ethereum address of the wallet to unlink.
	 * @param Address The address.
	 * @return This request for chaining.
	 */
	FUnlinkWallet& SetEthAddress(FString Address);

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FUnlinkWallet& Rhs) const;

	bool operator!=(const FUnlinkWallet& Rhs) const;

private:
	TOptional<FString> EthAddressOpt;
};
}
}
}
