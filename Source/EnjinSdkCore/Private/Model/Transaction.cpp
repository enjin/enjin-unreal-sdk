// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Transaction.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FTransaction::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			Accepted.Reset();
			Asset.Reset();
			BlockchainData.Reset();
			Contract.Reset();
			CreatedAt.Reset();
			Id.Reset();
			Project.Reset();
			ProjectWallet.Reset();
			RetryState.Reset();
			State.Reset();
			Title.Reset();
			TransactionId.Reset();
			Type.Reset();
			UpdatedAt.Reset();
			Value.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("accepted"), Accepted);
		FJsonUtil::TryGetField(JsonRef, TEXT("asset"), Asset);
		FJsonUtil::TryGetField(JsonRef, TEXT("blockchainData"), BlockchainData);
		FJsonUtil::TryGetField(JsonRef, TEXT("contract"), Contract);
		FJsonUtil::TryGetField(JsonRef, TEXT("createdAt"), CreatedAt);
		FJsonUtil::TryGetField(JsonRef, TEXT("id"), Id);
		FJsonUtil::TryGetField(JsonRef, TEXT("project"), Project);
		FJsonUtil::TryGetField(JsonRef, TEXT("projectWallet"), ProjectWallet);
		FJsonUtil::TryGetField(JsonRef, TEXT("retryState"), RetryState);
		FJsonUtil::TryGetField(JsonRef, TEXT("state"), State);
		FJsonUtil::TryGetField(JsonRef, TEXT("title"), Title);
		FJsonUtil::TryGetField(JsonRef, TEXT("transactionId"), TransactionId);
		FJsonUtil::TryGetField(JsonRef, TEXT("type"), Type);
		FJsonUtil::TryGetField(JsonRef, TEXT("updatedAt"), UpdatedAt);
		FJsonUtil::TryGetField(JsonRef, TEXT("value"), Value);
		FJsonUtil::TryGetField(JsonRef, TEXT("wallet"), Wallet);
	}

	const TOptional<bool>& GetAccepted() const
	{
		return Accepted;
	}

	const TOptional<FAsset>& GetAsset() const
	{
		return Asset;
	}

	const TOptional<FBlockchainData>& GetBlockchainData() const
	{
		return BlockchainData;
	}

	const TOptional<FString>& GetContract() const
	{
		return Contract;
	}

	const TOptional<FString>& GetCreatedAt() const
	{
		return CreatedAt;
	}

	const TOptional<int32>& GetId() const
	{
		return Id;
	}

	const TOptional<FProject>& GetProject() const
	{
		return Project;
	}

	const TOptional<bool>& GetProjectWallet() const
	{
		return ProjectWallet;
	}

	const TOptional<FString>& GetRetryState() const
	{
		return RetryState;
	}

	const TOptional<ETransactionState>& GetState() const
	{
		return State;
	}

	const TOptional<FString>& GetTitle() const
	{
		return Title;
	}

	const TOptional<FString>& GetTransactionId() const
	{
		return TransactionId;
	}

	const TOptional<ETransactionType>& GetType() const
	{
		return Type;
	}

	const TOptional<FString>& GetUpdatedAt() const
	{
		return UpdatedAt;
	}

	const TOptional<FString>& GetValue() const
	{
		return Value;
	}

	const TOptional<FWallet>& GetWallet() const
	{
		return Wallet;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return Accepted == Rhs.Accepted
			&& Asset == Rhs.Asset
			&& BlockchainData == Rhs.BlockchainData
			&& Contract == Rhs.Contract
			&& CreatedAt == Rhs.CreatedAt
			&& Id == Rhs.Id
			&& Project == Rhs.Project
			&& ProjectWallet == Rhs.ProjectWallet
			&& RetryState == Rhs.RetryState
			&& State == Rhs.State
			&& Title == Rhs.Title
			&& TransactionId == Rhs.TransactionId
			&& Type == Rhs.Type
			&& UpdatedAt == Rhs.UpdatedAt
			&& Value == Rhs.Value
			&& Wallet == Rhs.Wallet;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<bool> Accepted;
	TOptional<FAsset> Asset;
	TOptional<FBlockchainData> BlockchainData;
	TOptional<FString> Contract;
	TOptional<FString> CreatedAt;
	TOptional<int32> Id;
	TOptional<FProject> Project;
	TOptional<bool> ProjectWallet;
	TOptional<FString> RetryState;
	TOptional<ETransactionState> State;
	TOptional<FString> Title;
	TOptional<FString> TransactionId;
	TOptional<ETransactionType> Type;
	TOptional<FString> UpdatedAt;
	TOptional<FString> Value;
	TOptional<FWallet> Wallet;
};

FTransaction::FTransaction() : Pimpl(MakeUnique<FImpl>())
{
}

FTransaction::FTransaction(const FTransaction& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FTransaction::FTransaction(FTransaction&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FTransaction::~FTransaction() = default;

void FTransaction::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<bool>& FTransaction::GetAccepted() const
{
	return Pimpl->GetAccepted();
}

const TOptional<FAsset>& FTransaction::GetAsset() const
{
	return Pimpl->GetAsset();
}

const TOptional<FBlockchainData>& FTransaction::GetBlockchainData() const
{
	return Pimpl->GetBlockchainData();
}

const TOptional<FString>& FTransaction::GetContract() const
{
	return Pimpl->GetContract();
}

const TOptional<FString>& FTransaction::GetCreatedAt() const
{
	return Pimpl->GetCreatedAt();
}

const TOptional<int32>& FTransaction::GetId() const
{
	return Pimpl->GetId();
}

const TOptional<FProject>& FTransaction::GetProject() const
{
	return Pimpl->GetProject();
}

const TOptional<bool>& FTransaction::GetProjectWallet() const
{
	return Pimpl->GetProjectWallet();
}

const TOptional<FString>& FTransaction::GetRetryState() const
{
	return Pimpl->GetRetryState();
}

const TOptional<ETransactionState>& FTransaction::GetState() const
{
	return Pimpl->GetState();
}

const TOptional<FString>& FTransaction::GetTitle() const
{
	return Pimpl->GetTitle();
}

const TOptional<FString>& FTransaction::GetTransactionId() const
{
	return Pimpl->GetTransactionId();
}

const TOptional<ETransactionType>& FTransaction::GetType() const
{
	return Pimpl->GetType();
}

const TOptional<FString>& FTransaction::GetUpdatedAt() const
{
	return Pimpl->GetUpdatedAt();
}

const TOptional<FString>& FTransaction::GetValue() const
{
	return Pimpl->GetValue();
}

const TOptional<FWallet>& FTransaction::GetWallet() const
{
	return Pimpl->GetWallet();
}

bool FTransaction::operator==(const FTransaction& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FTransaction::operator!=(const FTransaction& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FTransaction& FTransaction::operator=(const FTransaction& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
