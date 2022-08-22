// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetTransferable.h"

using namespace Enjin::Sdk::Model;

EAssetTransferable Enjin::Sdk::Model::ToAssetTransferable(const FString& String)
{
	const FString S = String.ToUpper();

	if (S.Equals(TEXT("PERMANENT")))
	{
		return EAssetTransferable::Permanent;
	}

	if (S.Equals(TEXT("TEMPORARY")))
	{
		return EAssetTransferable::Temporary;
	}

	if (S.Equals(TEXT("BOUND")))
	{
		return EAssetTransferable::Bound;
	}

	return EAssetTransferable::Unknown;
}

const TCHAR* Enjin::Sdk::Model::ToString(const EAssetTransferable Value)
{
	switch (Value)
	{
		case EAssetTransferable::Permanent:
			return TEXT("PERMANENT");

		case EAssetTransferable::Temporary:
			return TEXT("TEMPORARY");

		case EAssetTransferable::Bound:
			return TEXT("BOUND");

		default:
			return TEXT("");
	}
}
