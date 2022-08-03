// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/PusherChannels.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FPusherChannels::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			Asset.Reset();
			Player.Reset();
			Project.Reset();
			Wallet.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("asset"), Asset);
		FJsonUtil::TryGetField(JsonRef, TEXT("player"), Player);
		FJsonUtil::TryGetField(JsonRef, TEXT("project"), Project);
		FJsonUtil::TryGetField(JsonRef, TEXT("wallet"), Wallet);
	}

	const TOptional<FString>& GetAsset() const
	{
		return Asset;
	}

	const TOptional<FString>& GetPlayer() const
	{
		return Player;
	}

	const TOptional<FString>& GetProject() const
	{
		return Project;
	}

	const TOptional<FString>& GetWallet() const
	{
		return Wallet;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return Asset == Rhs.Asset
			&& Player == Rhs.Player
			&& Project == Rhs.Project
			&& Wallet == Rhs.Wallet;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> Asset;
	TOptional<FString> Player;
	TOptional<FString> Project;
	TOptional<FString> Wallet;
};

FPusherChannels::FPusherChannels() : Pimpl(MakeUnique<FImpl>())
{
}

FPusherChannels::FPusherChannels(const FPusherChannels& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FPusherChannels::FPusherChannels(FPusherChannels&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FPusherChannels::~FPusherChannels() = default;

void FPusherChannels::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FPusherChannels::GetAsset() const
{
	return Pimpl->GetAsset();
}

const TOptional<FString>& FPusherChannels::GetPlayer() const
{
	return Pimpl->GetPlayer();
}

const TOptional<FString>& FPusherChannels::GetProject() const
{
	return Pimpl->GetProject();
}

const TOptional<FString>& FPusherChannels::GetWallet() const
{
	return Pimpl->GetWallet();
}

bool FPusherChannels::operator==(const FPusherChannels& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FPusherChannels::operator!=(const FPusherChannels& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FPusherChannels& FPusherChannels::operator=(const FPusherChannels& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
