// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/GetPlatform.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetPlatform::FGetPlatform() : IGraphQlRequest(TEXT("enjin.sdk.shared.GetPlatform"))
{
}

FString FGetPlatform::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FGetPlatform& FGetPlatform::SetWithContracts()
{
	WithContractsOpt.Emplace(true);
	return *this;
}

FGetPlatform& FGetPlatform::SetWithNotifications()
{
	WithNotificationsOpt.Emplace(true);
	return *this;
}

TSharedRef<FJsonObject> FGetPlatform::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::TrySetField(JsonRef, TEXT("withContracts"), WithContractsOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("withNotificationDrivers"), WithNotificationsOpt);

	return JsonRef;
}

bool FGetPlatform::operator==(const FGetPlatform& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& WithContractsOpt == Rhs.WithContractsOpt
		&& WithNotificationsOpt == Rhs.WithNotificationsOpt;
}

bool FGetPlatform::operator!=(const FGetPlatform& Rhs) const
{
	return !(*this == Rhs);
}
