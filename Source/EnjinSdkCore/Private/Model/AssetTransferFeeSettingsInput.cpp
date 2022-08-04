// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetTransferFeeSettingsInput.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FAssetTransferFeeSettingsInput::FImpl final : public ISerializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual FString Serialize() const override
	{
		return FJsonUtil::SerializeJsonObject(ToJson());
	}

	void SetAssetId(FString AssetId)
	{
		AssetIdOpt.Emplace(MoveTemp(AssetId));
	}

	void SetType(const EAssetTransferFeeType Type)
	{
		TypeOpt.Emplace(Type);
	}

	void SetValue(FString Value)
	{
		ValueOpt.Emplace(MoveTemp(Value));
	}

	virtual TSharedRef<FJsonObject> ToJson() const override
	{
		TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

		FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("type"), TypeOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

		return JsonRef;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return AssetIdOpt == Rhs.AssetIdOpt
			&& TypeOpt == Rhs.TypeOpt
			&& ValueOpt == Rhs.ValueOpt;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> AssetIdOpt;
	TOptional<EAssetTransferFeeType> TypeOpt;
	TOptional<FString> ValueOpt;
};

FAssetTransferFeeSettingsInput::FAssetTransferFeeSettingsInput() : Pimpl(MakeUnique<FImpl>())
{
}

FAssetTransferFeeSettingsInput::FAssetTransferFeeSettingsInput(const FAssetTransferFeeSettingsInput& Other)
	: Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FAssetTransferFeeSettingsInput::FAssetTransferFeeSettingsInput(FAssetTransferFeeSettingsInput&& Other) noexcept
	: Pimpl(MoveTemp(Other.Pimpl))
{
}

FAssetTransferFeeSettingsInput::~FAssetTransferFeeSettingsInput() = default;

FString FAssetTransferFeeSettingsInput::Serialize() const
{
	return Pimpl->Serialize();
}

FAssetTransferFeeSettingsInput& FAssetTransferFeeSettingsInput::SetAssetId(FString AssetId)
{
	Pimpl->SetAssetId(MoveTemp(AssetId));
	return *this;
}

FAssetTransferFeeSettingsInput& FAssetTransferFeeSettingsInput::SetType(const EAssetTransferFeeType Type)
{
	Pimpl->SetType(Type);
	return *this;
}

FAssetTransferFeeSettingsInput& FAssetTransferFeeSettingsInput::SetValue(FString Value)
{
	Pimpl->SetValue(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> FAssetTransferFeeSettingsInput::ToJson() const
{
	return Pimpl->ToJson();
}

bool FAssetTransferFeeSettingsInput::operator==(const FAssetTransferFeeSettingsInput& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FAssetTransferFeeSettingsInput::operator!=(const FAssetTransferFeeSettingsInput& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FAssetTransferFeeSettingsInput& FAssetTransferFeeSettingsInput::operator=(const FAssetTransferFeeSettingsInput& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
