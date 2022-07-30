// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Project/CreateAsset.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Project;
using namespace Enjin::Sdk::Util;

FCreateAsset::FCreateAsset() : IGraphQlRequest(TEXT("enjin.sdk.project.CreateAsset")),
                               TTransactionRequestArguments<FCreateAsset>()
{
}

FString FCreateAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

FCreateAsset& FCreateAsset::SetInitialReserve(FString InitialReserve)
{
	InitialReserveOpt.Emplace(MoveTemp(InitialReserve));
	return *this;
}

FCreateAsset& FCreateAsset::SetMeltFeeRatio(const int32 MeltFeeRatio)
{
	MeltFeeRatioOpt.Emplace(MeltFeeRatio);
	return *this;
}

FCreateAsset& FCreateAsset::SetMeltValue(FString MeltValue)
{
	MeltValueOpt.Emplace(MoveTemp(MeltValue));
	return *this;
}

FCreateAsset& FCreateAsset::SetName(FString Name)
{
	NameOpt.Emplace(MoveTemp(Name));
	return *this;
}

FCreateAsset& FCreateAsset::SetNonFungible(const bool bIsNonFungible)
{
	NonFungibleOpt.Emplace(bIsNonFungible);
	return *this;
}

FCreateAsset& FCreateAsset::SetSupplyModel(const EAssetSupplyModel SupplyModel)
{
	SupplyModelOpt.Emplace(SupplyModel);
	return *this;
}

FCreateAsset& FCreateAsset::SetTotalSupply(FString TotalSupply)
{
	TotalSupplyOpt.Emplace(MoveTemp(TotalSupply));
	return *this;
}

FCreateAsset& FCreateAsset::SetTransferFeeSettings(FAssetTransferFeeSettingsInput Settings)
{
	TransferFeeSettingsOpt.Emplace(MoveTemp(Settings));
	return *this;
}

FCreateAsset& FCreateAsset::SetTransferable(const EAssetTransferable Transferable)
{
	TransferableOpt.Emplace(Transferable);
	return *this;
}

TSharedRef<FJsonObject> FCreateAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionRequestArguments<FCreateAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("initialReserve"), InitialReserveOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("meltFeeRatio"), MeltFeeRatioOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("meltValue"), MeltValueOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("name"), NameOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("nonFungible"), NonFungibleOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("supplyModel"), SupplyModelOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("totalSupply"), TotalSupplyOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("transferFeeSettings"), TransferFeeSettingsOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("transferable"), TransferableOpt);

	return JsonRef;
}

bool FCreateAsset::operator==(const FCreateAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionRequestArguments<FCreateAsset>&>(*this) == Rhs
		&& InitialReserveOpt == Rhs.InitialReserveOpt
		&& MeltFeeRatioOpt == Rhs.MeltFeeRatioOpt
		&& MeltValueOpt == Rhs.MeltValueOpt
		&& NameOpt == Rhs.NameOpt
		&& NonFungibleOpt == Rhs.NonFungibleOpt
		&& SupplyModelOpt == Rhs.SupplyModelOpt
		&& TotalSupplyOpt == Rhs.TotalSupplyOpt
		&& TransferFeeSettingsOpt == Rhs.TransferFeeSettingsOpt
		&& TransferableOpt == Rhs.TransferableOpt;
}

bool FCreateAsset::operator!=(const FCreateAsset& Rhs) const
{
	return !(*this == Rhs);
}
