// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/TransactionState.h"

using namespace Enjin::Sdk::Model;

const TCHAR* Enjin::Sdk::Model::ToString(const ETransactionState Value)
{
	switch (Value)
	{
		case ETransactionState::Broadcast:
			return TEXT("BROADCAST");

		case ETransactionState::CanceledPlatform:
			return TEXT("CANCELED_PLATFORM");

		case ETransactionState::CanceledUser:
			return TEXT("CANCELED_USER");

		case ETransactionState::Dropped:
			return TEXT("DROPPED");

		case ETransactionState::Executed:
			return TEXT("EXECUTED");

		case ETransactionState::Failed:
			return TEXT("FAILED");

		case ETransactionState::Pending:
			return TEXT("PENDING");

		case ETransactionState::TpProcessing:
			return TEXT("TP_PROCESSING");

		default:
			return TEXT("");
	}
}

ETransactionState Enjin::Sdk::Model::ToTransactionState(const FString& String)
{
	const FString S = String.ToUpper();

	if (S.Equals(TEXT("BROADCAST")))
	{
		return ETransactionState::Broadcast;
	}

	if (S.Equals(TEXT("CANCELED_PLATFORM")))
	{
		return ETransactionState::CanceledPlatform;
	}

	if (S.Equals(TEXT("CANCELED_USER")))
	{
		return ETransactionState::CanceledUser;
	}

	if (S.Equals(TEXT("DROPPED")))
	{
		return ETransactionState::Dropped;
	}

	if (S.Equals(TEXT("EXECUTED")))
	{
		return ETransactionState::Executed;
	}

	if (S.Equals(TEXT("FAILED")))
	{
		return ETransactionState::Failed;
	}

	if (S.Equals(TEXT("PENDING")))
	{
		return ETransactionState::Pending;
	}

	if (S.Equals(TEXT("TP_PROCESSING")))
	{
		return ETransactionState::TpProcessing;
	}

	return ETransactionState::Unknown;
}
