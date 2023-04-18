// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "BaseSchema.h"
#include "Shared/ISharedSchema.h"

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Class for sending requests shared across schemas.
 */
class ENJINSDKCORE_API FSharedSchema : public ISharedSchema,
                                       public FBaseSchema
{
public:
	FSharedSchema() = delete;

	/**
	 * @brief Default destructor.
	 */
	virtual ~FSharedSchema() override = default;

	/**
	 * @brief Sends the CancelTransaction request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<bool>>
	CancelTransaction(const FCancelTransaction& Request) override;

	/**
	 * @brief Sends the GetAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FAsset>>
	GetAsset(const FGetAsset& Request) override;

	/**
	 * @brief Sends the GetAssets request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FAsset>>
	GetAssets(const FGetAssets& Request) override;

	/**
	 * @brief Sends the GetBalances request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FBalance>>
	GetBalances(const FGetBalances& Request) override;

	/**
	 * @brief Sends the GetBalancesFromProjects request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FBalance>>
	GetBalancesFromProjects(const FGetBalancesFromProjects& Request) override;

	/**
	 * @brief Sends the GetGasPrices request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FGasPrices>>
	GetGasPrices(const FGetGasPrices& Request) override;

	/**
	 * @brief Sends the GetPlatform request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FPlatform>>
	GetPlatform(const FGetPlatform& Request) override;

	/**
	 * @brief Sends the GetProject request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FProject>>
	GetProject(const FGetProject& Request) override;

	/**
	 * @brief Sends the GetTransaction request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	GetTransaction(const FGetTransaction& Request) override;

	/**
	 * @brief Sends the GetTransactions request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FTransaction>>
	GetTransactions(const FGetTransactions& Request) override;

protected:
	/**
	 * @brief Constructs an instance of this class.
	 * @param BaseUrl The base URL for the platform.
	 * @param Schema The name of the schema.
	 * @param HttpLogLevel The log level for HTTP traffic.
	 * @param LoggerProvider The logger provider.
	 */
	FSharedSchema(FString BaseUrl,
	              FString Schema,
	              const Http::EHttpLogLevel HttpLogLevel,
	              Util::FLoggerProviderPtr LoggerProvider = nullptr);
};
}
}
}
