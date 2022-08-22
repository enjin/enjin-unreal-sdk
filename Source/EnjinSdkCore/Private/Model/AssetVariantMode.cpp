// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetVariantMode.h"

using namespace Enjin::Sdk::Model;

EAssetVariantMode Enjin::Sdk::Model::ToAssetVariantMode(const FString& String)
{
	const FString S = String.ToUpper();

	if (S.Equals(TEXT("NONE")))
	{
		return EAssetVariantMode::None;
	}

	if (S.Equals(TEXT("BEAM")))
	{
		return EAssetVariantMode::Beam;
	}

	if (S.Equals(TEXT("ONCE")))
	{
		return EAssetVariantMode::Once;
	}

	if (S.Equals(TEXT("ALWAYS")))
	{
		return EAssetVariantMode::Always;
	}

	return EAssetVariantMode::Unknown;
}
