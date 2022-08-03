// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Pusher.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FPusher::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			Channels.Reset();
			Key.Reset();
			Namespace.Reset();
			Options.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("channels"), Channels);
		FJsonUtil::TryGetField(JsonRef, TEXT("key"), Key);
		FJsonUtil::TryGetField(JsonRef, TEXT("namespace"), Namespace);
		FJsonUtil::TryGetField(JsonRef, TEXT("options"), Options);
	}

	const TOptional<FPusherChannels>& GetChannels() const
	{
		return Channels;
	}

	const TOptional<FString>& GetKey() const
	{
		return Key;
	}

	const TOptional<FString>& GetNamespace() const
	{
		return Namespace;
	}

	const TOptional<FPusherOptions>& GetOptions() const
	{
		return Options;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return Channels == Rhs.Channels
			&& Key == Rhs.Key
			&& Namespace == Rhs.Namespace
			&& Options == Rhs.Options;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FPusherChannels> Channels;
	TOptional<FString> Key;
	TOptional<FString> Namespace;
	TOptional<FPusherOptions> Options;
};

FPusher::FPusher() : Pimpl(MakeUnique<FImpl>())
{
}

FPusher::FPusher(const FPusher& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FPusher::FPusher(FPusher&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FPusher::~FPusher() = default;

void FPusher::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FPusherChannels>& FPusher::GetChannels() const
{
	return Pimpl->GetChannels();
}

const TOptional<FString>& FPusher::GetKey() const
{
	return Pimpl->GetKey();
}

const TOptional<FString>& FPusher::GetNamespace() const
{
	return Pimpl->GetNamespace();
}

const TOptional<FPusherOptions>& FPusher::GetOptions() const
{
	return Pimpl->GetOptions();
}

bool FPusher::operator==(const FPusher& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FPusher::operator!=(const FPusher& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FPusher& FPusher::operator=(const FPusher& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
