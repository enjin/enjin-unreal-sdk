// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/TransactionType.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FTransactionTypeSpec,
                  "Enjin.Sdk.Model.TransactionType",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FTransactionTypeSpec)

void FTransactionTypeSpec::Define()
{
	Describe("ToTransactionType returns correct value for given parameter", [this]()
	{
		TArray<TPair<FString, ETransactionType>> Params =
		{
			TPair<FString, ETransactionType>(TEXT(""), ETransactionType::Unknown),
			TPair<FString, ETransactionType>(TEXT("ACCEPT_ASSIGNMENT"), ETransactionType::AcceptAssignment),
			TPair<FString, ETransactionType>(TEXT("ADD_LOG"), ETransactionType::AddLog),
			TPair<FString, ETransactionType>(TEXT("ADVANCED_SEND"), ETransactionType::AdvancedSend),
			TPair<FString, ETransactionType>(TEXT("APPROVE"), ETransactionType::Approve),
			TPair<FString, ETransactionType>(TEXT("ASSIGN"), ETransactionType::Assign),
			TPair<FString, ETransactionType>(TEXT("CANCEL_TRADE"), ETransactionType::CancelTrade),
			TPair<FString, ETransactionType>(TEXT("CREATE"), ETransactionType::Create),
			TPair<FString, ETransactionType>(TEXT("CREATE_TRADE"), ETransactionType::CreateTrade),
			TPair<FString, ETransactionType>(TEXT("DECREASE_MAX_MELT_FEE"), ETransactionType::DecreaseMaxMeltFee),
			TPair<FString, ETransactionType>(TEXT("DECREASE_MAX_TRANSFER_FEE"),
			                                 ETransactionType::DecreaseMaxTransferFee),
			TPair<FString, ETransactionType>(TEXT("MANAGE_UPDATE"), ETransactionType::ManageUpdate),
			TPair<FString, ETransactionType>(TEXT("MELT"), ETransactionType::Melt),
			TPair<FString, ETransactionType>(TEXT("MESSAGE"), ETransactionType::Message),
			TPair<FString, ETransactionType>(TEXT("MINT"), ETransactionType::Mint),
			TPair<FString, ETransactionType>(TEXT("RELEASE_RESERVE"), ETransactionType::ReleaseReserve),
			TPair<FString, ETransactionType>(TEXT("SEND"), ETransactionType::Send),
			TPair<FString, ETransactionType>(TEXT("SEND_ENJ"), ETransactionType::SendEnj),
			TPair<FString, ETransactionType>(TEXT("SET_APPROVAL_FOR_ALL"), ETransactionType::SetApprovalForAll),
			TPair<FString, ETransactionType>(TEXT("SET_DECIMALS"), ETransactionType::SetDecimals),
			TPair<FString, ETransactionType>(TEXT("SET_ITEM_URI"), ETransactionType::SetItemUri),
			TPair<FString, ETransactionType>(TEXT("SET_MELT_FEE"), ETransactionType::SetMeltFee),
			TPair<FString, ETransactionType>(TEXT("SET_SYMBOL"), ETransactionType::SetSymbol),
			TPair<FString, ETransactionType>(TEXT("SET_TRANSFER_FEE"), ETransactionType::SetTransferFee),
			TPair<FString, ETransactionType>(TEXT("SET_TRANSFERABLE"), ETransactionType::SetTransferable),
			TPair<FString, ETransactionType>(TEXT("SET_WHITELISTED"), ETransactionType::SetWhitelisted),
			TPair<FString, ETransactionType>(TEXT("UPDATE_NAME"), ETransactionType::UpdateName),
		};

		for (const TPair<FString, ETransactionType> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Key), [this, Param]()
			{
				// Arrange
				const ETransactionType Expected = Param.Value;
				const FString Input = Param.Key;

				// Act
				const ETransactionType Actual = ToTransactionType(Input);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});

	Describe("ToString returns correct value for given parameter", [this]()
	{
		TArray<TPair<ETransactionType, FString>> Params =
		{
			TPair<ETransactionType, FString>(ETransactionType::Unknown, TEXT("")),
			TPair<ETransactionType, FString>(ETransactionType::AcceptAssignment, TEXT("ACCEPT_ASSIGNMENT")),
			TPair<ETransactionType, FString>(ETransactionType::AddLog, TEXT("ADD_LOG")),
			TPair<ETransactionType, FString>(ETransactionType::AdvancedSend, TEXT("ADVANCED_SEND")),
			TPair<ETransactionType, FString>(ETransactionType::Approve, TEXT("APPROVE")),
			TPair<ETransactionType, FString>(ETransactionType::Assign, TEXT("ASSIGN")),
			TPair<ETransactionType, FString>(ETransactionType::CancelTrade, TEXT("CANCEL_TRADE")),
			TPair<ETransactionType, FString>(ETransactionType::Create, TEXT("CREATE")),
			TPair<ETransactionType, FString>(ETransactionType::CreateTrade, TEXT("CREATE_TRADE")),
			TPair<ETransactionType, FString>(ETransactionType::DecreaseMaxMeltFee, TEXT("DECREASE_MAX_MELT_FEE")),
			TPair<ETransactionType, FString>(ETransactionType::DecreaseMaxTransferFee,
			                                 TEXT("DECREASE_MAX_TRANSFER_FEE")),
			TPair<ETransactionType, FString>(ETransactionType::ManageUpdate, TEXT("MANAGE_UPDATE")),
			TPair<ETransactionType, FString>(ETransactionType::Melt, TEXT("MELT")),
			TPair<ETransactionType, FString>(ETransactionType::Message, TEXT("MESSAGE")),
			TPair<ETransactionType, FString>(ETransactionType::Mint, TEXT("MINT")),
			TPair<ETransactionType, FString>(ETransactionType::ReleaseReserve, TEXT("RELEASE_RESERVE")),
			TPair<ETransactionType, FString>(ETransactionType::Send, TEXT("SEND")),
			TPair<ETransactionType, FString>(ETransactionType::SendEnj, TEXT("SEND_ENJ")),
			TPair<ETransactionType, FString>(ETransactionType::SetApprovalForAll, TEXT("SET_APPROVAL_FOR_ALL")),
			TPair<ETransactionType, FString>(ETransactionType::SetDecimals, TEXT("SET_DECIMALS")),
			TPair<ETransactionType, FString>(ETransactionType::SetItemUri, TEXT("SET_ITEM_URI")),
			TPair<ETransactionType, FString>(ETransactionType::SetMeltFee, TEXT("SET_MELT_FEE")),
			TPair<ETransactionType, FString>(ETransactionType::SetSymbol, TEXT("SET_SYMBOL")),
			TPair<ETransactionType, FString>(ETransactionType::SetTransferFee, TEXT("SET_TRANSFER_FEE")),
			TPair<ETransactionType, FString>(ETransactionType::SetTransferable, TEXT("SET_TRANSFERABLE")),
			TPair<ETransactionType, FString>(ETransactionType::SetWhitelisted, TEXT("SET_WHITELISTED")),
			TPair<ETransactionType, FString>(ETransactionType::UpdateName, TEXT("UPDATE_NAME")),
		};

		for (const TPair<ETransactionType, FString> Param : Params)
		{
			It(FString::Printf(TEXT("should resolve '%s'"), *Param.Value), [this, Param]()
			{
				// Arrange
				const FString Expected = Param.Value;
				const ETransactionType EnumValue = Param.Key;

				// Act
				const FString Actual = ToString(EnumValue);

				// Assert
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			});
		}
	});
}
