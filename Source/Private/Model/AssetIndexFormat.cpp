// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetIndexFormat.h"

using namespace Enjin::Sdk::Model;

const TCHAR* Enjin::Sdk::Model::ToString(const EAssetIndexFormat Value)
{
	switch (Value)
	{
		case EAssetIndexFormat::Hex64:
			return TEXT("hex64");

		case EAssetIndexFormat::UInt64:
			return TEXT("uint64");

		default:
			return TEXT("");
	}
}
