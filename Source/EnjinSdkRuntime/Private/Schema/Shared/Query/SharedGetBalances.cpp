// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/GetBalances.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetBalances::FGetBalances() : IGraphQlRequest(TEXT("enjin.sdk.shared.GetBalances")),
                               TBalanceFragmentArguments<FGetBalances>(),
                               TPaginationArguments<FGetBalances>()
{
}

FString FGetBalances::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FGetBalances& FGetBalances::SetFilter(FBalanceFilter Filter)
{
	FilterOpt.Emplace(MoveTemp(Filter));
	return *this;
}

TSharedRef<FJsonObject> FGetBalances::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TBalanceFragmentArguments<FGetBalances>::ToJson());
	FJsonUtil::JoinObject(JsonRef, TPaginationArguments<FGetBalances>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("filter"), FilterOpt);

	return JsonRef;
}

bool FGetBalances::operator==(const FGetBalances& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TBalanceFragmentArguments<FGetBalances>&>(*this) == Rhs
		&& static_cast<const TPaginationArguments<FGetBalances>&>(*this) == Rhs
		&& FilterOpt == Rhs.FilterOpt;
}

bool FGetBalances::operator!=(const FGetBalances& Rhs) const
{
	return !(*this == Rhs);
}
