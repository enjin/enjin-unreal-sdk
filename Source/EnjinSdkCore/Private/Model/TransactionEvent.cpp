// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/TransactionEvent.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FTransactionEvent::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			EncodedSignature.Reset();
			IndexedInputs.Reset();
			Inputs.Reset();
			Name.Reset();
			NonIndexedInputs.Reset();
			Signature.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("encodedSignature"), EncodedSignature);
		FJsonUtil::TryGetField(JsonRef, TEXT("indexedInputs"), IndexedInputs);
		FJsonUtil::TryGetField(JsonRef, TEXT("inputs"), Inputs);
		FJsonUtil::TryGetField(JsonRef, TEXT("name"), Name);
		FJsonUtil::TryGetField(JsonRef, TEXT("nonIndexedInputs"), NonIndexedInputs);
		FJsonUtil::TryGetField(JsonRef, TEXT("signature"), Signature);
	}

	const TOptional<FString>& GetEncodedSignature() const
	{
		return EncodedSignature;
	}

	const TOptional<TArray<FString>>& GetIndexedInputs() const
	{
		return IndexedInputs;
	}

	const TOptional<TArray<FString>>& GetInputs() const
	{
		return Inputs;
	}

	const TOptional<FString>& GetName() const
	{
		return Name;
	}

	const TOptional<TArray<FString>>& GetNonIndexedInputs() const
	{
		return NonIndexedInputs;
	}

	const TOptional<FString>& GetSignature() const
	{
		return Signature;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return EncodedSignature == Rhs.EncodedSignature
			&& IndexedInputs == Rhs.IndexedInputs
			&& Inputs == Rhs.Inputs
			&& Name == Rhs.Name
			&& NonIndexedInputs == Rhs.NonIndexedInputs
			&& Signature == Rhs.Signature;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> EncodedSignature;
	TOptional<TArray<FString>> IndexedInputs;
	TOptional<TArray<FString>> Inputs;
	TOptional<FString> Name;
	TOptional<TArray<FString>> NonIndexedInputs;
	TOptional<FString> Signature;
};

FTransactionEvent::FTransactionEvent() : Pimpl(MakeUnique<FImpl>())
{
}

FTransactionEvent::FTransactionEvent(const FTransactionEvent& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FTransactionEvent::FTransactionEvent(FTransactionEvent&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FTransactionEvent::~FTransactionEvent() = default;

void FTransactionEvent::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FTransactionEvent::GetEncodedSignature() const
{
	return Pimpl->GetEncodedSignature();
}

const TOptional<TArray<FString>>& FTransactionEvent::GetIndexedInputs() const
{
	return Pimpl->GetIndexedInputs();
}

const TOptional<TArray<FString>>& FTransactionEvent::GetInputs() const
{
	return Pimpl->GetInputs();
}

const TOptional<FString>& FTransactionEvent::GetName() const
{
	return Pimpl->GetName();
}

const TOptional<TArray<FString>>& FTransactionEvent::GetNonIndexedInputs() const
{
	return Pimpl->GetNonIndexedInputs();
}

const TOptional<FString>& FTransactionEvent::GetSignature() const
{
	return Pimpl->GetSignature();
}

bool FTransactionEvent::operator==(const FTransactionEvent& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FTransactionEvent::operator!=(const FTransactionEvent& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FTransactionEvent& FTransactionEvent::operator=(const FTransactionEvent& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
