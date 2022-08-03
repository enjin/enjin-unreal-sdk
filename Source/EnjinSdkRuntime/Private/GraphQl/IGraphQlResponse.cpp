// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "IGraphQlResponse.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Util;

const TOptional<TArray<FGraphQlError>>& IGraphQlResponse::GetErrors() const
{
	return Errors;
}

bool IGraphQlResponse::HasErrors() const
{
	return Errors.IsSet() && Errors.GetValue().Num() > 0;
}

bool IGraphQlResponse::IsSuccessful() const
{
	return !(IsEmpty() || HasErrors());
}

void IGraphQlResponse::Process(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject;
	if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
	{
		return;
	}

	const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

	FJsonUtil::TryGetField(JsonRef, TEXT("errors"), Errors);

	const TSharedPtr<FJsonObject>* DataObject;
	if (JsonRef->TryGetObjectField(TEXT("data"), DataObject))
	{
		ProcessData(DataObject->ToSharedRef());
	}
}
