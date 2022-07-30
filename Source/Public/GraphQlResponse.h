// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "IGraphQlResponse.h"
#include "JsonUtil.h"
#include <type_traits>

namespace Enjin
{
namespace Sdk
{
namespace GraphQl
{
/**
 * @brief Variadic template for GraphQL responses.
 */
template <class ...>
class ENJINSDK_API TGraphQlResponse;

/**
 * @brief Models the body of a GraphQL response for responses with a single result.
 * @tparam T The model of the data field.
 */
template <class T>
class ENJINSDK_API TGraphQlResponse<T> final : public IGraphQlResponse
{
	static_assert(std::is_base_of_v<Serialization::IDeserializable, T> || std::is_same_v<bool, T>,
		"Class T must inherit from IDeserializable or be type boolean.");

public:
	TGraphQlResponse() = delete;

	/**
	 * @brief Constructs an instance of this class populated with the raw JSON.
	 * @param Json The raw JSON.
	 */
	explicit TGraphQlResponse(const FString& Json)
	{
		Process(Json);
	}

	/**
	 * @brief Default destructor.
	 */
	virtual ~TGraphQlResponse() override = default;

	/**
	 * @brief Returns the pagination cursor of this response.
	 * @return The cursor.
	 */
	virtual const TOptional<Model::FPaginationCursor>& GetCursor() const override
	{
		return EmptyCursor;
	}

	/**
	 * @brief Returns the result for this response.
	 * @return The result.
	 */
	const TOptional<T>& GetResult() const
	{
		return Result;
	}

	/**
	 * @brief Determines whether this response is empty.
	 * @return Whether this response is empty.
	 */
	virtual bool IsEmpty() const override
	{
		return !Result.IsSet();
	}

	/**
	 * @brief Determines whether this response is paginated.
	 * @return Whether this response is paginated.
	 */
	virtual bool IsPaginated() const override
	{
		return false;
	}

protected:
	/**
	 * @brief Processes the response data to set the result of this response.
	 * @param Data The data object.
	 */
	virtual void ProcessData(const TSharedRef<FJsonObject> Data) override
	{
		T NewResult;
		if (Util::FJsonUtil::TryGetObjectAsType(Data, TEXT("result"), NewResult))
		{
			Result.Emplace(MoveTemp(NewResult));
		}
	}

private:
	const TOptional<Model::FPaginationCursor> EmptyCursor;
	TOptional<T> Result;
};

template <>
inline void TGraphQlResponse<bool>::ProcessData(const TSharedRef<FJsonObject> Data)
{
	bool NewResult;
	if (Data->TryGetBoolField(TEXT("result"), NewResult))
	{
		Result.Emplace(NewResult);
	}
}

/**
 * @brief Models the body of a GraphQL response for responses with many results.
 * @tparam T The model of the data field.
 */
template <class T>
class ENJINSDK_API TGraphQlResponse<TArray<T>> final : public IGraphQlResponse
{
	static_assert(std::is_base_of_v<Serialization::IDeserializable, T>,
		"Class T must inherit from IDeserializable.");

public:
	TGraphQlResponse() = delete;

	/**
	 * @brief Constructs an instance of this class populated with the raw JSON.
	 * @param Json The raw JSON.
	 */
	explicit TGraphQlResponse(const FString& Json)
	{
		Process(Json);
	}

	/**
	 * @brief Default destructor.
	 */
	virtual ~TGraphQlResponse() override = default;

	/**
	 * @brief Returns the pagination cursor of this response.
	 * @return The cursor.
	 */
	virtual const TOptional<Model::FPaginationCursor>& GetCursor() const override
	{
		return Cursor;
	}

	/**
	 * @brief Returns the result for this response.
	 * @return The result.
	 */
	const TOptional<TArray<T>>& GetResult() const
	{
		return Result;
	}

	/**
	 * @brief Determines whether this response is empty.
	 * @return Whether this response is empty.
	 */
	virtual bool IsEmpty() const override
	{
		return !Result.IsSet();
	}

	/**
	 * @brief Determines whether this response is paginated.
	 * @return Whether this response is paginated.
	 */
	virtual bool IsPaginated() const override
	{
		return Cursor.IsSet();
	}

protected:
	/**
	 * @brief Processes the response data to form the result and pagination cursor of this response.
	 * @param Data The data object.
	 */
	virtual void ProcessData(const TSharedRef<FJsonObject> Data) override
	{
		if (IsResultPaginated(Data))
		{
			ProcessPaginatedResult(Data);
		}
		else
		{
			ProcessNonPaginatedResult(Data);
		}
	}

private:
	TOptional<Model::FPaginationCursor> Cursor;
	TOptional<TArray<T>> Result;

	/**
	 * @brief Processes non-paginated data to form the result.
	 * @param Data The data object.
	 */
	void ProcessNonPaginatedResult(const TSharedRef<FJsonObject> Data)
	{
		TArray<T> NewResult;
		if (Util::FJsonUtil::TryGetArrayAsTypeArray(Data, TEXT("result"), NewResult))
		{
			Result.Emplace(MoveTemp(NewResult));
		}
	}

	/**
	 * @brief Processes paginated data to form the result and pagination cursor.
	 * @param Data The data object.
	 */
	void ProcessPaginatedResult(const TSharedRef<FJsonObject> Data)
	{
		const TSharedPtr<FJsonObject>* ResultObject;

		if (!Data->TryGetObjectField(TEXT("result"), ResultObject))
		{
			return;
		}

		const TSharedRef<FJsonObject> ResultObjectRef = ResultObject->ToSharedRef();

		Model::FPaginationCursor NewCursor;
		if (Util::FJsonUtil::TryGetObjectAsType(ResultObjectRef, TEXT("cursor"), NewCursor))
		{
			Cursor.Emplace(MoveTemp(NewCursor));
		}

		TArray<T> NewResult;
		if (Util::FJsonUtil::TryGetArrayAsTypeArray(ResultObjectRef, TEXT("items"), NewResult))
		{
			Result.Emplace(MoveTemp(NewResult));
		}
	}

	/**
	 * @brief Determines whether the data is paginated.
	 * @param Data The data object.
	 * @return Whether the data is paginated.
	 */
	static bool IsResultPaginated(const TSharedRef<FJsonObject> Data)
	{
		const TSharedPtr<FJsonObject>* ResultObject;

		if (Data->TryGetObjectField(TEXT("result"), ResultObject))
		{
			return ResultObject->Get()->HasTypedField<EJson::Object>(TEXT("cursor"));
		}

		return false;
	}
};

/**
 * @brief Alias for GraphQL responses containing one result.
 * @tparam T The type contained within the response.
 */
template <class T>
using TGraphQlResponseForOne = TGraphQlResponse<T>;

/**
 * @brief Alias for GraphQL responses containing many results.
 * @tparam T The type contained within the response.
 */
template <class T>
using TGraphQlResponseForMany = TGraphQlResponse<TArray<T>>;

/**
 * @brief Alias for shared-pointers of GraphQL responses containing one result.
 * @tparam T The type contained within the response.
 */
template <class T>
using TGraphQlResponseForOnePtr = TSharedPtr<TGraphQlResponseForOne<T>, ESPMode::ThreadSafe>;

/**
 * @brief Alias for shared-pointers of GraphQL responses containing many results.
 * @tparam T The type contained within the response.
 */
template <class T>
using TGraphQlResponseForManyPtr = TSharedPtr<TGraphQlResponseForMany<T>, ESPMode::ThreadSafe>;
}
}
}
