// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PusherOptionsInput.h"

using namespace Enjin::Sdk::Pusher;

FString FPusherOptionsInput::GetCluster() const
{
	return ClusterOpt.Get(TEXT("mt1"));
}

FString FPusherOptionsInput::Host() const
{
	return FString::Printf(TEXT("ws-%s.pusher.com"), *GetCluster());
}

bool FPusherOptionsInput::IsEncrypted() const
{
	return EncryptedOpt.Get(true);
}

FPusherOptionsInput& FPusherOptionsInput::SetCluster(FString Cluster)
{
	ClusterOpt.Emplace(MoveTemp(Cluster));
	return *this;
}

FPusherOptionsInput& FPusherOptionsInput::SetEncrypted(const bool bIsEncrypted)
{
	EncryptedOpt.Emplace(bIsEncrypted);
	return *this;
}
