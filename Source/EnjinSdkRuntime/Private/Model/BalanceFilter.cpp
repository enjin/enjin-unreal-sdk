// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/BalanceFilter.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FBalanceFilter::FImpl final : public ISerializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual FString Serialize() const override
	{
		return FJsonUtil::SerializeJsonObject(ToJson());
	}

	void SetAnd(TArray<FBalanceFilter> Others)
	{
		AndFiltersOpt.Emplace(MoveTemp(Others));
	}

	void SetAssetId(FString Id)
	{
		AssetIdOpt.Emplace(MoveTemp(Id));
	}

	void SetAssetIdIn(TArray<FString> Ids)
	{
		AssetIdInOpt.Emplace(MoveTemp(Ids));
	}

	void SetOr(TArray<FBalanceFilter> Others)
	{
		OrFiltersOpt.Emplace(MoveTemp(Others));
	}

	void SetValue(const int32 Value)
	{
		ValueOpt.Emplace(Value);
	}

	void SetValueIs(const EOperator ValueIs)
	{
		ValueIsOpt.Emplace(ValueIs);
	}

	void SetWallet(FString Wallet)
	{
		WalletOpt.Emplace(MoveTemp(Wallet));
	}

	void SetWalletIn(TArray<FString> Wallets)
	{
		WalletInOpt.Emplace(MoveTemp(Wallets));
	}

	virtual TSharedRef<FJsonObject> ToJson() const override
	{
		TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

		FJsonUtil::TrySetField(JsonRef, TEXT("and"), AndFiltersOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("assetId_in"), AssetIdInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("or"), OrFiltersOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("value_is"), ValueIsOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("wallet_in"), WalletInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("wallet"), WalletOpt);

		return JsonRef;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return AndFiltersOpt == Rhs.AndFiltersOpt
			&& AssetIdInOpt == Rhs.AssetIdInOpt
			&& AssetIdOpt == Rhs.AssetIdOpt
			&& OrFiltersOpt == Rhs.OrFiltersOpt
			&& ValueIsOpt == Rhs.ValueIsOpt
			&& ValueOpt == Rhs.ValueOpt
			&& WalletInOpt == Rhs.WalletInOpt
			&& WalletOpt == Rhs.WalletOpt;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<TArray<FBalanceFilter>> AndFiltersOpt;
	TOptional<TArray<FString>> AssetIdInOpt;
	TOptional<FString> AssetIdOpt;
	TOptional<TArray<FBalanceFilter>> OrFiltersOpt;
	TOptional<EOperator> ValueIsOpt;
	TOptional<int32> ValueOpt;
	TOptional<TArray<FString>> WalletInOpt;
	TOptional<FString> WalletOpt;
};

FBalanceFilter::FBalanceFilter() : Pimpl(MakeUnique<FImpl>())
{
}

FBalanceFilter::FBalanceFilter(const FBalanceFilter& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FBalanceFilter::FBalanceFilter(FBalanceFilter&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FBalanceFilter::~FBalanceFilter() = default;

FString FBalanceFilter::Serialize() const
{
	return Pimpl->Serialize();
}

FBalanceFilter& FBalanceFilter::SetAnd(TArray<FBalanceFilter> Others)
{
	Pimpl->SetAnd(MoveTemp(Others));
	return *this;
}

FBalanceFilter& FBalanceFilter::SetAssetId(FString Id)
{
	Pimpl->SetAssetId(MoveTemp(Id));
	return *this;
}

FBalanceFilter& FBalanceFilter::SetAssetIdIn(TArray<FString> Ids)
{
	Pimpl->SetAssetIdIn(MoveTemp(Ids));
	return *this;
}

FBalanceFilter& FBalanceFilter::SetOr(TArray<FBalanceFilter> Others)
{
	Pimpl->SetOr(MoveTemp(Others));
	return *this;
}

FBalanceFilter& FBalanceFilter::SetValue(const int32 Value)
{
	Pimpl->SetValue(Value);
	return *this;
}

FBalanceFilter& FBalanceFilter::SetValueIs(const EOperator ValueIs)
{
	Pimpl->SetValueIs(ValueIs);
	return *this;
}

FBalanceFilter& FBalanceFilter::SetWallet(FString Wallet)
{
	Pimpl->SetWallet(MoveTemp(Wallet));
	return *this;
}

FBalanceFilter& FBalanceFilter::SetWalletIn(TArray<FString> Wallets)
{
	Pimpl->SetWalletIn(MoveTemp(Wallets));
	return *this;
}

TSharedRef<FJsonObject> FBalanceFilter::ToJson() const
{
	return Pimpl->ToJson();
}

bool FBalanceFilter::operator==(const FBalanceFilter& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FBalanceFilter::operator!=(const FBalanceFilter& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FBalanceFilter& FBalanceFilter::operator=(const FBalanceFilter& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
