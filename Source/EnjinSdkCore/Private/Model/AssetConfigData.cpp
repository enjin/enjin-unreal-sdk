// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetConfigData.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FAssetConfigData::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			MeltFeeMaxRatio.Reset();
			MeltFeeRatio.Reset();
			MeltValue.Reset();
			MetadataUri.Reset();
			TransferFeeSettings.Reset();
			Transferable.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("meltFeeMaxRatio"), MeltFeeMaxRatio);
		FJsonUtil::TryGetField(JsonRef, TEXT("meltFeeRatio"), MeltFeeRatio);
		FJsonUtil::TryGetField(JsonRef, TEXT("meltValue"), MeltValue);
		FJsonUtil::TryGetField(JsonRef, TEXT("metadataURI"), MetadataUri);
		FJsonUtil::TryGetField(JsonRef, TEXT("transferFeeSettings"), TransferFeeSettings);
		FJsonUtil::TryGetField(JsonRef, TEXT("transferable"), Transferable);
	}

	const TOptional<int32>& GetMeltFeeMaxRatio() const
	{
		return MeltFeeMaxRatio;
	}

	const TOptional<int32>& GetMeltFeeRatio() const
	{
		return MeltFeeRatio;
	}

	const TOptional<FString>& GetMeltValue() const
	{
		return MeltValue;
	}

	const TOptional<FString>& GetMetadataUri() const
	{
		return MetadataUri;
	}

	const TOptional<FAssetTransferFeeSettings>& GetTransferFeeSettings() const
	{
		return TransferFeeSettings;
	}

	const TOptional<EAssetTransferable>& GetTransferable() const
	{
		return Transferable;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return MeltFeeMaxRatio == Rhs.MeltFeeMaxRatio
			&& MeltFeeRatio == Rhs.MeltFeeRatio
			&& MeltValue == Rhs.MeltValue
			&& MetadataUri == Rhs.MetadataUri
			&& TransferFeeSettings == Rhs.TransferFeeSettings
			&& Transferable == Rhs.Transferable;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<int32> MeltFeeMaxRatio;
	TOptional<int32> MeltFeeRatio;
	TOptional<FString> MeltValue;
	TOptional<FString> MetadataUri;
	TOptional<FAssetTransferFeeSettings> TransferFeeSettings;
	TOptional<EAssetTransferable> Transferable;
};

FAssetConfigData::FAssetConfigData() : Pimpl(MakeUnique<FImpl>())
{
}

FAssetConfigData::FAssetConfigData(const FAssetConfigData& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FAssetConfigData::FAssetConfigData(FAssetConfigData&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FAssetConfigData::~FAssetConfigData() = default;

void FAssetConfigData::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<int32>& FAssetConfigData::GetMeltFeeMaxRatio() const
{
	return Pimpl->GetMeltFeeMaxRatio();
}

const TOptional<int32>& FAssetConfigData::GetMeltFeeRatio() const
{
	return Pimpl->GetMeltFeeRatio();
}

const TOptional<FString>& FAssetConfigData::GetMeltValue() const
{
	return Pimpl->GetMeltValue();
}

const TOptional<FString>& FAssetConfigData::GetMetadataUri() const
{
	return Pimpl->GetMetadataUri();
}

const TOptional<FAssetTransferFeeSettings>& FAssetConfigData::GetTransferFeeSettings() const
{
	return Pimpl->GetTransferFeeSettings();
}

const TOptional<EAssetTransferable>& FAssetConfigData::GetTransferable() const
{
	return Pimpl->GetTransferable();
}

bool FAssetConfigData::operator==(const FAssetConfigData& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FAssetConfigData::operator!=(const FAssetConfigData& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FAssetConfigData& FAssetConfigData::operator=(const FAssetConfigData& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
