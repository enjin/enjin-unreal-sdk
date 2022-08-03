// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"

namespace Enjin
{
namespace Sdk
{
namespace GraphQl
{
/**
 * @brief Base class for representing a GraphQL request to the platform.
 */
class ENJINSDKRUNTIME_API IGraphQlRequest : public Serialization::ISerializable
{
public:
	IGraphQlRequest() = delete;

	/**
	 * @brief Default destructor.
	 */
	virtual ~IGraphQlRequest() override = default;

	/**
	 * @brief Returns the namespace of this request.
	 * @return This namespace.
	 */
	const FString& GetNamespace() const;

	bool operator==(const IGraphQlRequest& Rhs) const;

	bool operator!=(const IGraphQlRequest& Rhs) const;

protected:
	/**
	 * @brief Constructs an instance of this class.
	 * @param Namespace The namespace.
	 */
	explicit IGraphQlRequest(FString Namespace);

private:
	const FString Namespace;
};
}
}
}
