// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"
#include "Model/AssetSupplyModel.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models the state data of a asset.
 */
class ENJINSDKRUNTIME_API FAssetStateData final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FAssetStateData();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FAssetStateData(const FAssetStateData& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FAssetStateData(FAssetStateData&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FAssetStateData() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the block number of the last update.
	 * @return The block number.
	 */
	const TOptional<int32>& GetBlockHeight() const;

	/**
	 * @brief Returns the amount of the asset in circulation.
	 * @return The amount in circulation.
	 */
	const TOptional<FString>& GetCirculatingSupply() const;

	/**
	 * @brief Returns the wallet address of the creator of the asset.
	 * @return The creator's wallet address.
	 */
	const TOptional<FString>& GetCreator() const;

	/**
	 * @brief Returns the first block the asset appeared on.
	 * @return The block number.
	 */
	const TOptional<int32>& GetFirstBlock() const;

	/**
	 * @brief Returns the amount of the asset available for minting.
	 * @return The amount available.
	 */
	const TOptional<FString>& GetMintableSupply() const;

	/**
	 * @brief Returns the fungible state of the asset.
	 * @return Whether the asset is fungible.
	 */
	const TOptional<bool>& GetNonFungible() const;

	/**
	 * @brief Returns the reserve amount of the asset.
	 * @return The reserve amount.
	 */
	const TOptional<FString>& GetReserve() const;

	/**
	 * @brief Returns the supply model of the asset.
	 * @return The supply model.
	 */
	const TOptional<EAssetSupplyModel>& GetSupplyModel() const;

	/**
	 * @brief Returns the total supply of the asset.
	 * @return The total supply.
	 */
	const TOptional<FString>& GetTotalSupply() const;

	bool operator==(const FAssetStateData& Rhs) const;

	bool operator!=(const FAssetStateData& Rhs) const;

	FAssetStateData& operator=(const FAssetStateData& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
