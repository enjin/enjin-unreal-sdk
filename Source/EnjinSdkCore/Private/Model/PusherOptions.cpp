// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/PusherOptions.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FPusherOptions::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			Cluster.Reset();
			Encrypted.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("cluster"), Cluster);
		FJsonUtil::TryGetField(JsonRef, TEXT("encrypted"), Encrypted);
	}

	const TOptional<FString>& GetCluster() const
	{
		return Cluster;
	}

	const TOptional<bool>& GetEncrypted() const
	{
		return Encrypted;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return Cluster == Rhs.Cluster
			&& Encrypted == Rhs.Encrypted;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> Cluster;
	TOptional<bool> Encrypted;
};

FPusherOptions::FPusherOptions() : Pimpl(MakeUnique<FImpl>())
{
}

FPusherOptions::FPusherOptions(const FPusherOptions& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FPusherOptions::FPusherOptions(FPusherOptions&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FPusherOptions::~FPusherOptions() = default;

void FPusherOptions::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FPusherOptions::GetCluster() const
{
	return Pimpl->GetCluster();
}

const TOptional<bool>& FPusherOptions::GetEncrypted() const
{
	return Pimpl->GetEncrypted();
}

bool FPusherOptions::operator==(const FPusherOptions& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FPusherOptions::operator!=(const FPusherOptions& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FPusherOptions& FPusherOptions::operator=(const FPusherOptions& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
