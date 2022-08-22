// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "ISerializable.h"

namespace Enjin
{
namespace Test
{
namespace Util
{
/**
 * @brief Dummy object to be used in plugin tests.
 */
class FDummyObject final : public Sdk::Serialization::IDeserializable,
                           public Sdk::Serialization::ISerializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FDummyObject() = default;

	/**
	 * @brief Constructs an instance of this class with the given integer.
	 * @param Int The integer.
	 */
	explicit FDummyObject(const int32 Int);

	/**
	 * @brief Default destructor.
	 */
	virtual ~FDummyObject() override = default;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the integer field of this class.
	 * @return The integer field.
	 */
	const TOptional<int32>& GetInt() const;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override;

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override;

	bool operator==(const FDummyObject& Rhs) const;

	bool operator!=(const FDummyObject& Rhs) const;

	/**
	 * @brief Returns a populated instance of this class.
	 * @return The instance.
	 */
	static FDummyObject CreateDefault();

private:
	TOptional<int32> IntOpt;
};
}
}
}
