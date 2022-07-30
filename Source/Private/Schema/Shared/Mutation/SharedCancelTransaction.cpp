// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/CancelTransaction.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FCancelTransaction::FCancelTransaction() : IGraphQlRequest(TEXT("enjin.sdk.shared.CancelTransaction"))
{
}

FString FCancelTransaction::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FCancelTransaction& FCancelTransaction::SetId(const int32 Id)
{
	IdOpt.Emplace(Id);
	return *this;
}

TSharedRef<FJsonObject> FCancelTransaction::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);

	return JsonRef;
}

bool FCancelTransaction::operator==(const FCancelTransaction& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& IdOpt == Rhs.IdOpt;
}

bool FCancelTransaction::operator!=(const FCancelTransaction& Rhs) const
{
	return !(*this == Rhs);
}
