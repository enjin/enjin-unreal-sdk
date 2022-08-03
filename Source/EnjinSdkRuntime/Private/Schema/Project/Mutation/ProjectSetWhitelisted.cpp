// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/SetWhitelisted.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FSetWhitelisted::FSetWhitelisted() : IGraphQlRequest(TEXT("enjin.sdk.project.SetWhitelisted")),
                                     TTransactionRequestArguments<FSetWhitelisted>()
{
}

FString FSetWhitelisted::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FSetWhitelisted& FSetWhitelisted::SetAccountAddress(FString Address)
{
	AccountAddressOpt.Emplace(MoveTemp(Address));
	return *this;
}

FSetWhitelisted& FSetWhitelisted::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

FSetWhitelisted& FSetWhitelisted::SetOn(const bool bIsOn)
{
	OnOpt.Emplace(bIsOn);
	return *this;
}

FSetWhitelisted& FSetWhitelisted::SetWhitelisted(const EWhitelisted Setting)
{
	WhitelistedOpt.Emplace(Setting);
	return *this;
}

FSetWhitelisted& FSetWhitelisted::SetWhitelistedAddress(FString Address)
{
	WhitelistedAddressOpt.Emplace(MoveTemp(Address));
	return *this;
}

TSharedRef<FJsonObject> FSetWhitelisted::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FSetWhitelisted>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("accountAddress"), AccountAddressOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("on"), OnOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("whitelistedAddress"), WhitelistedAddressOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("whitelisted"), WhitelistedOpt);

	return JsonRef;
}

bool FSetWhitelisted::operator==(const FSetWhitelisted& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FSetWhitelisted>&>(*this) == Rhs
		&& AccountAddressOpt == Rhs.AccountAddressOpt
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& OnOpt == Rhs.OnOpt
		&& WhitelistedAddressOpt == Rhs.WhitelistedAddressOpt
		&& WhitelistedOpt == Rhs.WhitelistedOpt;
}

bool FSetWhitelisted::operator!=(const FSetWhitelisted& Rhs) const
{
	return !(*this == Rhs);
}
