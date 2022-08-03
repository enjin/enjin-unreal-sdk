// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "AssetChannel.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

FAssetChannel::FAssetChannel(const FPlatform& Platform, const FString& Asset)
	: Channel(FString::Printf(TEXT("enjincloud.%s.asset.%s"),
	                          *Platform.GetNetwork()->ToLower(),
	                          *Asset))
{
}

const FString& FAssetChannel::GetChannel() const
{
	return Channel;
}
