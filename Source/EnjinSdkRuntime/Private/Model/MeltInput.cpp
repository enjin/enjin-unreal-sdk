// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/MeltInput.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FMeltInput::FImpl final : public ISerializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual FString Serialize() const override
	{
		return FJsonUtil::SerializeJsonObject(ToJson());
	}

	void SetAssetId(FString Id)
	{
		AssetIdOpt.Emplace(MoveTemp(Id));
	}

	void SetAssetIndex(FString Index)
	{
		AssetIndexOpt.Emplace(MoveTemp(Index));
	}

	void SetValue(FString Value)
	{
		ValueOpt.Emplace(MoveTemp(Value));
	}

	virtual TSharedRef<FJsonObject> ToJson() const override
	{
		TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

		FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("assetIndex"), AssetIndexOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

		return JsonRef;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return AssetIdOpt == Rhs.AssetIdOpt
			&& AssetIndexOpt == Rhs.AssetIndexOpt
			&& ValueOpt == Rhs.ValueOpt;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> AssetIdOpt;
	TOptional<FString> AssetIndexOpt;
	TOptional<FString> ValueOpt;
};

FMeltInput::FMeltInput() : Pimpl(MakeUnique<FImpl>())
{
}

FMeltInput::FMeltInput(const FMeltInput& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FMeltInput::FMeltInput(FMeltInput&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FMeltInput::~FMeltInput() = default;

FString FMeltInput::Serialize() const
{
	return Pimpl->Serialize();
}

FMeltInput& FMeltInput::SetAssetId(FString Id)
{
	Pimpl->SetAssetId(MoveTemp(Id));
	return *this;
}

FMeltInput& FMeltInput::SetAssetIndex(FString Index)
{
	Pimpl->SetAssetIndex(MoveTemp(Index));
	return *this;
}

FMeltInput& FMeltInput::SetValue(FString Value)
{
	Pimpl->SetValue(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> FMeltInput::ToJson() const
{
	return Pimpl->ToJson();
}

bool FMeltInput::operator==(const FMeltInput& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FMeltInput::operator!=(const FMeltInput& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FMeltInput& FMeltInput::operator=(const FMeltInput& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
