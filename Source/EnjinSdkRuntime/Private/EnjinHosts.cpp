// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "EnjinHosts.h"

using namespace Enjin::Sdk;

const TCHAR* FEnjinHosts::Goerli()
{
	return TEXT("https://goerli.cloud.enjin.io");
}

const TCHAR* FEnjinHosts::MainNet()
{
	return TEXT("https://cloud.enjin.io");
}

const TCHAR* FEnjinHosts::JumpNet()
{
	return TEXT("https://jumpnet.cloud.enjin.io");
}
