// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "IGraphQlRequest.h"

using namespace Enjin::Sdk::GraphQl;

IGraphQlRequest::IGraphQlRequest(FString Namespace) : Namespace(MoveTemp(Namespace))
{
}

const FString& IGraphQlRequest::GetNamespace() const
{
	return Namespace;
}

bool IGraphQlRequest::operator==(const IGraphQlRequest& Rhs) const
{
	return Namespace == Rhs.Namespace;
}

bool IGraphQlRequest::operator!=(const IGraphQlRequest& Rhs) const
{
	return Namespace == Rhs.Namespace;
}
