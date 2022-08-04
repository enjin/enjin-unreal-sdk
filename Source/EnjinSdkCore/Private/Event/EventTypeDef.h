// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "Model/EventType.h"

namespace Enjin
{
namespace Sdk
{
namespace Event
{
/**
 * @brief Definition for event types.
 */
class FEventTypeDef final
{
public:
	/**
	 * @brief Constructs an instance of this class for the @link Model::EEventType::Unknown @endlink event type.
	 */
	FEventTypeDef();

	/**
	 * @brief Constructs an instance of this class with the given data.
	 * @param Type The event type.
	 * @param Key The event key.
	 * @param Channels The channels the event broadcasts on.
	 */
	FEventTypeDef(const Model::EEventType Type, FString Key, TArray<FString> Channels);

	/**
	 * @brief Class destructor.
	 */
	~FEventTypeDef() = default;

	/**
	 * @brief Returns the channels the event of this definition broadcasts on.
	 * @return The channels.
	 */
	const TArray<FString>& GetChannels() const;

	/**
	 * @brief Returns the key of the event for this definition.
	 * @return The key.
	 */
	const FString& GetKey() const;

	/**
	 * @brief Returns the name of the event for this definition.
	 * @return The name.
	 */
	const FString& GetName() const;

	/**
	 * @brief Returns the type of the event for this definition.
	 * @return The type.
	 */
	Model::EEventType GetType() const;

	bool operator==(const FEventTypeDef& Rhs) const;

	bool operator!=(const FEventTypeDef& Rhs) const;

	/**
	 * @brief Returns the definitions for the events that broadcast on the given channel.
	 * @param Channel The channel.
	 * @return The event type definitions.
	 */
	static TArray<FEventTypeDef> FilterByChannel(const FString& Channel);

	/**
	 * @brief Returns the definition for the event with the given key.
	 * @param Key The key.
	 * @return The event type definition.
	 */
	static const FEventTypeDef& GetFromKey(const FString& Key);

	/**
	 * @brief Returns the definition for the event with the given name.
	 * @param Name The name.
	 * @return The event type definition.
	 */
	static const FEventTypeDef& GetFromName(const FString& Name);

	/**
	 * @brief Returns the cached definitions.
	 * @return The definitions.
	 */
	static const TArray<FEventTypeDef>& Values();

private:
	/**
	 * @brief Struct type for static fields used across instances of @link FEventTypeDef @endlink.
	 */
	struct FStaticFields;

	const Model::EEventType Type;

	const TArray<FString> Channels;
	const FString Key;
	const FString Name;

	/**
	 * @brief Pointer to implemented struct for static fields.
	 */
	static const TUniquePtr<FStaticFields> StaticFieldsPtr;
};
}
}
}
