// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Model/AssetStateData.h"

#include "JsonUtil.h"

using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;

class FAssetStateData::FImpl final : public IDeserializable
{
public:
	FImpl() = default;

	virtual ~FImpl() override = default;

	virtual void Deserialize(const FString& Json) override
	{
		TSharedPtr<FJsonObject> JsonObject;
		if (!FJsonUtil::TryParseJsonObject(Json, JsonObject))
		{
			BlockHeight.Reset();
			CirculatingSupply.Reset();
			Creator.Reset();
			FirstBlock.Reset();
			MintableSupply.Reset();
			NonFungible.Reset();
			Reserve.Reset();
			SupplyModel.Reset();
			TotalSupply.Reset();

			return;
		}

		const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

		FJsonUtil::TryGetField(JsonRef, TEXT("blockHeight"), BlockHeight);
		FJsonUtil::TryGetField(JsonRef, TEXT("circulatingSupply"), CirculatingSupply);
		FJsonUtil::TryGetField(JsonRef, TEXT("creator"), Creator);
		FJsonUtil::TryGetField(JsonRef, TEXT("firstBlock"), FirstBlock);
		FJsonUtil::TryGetField(JsonRef, TEXT("mintableSupply"), MintableSupply);
		FJsonUtil::TryGetField(JsonRef, TEXT("nonFungible"), NonFungible);
		FJsonUtil::TryGetField(JsonRef, TEXT("reserve"), Reserve);
		FJsonUtil::TryGetField(JsonRef, TEXT("supplyModel"), SupplyModel);
		FJsonUtil::TryGetField(JsonRef, TEXT("totalSupply"), TotalSupply);
	}

	const TOptional<int32>& GetBlockHeight() const
	{
		return BlockHeight;
	}

	const TOptional<FString>& GetCirculatingSupply() const
	{
		return CirculatingSupply;
	}

	const TOptional<FString>& GetCreator() const
	{
		return Creator;
	}

	const TOptional<int32>& GetFirstBlock() const
	{
		return FirstBlock;
	}

	const TOptional<FString>& GetMintableSupply() const
	{
		return MintableSupply;
	}

	const TOptional<bool>& GetNonFungible() const
	{
		return NonFungible;
	}

	const TOptional<FString>& GetReserve() const
	{
		return Reserve;
	}

	const TOptional<EAssetSupplyModel>& GetSupplyModel() const
	{
		return SupplyModel;
	}

	const TOptional<FString>& GetTotalSupply() const
	{
		return TotalSupply;
	}

	bool operator==(const FImpl& Rhs) const
	{
		return BlockHeight == Rhs.BlockHeight
			&& CirculatingSupply == Rhs.CirculatingSupply
			&& Creator == Rhs.Creator
			&& FirstBlock == Rhs.FirstBlock
			&& MintableSupply == Rhs.MintableSupply
			&& NonFungible == Rhs.NonFungible
			&& Reserve == Rhs.Reserve
			&& SupplyModel == Rhs.SupplyModel
			&& TotalSupply == Rhs.TotalSupply;
	}

	bool operator!=(const FImpl& Rhs) const
	{
		return !(*this == Rhs);
	}

private:
	TOptional<int32> BlockHeight;
	TOptional<FString> CirculatingSupply;
	TOptional<FString> Creator;
	TOptional<int32> FirstBlock;
	TOptional<FString> MintableSupply;
	TOptional<bool> NonFungible;
	TOptional<FString> Reserve;
	TOptional<EAssetSupplyModel> SupplyModel;
	TOptional<FString> TotalSupply;
};

FAssetStateData::FAssetStateData() : Pimpl(MakeUnique<FImpl>())
{
}

FAssetStateData::FAssetStateData(const FAssetStateData& Other) : Pimpl(MakeUnique<FImpl>(*Other.Pimpl))
{
}

FAssetStateData::FAssetStateData(FAssetStateData&& Other) noexcept : Pimpl(MoveTemp(Other.Pimpl))
{
}

FAssetStateData::~FAssetStateData() = default;

void FAssetStateData::Deserialize(const FString& Json)
{
	Pimpl->Deserialize(Json);
}

const TOptional<int32>& FAssetStateData::GetBlockHeight() const
{
	return Pimpl->GetBlockHeight();
}

const TOptional<FString>& FAssetStateData::GetCirculatingSupply() const
{
	return Pimpl->GetCirculatingSupply();
}

const TOptional<FString>& FAssetStateData::GetCreator() const
{
	return Pimpl->GetCreator();
}

const TOptional<int32>& FAssetStateData::GetFirstBlock() const
{
	return Pimpl->GetFirstBlock();
}

const TOptional<FString>& FAssetStateData::GetMintableSupply() const
{
	return Pimpl->GetMintableSupply();
}

const TOptional<bool>& FAssetStateData::GetNonFungible() const
{
	return Pimpl->GetNonFungible();
}

const TOptional<FString>& FAssetStateData::GetReserve() const
{
	return Pimpl->GetReserve();
}

const TOptional<EAssetSupplyModel>& FAssetStateData::GetSupplyModel() const
{
	return Pimpl->GetSupplyModel();
}

const TOptional<FString>& FAssetStateData::GetTotalSupply() const
{
	return Pimpl->GetTotalSupply();
}

bool FAssetStateData::operator==(const FAssetStateData& Rhs) const
{
	return *Pimpl == *Rhs.Pimpl;
}

bool FAssetStateData::operator!=(const FAssetStateData& Rhs) const
{
	return *Pimpl != *Rhs.Pimpl;
}

FAssetStateData& FAssetStateData::operator=(const FAssetStateData& Rhs)
{
	Pimpl = MakeUnique<FImpl>(*Rhs.Pimpl);
	return *this;
}
