// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetTransferFeeType.h"

using namespace Enjin::Sdk::Model;

EAssetTransferFeeType Enjin::Sdk::Model::ToAssetTransferFeeType(const FString& String)
{
	const FString S = String.ToUpper();

	if (S.Equals(TEXT("NONE")))
	{
		return EAssetTransferFeeType::None;
	}

	if (S.Equals(TEXT("PER_TRANSFER")))
	{
		return EAssetTransferFeeType::PerTransfer;
	}

	if (S.Equals(TEXT("PER_CRYPTO_ITEM")))
	{
		return EAssetTransferFeeType::PerCryptoItem;
	}

	if (S.Equals(TEXT("RATIO_CUT")))
	{
		return EAssetTransferFeeType::RatioCut;
	}

	if (S.Equals(TEXT("RATIO_EXTRA")))
	{
		return EAssetTransferFeeType::RatioExtra;
	}

	return EAssetTransferFeeType::Unknown;
}

const TCHAR* Enjin::Sdk::Model::ToString(const EAssetTransferFeeType Value)
{
	switch (Value)
	{
		case EAssetTransferFeeType::None:
			return TEXT("NONE");

		case EAssetTransferFeeType::PerTransfer:
			return TEXT("PER_TRANSFER");

		case EAssetTransferFeeType::PerCryptoItem:
			return TEXT("PER_CRYPTO_ITEM");

		case EAssetTransferFeeType::RatioCut:
			return TEXT("RATIO_CUT");

		case EAssetTransferFeeType::RatioExtra:
			return TEXT("RATIO_EXTRA");

		default:
			return TEXT("");
	}
}
