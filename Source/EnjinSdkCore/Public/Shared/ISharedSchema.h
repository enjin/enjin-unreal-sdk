// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "GraphQlResponse.h"
#include "Model/Asset.h"
#include "Model/Balance.h"
#include "Model/GasPrices.h"
#include "Model/Platform.h"
#include "Model/Project.h"
#include "Model/Transaction.h"
#include "Shared/CancelTransaction.h"
#include "Shared/GetAsset.h"
#include "Shared/GetAssets.h"
#include "Shared/GetBalances.h"
#include "Shared/GetGasPrices.h"
#include "Shared/GetPlatform.h"
#include "Shared/GetProject.h"
#include "Shared/GetTransaction.h"
#include "Shared/GetTransactions.h"

namespace Enjin
{
namespace Sdk
{
namespace Shared
{
/**
 * @brief Interface for shared schema.
 */
class ENJINSDKCORE_API ISharedSchema
{
public:
	/**
	 * @brief Default destructor.
	 */
	virtual ~ISharedSchema() = default;

	/**
	 * @brief Sends the CancelTransaction request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<bool>>
	CancelTransaction(const FCancelTransaction& Request) = 0;

	/**
	 * @brief Sends the GetAsset request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FAsset>>
	GetAsset(const FGetAsset& Request) = 0;

	/**
	 * @brief Sends the GetAssets request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FAsset>>
	GetAssets(const FGetAssets& Request) = 0;

	/**
	 * @brief Sends the GetBalances request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FBalance>>
	GetBalances(const FGetBalances& Request) = 0;

	/**
	 * @brief Sends the GetGasPrices request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FGasPrices>>
	GetGasPrices(const FGetGasPrices& Request) = 0;

	/**
	 * @brief Sends the GetPlatform request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FPlatform>>
	GetPlatform(const FGetPlatform& Request) = 0;

	/**
	 * @brief Sends the GetProject request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FProject>>
	GetProject(const FGetProject& Request) = 0;

	/**
	 * @brief Sends the GetTransaction request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForOnePtr<Model::FTransaction>>
	GetTransaction(const FGetTransaction& Request) = 0;

	/**
	 * @brief Sends the GetTransactions request to the platform.
	 * @param Request The request.
	 * @return The future containing the response.
	 */
	virtual TFuture<GraphQl::TGraphQlResponseForManyPtr<Model::FTransaction>>
	GetTransactions(const FGetTransactions& Request) = 0;
};
}
}
}
