// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/BlockchainData.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FBlockchainData::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			EncodedData.Reset();
			Error.Reset();
			Nonce.Reset();
			Receipt.Reset();
			SignedBackupTransaction.Reset();
			SignedCancelTransaction.Reset();
			SignedTransaction.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("encodedData"), EncodedData);
		FJsonUtil::TryGetField(JsonRef, TEXT("error"), Error);
		FJsonUtil::TryGetField(JsonRef, TEXT("nonce"), Nonce);
		FJsonUtil::TryGetField(JsonRef, TEXT("receipt"), Receipt);
		FJsonUtil::TryGetField(JsonRef, TEXT("signedBackupTransaction"), SignedBackupTransaction);
		FJsonUtil::TryGetField(JsonRef, TEXT("signedCancelTransaction"), SignedCancelTransaction);
		FJsonUtil::TryGetField(JsonRef, TEXT("signedTransaction"), SignedTransaction);
	}

	const TOptional<FString>& GetEncodedData() const
	{
		return EncodedData;
	}

	const TOptional<FString>& GetError() const
	{
		return Error;
	}

	const TOptional<FString>& GetNonce() const
	{
		return Nonce;
	}

	const TOptional<FTransactionReceipt>& GetReceipt() const
	{
		return Receipt;
	}

	const TOptional<FString>& GetSignedBackupTransaction() const
	{
		return SignedBackupTransaction;
	}

	const TOptional<FString>& GetSignedCancelTransaction() const
	{
		return SignedCancelTransaction;
	}

	const TOptional<FString>& GetSignedTransaction() const
	{
		return SignedTransaction;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return EncodedData == Rhs.EncodedData
			&& Error == Rhs.Error
			&& Nonce == Rhs.Nonce
			&& Receipt == Rhs.Receipt
			&& SignedBackupTransaction == Rhs.SignedBackupTransaction
			&& SignedCancelTransaction == Rhs.SignedCancelTransaction
			&& SignedTransaction == Rhs.SignedTransaction;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> EncodedData;
	TOptional<FString> Error;
	TOptional<FString> Nonce;
	TOptional<FTransactionReceipt> Receipt;
	TOptional<FString> SignedBackupTransaction;
	TOptional<FString> SignedCancelTransaction;
	TOptional<FString> SignedTransaction;
};

FBlockchainData::FBlockchainData() : Pimpl(MakeUnique<FImpl>())
{
}

FBlockchainData::FBlockchainData(const FBlockchainData& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FBlockchainData::FBlockchainData(FBlockchainData&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FBlockchainData::~FBlockchainData() = default;

void FBlockchainData::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FBlockchainData::GetEncodedData() const
{
	return Pimpl->GetEncodedData();
}

const TOptional<FString>& FBlockchainData::GetError() const
{
	return Pimpl->GetError();
}

const TOptional<FString>& FBlockchainData::GetNonce() const
{
	return Pimpl->GetNonce();
}

const TOptional<FTransactionReceipt>& FBlockchainData::GetReceipt() const
{
	return Pimpl->GetReceipt();
}

const TOptional<FString>& FBlockchainData::GetSignedBackupTransaction() const
{
	return Pimpl->GetSignedBackupTransaction();
}

const TOptional<FString>& FBlockchainData::GetSignedCancelTransaction() const
{
	return Pimpl->GetSignedCancelTransaction();
}

const TOptional<FString>& FBlockchainData::GetSignedTransaction() const
{
	return Pimpl->GetSignedTransaction();
}

bool FBlockchainData::operator==(const FBlockchainData& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FBlockchainData::operator!=(const FBlockchainData& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FBlockchainData& FBlockchainData::operator=(const FBlockchainData& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
