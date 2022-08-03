// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/GetWallets.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FGetWallets::FGetWallets() : IGraphQlRequest(TEXT("enjin.sdk.project.GetWallets")),
                             TWalletFragmentArguments<FGetWallets>()
{
}

FString FGetWallets::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FGetWallets& FGetWallets::SetEthAddresses(TArray<FString> Addresses)
{
	EthAddressesOpt.Emplace(MoveTemp(Addresses));
	return *this;
}

FGetWallets& FGetWallets::SetUserIds(TArray<FString> Ids)
{
	UserIdsOpt.Emplace(MoveTemp(Ids));
	return *this;
}

TSharedRef<FJsonObject> FGetWallets::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TWalletFragmentArguments<FGetWallets>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("ethAddresses"), EthAddressesOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("userIds"), UserIdsOpt);

	return JsonRef;
}

bool FGetWallets::operator==(const FGetWallets& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TWalletFragmentArguments<FGetWallets>&>(*this) == Rhs
		&& EthAddressesOpt == Rhs.EthAddressesOpt
		&& UserIdsOpt == Rhs.UserIdsOpt;
}

bool FGetWallets::operator!=(const FGetWallets& Rhs) const
{
	return !(*this == Rhs);
}
