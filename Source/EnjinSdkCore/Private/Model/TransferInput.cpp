// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/TransferInput.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FTransferInput::FImpl final : public ISerializable
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

	void SetFrom(FString From)
	{
		FromOpt.Emplace(MoveTemp(From));
	}

	void SetTo(FString To)
	{
		ToOpt.Emplace(MoveTemp(To));
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
		FJsonUtil::TrySetField(JsonRef, TEXT("from"), FromOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("to"), ToOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

		return JsonRef;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return AssetIdOpt == Rhs.AssetIdOpt
			&& AssetIndexOpt == Rhs.AssetIndexOpt
			&& FromOpt == Rhs.FromOpt
			&& ToOpt == Rhs.ToOpt
			&& ValueOpt == Rhs.ValueOpt;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> AssetIdOpt;
	TOptional<FString> AssetIndexOpt;
	TOptional<FString> FromOpt;
	TOptional<FString> ToOpt;
	TOptional<FString> ValueOpt;
};

FTransferInput::FTransferInput() : Pimpl(MakeUnique<FImpl>())
{
}

FTransferInput::FTransferInput(const FTransferInput& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FTransferInput::FTransferInput(FTransferInput&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FTransferInput::~FTransferInput() = default;

FString FTransferInput::Serialize() const
{
	return Pimpl->Serialize();
}

FTransferInput& FTransferInput::SetAssetId(FString Id)
{
	Pimpl->SetAssetId(MoveTemp(Id));
	return *this;
}

FTransferInput& FTransferInput::SetAssetIndex(FString Index)
{
	Pimpl->SetAssetIndex(MoveTemp(Index));
	return *this;
}

FTransferInput& FTransferInput::SetFrom(FString From)
{
	Pimpl->SetFrom(MoveTemp(From));
	return *this;
}

FTransferInput& FTransferInput::SetTo(FString To)
{
	Pimpl->SetTo(MoveTemp(To));
	return *this;
}

FTransferInput& FTransferInput::SetValue(FString Value)
{
	Pimpl->SetValue(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> FTransferInput::ToJson() const
{
	return Pimpl->ToJson();
}

bool FTransferInput::operator==(const FTransferInput& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FTransferInput::operator!=(const FTransferInput& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FTransferInput& FTransferInput::operator=(const FTransferInput& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
