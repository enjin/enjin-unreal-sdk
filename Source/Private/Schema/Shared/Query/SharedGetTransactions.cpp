// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/GetTransactions.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetTransactions::FGetTransactions() : IGraphQlRequest(TEXT("enjin.sdk.shared.GetTransactions")),
                                       TTransactionFragmentArguments<FGetTransactions>(),
                                       TPaginationArguments<FGetTransactions>()
{
}

FString FGetTransactions::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FGetTransactions& FGetTransactions::SetFilter(FTransactionFilter Filter)
{
	FilterOpt.Emplace(MoveTemp(Filter));
	return *this;
}

FGetTransactions& FGetTransactions::SetSort(FTransactionSortInput Sort)
{
	SortOpt.Emplace(MoveTemp(Sort));
	return *this;
}

TSharedRef<FJsonObject> FGetTransactions::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TPaginationArguments<FGetTransactions>::ToJson());
	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FGetTransactions>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("filter"), FilterOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("sort"), SortOpt);

	return JsonRef;
}

bool FGetTransactions::operator==(const FGetTransactions& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FGetTransactions>&>(*this) == Rhs
		&& FilterOpt == Rhs.FilterOpt
		&& SortOpt == Rhs.SortOpt;
}

bool FGetTransactions::operator!=(const FGetTransactions& Rhs) const
{
	return !(*this == Rhs);
}
