// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/PlayerFilter.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FPlayerFilter::FImpl final : ISerializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual FString Serialize() const override
	{
		return FJsonUtil::SerializeJsonObject(ToJson());
	}

	void SetAnd(TArray<FPlayerFilter> Others)
	{
		AndFiltersOpt.Emplace(MoveTemp(Others));
	}

	void SetId(FString Id)
	{
		IdOpt.Emplace(MoveTemp(Id));
	}

	void SetIdIn(TArray<FString> Ids)
	{
		IdInOpt.Emplace(MoveTemp(Ids));
	}

	void SetOr(TArray<FPlayerFilter> Others)
	{
		OrFiltersOpt.Emplace(MoveTemp(Others));
	}

	virtual TSharedRef<FJsonObject> ToJson() const override
	{
		TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

		FJsonUtil::TrySetField(JsonRef, TEXT("and"), AndFiltersOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("id_in"), IdInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("or"), OrFiltersOpt);

		return JsonRef;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return AndFiltersOpt == Rhs.AndFiltersOpt
			&& IdInOpt == Rhs.IdInOpt
			&& IdOpt == Rhs.IdOpt
			&& OrFiltersOpt == Rhs.OrFiltersOpt;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<TArray<FPlayerFilter>> AndFiltersOpt;
	TOptional<TArray<FString>> IdInOpt;
	TOptional<FString> IdOpt;
	TOptional<TArray<FPlayerFilter>> OrFiltersOpt;
};

FPlayerFilter::FPlayerFilter() : Pimpl(MakeUnique<FImpl>())
{
}

FPlayerFilter::FPlayerFilter(const FPlayerFilter& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FPlayerFilter::FPlayerFilter(FPlayerFilter&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FPlayerFilter::~FPlayerFilter() = default;

FString FPlayerFilter::Serialize() const
{
	return Pimpl->Serialize();
}

FPlayerFilter& FPlayerFilter::SetAnd(TArray<FPlayerFilter> Others)
{
	Pimpl->SetAnd(MoveTemp(Others));
	return *this;
}

FPlayerFilter& FPlayerFilter::SetId(FString Id)
{
	Pimpl->SetId(MoveTemp(Id));
	return *this;
}

FPlayerFilter& FPlayerFilter::SetIdIn(TArray<FString> Ids)
{
	Pimpl->SetIdIn(MoveTemp(Ids));
	return *this;
}

FPlayerFilter& FPlayerFilter::SetOr(TArray<FPlayerFilter> Others)
{
	Pimpl->SetOr(MoveTemp(Others));
	return *this;
}

TSharedRef<FJsonObject> FPlayerFilter::ToJson() const
{
	return Pimpl->ToJson();
}

bool FPlayerFilter::operator==(const FPlayerFilter& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FPlayerFilter::operator!=(const FPlayerFilter& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FPlayerFilter& FPlayerFilter::operator=(const FPlayerFilter& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
