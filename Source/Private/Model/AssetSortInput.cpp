// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetSortInput.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FAssetSortInput::FImpl final : public ISerializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual FString Serialize() const override
	{
		return FJsonUtil::SerializeJsonObject(ToJson());
	}

	void SetDirection(const ESortDirection Direction)
	{
		DirectionOpt.Emplace(Direction);
	}

	void SetField(const EAssetField Field)
	{
		FieldOpt.Emplace(Field);
	}

	virtual TSharedRef<FJsonObject> ToJson() const override
	{
		TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

		FJsonUtil::TrySetField(JsonRef, TEXT("direction"), DirectionOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("field"), FieldOpt);

		return JsonRef;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return DirectionOpt == Rhs.DirectionOpt
			&& FieldOpt == Rhs.FieldOpt;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<ESortDirection> DirectionOpt;
	TOptional<EAssetField> FieldOpt;
};

FAssetSortInput::FAssetSortInput() : Pimpl(MakeUnique<FImpl>())
{
}

FAssetSortInput::FAssetSortInput(const FAssetSortInput& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FAssetSortInput::FAssetSortInput(FAssetSortInput&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FAssetSortInput::~FAssetSortInput() = default;

FString FAssetSortInput::Serialize() const
{
	return Pimpl->Serialize();
}

FAssetSortInput& FAssetSortInput::SetDirection(const ESortDirection Direction)
{
	Pimpl->SetDirection(Direction);
	return *this;
}

FAssetSortInput& FAssetSortInput::SetField(const EAssetField Field)
{
	Pimpl->SetField(Field);
	return *this;
}

TSharedRef<FJsonObject> FAssetSortInput::ToJson() const
{
	return Pimpl->ToJson();
}

bool FAssetSortInput::operator==(const FAssetSortInput& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FAssetSortInput::operator!=(const FAssetSortInput& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FAssetSortInput& FAssetSortInput::operator=(const FAssetSortInput& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
