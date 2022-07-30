// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetVariant.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FAssetVariant::FImpl final : public IDeserializable
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
			CreatedAt.Reset();
			Id.Reset();
			UpdatedAt.Reset();
			UsageCount.Reset();
			VariantMetadata.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("assetId"), AssetId);
		FJsonUtil::TryGetField(JsonRef, TEXT("createdAt"), CreatedAt);
		FJsonUtil::TryGetField(JsonRef, TEXT("id"), Id);
		FJsonUtil::TryGetField(JsonRef, TEXT("updatedAt"), UpdatedAt);
		FJsonUtil::TryGetField(JsonRef, TEXT("usageCount"), UsageCount);
		FJsonUtil::TryGetField(JsonRef, TEXT("variantMetadata"), VariantMetadata);
	}

	const TOptional<FString>& GetAssetId() const
	{
		return AssetId;
	}

	const TOptional<FString>& GetCreatedAt() const
	{
		return CreatedAt;
	}

	const TOptional<int32>& GetId() const
	{
		return Id;
	}

	const TOptional<FString>& GetUpdatedAt() const
	{
		return UpdatedAt;
	}

	const TOptional<int32>& GetUsageCount() const
	{
		return UsageCount;
	}

	const TOptional<TSharedRef<FJsonObject>>& GetVariantMetadata() const
	{
		return VariantMetadata;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return AssetId == Rhs.AssetId
			&& CreatedAt == Rhs.CreatedAt
			&& Id == Rhs.Id
			&& UpdatedAt == Rhs.UpdatedAt
			&& UsageCount == Rhs.UsageCount
			&& FJsonUtil::Equals(VariantMetadata, Rhs.VariantMetadata);
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> AssetId;
	TOptional<FString> CreatedAt;
	TOptional<int32> Id;
	TOptional<FString> UpdatedAt;
	TOptional<int32> UsageCount;
	TOptional<TSharedRef<FJsonObject>> VariantMetadata;
};

FAssetVariant::FAssetVariant() : Pimpl(MakeUnique<FImpl>())
{
}

FAssetVariant::FAssetVariant(const FAssetVariant& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FAssetVariant::FAssetVariant(FAssetVariant&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FAssetVariant::~FAssetVariant() = default;

void FAssetVariant::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FAssetVariant::GetAssetId() const
{
	return Pimpl->GetAssetId();
}

const TOptional<FString>& FAssetVariant::GetCreatedAt() const
{
	return Pimpl->GetCreatedAt();
}

const TOptional<int32>& FAssetVariant::GetId() const
{
	return Pimpl->GetId();
}

const TOptional<FString>& FAssetVariant::GetUpdatedAt() const
{
	return Pimpl->GetUpdatedAt();
}

const TOptional<int32>& FAssetVariant::GetUsageCount() const
{
	return Pimpl->GetUsageCount();
}

const TOptional<TSharedRef<FJsonObject>>& FAssetVariant::GetVariantMetadata() const
{
	return Pimpl->GetVariantMetadata();
}

bool FAssetVariant::operator==(const FAssetVariant& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FAssetVariant::operator!=(const FAssetVariant& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FAssetVariant& FAssetVariant::operator=(const FAssetVariant& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
