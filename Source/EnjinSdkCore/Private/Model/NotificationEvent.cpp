// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/NotificationEvent.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Util;

class FNotificationEvent::FImpl final
{
public:
	FImpl() = delete;

	FImpl(const EEventType Type, FString Channel, FString Message) : Channel(MoveTemp(Channel)),
	                                                                 Message(MoveTemp(Message)),
	                                                                 Type(Type),
	                                                                 Data(CreateEventData())
	{
	}

	~FImpl() = default;

	const FString& GetChannel() const
	{
		return Channel;
	}

	const TSharedPtr<const FJsonObject>& GetData() const
	{
		return Data;
	}

	const FString& GetMessage() const
	{
		return Message;
	}

	EEventType GetType() const
	{
		return Type;
	}

	bool operator==(const FImpl& Rhs) const
	{
		// Do not check `Data` fields for equality since they are derived from `Message`.
		return Channel == Rhs.Channel
			&& Message == Rhs.Message
			&& Type == Rhs.Type;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	const FString Channel;
	const FString Message;
	const EEventType Type;

	const TSharedPtr<const FJsonObject> Data;

	TSharedPtr<const FJsonObject> CreateEventData() const
	{
		TSharedPtr<FJsonObject> JsonObject;
		FJsonUtil::TryParseJsonObject(Message, JsonObject);

		return JsonObject;
	}
};

FNotificationEvent::FNotificationEvent(const EEventType Type, FString Channel, FString Message)
	: Pimpl(MakeUnique<FImpl>(Type, MoveTemp(Channel), MoveTemp(Message)))
{
}

FNotificationEvent::FNotificationEvent(const FNotificationEvent& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FNotificationEvent::FNotificationEvent(FNotificationEvent&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FNotificationEvent::~FNotificationEvent() = default;

const FString& FNotificationEvent::GetChannel() const
{
	return Pimpl->GetChannel();
}

const TSharedPtr<const FJsonObject>& FNotificationEvent::GetData() const
{
	return Pimpl->GetData();
}

const FString& FNotificationEvent::GetMessage() const
{
	return Pimpl->GetMessage();
}

EEventType FNotificationEvent::GetType() const
{
	return Pimpl->GetType();
}

bool FNotificationEvent::operator==(const FNotificationEvent& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FNotificationEvent::operator!=(const FNotificationEvent& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FNotificationEvent& FNotificationEvent::operator=(const FNotificationEvent& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
