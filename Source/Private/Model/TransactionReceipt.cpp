// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/TransactionReceipt.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FTransactionReceipt::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			BlockHash.Reset();
			BlockNumber.Reset();
			CumulativeGasUsed.Reset();
			From.Reset();
			GasUsed.Reset();
			Logs.Reset();
			Status.Reset();
			To.Reset();
			TransactionHash.Reset();
			TransactionIndex.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("blockHash"), BlockHash);
		FJsonUtil::TryGetField(JsonRef, TEXT("blockNumber"), BlockNumber);
		FJsonUtil::TryGetField(JsonRef, TEXT("cumulativeGasUsed"), CumulativeGasUsed);
		FJsonUtil::TryGetField(JsonRef, TEXT("from"), From);
		FJsonUtil::TryGetField(JsonRef, TEXT("gasUsed"), GasUsed);
		FJsonUtil::TryGetField(JsonRef, TEXT("logs"), Logs);
		FJsonUtil::TryGetField(JsonRef, TEXT("status"), Status);
		FJsonUtil::TryGetField(JsonRef, TEXT("to"), To);
		FJsonUtil::TryGetField(JsonRef, TEXT("transactionHash"), TransactionHash);
		FJsonUtil::TryGetField(JsonRef, TEXT("transactionIndex"), TransactionIndex);
	}

	const TOptional<FString>& GetBlockHash() const
	{
		return BlockHash;
	}

	const TOptional<int32>& GetBlockNumber() const
	{
		return BlockNumber;
	}

	const TOptional<int32>& GetCumulativeGasUsed() const
	{
		return CumulativeGasUsed;
	}

	const TOptional<FString>& GetFrom() const
	{
		return From;
	}

	const TOptional<int32>& GetGasUsed() const
	{
		return GasUsed;
	}

	const TOptional<TArray<FTransactionLog>>& GetLogs() const
	{
		return Logs;
	}

	const TOptional<bool>& GetStatus() const
	{
		return Status;
	}

	const TOptional<FString>& GetTo() const
	{
		return To;
	}

	const TOptional<FString>& GetTransactionHash() const
	{
		return TransactionHash;
	}

	const TOptional<int32>& GetTransactionIndex() const
	{
		return TransactionIndex;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return BlockHash == Rhs.BlockHash
			&& BlockNumber == Rhs.BlockNumber
			&& CumulativeGasUsed == Rhs.CumulativeGasUsed
			&& From == Rhs.From
			&& GasUsed == Rhs.GasUsed
			&& Logs == Rhs.Logs
			&& Status == Rhs.Status
			&& To == Rhs.To
			&& TransactionHash == Rhs.TransactionHash
			&& TransactionIndex == Rhs.TransactionIndex;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> BlockHash;
	TOptional<int32> BlockNumber;
	TOptional<int32> CumulativeGasUsed;
	TOptional<FString> From;
	TOptional<int32> GasUsed;
	TOptional<TArray<FTransactionLog>> Logs;
	TOptional<bool> Status;
	TOptional<FString> To;
	TOptional<FString> TransactionHash;
	TOptional<int32> TransactionIndex;
};

FTransactionReceipt::FTransactionReceipt() : Pimpl(MakeUnique<FImpl>())
{
}

FTransactionReceipt::FTransactionReceipt(const FTransactionReceipt& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FTransactionReceipt::FTransactionReceipt(FTransactionReceipt&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FTransactionReceipt::~FTransactionReceipt() = default;

void FTransactionReceipt::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FTransactionReceipt::GetBlockHash() const
{
	return Pimpl->GetBlockHash();
}

const TOptional<int32>& FTransactionReceipt::GetBlockNumber() const
{
	return Pimpl->GetBlockNumber();
}

const TOptional<int32>& FTransactionReceipt::GetCumulativeGasUsed() const
{
	return Pimpl->GetCumulativeGasUsed();
}

const TOptional<FString>& FTransactionReceipt::GetFrom() const
{
	return Pimpl->GetFrom();
}

const TOptional<int32>& FTransactionReceipt::GetGasUsed() const
{
	return Pimpl->GetGasUsed();
}

const TOptional<TArray<FTransactionLog>>& FTransactionReceipt::GetLogs() const
{
	return Pimpl->GetLogs();
}

const TOptional<bool>& FTransactionReceipt::GetStatus() const
{
	return Pimpl->GetStatus();
}

const TOptional<FString>& FTransactionReceipt::GetTo() const
{
	return Pimpl->GetTo();
}

const TOptional<FString>& FTransactionReceipt::GetTransactionHash() const
{
	return Pimpl->GetTransactionHash();
}

const TOptional<int32>& FTransactionReceipt::GetTransactionIndex() const
{
	return Pimpl->GetTransactionIndex();
}

bool FTransactionReceipt::operator==(const FTransactionReceipt& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FTransactionReceipt::operator!=(const FTransactionReceipt& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FTransactionReceipt& FTransactionReceipt::operator=(const FTransactionReceipt& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
