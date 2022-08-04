// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Platform.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FPlatform::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			Contracts.Reset();
			Id.Reset();
			Name.Reset();
			Network.Reset();
			Notifications.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("contracts"), Contracts);
		FJsonUtil::TryGetField(JsonRef, TEXT("id"), Id);
		FJsonUtil::TryGetField(JsonRef, TEXT("name"), Name);
		FJsonUtil::TryGetField(JsonRef, TEXT("network"), Network);
		FJsonUtil::TryGetField(JsonRef, TEXT("notifications"), Notifications);
	}

	const TOptional<FContracts>& GetContracts() const
	{
		return Contracts;
	}

	const TOptional<int32>& GetId() const
	{
		return Id;
	}

	const TOptional<FString>& GetName() const
	{
		return Name;
	}

	const TOptional<FString>& GetNetwork() const
	{
		return Network;
	}

	const TOptional<FNotifications>& GetNotifications() const
	{
		return Notifications;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return Contracts == Rhs.Contracts
			&& Id == Rhs.Id
			&& Name == Rhs.Name
			&& Network == Rhs.Network
			&& Notifications == Rhs.Notifications;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FContracts> Contracts;
	TOptional<int32> Id;
	TOptional<FString> Name;
	TOptional<FString> Network;
	TOptional<FNotifications> Notifications;
};

FPlatform::FPlatform() : Pimpl(MakeUnique<FImpl>())
{
}

FPlatform::FPlatform(const FPlatform& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FPlatform::FPlatform(FPlatform&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FPlatform::~FPlatform() = default;

void FPlatform::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FContracts>& FPlatform::GetContracts() const
{
	return Pimpl->GetContracts();
}

const TOptional<int32>& FPlatform::GetId() const
{
	return Pimpl->GetId();
}

const TOptional<FString>& FPlatform::GetName() const
{
	return Pimpl->GetName();
}

const TOptional<FString>& FPlatform::GetNetwork() const
{
	return Pimpl->GetNetwork();
}

const TOptional<FNotifications>& FPlatform::GetNotifications() const
{
	return Pimpl->GetNotifications();
}

bool FPlatform::operator==(const FPlatform& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FPlatform::operator!=(const FPlatform& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FPlatform& FPlatform::operator=(const FPlatform& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
