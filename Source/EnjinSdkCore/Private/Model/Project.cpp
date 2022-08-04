// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Project.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FProject::FImpl final : public IDeserializable
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
			Description.Reset();
			Image.Reset();
			Name.Reset();
			UpdatedAt.Reset();
			Uuid.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("createdAt"), CreatedAt);
		FJsonUtil::TryGetField(JsonRef, TEXT("description"), Description);
		FJsonUtil::TryGetField(JsonRef, TEXT("image"), Image);
		FJsonUtil::TryGetField(JsonRef, TEXT("name"), Name);
		FJsonUtil::TryGetField(JsonRef, TEXT("updatedAt"), UpdatedAt);
		FJsonUtil::TryGetField(JsonRef, TEXT("uuid"), Uuid);
	}

	const TOptional<FString>& GetCreatedAt() const
	{
		return CreatedAt;
	}

	const TOptional<FString>& GetDescription() const
	{
		return Description;
	}

	const TOptional<FString>& GetImage() const
	{
		return Image;
	}

	const TOptional<FString>& GetName() const
	{
		return Name;
	}

	const TOptional<FString>& GetUpdatedAt() const
	{
		return UpdatedAt;
	}

	const TOptional<FString>& GetUuid() const
	{
		return Uuid;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return CreatedAt == Rhs.CreatedAt
			&& Description == Rhs.Description
			&& Image == Rhs.Image
			&& Name == Rhs.Name
			&& UpdatedAt == Rhs.UpdatedAt
			&& Uuid == Rhs.Uuid;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<FString> CreatedAt;
	TOptional<FString> Description;
	TOptional<FString> Image;
	TOptional<FString> Name;
	TOptional<FString> UpdatedAt;
	TOptional<FString> Uuid;
};

FProject::FProject() : Pimpl(MakeUnique<FImpl>())
{
}

FProject::FProject(const FProject& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FProject::FProject(FProject&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FProject::~FProject() = default;

void FProject::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<FString>& FProject::GetCreatedAt() const
{
	return Pimpl->GetCreatedAt();
}

const TOptional<FString>& FProject::GetDescription() const
{
	return Pimpl->GetDescription();
}

const TOptional<FString>& FProject::GetImage() const
{
	return Pimpl->GetImage();
}

const TOptional<FString>& FProject::GetName() const
{
	return Pimpl->GetName();
}

const TOptional<FString>& FProject::GetUpdatedAt() const
{
	return Pimpl->GetUpdatedAt();
}

const TOptional<FString>& FProject::GetUuid() const
{
	return Pimpl->GetUuid();
}

bool FProject::operator==(const FProject& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FProject::operator!=(const FProject& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FProject& FProject::operator=(const FProject& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
