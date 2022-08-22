// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "JsonUtil.h"

#include "Policies/CondensedJsonPrintPolicy.h"
#include "Serialization/JsonSerializer.h"

using namespace Enjin::Sdk::Util;

typedef TJsonWriter<TCHAR, TCondensedJsonPrintPolicy<TCHAR>> FJsonWriter;
typedef TJsonWriterFactory<TCHAR, TCondensedJsonPrintPolicy<TCHAR>> FJsonWriterFactory;

bool FJsonUtil::Equals(const TSharedPtr<FJsonObject>& First, const TSharedPtr<FJsonObject>& Second)
{
	if (First.IsValid() && Second.IsValid())
	{
		return Equals(First.ToSharedRef(), Second.ToSharedRef());
	}

	return !First.IsValid() && !Second.IsValid();
}

bool FJsonUtil::Equals(const TSharedRef<FJsonObject>& First, const TSharedRef<FJsonObject>& Second)
{
	const TMap<FString, TSharedPtr<FJsonValue>> FirstValues = First->Values;
	const TMap<FString, TSharedPtr<FJsonValue>> SecondValues = Second->Values;
	TSet<FString> FirstKeys;
	TSet<FString> SecondKeys;

	if (FirstValues.GetKeys(FirstKeys) != SecondValues.GetKeys(SecondKeys))
	{
		return false;
	}

	for (const FString& Entry : FirstKeys)
	{
		if (!SecondKeys.Contains(Entry) || !Equals(FirstValues[Entry], SecondValues[Entry]))
		{
			return false;
		}
	}

	return true;
}

bool FJsonUtil::Equals(const TOptional<TSharedRef<FJsonObject>>& First,
                       const TOptional<TSharedRef<FJsonObject>>& Second)
{
	if (First.IsSet() && Second.IsSet())
	{
		return FJsonUtil::Equals(First.GetValue(), Second.GetValue());
	}

	return !First.IsSet() && !Second.IsSet();
}

bool FJsonUtil::Equals(const TSharedPtr<FJsonValue>& First, const TSharedPtr<FJsonValue>& Second)
{
	if (First.IsValid() && Second.IsValid())
	{
		return Equals(First.ToSharedRef(), Second.ToSharedRef());
	}

	return !First.IsValid() && !Second.IsValid();
}

bool FJsonUtil::Equals(const TSharedRef<FJsonValue>& First, const TSharedRef<FJsonValue>& Second)
{
	const EJson Type = First->Type;
	if (Type != Second->Type)
	{
		return false;
	}

	switch (Type)
	{
		case EJson::None:
		case EJson::Null:
			return true;

		case EJson::Boolean:
			return First->AsBool() == Second->AsBool();

		case EJson::Number:
			return First->AsNumber() == Second->AsNumber();

		case EJson::String:
			return First->AsString().Equals(Second->AsString());

		case EJson::Array:
			return Equals(First->AsArray(), Second->AsArray());

		case EJson::Object:
			return Equals(First->AsObject(), Second->AsObject());

		default:
			return false;
	}
}

bool FJsonUtil::Equals(const TArray<TSharedPtr<FJsonValue>>& First, const TArray<TSharedPtr<FJsonValue>>& Second)
{
	const int32 Size = First.Num();
	if (Size != Second.Num())
	{
		return false;
	}

	for (int32 i = 0; i < Size; i++)
	{
		if (!Equals(First[i], Second[i]))
		{
			return false;
		}
	}

	return true;
}

void FJsonUtil::JoinObject(const TSharedRef<FJsonObject> JsonObject, const TSharedRef<FJsonObject> Other)
{
	for (const auto& Field : Other->Values)
	{
		JsonObject->SetField(Field.Key, Field.Value);
	}
}

FString FJsonUtil::SerializeJsonObject(const TSharedRef<FJsonObject>& JsonObject)
{
	FString OutString;

	const TSharedRef<FJsonWriter> Writer = FJsonWriterFactory::Create(&OutString);
	FJsonSerializer::Serialize(JsonObject, Writer);

	return OutString;
}

bool FJsonUtil::TryParseJsonObject(const FString& Json, TSharedPtr<FJsonObject>& OutObject)
{
	const TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(Json);
	return FJsonSerializer::Deserialize(JsonReader, OutObject);
}
