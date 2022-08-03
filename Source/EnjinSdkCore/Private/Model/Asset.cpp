// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Asset.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FAsset::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			ConfigData.Reset();
			CreatedAt.Reset();
			Id.Reset();
			Name.Reset();
			StateData.Reset();
			UpdatedAt.Reset();
			VariantMode.Reset();
			Variants.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("configData"), ConfigData);
		FJsonUtil::TryGetField(JsonRef, TEXT("createdAt"), CreatedAt);
		FJsonUtil::TryGetField(JsonRef, TEXT("id"), Id);
		FJsonUtil::TryGetField(JsonRef, TEXT("name"), Name);
		FJsonUtil::TryGetField(JsonRef, TEXT("stateData"), StateData);
		FJsonUtil::TryGetField(JsonRef, TEXT("updatedAt"), UpdatedAt);
		FJsonUtil::TryGetField(JsonRef, TEXT("variantMode"), VariantMode);
		FJsonUtil::TryGetField(JsonRef, TEXT("variants"), Variants);
	}

	const TOptional<FAssetConfigData>& GetConfigData() const
	{
		return ConfigData;
	}

	const TOptional<FString>& GetCreatedAt() const
	{
		return CreatedAt;
	}

	const TOptional<FString>& GetId() const
	{
		return Id;
	}

	const TOptional<FString>& GetName() const
	{
		return Name;
	}

	const TOptional<FAssetStateData>& GetStateData() const
	{
		return StateData;
	}

	const TOptional<FString>& GetUpdatedAt() const
	{
		return UpdatedAt;
	}

	const TOptional<EAssetVariantMode>& GetVariantMode() const
	{
		return VariantMode;
	}

	const TOptional<TArray<FAssetVariant>>& GetVariants() const
	{
		return Variants;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return ConfigData == Rhs.ConfigData
			&& CreatedAt == Rhs.CreatedAt
			&& Id == Rhs.Id
			&& Name == Rhs.Name
			&& StateData == Rhs.StateData
			&& UpdatedAt == Rhs.UpdatedAt
			&& VariantMode == Rhs.VariantMode
			&& Variants == Rhs.Variants;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FAssetConfigData> ConfigData;
	TOptional<FString> CreatedAt;
	TOptional<FString> Id;
	TOptional<FString> Name;
	TOptional<FAssetStateData> StateData;
	TOptional<FString> UpdatedAt;
	TOptional<EAssetVariantMode> VariantMode;
	TOptional<TArray<FAssetVariant>> Variants;
};

FAsset::FAsset() : Pimpl(MakeUnique<FImpl>())
{
}

FAsset::FAsset(const FAsset& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FAsset::FAsset(FAsset&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FAsset::~FAsset() = default;

void FAsset::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FAssetConfigData>& FAsset::GetConfigData() const
{
	return Pimpl->GetConfigData();
}

const TOptional<FString>& FAsset::GetCreatedAt() const
{
	return Pimpl->GetCreatedAt();
}

const TOptional<FString>& FAsset::GetId() const
{
	return Pimpl->GetId();
}

const TOptional<FString>& FAsset::GetName() const
{
	return Pimpl->GetName();
}

const TOptional<FAssetStateData>& FAsset::GetStateData() const
{
	return Pimpl->GetStateData();
}

const TOptional<FString>& FAsset::GetUpdatedAt() const
{
	return Pimpl->GetUpdatedAt();
}

const TOptional<EAssetVariantMode>& FAsset::GetVariantMode() const
{
	return Pimpl->GetVariantMode();
}

const TOptional<TArray<FAssetVariant>>& FAsset::GetVariants() const
{
	return Pimpl->GetVariants();
}

bool FAsset::operator==(const FAsset& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FAsset::operator!=(const FAsset& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FAsset& FAsset::operator=(const FAsset& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
