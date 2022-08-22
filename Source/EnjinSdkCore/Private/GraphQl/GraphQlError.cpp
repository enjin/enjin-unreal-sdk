// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "GraphQlError.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Util;

void FGraphQlError::Deserialize(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject;
	if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
	{
		Code.Reset();
		Details.Reset();
		Locations.Reset();
		Message.Reset();

		return;
	}

	const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

	FJsonUtil::TryGetField(JsonRef, TEXT("code"), Code);
	FJsonUtil::TryGetField(JsonRef, TEXT("details"), Details);
	FJsonUtil::TryGetField(JsonRef, TEXT("message"), Message);

	const TArray<TSharedPtr<FJsonValue>>* LocationsValue;
	if (!JsonObject->TryGetArrayField(TEXT("locations"), LocationsValue))
	{
		Locations.Reset();
		return;
	}

	TArray<TMap<FString, int32>> LocationsArray;

	for (const TSharedPtr<FJsonValue> LocationValue : *LocationsValue)
	{
		const TSharedPtr<FJsonObject>& LocationObject = LocationValue->AsObject();
		if (!LocationObject.IsValid())
		{
			continue;
		}

		TMap<FString, int32> Location;

		for (const TTuple<FString, TSharedPtr<FJsonValue>> KeyValuePair : LocationObject->Values)
		{
			int32 Value;
			if (KeyValuePair.Value->TryGetNumber(Value))
			{
				Location.Add(KeyValuePair.Key, Value);
			}
		}

		LocationsArray.Add(MoveTemp(Location));
	}

	Locations.Emplace(MoveTemp(LocationsArray));
}

const TOptional<int32>& FGraphQlError::GetCode() const
{
	return Code;
}

const TOptional<FString>& FGraphQlError::GetDetails() const
{
	return Details;
}

const TOptional<TArray<TMap<FString, int32>>>& FGraphQlError::GetLocations() const
{
	return Locations;
}

const TOptional<FString>& FGraphQlError::GetMessage() const
{
	return Message;
}

bool FGraphQlError::operator==(const FGraphQlError& Rhs) const
{
	return Code == Rhs.Code
		&& Details == Rhs.Details
		&& Message == Rhs.Message;
}

bool FGraphQlError::operator!=(const FGraphQlError& Rhs) const
{
	return !(*this == Rhs);
}
