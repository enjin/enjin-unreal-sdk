// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/LinkingInfo.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FLinkingInfo::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			Code.Reset();
			Qr.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("code"), Code);
		FJsonUtil::TryGetField(JsonRef, TEXT("qr"), Qr);
	}

	const TOptional<FString>& GetCode() const
	{
		return Code;
	}

	const TOptional<FString>& GetQr() const
	{
		return Qr;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return Code == Rhs.Code
			&& Qr == Rhs.Qr;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> Code;
	TOptional<FString> Qr;
};

FLinkingInfo::FLinkingInfo() : Pimpl(MakeUnique<FImpl>())
{
}

FLinkingInfo::FLinkingInfo(const FLinkingInfo& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FLinkingInfo::FLinkingInfo(FLinkingInfo&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FLinkingInfo::~FLinkingInfo() = default;

void FLinkingInfo::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FLinkingInfo::GetCode() const
{
	return Pimpl->GetCode();
}

const TOptional<FString>& FLinkingInfo::GetQr() const
{
	return Pimpl->GetQr();
}

bool FLinkingInfo::operator==(const FLinkingInfo& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FLinkingInfo::operator!=(const FLinkingInfo& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FLinkingInfo& FLinkingInfo::operator=(const FLinkingInfo& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
