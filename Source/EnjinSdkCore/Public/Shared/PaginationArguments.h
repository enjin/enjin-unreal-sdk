// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "ISerializable.h"
#include "JsonUtil.h"
#include "Model/PaginationInput.h"
#include <type_traits>

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Fragment interface to set options for a pagination returned by the platform.
 * @tparam T The type of the implementing class.
 */
template <class T>
class ENJINSDKCORE_API TPaginationArguments : public Serialization::ISerializable
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~TPaginationArguments() override = default;

	/**
	 * @brief Returns the raw JSON representation of this instance.
	 * @return The raw JSON.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual FString Serialize() const override
	{
		return Util::FJsonUtil::SerializeJsonObject(ToJson());
	}

	/**
	 * @brief Sets the pagination input.
	 * @param Pagination The pagination input.
	 * @return This request for chaining.
	 */
	T& SetPagination(Model::FPaginationInput Pagination)
	{
		PaginationOpt.Emplace(MoveTemp(Pagination));
		return static_cast<T&>(*this);
	}

	/**
	 * @brief Sets the pagination input.
	 * @param Page The page to start on.
	 * @param Limit The number of items per page.
	 * @return This request for chaining.
	 */
	T& SetPagination(const int32 Page, const int32 Limit)
	{
		return SetPagination(Model::FPaginationInput().SetPage(Page).SetLimit(Limit));
	}

	/**
	 * @brief Returns a JSON object representing this instance.
	 * @return The JSON object.
	 * @remark Fields that would result in null JSON values are omitted.
	 */
	virtual TSharedRef<FJsonObject> ToJson() const override
	{
		TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

		Util::FJsonUtil::TrySetField(JsonRef, TEXT("pagination"), PaginationOpt);

		return JsonRef;
	}

	bool operator==(const TPaginationArguments& Rhs) const
	{
		return PaginationOpt == Rhs.PaginationOpt;
	}

	bool operator!=(const TPaginationArguments& Rhs) const
	{
		return !(*this == Rhs);
	}

protected:
	/**
	 * @brief Constructor for this interface. Asserts that the T parameter implements this interface.
	 */
	TPaginationArguments()
	{
		static_assert(std::is_base_of<TPaginationArguments, T>::value,
			"Class T must inherit from TPaginationArguments");
	}

private:
	TOptional<Model::FPaginationInput> PaginationOpt;
};
}
}
}
