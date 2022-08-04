// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a pagination cursor for queries.
 */
class ENJINSDKCORE_API FPaginationCursor final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FPaginationCursor();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FPaginationCursor(const FPaginationCursor& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FPaginationCursor(FPaginationCursor&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FPaginationCursor() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the current page of this cursor.
	 * @return The current page.
	 */
	const TOptional<int32>& GetCurrentPage() const;

	/**
	 * @brief Returns the first item returned for this cursor.
	 * @return The first item returned.
	 */
	const TOptional<int32>& GetFrom() const;

	/**
	 * @brief Returns whether there are more pages for this cursor.
	 * @return Whether the cursor has more pages.
	 */
	const TOptional<bool>& GetHasMorePages() const;

	/**
	 * @brief Returns whether this cursor has pages.
	 * @return Whether this cursor has pages.
	 */
	const TOptional<bool>& GetHasPages() const;

	/**
	 * @brief Returns the last page (and number of pages) for this cursor.
	 * @return The last page number.
	 */
	const TOptional<int32>& GetLastPage() const;

	/**
	 * @brief Returns the number of items per page for this cursor.
	 * @return The number items per page.
	 */
	const TOptional<int32>& GetPerPage() const;

	/**
	 * @brief Returns the last item returned for this cursor.
	 * @return The last item returned.
	 */
	const TOptional<int32>& GetTo() const;

	/**
	 * @brief Returns the total number of items selected by this cursor.
	 * @return The total number of items.
	 */
	const TOptional<int32>& GetTotal() const;

	bool operator==(const FPaginationCursor& Rhs) const;

	bool operator!=(const FPaginationCursor& Rhs) const;

	FPaginationCursor& operator=(const FPaginationCursor& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
