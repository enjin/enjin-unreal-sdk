// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Contracts.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FContracts::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			CryptoItems.Reset();
			Enj.Reset();
			PlatformRegistry.Reset();
			SupplyModels.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("cryptoItems"), CryptoItems);
		FJsonUtil::TryGetField(JsonRef, TEXT("enj"), Enj);
		FJsonUtil::TryGetField(JsonRef, TEXT("platformRegistry"), PlatformRegistry);
		FJsonUtil::TryGetField(JsonRef, TEXT("supplyModels"), SupplyModels);
	}

	const TOptional<FString>& GetCryptoItems() const
	{
		return CryptoItems;
	}

	const TOptional<FString>& GetEnj() const
	{
		return Enj;
	}

	const TOptional<FString>& GetPlatformRegistry() const
	{
		return PlatformRegistry;
	}

	const TOptional<FSupplyModels>& GetSupplyModels() const
	{
		return SupplyModels;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return CryptoItems == Rhs.CryptoItems
			&& Enj == Rhs.Enj
			&& PlatformRegistry == Rhs.PlatformRegistry
			&& SupplyModels == Rhs.SupplyModels;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> CryptoItems;
	TOptional<FString> Enj;
	TOptional<FString> PlatformRegistry;
	TOptional<FSupplyModels> SupplyModels;
};

FContracts::FContracts() : Pimpl(MakeUnique<FImpl>())
{
}

FContracts::FContracts(const FContracts& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FContracts::FContracts(FContracts&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FContracts::~FContracts() = default;

void FContracts::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FContracts::GetCryptoItems() const
{
	return Pimpl->GetCryptoItems();
}

const TOptional<FString>& FContracts::GetEnj() const
{
	return Pimpl->GetEnj();
}

const TOptional<FString>& FContracts::GetPlatformRegistry() const
{
	return Pimpl->GetPlatformRegistry();
}

const TOptional<FSupplyModels>& FContracts::GetSupplyModels() const
{
	return Pimpl->GetSupplyModels();
}

bool FContracts::operator==(const FContracts& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FContracts::operator!=(const FContracts& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FContracts& FContracts::operator=(const FContracts& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
