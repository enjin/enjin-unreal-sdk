// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Balance.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FBalance::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			Id.Reset();
			Index.Reset();
			Project.Reset();
			Value.Reset();
			Wallet.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("id"), Id);
		FJsonUtil::TryGetField(JsonRef, TEXT("index"), Index);
		FJsonUtil::TryGetField(JsonRef, TEXT("project"), Project);
		FJsonUtil::TryGetField(JsonRef, TEXT("value"), Value);
		FJsonUtil::TryGetField(JsonRef, TEXT("wallet"), Wallet);
	}

	const TOptional<FString>& GetId() const
	{
		return Id;
	}

	const TOptional<FString>& GetIndex() const
	{
		return Index;
	}

	const TOptional<FProject>& GetProject() const
	{
		return Project;
	}

	const TOptional<int32>& GetValue() const
	{
		return Value;
	}

	const TOptional<FWallet>& GetWallet() const
	{
		return Wallet;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return Id == Rhs.Id
			&& Index == Rhs.Index
			&& Project == Rhs.Project
			&& Value == Rhs.Value
			&& Wallet == Rhs.Wallet;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> Id;
	TOptional<FString> Index;
	TOptional<FProject> Project;
	TOptional<int32> Value;
	TOptional<FWallet> Wallet;
};

FBalance::FBalance() : Pimpl(MakeUnique<FImpl>())
{
}

FBalance::FBalance(const FBalance& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FBalance::FBalance(FBalance&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FBalance::~FBalance() = default;

void FBalance::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FBalance::GetId() const
{
	return Pimpl->GetId();
}

const TOptional<FString>& FBalance::GetIndex() const
{
	return Pimpl->GetIndex();
}

const TOptional<FProject>& FBalance::GetProject() const
{
	return Pimpl->GetProject();
}

const TOptional<int32>& FBalance::GetValue() const
{
	return Pimpl->GetValue();
}

const TOptional<FWallet>& FBalance::GetWallet() const
{
	return Pimpl->GetWallet();
}

bool FBalance::operator==(const FBalance& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FBalance::operator!=(const FBalance& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FBalance& FBalance::operator=(const FBalance& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
