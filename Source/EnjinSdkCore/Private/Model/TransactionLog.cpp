// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/TransactionLog.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FTransactionLog::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			Address.Reset();
			BlockNumber.Reset();
			Data.Reset();
			Event.Reset();
			Topics.Reset();
			TransactionHash.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("address"), Address);
		FJsonUtil::TryGetField(JsonRef, TEXT("blockNumber"), BlockNumber);
		FJsonUtil::TryGetField(JsonRef, TEXT("data"), Data);
		FJsonUtil::TryGetField(JsonRef, TEXT("event"), Event);
		FJsonUtil::TryGetField(JsonRef, TEXT("topics"), Topics);
		FJsonUtil::TryGetField(JsonRef, TEXT("transactionHash"), TransactionHash);
	}

	const TOptional<FString>& GetAddress() const
	{
		return Address;
	}

	const TOptional<int32>& GetBlockNumber() const
	{
		return BlockNumber;
	}

	const TOptional<TArray<FString>>& GetData() const
	{
		return Data;
	}

	const TOptional<FTransactionEvent>& GetEvent() const
	{
		return Event;
	}

	const TOptional<TArray<FString>>& GetTopics() const
	{
		return Topics;
	}

	const TOptional<FString>& GetTransactionHash() const
	{
		return TransactionHash;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return Address == Rhs.Address
			&& BlockNumber == Rhs.BlockNumber
			&& Data == Rhs.Data
			&& Event == Rhs.Event
			&& Topics == Rhs.Topics
			&& TransactionHash == Rhs.TransactionHash;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> Address;
	TOptional<int32> BlockNumber;
	TOptional<TArray<FString>> Data;
	TOptional<FTransactionEvent> Event;
	TOptional<TArray<FString>> Topics;
	TOptional<FString> TransactionHash;
};

FTransactionLog::FTransactionLog() : Pimpl(MakeUnique<FImpl>())
{
}

FTransactionLog::FTransactionLog(const FTransactionLog& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FTransactionLog::FTransactionLog(FTransactionLog&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FTransactionLog::~FTransactionLog() = default;

void FTransactionLog::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FTransactionLog::GetAddress() const
{
	return Pimpl->GetAddress();
}

const TOptional<int32>& FTransactionLog::GetBlockNumber() const
{
	return Pimpl->GetBlockNumber();
}

const TOptional<TArray<FString>>& FTransactionLog::GetData() const
{
	return Pimpl->GetData();
}

const TOptional<FTransactionEvent>& FTransactionLog::GetEvent() const
{
	return Pimpl->GetEvent();
}

const TOptional<TArray<FString>>& FTransactionLog::GetTopics() const
{
	return Pimpl->GetTopics();
}

const TOptional<FString>& FTransactionLog::GetTransactionHash() const
{
	return Pimpl->GetTransactionHash();
}

bool FTransactionLog::operator==(const FTransactionLog& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FTransactionLog::operator!=(const FTransactionLog& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}
