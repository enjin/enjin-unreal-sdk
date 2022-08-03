// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/CompleteTrade.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FCompleteTrade::FCompleteTrade() : IGraphQlRequest(TEXT("enjin.sdk.project.CompleteTrade")),
                                   TTransactionRequestArguments<FCompleteTrade>()
{
}

FString FCompleteTrade::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FCompleteTrade& FCompleteTrade::SetTradeId(FString Id)
{
	TradeIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

TSharedRef<FJsonObject> FCompleteTrade::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FCompleteTrade>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("tradeId"), TradeIdOpt);

	return JsonRef;
}

bool FCompleteTrade::operator==(const FCompleteTrade& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FCompleteTrade>&>(*this) == Rhs
		&& TradeIdOpt == Rhs.TradeIdOpt;
}

bool FCompleteTrade::operator!=(const FCompleteTrade& Rhs) const
{
	return !(*this == Rhs);
}
