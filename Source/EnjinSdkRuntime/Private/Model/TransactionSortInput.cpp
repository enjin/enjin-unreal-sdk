// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/TransactionSortInput.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FTransactionSortInput::FImpl final : public ISerializable
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

	void SetField(const ETransactionField Field)
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
	TOptional<ETransactionField> FieldOpt;
};

FTransactionSortInput::FTransactionSortInput() : Pimpl(MakeUnique<FImpl>())
{
}

FTransactionSortInput::FTransactionSortInput(const FTransactionSortInput& Other)
	: Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FTransactionSortInput::FTransactionSortInput(FTransactionSortInput&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FTransactionSortInput::~FTransactionSortInput() = default;

FString FTransactionSortInput::Serialize() const
{
	return Pimpl->Serialize();
}

FTransactionSortInput& FTransactionSortInput::SetDirection(const ESortDirection Direction)
{
	Pimpl->SetDirection(Direction);
	return *this;
}

FTransactionSortInput& FTransactionSortInput::SetField(const ETransactionField Field)
{
	Pimpl->SetField(Field);
	return *this;
}

TSharedRef<FJsonObject> FTransactionSortInput::ToJson() const
{
	return Pimpl->ToJson();
}

bool FTransactionSortInput::operator==(const FTransactionSortInput& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FTransactionSortInput::operator!=(const FTransactionSortInput& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FTransactionSortInput& FTransactionSortInput::operator=(const FTransactionSortInput& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
