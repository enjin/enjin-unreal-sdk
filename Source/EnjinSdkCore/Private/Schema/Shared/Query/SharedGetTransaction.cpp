// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/GetTransaction.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetTransaction::FGetTransaction() : IGraphQlRequest(TEXT("enjin.sdk.shared.GetTransaction")),
                                     TTransactionFragmentArguments<FGetTransaction>()
{
}

FString FGetTransaction::Serialize() const
{
	return TTransactionFragmentArguments<FGetTransaction>::Serialize();
}

FGetTransaction& FGetTransaction::SetId(const int32 Id)
{
	IdOpt.Emplace(Id);
	return *this;
}

FGetTransaction& FGetTransaction::SetTransactionId(FString Id)
{
	TransactionIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

TSharedRef<FJsonObject> FGetTransaction::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FGetTransaction>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("transactionId"), TransactionIdOpt);

	return JsonRef;
}

bool FGetTransaction::operator==(const FGetTransaction& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FGetTransaction>&>(*this) == Rhs
		&& IdOpt == Rhs.IdOpt
		&& TransactionIdOpt == Rhs.TransactionIdOpt;
}

bool FGetTransaction::operator!=(const FGetTransaction& Rhs) const
{
	return !(*this == Rhs);
}
