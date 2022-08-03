// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetIdFormat.h"

using namespace Enjin::Sdk::Model;

const TCHAR* Enjin::Sdk::Model::ToString(const EAssetIdFormat Value)
{
	switch (Value)
	{
		case EAssetIdFormat::Hex64:
			return TEXT("hex64");

		case EAssetIdFormat::Hex256:
			return TEXT("hex256");

		case EAssetIdFormat::UInt256:
			return TEXT("uint256");

		default:
			return TEXT("");
	}
}
