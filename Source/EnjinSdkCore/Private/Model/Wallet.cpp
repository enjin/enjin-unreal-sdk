// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Wallet.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FWallet::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			AssetsCreated.Reset();
			EnjAllowance.Reset();
			EnjBalance.Reset();
			EthAddress.Reset();
			EthBalance.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("assetsCreated"), AssetsCreated);
		FJsonUtil::TryGetField(JsonRef, TEXT("balances"), Balances);
		FJsonUtil::TryGetField(JsonRef, TEXT("enjAllowance"), EnjAllowance);
		FJsonUtil::TryGetField(JsonRef, TEXT("enjBalance"), EnjBalance);
		FJsonUtil::TryGetField(JsonRef, TEXT("ethAddress"), EthAddress);
		FJsonUtil::TryGetField(JsonRef, TEXT("ethBalance"), EthBalance);
		FJsonUtil::TryGetField(JsonRef, TEXT("transactions"), Transactions);
	}

	const TOptional<TArray<FAsset>>& GetAssetsCreated() const
	{
		return AssetsCreated;
	}

	const TOptional<TArray<FBalance>>& GetBalances() const
	{
		return Balances;
	}

	const TOptional<double>& GetEnjAllowance() const
	{
		return EnjAllowance;
	}

	const TOptional<double>& GetEnjBalance() const
	{
		return EnjBalance;
	}

	const TOptional<FString>& GetEthAddress() const
	{
		return EthAddress;
	}

	const TOptional<double>& GetEthBalance() const
	{
		return EthBalance;
	}

	const TOptional<TArray<FTransaction>>& GetTransactions() const
	{
		return Transactions;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return AssetsCreated == Rhs.AssetsCreated
			&& Balances == Rhs.Balances
			&& EnjAllowance == Rhs.EnjAllowance
			&& EnjBalance == Rhs.EnjBalance
			&& EthAddress == Rhs.EthAddress
			&& EthBalance == Rhs.EthBalance
			&& Transactions == Rhs.Transactions;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<TArray<FAsset>> AssetsCreated;
	TOptional<TArray<FBalance>> Balances;
	TOptional<double> EnjAllowance;
	TOptional<double> EnjBalance;
	TOptional<FString> EthAddress;
	TOptional<double> EthBalance;
	TOptional<TArray<FTransaction>> Transactions;
};

FWallet::FWallet() : Pimpl(MakeUnique<FImpl>())
{
}

FWallet::FWallet(const FWallet& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FWallet::FWallet(FWallet&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FWallet::~FWallet() = default;

void FWallet::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<TArray<FAsset>>& FWallet::GetAssetsCreated() const
{
	return Pimpl->GetAssetsCreated();
}

const TOptional<TArray<FBalance>>& FWallet::GetBalances() const
{
	return Pimpl->GetBalances();
}

const TOptional<double>& FWallet::GetEnjAllowance() const
{
	return Pimpl->GetEnjAllowance();
}

const TOptional<double>& FWallet::GetEnjBalance() const
{
	return Pimpl->GetEnjBalance();
}

const TOptional<FString>& FWallet::GetEthAddress() const
{
	return Pimpl->GetEthAddress();
}

const TOptional<double>& FWallet::GetEthBalance() const
{
	return Pimpl->GetEthBalance();
}

const TOptional<TArray<FTransaction>>& FWallet::GetTransactions() const
{
	return Pimpl->GetTransactions();
}

bool FWallet::operator==(const FWallet& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FWallet::operator!=(const FWallet& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FWallet& FWallet::operator=(const FWallet& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
