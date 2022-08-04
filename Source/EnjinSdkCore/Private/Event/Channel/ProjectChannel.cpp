// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "ProjectChannel.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

FProjectChannel::FProjectChannel(const FPlatform& Platform, const FString& Project)
	: Channel(FString::Printf(TEXT("enjincloud.%s.project.%s"),
	                          *Platform.GetNetwork()->ToLower(),
	                          *Project))
{
}

const FString& FProjectChannel::GetChannel() const
{
	return Channel;
}
