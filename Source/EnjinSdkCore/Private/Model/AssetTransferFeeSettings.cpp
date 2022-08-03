// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetTransferFeeSettings.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FAssetTransferFeeSettings::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			AssetId.Reset();
			Type.Reset();
			Value.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("assetId"), AssetId);
		FJsonUtil::TryGetField(JsonRef, TEXT("type"), Type);
		FJsonUtil::TryGetField(JsonRef, TEXT("value"), Value);
	}

	const TOptional<FString>& GetAssetId() const
	{
		return AssetId;
	}

	const TOptional<EAssetTransferFeeType>& GetType() const
	{
		return Type;
	}

	const TOptional<FString>& GetValue() const
	{
		return Value;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return AssetId == Rhs.AssetId
			&& Type == Rhs.Type
			&& Value == Rhs.Value;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> AssetId;
	TOptional<EAssetTransferFeeType> Type;
	TOptional<FString> Value;
};

FAssetTransferFeeSettings::FAssetTransferFeeSettings() : Pimpl(MakeUnique<FImpl>())
{
}

FAssetTransferFeeSettings::FAssetTransferFeeSettings(const FAssetTransferFeeSettings& Other)
	: Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FAssetTransferFeeSettings::FAssetTransferFeeSettings(FAssetTransferFeeSettings&& Other) noexcept
	: Pimpl(MoveTemp(Other.Pimpl))
{
}

FAssetTransferFeeSettings::~FAssetTransferFeeSettings() = default;

void FAssetTransferFeeSettings::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FAssetTransferFeeSettings::GetAssetId() const
{
	return Pimpl->GetAssetId();
}

const TOptional<EAssetTransferFeeType>& FAssetTransferFeeSettings::GetType() const
{
	return Pimpl->GetType();
}

const TOptional<FString>& FAssetTransferFeeSettings::GetValue() const
{
	return Pimpl->GetValue();
}

bool FAssetTransferFeeSettings::operator==(const FAssetTransferFeeSettings& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FAssetTransferFeeSettings::operator!=(const FAssetTransferFeeSettings& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FAssetTransferFeeSettings& FAssetTransferFeeSettings::operator=(const FAssetTransferFeeSettings& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
