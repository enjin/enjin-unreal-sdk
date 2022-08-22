// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/SupplyModels.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FSupplyModels::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			AnnualPercentage.Reset();
			AnnualValue.Reset();
			Collapsing.Reset();
			Fixed.Reset();
			Infinite.Reset();
			Settable.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("annualPercentage"), AnnualPercentage);
		FJsonUtil::TryGetField(JsonRef, TEXT("annualValue"), AnnualValue);
		FJsonUtil::TryGetField(JsonRef, TEXT("collapsing"), Collapsing);
		FJsonUtil::TryGetField(JsonRef, TEXT("fixed"), Fixed);
		FJsonUtil::TryGetField(JsonRef, TEXT("infinite"), Infinite);
		FJsonUtil::TryGetField(JsonRef, TEXT("settable"), Settable);
	}

	const TOptional<FString>& GetAnnualPercentage() const
	{
		return AnnualPercentage;
	}

	const TOptional<FString>& GetAnnualValue() const
	{
		return AnnualValue;
	}

	const TOptional<FString>& GetCollapsing() const
	{
		return Collapsing;
	}

	const TOptional<FString>& GetFixed() const
	{
		return Fixed;
	}

	const TOptional<FString>& GetInfinite() const
	{
		return Infinite;
	}

	const TOptional<FString>& GetSettable() const
	{
		return Settable;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return AnnualPercentage == Rhs.AnnualPercentage
			&& AnnualValue == Rhs.AnnualValue
			&& Collapsing == Rhs.Collapsing
			&& Fixed == Rhs.Fixed
			&& Infinite == Rhs.Infinite
			&& Settable == Rhs.Settable;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> AnnualPercentage;
	TOptional<FString> AnnualValue;
	TOptional<FString> Collapsing;
	TOptional<FString> Fixed;
	TOptional<FString> Infinite;
	TOptional<FString> Settable;
};

FSupplyModels::FSupplyModels() : Pimpl(MakeUnique<FImpl>())
{
}

FSupplyModels::FSupplyModels(const FSupplyModels& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FSupplyModels::FSupplyModels(FSupplyModels&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FSupplyModels::~FSupplyModels() = default;

void FSupplyModels::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FSupplyModels::GetAnnualPercentage() const
{
	return Pimpl->GetAnnualPercentage();
}

const TOptional<FString>& FSupplyModels::GetAnnualValue() const
{
	return Pimpl->GetAnnualValue();
}

const TOptional<FString>& FSupplyModels::GetCollapsing() const
{
	return Pimpl->GetCollapsing();
}

const TOptional<FString>& FSupplyModels::GetFixed() const
{
	return Pimpl->GetFixed();
}

const TOptional<FString>& FSupplyModels::GetInfinite() const
{
	return Pimpl->GetInfinite();
}

const TOptional<FString>& FSupplyModels::GetSettable() const
{
	return Pimpl->GetSettable();
}

bool FSupplyModels::operator==(const FSupplyModels& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FSupplyModels::operator!=(const FSupplyModels& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FSupplyModels& FSupplyModels::operator=(const FSupplyModels& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
