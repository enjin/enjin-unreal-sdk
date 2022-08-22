// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "ISerializable.h"
#include "Model/AssetField.h"
#include "Model/AssetIdFormat.h"
#include "Model/AssetIndexFormat.h"
#include "Model/AssetSupplyModel.h"
#include "Model/AssetTransferFeeType.h"
#include "Model/AssetTransferable.h"
#include "Model/AssetVariantMode.h"
#include "Model/Operator.h"
#include "Model/SortDirection.h"
#include "Model/TransactionField.h"
#include "Model/TransactionState.h"
#include "Model/TransactionType.h"
#include "Model/Whitelisted.h"
#include <type_traits>

namespace Enjin
{
namespace Sdk
{
namespace Util
{
/**
 * @brief Utility class for JSON processing.
 */
class ENJINSDKCORE_API FJsonUtil final
{
public:
	FJsonUtil() = delete;

	~FJsonUtil() = delete;

	/**
	 * @brief Determines whether two JSON objects are equal.
	 * @param First The first object.
	 * @param Second The second object.
	 * @return Whether the two JSON objects are equal.
	 */
	static bool Equals(const TSharedPtr<FJsonObject>& First, const TSharedPtr<FJsonObject>& Second);

	/**
	 * @brief Determines whether two JSON objects are equal.
	 * @param First The first object.
	 * @param Second The second object.
	 * @return Whether the two JSON objects are equal.
	 */
	static bool Equals(const TSharedRef<FJsonObject>& First, const TSharedRef<FJsonObject>& Second);

	/**
	 * @brief Determines whether two optionals containing JSON objects are equal.
	 * @param First The first optional.
	 * @param Second The second optional.
	 * @return Whether the two optionals are equal.
	 */
	static bool Equals(const TOptional<TSharedRef<FJsonObject>>& First,
	                   const TOptional<TSharedRef<FJsonObject>>& Second);

	/**
	 * @brief Determines whether two JSON values are equal.
	 * @param First The first value.
	 * @param Second The second value.
	 * @return Whether the two JSON values are equal.
	 */
	static bool Equals(const TSharedPtr<FJsonValue>& First, const TSharedPtr<FJsonValue>& Second);

	/**
	 * @brief Determines whether two JSON values are equal.
	 * @param First The first value.
	 * @param Second The second value.
	 * @return Whether the two JSON values are equal.
	 */
	static bool Equals(const TSharedRef<FJsonValue>& First, const TSharedRef<FJsonValue>& Second);

	/**
	 * @brief Determines whether two JSON arrays are equal.
	 * @param First The first array.
	 * @param Second The second array.
	 * @return Whether the two JSON arrays are equal.
	 */
	static bool Equals(const TArray<TSharedPtr<FJsonValue>>& First, const TArray<TSharedPtr<FJsonValue>>& Second);

	/**
	 * @brief Creates an array of JSON values from a typed array.
	 * @tparam T The type contained within the array being processed.
	 * @param Array The array being processed.
	 * @return The array of JSON values.
	 */
	template <class T>
	static TArray<TSharedPtr<FJsonValue>> GetTypeArrayAsJsonValueArray(const TArray<T>& Array)
	{
		static_assert(std::is_base_of_v<Serialization::ISerializable, T>,
			"Class T does not inherit from ISerializable.");

		TArray<TSharedPtr<FJsonValue>> ValueArray;

		for (const T& El : Array)
		{
			TSharedPtr<FJsonObject> JsonObject;
			if (TryParseJsonObject(El.Serialize(), JsonObject))
			{
				ValueArray.Add(MakeShared<FJsonValueObject>(MoveTemp(JsonObject)));
			}
		}

		return ValueArray;
	}

	/**
	 * @brief Joins one JSON object to another.
	 * @param JsonObject The JSON object to modify.
	 * @param Other The JSON object to copy fields from.
	 * @remarks Will overwrite preexisting fields in the JSON object.
	 */
	static void JoinObject(const TSharedRef<FJsonObject> JsonObject, const TSharedRef<FJsonObject> Other);

	/**
	 * @brief Returns the raw representation of the given JSON object.
	 * @param JsonObject The JSON object.
	 * @return The raw JSON.
	 */
	static FString SerializeJsonObject(const TSharedRef<FJsonObject>& JsonObject);

	/**
	 * @brief Tries to get the specified object field as a typed array.
	 * @tparam T The class type the array stores.
	 * @param JsonObject The JSON object.
	 * @param Key The name of the field.
	 * @param OutArray The array being set.
	 * @return Whether this action was successful.
	 * @remark Class type T must implement Serialization::IDeserializable.
	 */
	template <class T>
	static bool TryGetArrayAsTypeArray(const TSharedRef<FJsonObject>& JsonObject,
	                                   const FString& Key,
	                                   TArray<T>& OutArray)
	{
		static_assert(std::is_base_of_v<Serialization::IDeserializable, T>,
			"Class T does not inherit from IDeserializable.");

		OutArray.Reset();

		const TArray<TSharedPtr<FJsonValue>>* ValueArray;
		if (!JsonObject->TryGetArrayField(Key, ValueArray))
		{
			return false;
		}

		for (const TSharedPtr<FJsonValue> Value : *ValueArray)
		{
			const TSharedPtr<FJsonObject>* ValueObject;
			if (!Value->TryGetObject(ValueObject))
			{
				continue;
			}

			const FString ValueJson = SerializeJsonObject(ValueObject->ToSharedRef());

			T t;
			t.Deserialize(ValueJson);

			OutArray.Add(MoveTemp(t));
		}

		return true;
	}

	/**
	 * @brief Tries and set the optional with the specified field.
	 * @tparam T The class type of the object.
	 * @param JsonObject The JSON object.
	 * @param Key The name of the field.
	 * @param OutField The optional to write to.
	 * @return Whether this action was successful.
	 * @remarks The out optional will be cleared if this operation is not successful.
	 */
	template <class T>
	static bool TryGetField(const TSharedRef<FJsonObject>& JsonObject, const FString& Key, TOptional<T>& OutField)
	{
		T NewField;
		if (FJsonUtil::TryGetObjectAsType<T>(JsonObject, Key, NewField))
		{
			OutField.Emplace(MoveTemp(NewField));
			return true;
		}

		OutField.Reset();
		return false;
	}

	/**
	 * @brief Tries and set the optional with the specified array field.
	 * @tparam T The class type contained in the array.
	 * @param JsonObject The JSON object.
	 * @param Key The name of the field.
	 * @param OutField The optional to write to.
	 * @return Whether this action was successful.
	 * @remarks The out optional will be cleared if this operation is not successful.
	 */
	template <class T>
	static bool TryGetField(const TSharedRef<FJsonObject>& JsonObject,
	                        const FString& Key,
	                        TOptional<TArray<T>>& OutField)
	{
		TArray<T> NewField;
		if (FJsonUtil::TryGetArrayAsTypeArray(JsonObject, Key, NewField))
		{
			OutField.Emplace(MoveTemp(NewField));
			return true;
		}

		OutField.Reset();
		return false;
	}

	/**
	 * @brief Tries to get the specified object field as an instance of the class type.
	 * @tparam T The class type of the object.
	 * @param JsonObject The JSON object.
	 * @param Key The name of the field.
	 * @param OutObject The object being set.
	 * @return Whether this action was successful.
	 * @remark Class type T must implement Serialization::IDeserializable.
	 */
	template <class T>
	static bool TryGetObjectAsType(const TSharedRef<FJsonObject>& JsonObject, const FString& Key, T& OutObject)
	{
		static_assert(std::is_base_of_v<Serialization::IDeserializable, T>,
			"Class T does not inherit from IDeserializable.");

		const TSharedPtr<FJsonObject>* ValueObject;
		if (!JsonObject->TryGetObjectField(Key, ValueObject))
		{
			return false;
		}

		const FString ValueJson = SerializeJsonObject(ValueObject->ToSharedRef());
		OutObject.Deserialize(ValueJson);

		return true;
	}

	/**
	 * @brief Tries to get the JSON value as an instance of the class type.
	 * @tparam T The class type of the object.
	 * @param JsonValue The JSON value.
	 * @param OutObject The object being set.
	 * @return Whether this action was successful.
	 * @remark Class type T must implement Serialization::IDeserializable.
	 */
	template <class T>
	static bool TryGetValueAsType(const TSharedRef<FJsonValue>& JsonValue, T& OutObject)
	{
		static_assert(std::is_base_of_v<Serialization::IDeserializable, T>,
			"Class T does not inherit from IDeserializable.");

		const TSharedPtr<FJsonObject>* JsonObject;
		if (!JsonValue->TryGetObject(JsonObject))
		{
			return false;
		}

		const FString Json = SerializeJsonObject(JsonObject->ToSharedRef());
		OutObject.Deserialize(Json);

		return true;
	}

	/**
	 * @brief Tries and parse raw JSON into a JSON object.
	 * @param Json The raw JSON.
	 * @param OutObject The object to write into.
	 * @return Whether the raw JSON was parsed.
	 */
	static bool TryParseJsonObject(const FString& Json, TSharedPtr<FJsonObject>& OutObject);

	/**
	 * @brief Tries and set the specified field in the JSON object with the data contained within the optional.
	 * @tparam T The class type of the object.
	 * @param JsonObject The JSON object.
	 * @param Key The name of the field.
	 * @param InField The optional containing the data to set.
	 * @return Whether this action was successful.
	 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
	 */
	template <class T>
	static bool TrySetField(const TSharedRef<FJsonObject>& JsonObject, const FString& Key, const TOptional<T>& InField)
	{
		if (InField.IsSet())
		{
			TSharedPtr<FJsonObject> SubObject;
			if (TryParseJsonObject(InField.GetValue().Serialize(), SubObject))
			{
				JsonObject->SetObjectField(Key, SubObject);
				return true;
			}
		}

		if (JsonObject->HasField(Key))
		{
			JsonObject->RemoveField(Key);
		}

		return false;
	}

	/**
	 * @brief Tries and set the specified field in the JSON object with the array contained within the optional.
	 * @tparam T The class type of the object.
	 * @param JsonObject The JSON object.
	 * @param Key The name of the field.
	 * @param InField The array containing the data to set.
	 * @return Whether this action was successful.
	 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
	 */
	template <class T>
	static bool TrySetField(const TSharedRef<FJsonObject>& JsonObject,
	                        const FString& Key,
	                        const TOptional<TArray<T>>& InField)
	{
		if (InField.IsSet())
		{
			JsonObject->SetArrayField(Key, GetTypeArrayAsJsonValueArray(InField.GetValue()));
			return true;
		}

		if (JsonObject->HasField(Key))
		{
			JsonObject->RemoveField(Key);
		}

		return false;
	}
};

/**
 * @brief Creates an array of JSON values from a string array.
 * @param Array The array being processed.
 * @return The array of JSON values.
 */
template <>
inline TArray<TSharedPtr<FJsonValue>> FJsonUtil::GetTypeArrayAsJsonValueArray<FString>(const TArray<FString>& Array)
{
	TArray<TSharedPtr<FJsonValue>> ValueArray;

	for (const FString& String : Array)
	{
		ValueArray.Add(MakeShared<FJsonValueString>(String));
	}

	return ValueArray;
}

/**
 * @brief Tries to get the specified object field as a string array.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutArray The array being set.
 * @return Whether this action was successful.
 */
template <>
inline bool FJsonUtil::TryGetArrayAsTypeArray<FString>(const TSharedRef<FJsonObject>& JsonObject,
                                                       const FString& Key,
                                                       TArray<FString>& OutArray)
{
	return JsonObject->TryGetStringArrayField(Key, OutArray);
}

/**
 * @brief Tries and set the optional with the specified bool field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<bool>(const TSharedRef<FJsonObject>& JsonObject,
                                         const FString& Key,
                                         TOptional<bool>& OutField)
{
	bool NewField;
	if (JsonObject->TryGetBoolField(Key, NewField))
	{
		OutField.Emplace(NewField);
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified number field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<int32>(const TSharedRef<FJsonObject>& JsonObject,
                                          const FString& Key,
                                          TOptional<int32>& OutField)
{
	int32 NewField;
	if (JsonObject->TryGetNumberField(Key, NewField))
	{
		OutField.Emplace(NewField);
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified number field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<int64>(const TSharedRef<FJsonObject>& JsonObject,
                                          const FString& Key,
                                          TOptional<int64>& OutField)
{
	int32 NewField;
	if (JsonObject->TryGetNumberField(Key, NewField))
	{
		OutField.Emplace(NewField);
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified number field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<double>(const TSharedRef<FJsonObject>& JsonObject,
                                           const FString& Key,
                                           TOptional<double>& OutField)
{
	int32 NewField;
	if (JsonObject->TryGetNumberField(Key, NewField))
	{
		OutField.Emplace(NewField);
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified string field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<FString>(const TSharedRef<FJsonObject>& JsonObject,
                                            const FString& Key,
                                            TOptional<FString>& OutField)
{
	FString NewField;
	if (JsonObject->TryGetStringField(Key, NewField))
	{
		OutField.Emplace(MoveTemp(NewField));
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified object field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<TSharedRef<FJsonObject>>(const TSharedRef<FJsonObject>& JsonObject,
                                                            const FString& Key,
                                                            TOptional<TSharedRef<FJsonObject>>& OutField)
{
	const TSharedPtr<FJsonObject>* NewField;
	if (JsonObject->TryGetObjectField(Key, NewField))
	{
		OutField.Emplace(NewField->ToSharedRef());
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified enum field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<Model::EAssetSupplyModel>(const TSharedRef<FJsonObject>& JsonObject,
                                                             const FString& Key,
                                                             TOptional<Model::EAssetSupplyModel>& OutField)
{
	FString NewField;
	if (JsonObject->TryGetStringField(Key, NewField))
	{
		OutField.Emplace(Model::ToAssetSupplyModel(NewField));
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified enum field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<Model::EAssetTransferFeeType>(const TSharedRef<FJsonObject>& JsonObject,
                                                                 const FString& Key,
                                                                 TOptional<Model::EAssetTransferFeeType>& OutField)
{
	FString NewField;
	if (JsonObject->TryGetStringField(Key, NewField))
	{
		OutField.Emplace(Model::ToAssetTransferFeeType(NewField));
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified enum field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<Model::EAssetTransferable>(const TSharedRef<FJsonObject>& JsonObject,
                                                              const FString& Key,
                                                              TOptional<Model::EAssetTransferable>& OutField)
{
	FString NewField;
	if (JsonObject->TryGetStringField(Key, NewField))
	{
		OutField.Emplace(Model::ToAssetTransferable(NewField));
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified enum field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<Model::EAssetVariantMode>(const TSharedRef<FJsonObject>& JsonObject,
                                                             const FString& Key,
                                                             TOptional<Model::EAssetVariantMode>& OutField)
{
	FString NewField;
	if (JsonObject->TryGetStringField(Key, NewField))
	{
		OutField.Emplace(Model::ToAssetVariantMode(NewField));
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified enum field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<Model::ETransactionState>(const TSharedRef<FJsonObject>& JsonObject,
                                                             const FString& Key,
                                                             TOptional<Model::ETransactionState>& OutField)
{
	FString NewField;
	if (JsonObject->TryGetStringField(Key, NewField))
	{
		OutField.Emplace(Model::ToTransactionState(NewField));
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the optional with the specified enum field.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param OutField The optional to write to.
 * @return Whether this action was successful.
 * @remarks The out optional will be cleared if this operation is not successful.
 */
template <>
inline bool FJsonUtil::TryGetField<Model::ETransactionType>(const TSharedRef<FJsonObject>& JsonObject,
                                                            const FString& Key,
                                                            TOptional<Model::ETransactionType>& OutField)
{
	FString NewField;
	if (JsonObject->TryGetStringField(Key, NewField))
	{
		OutField.Emplace(Model::ToTransactionType(NewField));
		return true;
	}

	OutField.Reset();
	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the boolean contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The boolean to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<bool>(const TSharedRef<FJsonObject>& JsonObject,
                                         const FString& Key,
                                         const TOptional<bool>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetBoolField(Key, InField.GetValue());
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the number contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The number to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<int32>(const TSharedRef<FJsonObject>& JsonObject,
                                          const FString& Key,
                                          const TOptional<int32>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetNumberField(Key, InField.GetValue());
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the number contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The number to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<int64>(const TSharedRef<FJsonObject>& JsonObject,
                                          const FString& Key,
                                          const TOptional<int64>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetNumberField(Key, InField.GetValue());
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the number contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The number to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<double>(const TSharedRef<FJsonObject>& JsonObject,
                                           const FString& Key,
                                           const TOptional<double>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetNumberField(Key, InField.GetValue());
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the string contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The string to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<FString>(const TSharedRef<FJsonObject>& JsonObject,
                                            const FString& Key,
                                            const TOptional<FString>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, InField.GetValue());
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the array of strings contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The string array to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<TArray<FString>>(const TSharedRef<FJsonObject>& JsonObject,
                                                    const FString& Key,
                                                    const TOptional<TArray<FString>>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetArrayField(Key, GetTypeArrayAsJsonValueArray(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the object contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The object to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<TSharedRef<FJsonObject>>(const TSharedRef<FJsonObject>& JsonObject,
                                                            const FString& Key,
                                                            const TOptional<TSharedRef<FJsonObject>>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetObjectField(Key, InField.GetValue());
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::EAssetField>(const TSharedRef<FJsonObject>& JsonObject,
                                                       const FString& Key,
                                                       const TOptional<Model::EAssetField>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, Model::ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::EAssetIdFormat>(const TSharedRef<FJsonObject>& JsonObject,
                                                          const FString& Key,
                                                          const TOptional<Model::EAssetIdFormat>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, Model::ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::EAssetIndexFormat>(const TSharedRef<FJsonObject>& JsonObject,
                                                             const FString& Key,
                                                             const TOptional<Model::EAssetIndexFormat>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, Model::ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::EAssetSupplyModel>(const TSharedRef<FJsonObject>& JsonObject,
                                                             const FString& Key,
                                                             const TOptional<Model::EAssetSupplyModel>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, Model::ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::EAssetTransferFeeType>(const TSharedRef<FJsonObject>& JsonObject,
                                                                 const FString& Key,
                                                                 const TOptional<Model::EAssetTransferFeeType>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, Model::ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::EAssetTransferable>(const TSharedRef<FJsonObject>& JsonObject,
                                                              const FString& Key,
                                                              const TOptional<Model::EAssetTransferable>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, Model::ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::EOperator>(const TSharedRef<FJsonObject>& JsonObject,
                                                     const FString& Key,
                                                     const TOptional<Model::EOperator>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::ESortDirection>(const TSharedRef<FJsonObject>& JsonObject,
                                                          const FString& Key,
                                                          const TOptional<Model::ESortDirection>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::ETransactionField>(const TSharedRef<FJsonObject>& JsonObject,
                                                             const FString& Key,
                                                             const TOptional<Model::ETransactionField>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::ETransactionState>(const TSharedRef<FJsonObject>& JsonObject,
                                                             const FString& Key,
                                                             const TOptional<Model::ETransactionState>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, Model::ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the array of enums contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum array to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::ETransactionState>(const TSharedRef<FJsonObject>& JsonObject,
                                                             const FString& Key,
                                                             const TOptional<TArray<Model::ETransactionState>>& InField)
{
	if (InField.IsSet())
	{
		TArray<FString> States;

		for (const Model::ETransactionState Type : InField.GetValue())
		{
			States.Add(Model::ToString(Type));
		}

		const TOptional<TArray<FString>> Optional(MoveTemp(States));
		return FJsonUtil::TrySetField(JsonObject, Key, Optional);
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::ETransactionType>(const TSharedRef<FJsonObject>& JsonObject,
                                                            const FString& Key,
                                                            const TOptional<Model::ETransactionType>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, Model::ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the array of enums contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum array to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::ETransactionType>(const TSharedRef<FJsonObject>& JsonObject,
                                                            const FString& Key,
                                                            const TOptional<TArray<Model::ETransactionType>>& InField)
{
	if (InField.IsSet())
	{
		TArray<FString> Types;

		for (const Model::ETransactionType Type : InField.GetValue())
		{
			Types.Add(Model::ToString(Type));
		}

		const TOptional<TArray<FString>> Optional(MoveTemp(Types));
		return FJsonUtil::TrySetField(JsonObject, Key, Optional);
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}

/**
 * @brief Tries and set the specified field in the JSON object with the enum contained within the optional.
 * @param JsonObject The JSON object.
 * @param Key The name of the field.
 * @param InField The enum to set.
 * @return Whether this action was successful.
 * @remarks If the JSON object already has the field and the optional is empty, then the field will be removed.
 */
template <>
inline bool FJsonUtil::TrySetField<Model::EWhitelisted>(const TSharedRef<FJsonObject>& JsonObject,
                                                        const FString& Key,
                                                        const TOptional<Model::EWhitelisted>& InField)
{
	if (InField.IsSet())
	{
		JsonObject->SetStringField(Key, ToString(InField.GetValue()));
		return true;
	}

	if (JsonObject->HasField(Key))
	{
		JsonObject->RemoveField(Key);
	}

	return false;
}
}
}
}
