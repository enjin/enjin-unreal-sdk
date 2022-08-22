// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/TransactionType.h"

using namespace Enjin::Sdk::Model;

const TCHAR* Enjin::Sdk::Model::ToString(const ETransactionType Value)
{
	switch (Value)
	{
		case ETransactionType::AcceptAssignment:
			return TEXT("ACCEPT_ASSIGNMENT");

		case ETransactionType::AddLog:
			return TEXT("ADD_LOG");

		case ETransactionType::AdvancedSend:
			return TEXT("ADVANCED_SEND");

		case ETransactionType::Approve:
			return TEXT("APPROVE");

		case ETransactionType::Assign:
			return TEXT("ASSIGN");

		case ETransactionType::CancelTrade:
			return TEXT("CANCEL_TRADE");

		case ETransactionType::Create:
			return TEXT("CREATE");

		case ETransactionType::CreateTrade:
			return TEXT("CREATE_TRADE");

		case ETransactionType::DecreaseMaxMeltFee:
			return TEXT("DECREASE_MAX_MELT_FEE");

		case ETransactionType::DecreaseMaxTransferFee:
			return TEXT("DECREASE_MAX_TRANSFER_FEE");

		case ETransactionType::ManageUpdate:
			return TEXT("MANAGE_UPDATE");

		case ETransactionType::Melt:
			return TEXT("MELT");

		case ETransactionType::Message:
			return TEXT("MESSAGE");

		case ETransactionType::Mint:
			return TEXT("MINT");

		case ETransactionType::ReleaseReserve:
			return TEXT("RELEASE_RESERVE");

		case ETransactionType::Send:
			return TEXT("SEND");

		case ETransactionType::SendEnj:
			return TEXT("SEND_ENJ");

		case ETransactionType::SetApprovalForAll:
			return TEXT("SET_APPROVAL_FOR_ALL");

		case ETransactionType::SetDecimals:
			return TEXT("SET_DECIMALS");

		case ETransactionType::SetItemUri:
			return TEXT("SET_ITEM_URI");

		case ETransactionType::SetMeltFee:
			return TEXT("SET_MELT_FEE");

		case ETransactionType::SetSymbol:
			return TEXT("SET_SYMBOL");

		case ETransactionType::SetTransferFee:
			return TEXT("SET_TRANSFER_FEE");

		case ETransactionType::SetTransferable:
			return TEXT("SET_TRANSFERABLE");

		case ETransactionType::SetWhitelisted:
			return TEXT("SET_WHITELISTED");

		case ETransactionType::UpdateName:
			return TEXT("UPDATE_NAME");

		default:
			return TEXT("");
	}
}

ETransactionType Enjin::Sdk::Model::ToTransactionType(const FString& String)
{
	const FString S = String.ToUpper();

	if (S.Equals(TEXT("ACCEPT_ASSIGNMENT")))
	{
		return ETransactionType::AcceptAssignment;
	}

	if (S.Equals(TEXT("ADD_LOG")))
	{
		return ETransactionType::AddLog;
	}

	if (S.Equals(TEXT("ADVANCED_SEND")))
	{
		return ETransactionType::AdvancedSend;
	}

	if (S.Equals(TEXT("APPROVE")))
	{
		return ETransactionType::Approve;
	}

	if (S.Equals(TEXT("ASSIGN")))
	{
		return ETransactionType::Assign;
	}

	if (S.Equals(TEXT("CANCEL_TRADE")))
	{
		return ETransactionType::CancelTrade;
	}

	if (S.Equals(TEXT("CREATE")))
	{
		return ETransactionType::Create;
	}

	if (S.Equals(TEXT("CREATE_TRADE")))
	{
		return ETransactionType::CreateTrade;
	}

	if (S.Equals(TEXT("DECREASE_MAX_MELT_FEE")))
	{
		return ETransactionType::DecreaseMaxMeltFee;
	}

	if (S.Equals(TEXT("DECREASE_MAX_TRANSFER_FEE")))
	{
		return ETransactionType::DecreaseMaxTransferFee;
	}

	if (S.Equals(TEXT("MANAGE_UPDATE")))
	{
		return ETransactionType::ManageUpdate;
	}

	if (S.Equals(TEXT("MELT")))
	{
		return ETransactionType::Melt;
	}

	if (S.Equals(TEXT("MESSAGE")))
	{
		return ETransactionType::Message;
	}

	if (S.Equals(TEXT("MINT")))
	{
		return ETransactionType::Mint;
	}

	if (S.Equals(TEXT("RELEASE_RESERVE")))
	{
		return ETransactionType::ReleaseReserve;
	}

	if (S.Equals(TEXT("SEND")))
	{
		return ETransactionType::Send;
	}

	if (S.Equals(TEXT("SEND_ENJ")))
	{
		return ETransactionType::SendEnj;
	}

	if (S.Equals(TEXT("SET_APPROVAL_FOR_ALL")))
	{
		return ETransactionType::SetApprovalForAll;
	}

	if (S.Equals(TEXT("SET_DECIMALS")))
	{
		return ETransactionType::SetDecimals;
	}

	if (S.Equals(TEXT("SET_ITEM_URI")))
	{
		return ETransactionType::SetItemUri;
	}

	if (S.Equals(TEXT("SET_MELT_FEE")))
	{
		return ETransactionType::SetMeltFee;
	}

	if (S.Equals(TEXT("SET_SYMBOL")))
	{
		return ETransactionType::SetSymbol;
	}

	if (S.Equals(TEXT("SET_TRANSFER_FEE")))
	{
		return ETransactionType::SetTransferFee;
	}

	if (S.Equals(TEXT("SET_TRANSFERABLE")))
	{
		return ETransactionType::SetTransferable;
	}

	if (S.Equals(TEXT("SET_WHITELISTED")))
	{
		return ETransactionType::SetWhitelisted;
	}

	if (S.Equals(TEXT("UPDATE_NAME")))
	{
		return ETransactionType::UpdateName;
	}

	return ETransactionType::Unknown;
}
