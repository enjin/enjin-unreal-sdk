// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/GasPrices.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FGasPrices::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			Average.Reset();
			Fast.Reset();
			Fastest.Reset();
			SafeLow.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("average"), Average);
		FJsonUtil::TryGetField(JsonRef, TEXT("fast"), Fast);
		FJsonUtil::TryGetField(JsonRef, TEXT("fastest"), Fastest);
		FJsonUtil::TryGetField(JsonRef, TEXT("safeLow"), SafeLow);
	}

	const TOptional<double>& GetAverage() const
	{
		return Average;
	}

	const TOptional<double>& GetFast() const
	{
		return Fast;
	}

	const TOptional<double>& GetFastest() const
	{
		return Fastest;
	}

	const TOptional<double>& GetSafeLow() const
	{
		return SafeLow;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return Average == Rhs.Average
			&& Fast == Rhs.Fast
			&& Fastest == Rhs.Fastest
			&& SafeLow == Rhs.SafeLow;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<double> Average;
	TOptional<double> Fast;
	TOptional<double> Fastest;
	TOptional<double> SafeLow;
};

FGasPrices::FGasPrices() : Pimpl(MakeUnique<FImpl>())
{
}

FGasPrices::FGasPrices(const FGasPrices& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FGasPrices::FGasPrices(FGasPrices&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FGasPrices::~FGasPrices() = default;

void FGasPrices::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<double>& FGasPrices::GetAverage() const
{
	return Pimpl->GetAverage();
}

const TOptional<double>& FGasPrices::GetFast() const
{
	return Pimpl->GetFast();
}

const TOptional<double>& FGasPrices::GetFastest() const
{
	return Pimpl->GetFastest();
}

const TOptional<double>& FGasPrices::GetSafeLow() const
{
	return Pimpl->GetSafeLow();
}

bool FGasPrices::operator==(const FGasPrices& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FGasPrices::operator!=(const FGasPrices& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FGasPrices& FGasPrices::operator=(const FGasPrices& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
