// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/CreateTrade.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FCreateTrade::FCreateTrade() : IGraphQlRequest(TEXT("enjin.sdk.project.CreateTrade")),
                               TTransactionRequestArguments<FCreateTrade>()
{
}

FString FCreateTrade::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FCreateTrade& FCreateTrade::SetAskingAssets(TArray<FTradeInput> Assets)
{
	AskingAssetsOpt.Emplace(MoveTemp(Assets));
	return *this;
}

FCreateTrade& FCreateTrade::SetOfferingAssets(TArray<FTradeInput> Assets)
{
	OfferingAssetsOpt.Emplace(MoveTemp(Assets));
	return *this;
}

FCreateTrade& FCreateTrade::SetRecipientAddress(FString Address)
{
	RecipientAddressOpt.Emplace(MoveTemp(Address));
	return *this;
}

TSharedRef<FJsonObject> FCreateTrade::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FCreateTrade>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("askingAssets"), AskingAssetsOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("offeringAssets"), OfferingAssetsOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("recipientAddress"), RecipientAddressOpt);

	return JsonRef;
}

bool FCreateTrade::operator==(const FCreateTrade& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FCreateTrade>&>(*this) == Rhs
		&& AskingAssetsOpt == Rhs.AskingAssetsOpt
		&& OfferingAssetsOpt == Rhs.OfferingAssetsOpt
		&& RecipientAddressOpt == Rhs.RecipientAddressOpt;
}

bool FCreateTrade::operator!=(const FCreateTrade& Rhs) const
{
	return !(*this == Rhs);
}
