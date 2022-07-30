// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Player.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FPlayer::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			CreatedAt.Reset();
			Id.Reset();
			LinkingInfo.Reset();
			UpdatedAt.Reset();
			Wallet.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("createdAt"), CreatedAt);
		FJsonUtil::TryGetField(JsonRef, TEXT("id"), Id);
		FJsonUtil::TryGetField(JsonRef, TEXT("linkingInfo"), LinkingInfo);
		FJsonUtil::TryGetField(JsonRef, TEXT("updatedAt"), UpdatedAt);
		FJsonUtil::TryGetField(JsonRef, TEXT("wallet"), Wallet);
	}

	const TOptional<FString>& GetCreatedAt() const
	{
		return CreatedAt;
	}

	const TOptional<FString>& GetId() const
	{
		return Id;
	}

	const TOptional<FLinkingInfo>& GetLinkingInfo() const
	{
		return LinkingInfo;
	}

	const TOptional<FString>& GetUpdatedAt() const
	{
		return UpdatedAt;
	}

	const TOptional<FWallet>& GetWallet() const
	{
		return Wallet;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return CreatedAt == Rhs.CreatedAt
			&& Id == Rhs.Id
			&& LinkingInfo == Rhs.LinkingInfo
			&& UpdatedAt == Rhs.UpdatedAt
			&& Wallet == Rhs.Wallet;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> CreatedAt;
	TOptional<FString> Id;
	TOptional<FLinkingInfo> LinkingInfo;
	TOptional<FString> UpdatedAt;
	TOptional<FWallet> Wallet;
};

FPlayer::FPlayer() : Pimpl(MakeUnique<FImpl>())
{
}

FPlayer::FPlayer(const FPlayer& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FPlayer::FPlayer(FPlayer&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FPlayer::~FPlayer() = default;

void FPlayer::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FPlayer::GetCreatedAt() const
{
	return Pimpl->GetCreatedAt();
}

const TOptional<FString>& FPlayer::GetId() const
{
	return Pimpl->GetId();
}

const TOptional<FLinkingInfo>& FPlayer::GetLinkingInfo() const
{
	return Pimpl->GetLinkingInfo();
}

const TOptional<FString>& FPlayer::GetUpdatedAt() const
{
	return Pimpl->GetUpdatedAt();
}

const TOptional<FWallet>& FPlayer::GetWallet() const
{
	return Pimpl->GetWallet();
}

bool FPlayer::operator==(const FPlayer& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FPlayer::operator!=(const FPlayer& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FPlayer& FPlayer::operator=(const FPlayer& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
