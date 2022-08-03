// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AccessToken.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FAccessToken::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			ExpiresIn.Reset();
			Token.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("expiresIn"), ExpiresIn);
		FJsonUtil::TryGetField(JsonRef, TEXT("accessToken"), Token);
	}

	const TOptional<int64>& GetExpiresIn() const
	{
		return ExpiresIn;
	}

	const TOptional<FString>& GetToken() const
	{
		return Token;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return ExpiresIn == Rhs.ExpiresIn
			&& Token == Rhs.Token;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<int64> ExpiresIn;
	TOptional<FString> Token;
};

FAccessToken::FAccessToken() : Pimpl(MakeUnique<FImpl>())
{
}

FAccessToken::FAccessToken(const FAccessToken& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FAccessToken::FAccessToken(FAccessToken&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FAccessToken::~FAccessToken() = default;

void FAccessToken::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<int64>& FAccessToken::GetExpiresIn() const
{
	return Pimpl->GetExpiresIn();
}

const TOptional<FString>& FAccessToken::GetToken() const
{
	return Pimpl->GetToken();
}

bool FAccessToken::operator==(const FAccessToken& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FAccessToken::operator!=(const FAccessToken& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FAccessToken& FAccessToken::operator=(const FAccessToken& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
