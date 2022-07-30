// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "PusherConnectionState.h"

using namespace Enjin::Sdk::Pusher;

const TCHAR* Enjin::Sdk::Pusher::ToString(const EPusherConnectionState Value)
{
	switch (Value)
	{
		case EPusherConnectionState::All:
			return TEXT("all");

		case EPusherConnectionState::Connected:
			return TEXT("connected");

		case EPusherConnectionState::Connecting:
			return TEXT("connecting");

		case EPusherConnectionState::Disconnected:
			return TEXT("disconnected");

		case EPusherConnectionState::Disconnecting:
			return TEXT("disconnecting");

		case EPusherConnectionState::Reconnecting:
			return TEXT("reconnecting");

		default:
			return TEXT("unknown connection state");
	}
}
