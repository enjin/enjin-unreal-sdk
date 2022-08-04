// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/SortDirection.h"

using namespace Enjin::Sdk::Model;

const TCHAR* Enjin::Sdk::Model::ToString(const ESortDirection Value)
{
	switch (Value)
	{
		case ESortDirection::Ascending:
			return TEXT("asc");

		case ESortDirection::Descending:
			return TEXT("desc");

		default:
			return TEXT("");
	}
}
