// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetField.h"

using namespace Enjin::Sdk::Model;

const TCHAR* Enjin::Sdk::Model::ToString(const EAssetField Value)
{
	switch (Value)
	{
		case EAssetField::Id:
			return TEXT("id");

		case EAssetField::Name:
			return TEXT("name");

		case EAssetField::CirculatingSupply:
			return TEXT("circulatingSupply");

		case EAssetField::NonFungible:
			return TEXT("nonFungible");

		case EAssetField::Reserve:
			return TEXT("reserve");

		case EAssetField::TotalSupply:
			return TEXT("totalSupply");

		case EAssetField::CreatedAt:
			return TEXT("createdAt");

		default:
			return TEXT("");
	}
}
