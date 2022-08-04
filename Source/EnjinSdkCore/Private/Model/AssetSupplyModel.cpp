// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetSupplyModel.h"

using namespace Enjin::Sdk::Model;

EAssetSupplyModel Enjin::Sdk::Model::ToAssetSupplyModel(const FString& String)
{
	const FString S = String.ToUpper();

	if (S.Equals(TEXT("FIXED")))
	{
		return EAssetSupplyModel::Fixed;
	}

	if (S.Equals(TEXT("SETTABLE")))
	{
		return EAssetSupplyModel::Settable;
	}

	if (S.Equals(TEXT("INFINITE")))
	{
		return EAssetSupplyModel::Infinite;
	}

	if (S.Equals(TEXT("COLLAPSING")))
	{
		return EAssetSupplyModel::Collapsing;
	}

	if (S.Equals(TEXT("ANNUAL_VALUE")))
	{
		return EAssetSupplyModel::AnnualValue;
	}

	if (S.Equals(TEXT("ANNUAL_PERCENTAGE")))
	{
		return EAssetSupplyModel::AnnualPercentage;
	}

	return EAssetSupplyModel::Unknown;
}

const TCHAR* Enjin::Sdk::Model::ToString(const EAssetSupplyModel Value)
{
	switch (Value)
	{
		case EAssetSupplyModel::AnnualPercentage:
			return TEXT("ANNUAL_PERCENTAGE");

		case EAssetSupplyModel::AnnualValue:
			return TEXT("ANNUAL_VALUE");

		case EAssetSupplyModel::Collapsing:
			return TEXT("COLLAPSING");

		case EAssetSupplyModel::Fixed:
			return TEXT("FIXED");

		case EAssetSupplyModel::Infinite:
			return TEXT("INFINITE");

		case EAssetSupplyModel::Settable:
			return TEXT("SETTABLE");

		default:
			return TEXT("");
	}
}
