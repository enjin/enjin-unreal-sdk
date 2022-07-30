// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "WalletChannel.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

FWalletChannel::FWalletChannel(const FPlatform& Platform, const FString& Wallet)
	: Channel(FString::Printf(TEXT("enjincloud.%s.wallet.%s"),
	                          *Platform.GetNetwork()->ToLower(),
	                          *Wallet))
{
}

const FString& FWalletChannel::GetChannel() const
{
	return Channel;
}
