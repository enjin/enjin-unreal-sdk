// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/TransactionFilter.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FTransactionFilter::FImpl final : public ISerializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual FString Serialize() const override
	{
		return FJsonUtil::SerializeJsonObject(ToJson());
	}

	void SetAnd(TArray<FTransactionFilter> Others)
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

	void SetId(FString Id)
	{
		IdOpt.Emplace(MoveTemp(Id));
	}

	void SetIdIn(TArray<FString> Ids)
	{
		IdInOpt.Emplace(MoveTemp(Ids));
	}

	void SetOr(TArray<FTransactionFilter> Others)
	{
		OrFiltersOpt.Emplace(MoveTemp(Others));
	}

	void SetState(const ETransactionState State)
	{
		StateOpt.Emplace(State);
	}

	void SetStateIn(TArray<ETransactionState> States)
	{
		StateInOpt.Emplace(MoveTemp(States));
	}

	void SetTransactionId(FString Id)
	{
		TransactionIdOpt.Emplace(MoveTemp(Id));
	}

	void SetTransactionIdIn(TArray<FString> Ids)
	{
		TransactionIdInOpt.Emplace(MoveTemp(Ids));
	}

	void SetType(const ETransactionType Type)
	{
		TypeOpt.Emplace(Type);
	}

	void SetTypeIn(TArray<ETransactionType> Types)
	{
		TypeInOpt.Emplace(MoveTemp(Types));
	}

	void SetValue(const int32 Value)
	{
		ValueOpt.Emplace(Value);
	}

	void SetValueGreaterThan(const int32 Value)
	{
		ValueGtOpt.Emplace(Value);
	}

	void SetValueGreaterThanOrEqual(const int32 Value)
	{
		ValueGteOpt.Emplace(Value);
	}

	void SetValueLessThan(const int32 Value)
	{
		ValueLtOpt.Emplace(Value);
	}

	void SetValueLessThanOrEqual(const int32 Value)
	{
		ValueLteOpt.Emplace(Value);
	}

	void SetWallet(FString Address)
	{
		WalletOpt.Emplace(MoveTemp(Address));
	}

	void SetWalletIn(TArray<FString> Addresses)
	{
		WalletInOpt.Emplace(MoveTemp(Addresses));
	}

	virtual TSharedRef<FJsonObject> ToJson() const override
	{
		TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

		FJsonUtil::TrySetField(JsonRef, TEXT("and"), AndFiltersOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("assetId_in"), AssetIdInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("assetId"), AssetIdOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("id_in"), IdInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("id"), IdOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("or"), OrFiltersOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("state_in"), StateInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("state"), StateOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("transactionId_in"), TransactionIdInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("transactionId"), TransactionIdOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("type_in"), TypeInOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("type"), TypeOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("value_gt"), ValueGtOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("value_gte"), ValueGteOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("value_lt"), ValueLtOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("value_lte"), ValueLteOpt);
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
			&& IdInOpt == Rhs.IdInOpt
			&& IdOpt == Rhs.IdOpt
			&& OrFiltersOpt == Rhs.OrFiltersOpt
			&& StateInOpt == Rhs.StateInOpt
			&& StateOpt == Rhs.StateOpt
			&& TransactionIdInOpt == Rhs.TransactionIdInOpt
			&& TransactionIdOpt == Rhs.TransactionIdOpt
			&& TypeInOpt == Rhs.TypeInOpt
			&& TypeOpt == Rhs.TypeOpt
			&& ValueGtOpt == Rhs.ValueGtOpt
			&& ValueGteOpt == Rhs.ValueGteOpt
			&& ValueLtOpt == Rhs.ValueLtOpt
			&& ValueLteOpt == Rhs.ValueLteOpt
			&& ValueOpt == Rhs.ValueOpt
			&& WalletInOpt == Rhs.WalletInOpt
			&& WalletOpt == Rhs.WalletOpt;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<TArray<FTransactionFilter>> AndFiltersOpt;
	TOptional<TArray<FString>> AssetIdInOpt;
	TOptional<FString> AssetIdOpt;
	TOptional<TArray<FString>> IdInOpt;
	TOptional<FString> IdOpt;
	TOptional<TArray<FTransactionFilter>> OrFiltersOpt;
	TOptional<TArray<ETransactionState>> StateInOpt;
	TOptional<ETransactionState> StateOpt;
	TOptional<TArray<FString>> TransactionIdInOpt;
	TOptional<FString> TransactionIdOpt;
	TOptional<TArray<ETransactionType>> TypeInOpt;
	TOptional<ETransactionType> TypeOpt;
	TOptional<int32> ValueGtOpt;
	TOptional<int32> ValueGteOpt;
	TOptional<int32> ValueLtOpt;
	TOptional<int32> ValueLteOpt;
	TOptional<int32> ValueOpt;
	TOptional<TArray<FString>> WalletInOpt;
	TOptional<FString> WalletOpt;
};

FTransactionFilter::FTransactionFilter() : Pimpl(MakeUnique<FImpl>())
{
}

FTransactionFilter::FTransactionFilter(const FTransactionFilter& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FTransactionFilter::FTransactionFilter(FTransactionFilter&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FTransactionFilter::~FTransactionFilter() = default;

FString FTransactionFilter::Serialize() const
{
	return Pimpl->Serialize();
}

FTransactionFilter& FTransactionFilter::SetAnd(TArray<FTransactionFilter> Others)
{
	Pimpl->SetAnd(MoveTemp(Others));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetAssetId(FString Id)
{
	Pimpl->SetAssetId(MoveTemp(Id));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetAssetIdIn(TArray<FString> Ids)
{
	Pimpl->SetAssetIdIn(MoveTemp(Ids));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetId(FString Id)
{
	Pimpl->SetId(MoveTemp(Id));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetIdIn(TArray<FString> Ids)
{
	Pimpl->SetIdIn(MoveTemp(Ids));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetOr(TArray<FTransactionFilter> Others)
{
	Pimpl->SetOr(MoveTemp(Others));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetState(const ETransactionState State)
{
	Pimpl->SetState(State);
	return *this;
}

FTransactionFilter& FTransactionFilter::SetStateIn(TArray<ETransactionState> States)
{
	Pimpl->SetStateIn(MoveTemp(States));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetTransactionId(FString Id)
{
	Pimpl->SetTransactionId(MoveTemp(Id));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetTransactionIdIn(TArray<FString> Ids)
{
	Pimpl->SetTransactionIdIn(MoveTemp(Ids));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetType(const ETransactionType Type)
{
	Pimpl->SetType(Type);
	return *this;
}

FTransactionFilter& FTransactionFilter::SetTypeIn(TArray<ETransactionType> Types)
{
	Pimpl->SetTypeIn(MoveTemp(Types));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetValue(const int32 Value)
{
	Pimpl->SetValue(Value);
	return *this;
}

FTransactionFilter& FTransactionFilter::SetValueGreaterThan(const int32 Value)
{
	Pimpl->SetValueGreaterThan(Value);
	return *this;
}

FTransactionFilter& FTransactionFilter::SetValueGreaterThanOrEqual(const int32 Value)
{
	Pimpl->SetValueGreaterThanOrEqual(Value);
	return *this;
}

FTransactionFilter& FTransactionFilter::SetValueLessThan(const int32 Value)
{
	Pimpl->SetValueLessThan(Value);
	return *this;
}

FTransactionFilter& FTransactionFilter::SetValueLessThanOrEqual(const int32 Value)
{
	Pimpl->SetValueLessThanOrEqual(Value);
	return *this;
}

FTransactionFilter& FTransactionFilter::SetWallet(FString Address)
{
	Pimpl->SetWallet(MoveTemp(Address));
	return *this;
}

FTransactionFilter& FTransactionFilter::SetWalletIn(TArray<FString> Addresses)
{
	Pimpl->SetWalletIn(MoveTemp(Addresses));
	return *this;
}

TSharedRef<FJsonObject> FTransactionFilter::ToJson() const
{
	return Pimpl->ToJson();
}

bool FTransactionFilter::operator==(const FTransactionFilter& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FTransactionFilter::operator!=(const FTransactionFilter& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FTransactionFilter& FTransactionFilter::operator=(const FTransactionFilter& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
