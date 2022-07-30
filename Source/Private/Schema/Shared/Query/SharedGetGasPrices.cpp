// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/GetGasPrices.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetGasPrices::FGetGasPrices() : IGraphQlRequest(TEXT("enjin.sdk.shared.GetGasPrices"))
{
}

FString FGetGasPrices::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

TSharedRef<FJsonObject> FGetGasPrices::ToJson() const
{
	return MakeShared<FJsonObject>();
}

bool FGetGasPrices::operator==(const FGetGasPrices& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs;
}

bool FGetGasPrices::operator!=(const FGetGasPrices& Rhs) const
{
	return !(*this == Rhs);
}
