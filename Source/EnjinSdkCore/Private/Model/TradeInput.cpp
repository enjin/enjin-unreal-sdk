// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/TradeInput.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FTradeInput::FImpl final : public ISerializable
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

FTradeInput::FTradeInput() : Pimpl(MakeUnique<FImpl>())
{
}

FTradeInput::FTradeInput(const FTradeInput& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FTradeInput::FTradeInput(FTradeInput&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FTradeInput::~FTradeInput() = default;

FString FTradeInput::Serialize() const
{
	return Pimpl->Serialize();
}

FTradeInput& FTradeInput::SetAssetId(FString Id)
{
	Pimpl->SetAssetId(MoveTemp(Id));
	return *this;
}

FTradeInput& FTradeInput::SetAssetIndex(FString Index)
{
	Pimpl->SetAssetIndex(MoveTemp(Index));
	return *this;
}

FTradeInput& FTradeInput::SetValue(FString Value)
{
	Pimpl->SetValue(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> FTradeInput::ToJson() const
{
	return Pimpl->ToJson();
}

bool FTradeInput::operator==(const FTradeInput& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FTradeInput::operator!=(const FTradeInput& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FTradeInput& FTradeInput::operator=(const FTradeInput& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
