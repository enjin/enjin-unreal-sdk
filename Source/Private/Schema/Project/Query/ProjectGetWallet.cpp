// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/GetWallet.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FGetWallet::FGetWallet() : IGraphQlRequest(TEXT("enjin.sdk.project.GetWallet")),
                                                TWalletFragmentArguments<FGetWallet>()
{
}

FString Enjin::Sdk::Project::FGetWallet::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FGetWallet& Enjin::Sdk::Project::FGetWallet::SetEthAddress(FString EthAddress)
{
	EthAddressOpt.Emplace(MoveTemp(EthAddress));
	return *this;
}

Enjin::Sdk::Project::FGetWallet& Enjin::Sdk::Project::FGetWallet::SetUserId(FString UserId)
{
	UserIdOpt.Emplace(MoveTemp(UserId));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FGetWallet::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TWalletFragmentArguments<FGetWallet>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("ethAddress"), EthAddressOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("userId"), UserIdOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FGetWallet::operator==(const FGetWallet& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TWalletFragmentArguments<FGetWallet>&>(*this) == Rhs
		&& EthAddressOpt == Rhs.EthAddressOpt
		&& UserIdOpt == Rhs.UserIdOpt;
}

bool Enjin::Sdk::Project::FGetWallet::operator!=(const FGetWallet& Rhs) const
{
	return !(*this == Rhs);
}
