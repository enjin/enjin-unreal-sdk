// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/Operator.h"

using namespace Enjin::Sdk::Model;

const TCHAR* Enjin::Sdk::Model::ToString(const EOperator Value)
{
	switch (Value)
	{
		case EOperator::GreaterThan:
			return TEXT("GREATER_THAN");

		case EOperator::GreaterThanOrEqual:
			return TEXT("GREATER_THAN_OR_EQUAL");

		case EOperator::LessThan:
			return TEXT("LESS_THAN");

		case EOperator::LessThanOrEqual:
			return TEXT("LESS_THAN_OR_EQUAL");

		default:
			return TEXT("");
	}
}
