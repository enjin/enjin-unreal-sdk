// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/PaginationCursor.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FPaginationCursor::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			CurrentPage.Reset();
			From.Reset();
			HasMorePages.Reset();
			HasPages.Reset();
			LastPage.Reset();
			PerPage.Reset();
			To.Reset();
			Total.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("currentPage"), CurrentPage);
		FJsonUtil::TryGetField(JsonRef, TEXT("from"), From);
		FJsonUtil::TryGetField(JsonRef, TEXT("hasMorePages"), HasMorePages);
		FJsonUtil::TryGetField(JsonRef, TEXT("hasPages"), HasPages);
		FJsonUtil::TryGetField(JsonRef, TEXT("lastPage"), LastPage);
		FJsonUtil::TryGetField(JsonRef, TEXT("perPage"), PerPage);
		FJsonUtil::TryGetField(JsonRef, TEXT("to"), To);
		FJsonUtil::TryGetField(JsonRef, TEXT("total"), Total);
	}

	const TOptional<int32>& GetCurrentPage() const
	{
		return CurrentPage;
	}

	const TOptional<int32>& GetFrom() const
	{
		return From;
	}

	const TOptional<bool>& GetHasMorePages() const
	{
		return HasMorePages;
	}

	const TOptional<bool>& GetHasPages() const
	{
		return HasPages;
	}

	const TOptional<int32>& GetLastPage() const
	{
		return LastPage;
	}

	const TOptional<int32>& GetPerPage() const
	{
		return PerPage;
	}

	const TOptional<int32>& GetTo() const
	{
		return To;
	}

	const TOptional<int32>& GetTotal() const
	{
		return Total;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return CurrentPage == Rhs.CurrentPage
			&& From == Rhs.From
			&& HasMorePages == Rhs.HasMorePages
			&& HasPages == Rhs.HasPages
			&& LastPage == Rhs.LastPage
			&& PerPage == Rhs.PerPage
			&& To == Rhs.To
			&& Total == Rhs.Total;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<int32> CurrentPage;
	TOptional<int32> From;
	TOptional<bool> HasMorePages;
	TOptional<bool> HasPages;
	TOptional<int32> LastPage;
	TOptional<int32> PerPage;
	TOptional<int32> To;
	TOptional<int32> Total;
};

FPaginationCursor::FPaginationCursor() : Pimpl(MakeUnique<FImpl>())
{
}

FPaginationCursor::FPaginationCursor(const FPaginationCursor& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FPaginationCursor::FPaginationCursor(FPaginationCursor&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FPaginationCursor::~FPaginationCursor() = default;

void FPaginationCursor::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<int32>& FPaginationCursor::GetCurrentPage() const
{
	return Pimpl->GetCurrentPage();
}

const TOptional<int32>& FPaginationCursor::GetFrom() const
{
	return Pimpl->GetFrom();
}

const TOptional<bool>& FPaginationCursor::GetHasMorePages() const
{
	return Pimpl->GetHasMorePages();
}

const TOptional<bool>& FPaginationCursor::GetHasPages() const
{
	return Pimpl->GetHasPages();
}

const TOptional<int32>& FPaginationCursor::GetLastPage() const
{
	return Pimpl->GetLastPage();
}

const TOptional<int32>& FPaginationCursor::GetPerPage() const
{
	return Pimpl->GetPerPage();
}

const TOptional<int32>& FPaginationCursor::GetTo() const
{
	return Pimpl->GetTo();
}

const TOptional<int32>& FPaginationCursor::GetTotal() const
{
	return Pimpl->GetTotal();
}

bool FPaginationCursor::operator==(const FPaginationCursor& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FPaginationCursor::operator!=(const FPaginationCursor& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FPaginationCursor& FPaginationCursor::operator=(const FPaginationCursor& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
