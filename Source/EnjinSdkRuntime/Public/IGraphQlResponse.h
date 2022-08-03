// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "GraphQlError.h"
#include "Model/PaginationCursor.h"

namespace Enjin
{
namespace Sdk
{
namespace GraphQl
{
/**
 * @brief Base class for representing a GraphQL response from the platform.
 */
class ENJINSDKRUNTIME_API IGraphQlResponse
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~IGraphQlResponse() = default;

	/**
	 * @brief Returns the pagination cursor of this response.
	 * @return The cursor.
	 */
	virtual const TOptional<Model::FPaginationCursor>& GetCursor() const = 0;

	/**
	 * @brief Returns the GraphQL errors of this response.
	 * @return The errors.
	 */
	const TOptional<TArray<FGraphQlError>>& GetErrors() const;

	/**
	 * @brief Determines whether this response has errors.
	 * @return Whether this response has errors.
	 */
	bool HasErrors() const;

	/**
	 * @brief Determines whether this response is empty.
	 * @return Whether this response is empty.
	 */
	virtual bool IsEmpty() const = 0;

	/**
	 * @brief Determines whether this response is paginated.
	 * @return Whether this response is paginated.
	 */
	virtual bool IsPaginated() const = 0;

	/**
	 * @brief Determines whether this response is successful.
	 * @return Whether this response is successful.
	 */
	bool IsSuccessful() const;

protected:
	/**
	 * @brief Processes this response from raw JSON input.
	 * @param Json The raw JSON.
	 */
	void Process(const FString& Json);

	/**
	 * @brief Processes the data field of the response.
	 * @param Data The JSON object of the data field.
	 */
	virtual void ProcessData(const TSharedRef<FJsonObject> Data) = 0;

private:
	TOptional<TArray<FGraphQlError>> Errors;
};
}
}
}
