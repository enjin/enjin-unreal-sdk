// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/TransactionField.h"

using namespace Enjin::Sdk::Model;

const TCHAR* Enjin::Sdk::Model::ToString(const ETransactionField Value)
{
	switch (Value)
	{
		case ETransactionField::CreatedAt:
			return TEXT("createdAt");

		case ETransactionField::Id:
			return TEXT("id");

		case ETransactionField::State:
			return TEXT("state");

		case ETransactionField::Title:
			return TEXT("title");

		case ETransactionField::UpdatedAt:
			return TEXT("updatedAt");

		default:
			return TEXT("");
	}
}
