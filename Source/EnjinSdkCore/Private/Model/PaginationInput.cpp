// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/PaginationInput.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Util;

class FPaginationInput::FImpl final : public ISerializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual FString Serialize() const override
	{
		return FJsonUtil::SerializeJsonObject(ToJson());
	}

	void SetLimit(int32 Limit)
	{
		LimitOpt.Emplace(Limit);
	}

	void SetPage(int32 Page)
	{
		PageOpt.Emplace(Page);
	}

	virtual TSharedRef<FJsonObject> ToJson() const override
	{
		TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

		FJsonUtil::TrySetField(JsonRef, TEXT("limit"), LimitOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("page"), PageOpt);

		return JsonRef;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return LimitOpt == Rhs.LimitOpt
			&& PageOpt == Rhs.PageOpt;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<int32> LimitOpt;
	TOptional<int32> PageOpt;
};

FPaginationInput::FPaginationInput() : Pimpl(MakeUnique<FImpl>())
{
}

FPaginationInput::FPaginationInput(const FPaginationInput& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FPaginationInput::FPaginationInput(FPaginationInput&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FPaginationInput::~FPaginationInput() = default;

FString FPaginationInput::Serialize() const
{
	return Pimpl->Serialize();
}

FPaginationInput& FPaginationInput::SetLimit(int32 Limit)
{
	Pimpl->SetLimit(Limit);
	return *this;
}

FPaginationInput& FPaginationInput::SetPage(int32 Page)
{
	Pimpl->SetPage(Page);
	return *this;
}

TSharedRef<FJsonObject> FPaginationInput::ToJson() const
{
	return Pimpl->ToJson();
}

bool FPaginationInput::operator==(const FPaginationInput& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FPaginationInput::operator!=(const FPaginationInput& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FPaginationInput& FPaginationInput::operator=(const FPaginationInput& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
