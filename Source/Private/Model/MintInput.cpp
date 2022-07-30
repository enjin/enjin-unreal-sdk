// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/MintInput.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FMintInput::FImpl final : ISerializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual FString Serialize() const override
	{
		return FJsonUtil::SerializeJsonObject(ToJson());
	}

	void SetTo(FString To)
	{
		ToOpt.Emplace(MoveTemp(To));
	}

	void SetValue(FString Value)
	{
		ValueOpt.Emplace(MoveTemp(Value));
	}

	virtual TSharedRef<FJsonObject> ToJson() const override
	{
		TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

		FJsonUtil::TrySetField(JsonRef, TEXT("to"), ToOpt);
		FJsonUtil::TrySetField(JsonRef, TEXT("value"), ValueOpt);

		return JsonRef;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return ToOpt == Rhs.ToOpt
			&& ValueOpt == Rhs.ValueOpt;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> ToOpt;
	TOptional<FString> ValueOpt;
};

FMintInput::FMintInput() : Pimpl(MakeUnique<FImpl>())
{
}

FMintInput::FMintInput(const FMintInput& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FMintInput::FMintInput(FMintInput&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FMintInput::~FMintInput() = default;

FString FMintInput::Serialize() const
{
	return Pimpl->Serialize();
}

FMintInput& FMintInput::SetTo(FString To)
{
	Pimpl->SetTo(MoveTemp(To));
	return *this;
}

FMintInput& FMintInput::SetValue(FString Value)
{
	Pimpl->SetValue(MoveTemp(Value));
	return *this;
}

TSharedRef<FJsonObject> FMintInput::ToJson() const
{
	return Pimpl->ToJson();
}

bool FMintInput::operator==(const FMintInput& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FMintInput::operator!=(const FMintInput& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FMintInput& FMintInput::operator=(const FMintInput& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
