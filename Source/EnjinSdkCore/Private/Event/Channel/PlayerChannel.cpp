// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PlayerChannel.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

FPlayerChannel::FPlayerChannel(const FPlatform& Platform, const FString& Project, const FString& Player)
	: Channel(FString::Printf(TEXT("enjincloud.%s.project.%s.player.%s"),
	                          *Platform.GetNetwork()->ToLower(),
	                          *Project,
	                          *Player))
{
}

const FString& FPlayerChannel::GetChannel() const
{
	return Channel;
}
