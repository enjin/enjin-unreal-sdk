// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"

namespace Enjin
{
namespace Sdk
{
namespace GraphQl
{
/**
 * @brief Models a GraphQL response error from the platform.
 */
class ENJINSDKRUNTIME_API FGraphQlError final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FGraphQlError() = default;

	/**
	 * @brief Default destructor.
	 */
	virtual ~FGraphQlError() override = default;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the code of this error.
	 * @return The code.
	 */
	const TOptional<int32>& GetCode() const;

	/**
	 * @brief Returns the details of this error.
	 * @return The details.
	 */
	const TOptional<FString>& GetDetails() const;

	/**
	 * @brief Returns the locations of this error.
	 * @return The locations.
	 */
	const TOptional<TArray<TMap<FString, int32>>>& GetLocations() const;

	/**
	 * @brief Returns the message of this error.
	 * @return The message.
	 */
	const TOptional<FString>& GetMessage() const;

	/**
	 * @remark Does not check equality of locations due to limitation with maps in arrays.
	 */
	bool operator==(const FGraphQlError& Rhs) const;

	/**
	 * @remark Does not check inequality of locations due to limitation with maps in arrays.
	 */
	bool operator!=(const FGraphQlError& Rhs) const;

private:
	TOptional<int32> Code;
	TOptional<FString> Details;
	TOptional<TArray<TMap<FString, int32>>> Locations;
	TOptional<FString> Message;
};
}
}
}
