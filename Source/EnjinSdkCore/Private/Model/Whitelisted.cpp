// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Whitelisted.h"

using namespace Enjin::Sdk::Model;

const TCHAR* Enjin::Sdk::Model::ToString(const EWhitelisted Value)
{
	switch (Value)
	{
		case EWhitelisted::Address:
			return TEXT("ADDRESS");

		case EWhitelisted::NoFees:
			return TEXT("NO_FEES");

		case EWhitelisted::None:
			return TEXT("NONE");

		case EWhitelisted::Receive:
			return TEXT("RECEIVE");

		case EWhitelisted::Send:
			return TEXT("SEND");

		case EWhitelisted::SendAndReceive:
			return TEXT("SEND_AND_RECEIVE");

		default:
			return TEXT("");
	}
}
