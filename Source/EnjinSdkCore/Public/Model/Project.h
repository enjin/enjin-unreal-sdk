// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IDeserializable.h"

namespace Enjin
{
namespace Sdk
{
namespace Model
{
/**
 * @brief Models a project on the platform.
 */
class ENJINSDKCORE_API FProject final : public Serialization::IDeserializable
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FProject();

	/**
	 * @brief Constructs an instance as a copy of another.
	 * @param Other The other instance.
	 */
	FProject(const FProject& Other);

	/**
	 * @brief Constructs an instance via move.
	 * @param Other The other instance being moved.
	 */
	FProject(FProject&& Other) noexcept;

	/**
	 * @brief Class destructor.
	 */
	virtual ~FProject() override;

	/**
	 * @brief Parses raw JSON and assigns valid values for member fields of this instance.
	 * @param Json The raw JSON.
	 */
	virtual void Deserialize(const FString& Json) override;

	/**
	 * @brief Returns the datetime when this project was created.
	 * @return The datetime.
	 * @remarks The datetime is formatted using ISO 8601 date format.
	 */
	const TOptional<FString>& GetCreatedAt() const;

	/**
	 * @brief Returns the description of this project.
	 * @return The description.
	 */
	const TOptional<FString>& GetDescription() const;

	/**
	 * @brief Returns the URL for the image of this project.
	 * @return The URL.
	 */
	const TOptional<FString>& GetImage() const;

	/**
	 * @brief Returns the name of this project.
	 * @return The name.
	 */
	const TOptional<FString>& GetName() const;

	/**
	 * @brief Returns the datetime when this project was last updated.
	 * @return The datetime.
	 * @remarks The datetime is formatted using ISO 8601 date format.
	 */
	const TOptional<FString>& GetUpdatedAt() const;

	/**
	 * @brief Returns the UUID of this project.
	 * @return The UUID.
	 */
	const TOptional<FString>& GetUuid() const;

	bool operator==(const FProject& Rhs) const;

	bool operator!=(const FProject& Rhs) const;

	FProject& operator=(const FProject& Rhs);

private:
	class FImpl;

	TUniquePtr<FImpl> Pimpl;
};
}
}
}
