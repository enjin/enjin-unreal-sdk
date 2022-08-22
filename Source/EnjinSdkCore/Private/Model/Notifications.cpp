// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Notifications.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FNotifications::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			Pusher.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("pusher"), Pusher);
	}

	const TOptional<FPusher>& GetPusher() const
	{
		return Pusher;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return Pusher == Rhs.Pusher;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FPusher> Pusher;
};

FNotifications::FNotifications() : Pimpl(MakeUnique<FImpl>())
{
}

FNotifications::FNotifications(const FNotifications& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FNotifications::FNotifications(FNotifications&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FNotifications::~FNotifications() = default;

void FNotifications::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FPusher>& FNotifications::GetPusher() const
{
	return Pimpl->GetPusher();
}

bool FNotifications::operator==(const FNotifications& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FNotifications::operator!=(const FNotifications& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FNotifications& FNotifications::operator=(const FNotifications& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
