// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Player/SendAsset.h"

#include "JsonUtil.h"

// Namespace for Enjin::Sdk::Player explicitly stated on types to avoid ambiguous symbol error with UE compiler
using namespace Enjin::Sdk::Util;

Enjin::Sdk::Player::FSendAsset::FSendAsset() : IGraphQlRequest(TEXT("enjin.sdk.player.SendAsset")),
                                               TTransactionFragmentArguments<FSendAsset>()
{
}

FString Enjin::Sdk::Player::FSendAsset::Serialize() const
{
	return FJsonUtil::SerializeJsonObject(ToJson());
}

Enjin::Sdk::Player::FSendAsset& Enjin::Sdk::Player::FSendAsset::SetAssetId(FString Id)
{
	AssetIdOpt.Emplace(MoveTemp(Id));
	return *this;
}

Enjin::Sdk::Player::FSendAsset& Enjin::Sdk::Player::FSendAsset::SetAssetIndex(FString Index)
{
	AssetIndexOpt.Emplace(MoveTemp(Index));
	return *this;
}

Enjin::Sdk::Player::FSendAsset& Enjin::Sdk::Player::FSendAsset::SetData(FString Data)
{
	DataOpt.Emplace(MoveTemp(Data));
	return *this;
}

Enjin::Sdk::Player::FSendAsset& Enjin::Sdk::Player::FSendAsset::SetRecipientAddress(FString Address)
{
	RecipientAddressOpt.Emplace(MoveTemp(Address));
	return *this;
}

Enjin::Sdk::Player::FSendAsset& Enjin::Sdk::Player::FSendAsset::SetValue(FString Value)
{
	ValueOpt.Emplace(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> Enjin::Sdk::Player::FSendAsset::ToJson() const
{
	TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

	FJsonUtil::JoinObject(JsonRef, TTransactionFragmentArguments<FSendAsset>::ToJson());
	FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("assetIndex"), AssetIndexOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("data"), DataOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("recipientAddress"), RecipientAddressOpt);
	FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

	return JsonRef;
}

bool Enjin::Sdk::Player::FSendAsset::operator==(const FSendAsset& Rhs) const
{
	return static_cast<const IGraphQlRequest&>(*this) == Rhs
		&& static_cast<const TTransactionFragmentArguments<FSendAsset>&>(*this) == Rhs
		&& AssetIdOpt == Rhs.AssetIdOpt
		&& AssetIndexOpt == Rhs.AssetIndexOpt
		&& DataOpt == Rhs.DataOpt
		&& RecipientAddressOpt == Rhs.RecipientAddressOpt
		&& ValueOpt == Rhs.ValueOpt;
}

bool Enjin::Sdk::Player::FSendAsset::operator!=(const FSendAsset& Rhs) const
{
	return !(*this == Rhs);
}
