// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetFilter.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FAssetFilter::FImpl final : public ISerializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual FString Serialize() const override
	{
		return FJsonUtil::SerializeJsonObject(ToJson());
	}

	void SetAnd(TArray<FAssetFilter> Others)
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

	void SetName(FString Name)
	{
		NameOpt.Emplace(MoveTemp(Name));
	}

	void SetNameContains(FString Text)
	{
		NameContainsOpt.Emplace(MoveTemp(Text));
	}

	void SetNameEndsWith(FString Suffix)
	{
		NameEndsWithOpt.Emplace(MoveTemp(Suffix));
	}

	void SetNameIn(TArray<FString> Names)
	{
		NameInOpt.Emplace(MoveTemp(Names));
	}

	void SetNameStartsWith(FString Prefix)
	{
		NameStartsWithOpt.Emplace(MoveTemp(Prefix));
	}

	void SetOr(TArray<FAssetFilter> Others)
	{
		OrFiltersOpt.Emplace(MoveTemp(Others));
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
		FJsonUtil::TrySetField(JsonRef, TEXT("id_in"), IdInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("name_contains"), NameContainsOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("name_ends_with"), NameEndsWithOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("name_in"), NameInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("name"), NameOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("name_starts_with"), NameStartsWithOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("or"), OrFiltersOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("wallet_in"), WalletInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("wallet"), WalletOpt);

		return JsonRef;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return AndFiltersOpt == Rhs.AndFiltersOpt
			&& IdInOpt == Rhs.IdInOpt
			&& IdOpt == Rhs.IdOpt
			&& NameContainsOpt == Rhs.NameContainsOpt
			&& NameEndsWithOpt == Rhs.NameEndsWithOpt
			&& NameInOpt == Rhs.NameInOpt
			&& NameOpt == Rhs.NameOpt
			&& NameStartsWithOpt == Rhs.NameStartsWithOpt
			&& OrFiltersOpt == Rhs.OrFiltersOpt
			&& WalletInOpt == Rhs.WalletInOpt
			&& WalletOpt == Rhs.WalletOpt;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<TArray<FAssetFilter>> AndFiltersOpt;
	TOptional<TArray<FString>> IdInOpt;
	TOptional<FString> IdOpt;
	TOptional<FString> NameContainsOpt;
	TOptional<FString> NameEndsWithOpt;
	TOptional<TArray<FString>> NameInOpt;
	TOptional<FString> NameOpt;
	TOptional<FString> NameStartsWithOpt;
	TOptional<TArray<FAssetFilter>> OrFiltersOpt;
	TOptional<TArray<FString>> WalletInOpt;
	TOptional<FString> WalletOpt;
};

FAssetFilter::FAssetFilter() : Pimpl(MakeUnique<FImpl>())
{
}

FAssetFilter::FAssetFilter(const FAssetFilter& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FAssetFilter::FAssetFilter(FAssetFilter&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FAssetFilter::~FAssetFilter() = default;

FString FAssetFilter::Serialize() const
{
	return Pimpl->Serialize();
}

FAssetFilter& FAssetFilter::SetAnd(TArray<FAssetFilter> Others)
{
	Pimpl->SetAnd(MoveTemp(Others));
	return *this;
}

FAssetFilter& FAssetFilter::SetId(FString Id)
{
	Pimpl->SetId(MoveTemp(Id));
	return *this;
}

FAssetFilter& FAssetFilter::SetIdIn(TArray<FString> Ids)
{
	Pimpl->SetIdIn(MoveTemp(Ids));
	return *this;
}

FAssetFilter& FAssetFilter::SetName(FString Name)
{
	Pimpl->SetName(MoveTemp(Name));
	return *this;
}

FAssetFilter& FAssetFilter::SetNameContains(FString Text)
{
	Pimpl->SetNameContains(MoveTemp(Text));
	return *this;
}

FAssetFilter& FAssetFilter::SetNameEndsWith(FString Suffix)
{
	Pimpl->SetNameEndsWith(MoveTemp(Suffix));
	return *this;
}

FAssetFilter& FAssetFilter::SetNameIn(TArray<FString> Names)
{
	Pimpl->SetNameIn(MoveTemp(Names));
	return *this;
}

FAssetFilter& FAssetFilter::SetNameStartsWith(FString Prefix)
{
	Pimpl->SetNameStartsWith(MoveTemp(Prefix));
	return *this;
}

FAssetFilter& FAssetFilter::SetOr(TArray<FAssetFilter> Others)
{
	Pimpl->SetOr(MoveTemp(Others));
	return *this;
}

FAssetFilter& FAssetFilter::SetWallet(FString Wallet)
{
	Pimpl->SetWallet(MoveTemp(Wallet));
	return *this;
}

FAssetFilter& FAssetFilter::SetWalletIn(TArray<FString> Wallets)
{
	Pimpl->SetWalletIn(MoveTemp(Wallets));
	return *this;
}

TSharedRef<FJsonObject> FAssetFilter::ToJson() const
{
	return Pimpl->ToJson();
}

bool FAssetFilter::operator==(const FAssetFilter& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FAssetFilter::operator!=(const FAssetFilter& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FAssetFilter& FAssetFilter::operator=(const FAssetFilter& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
