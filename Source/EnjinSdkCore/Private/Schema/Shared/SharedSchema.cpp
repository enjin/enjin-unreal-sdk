// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Shared/SharedSchema.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Http;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Shared;
using namespace Enjin::Sdk::Util;

FSharedSchema::FSharedSchema(FString BaseUrl,
                             FString Schema,
                             const EHttpLogLevel HttpLogLevel,
                             FLoggerProviderPtr LoggerProvider)
	: FBaseSchema(MoveTemp(BaseUrl), MoveTemp(Schema), HttpLogLevel, MoveTemp(LoggerProvider))
{
}

TFuture<TGraphQlResponseForOnePtr<FAsset>> FSharedSchema::GetAsset(const FGetAsset& Request)
{
	return SendRequestForOne<FAsset>(Request);
}

TFuture<TGraphQlResponseForManyPtr<FAsset>> FSharedSchema::GetAssets(const FGetAssets& Request)
{
	return SendRequestForMany<FAsset>(Request);
}

TFuture<TGraphQlResponseForOnePtr<bool>> FSharedSchema::CancelTransaction(const FCancelTransaction& Request)
{
	return SendRequestForOne<bool>(Request);
}

TFuture<TGraphQlResponseForManyPtr<FBalance>> FSharedSchema::GetBalances(const FGetBalances& Request)
{
	return SendRequestForMany<FBalance>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FGasPrices>> FSharedSchema::GetGasPrices(const FGetGasPrices& Request)
{
	return SendRequestForOne<FGasPrices>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FPlatform>> FSharedSchema::GetPlatform(const FGetPlatform& Request)
{
	return SendRequestForOne<FPlatform>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FProject>> FSharedSchema::GetProject(const FGetProject& Request)
{
	return SendRequestForOne<FProject>(Request);
}

TFuture<TGraphQlResponseForOnePtr<FTransaction>> FSharedSchema::GetTransaction(const FGetTransaction& Request)
{
	return SendRequestForOne<FTransaction>(Request);
}

TFuture<TGraphQlResponseForManyPtr<FTransaction>> FSharedSchema::GetTransactions(const FGetTransactions& Request)
{
	return SendRequestForMany<FTransaction>(Request);
}
