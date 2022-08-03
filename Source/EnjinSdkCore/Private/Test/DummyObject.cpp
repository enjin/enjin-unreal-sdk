// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "DummyObject.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Util;
using namespace Enjin::Test::Util;

FDummyObject::FDummyObject(const int32 Int) : IntOpt(Int)
{
}

void FDummyObject::Deserialize(const FString& Json)
{
	TSharedPtr<FJsonObject> JsonObject;
	if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
	{
		return;
	}

	const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

	FJsonUtil::TryGetField(JsonRef, TEXT("int"), IntOpt);
}

const TOptional<int32>& FDummyObject::GetInt() const
{
	return IntOpt;
}

FString FDummyObject::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

TSharedRef<FJsonObject> FDummyObject::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::TrySetField(JsonRef, TEXT("int"), IntOpt);

	return JsonRef;
}

bool FDummyObject::operator==(const FDummyObject& Rhs) const
{
	return IntOpt == Rhs.IntOpt;
}

bool FDummyObject::operator!=(const FDummyObject& Rhs) const
{
	return !(*this == Rhs);
}

FDummyObject FDummyObject::CreateDefault()
{
	return FDummyObject(1);
}
