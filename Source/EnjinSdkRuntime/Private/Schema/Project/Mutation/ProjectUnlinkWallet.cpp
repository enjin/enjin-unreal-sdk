// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/UnlinkWallet.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Project explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Project::FUnlinkWallet::FUnlinkWallet() : IGraphQlRequest(TEXT("enjin.sdk.project.UnlinkWallet"))
{
}

FString Enjin::Sdk::Project::FUnlinkWallet::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Project::FUnlinkWallet& Enjin::Sdk::Project::FUnlinkWallet::SetEthAddress(FString Address)
{
	EthAddressOpt.Emplace(MoveTemp(Address));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Project::FUnlinkWallet::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::TrySetField(JsonRef, TEXT("ethAddress"), EthAddressOpt);

	return JsonRef;
}

bool Enjin::Sdk::Project::FUnlinkWallet::operator==(const FUnlinkWallet& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& EthAddressOpt == Rhs.EthAddressOpt;
}

bool Enjin::Sdk::Project::FUnlinkWallet::operator!=(const FUnlinkWallet& Rhs) const
{
	return !(*this == Rhs);
}
