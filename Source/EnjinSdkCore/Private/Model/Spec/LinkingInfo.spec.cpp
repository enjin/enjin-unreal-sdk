// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Model/LinkingInfo.h"

using namespace Enjin::Sdk::Model;

BEGIN_DEFINE_SPEC(FLinkingInfoSpec,
                  "Enjin.Sdk.Model.LinkingInfo",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString EmptyJson = TEXT(R"({})");
	const FString Json = TEXT(R"({"code":"1","qr":"1"})");
END_DEFINE_SPEC(FLinkingInfoSpec)

void FLinkingInfoSpec::Define()
{
	Describe(TEXT("Deserialization"), [this]()
	{
		It(TEXT("should be empty after construction"), [this]()
		{
			// Arrange
			const FLinkingInfo ClassUnderTest;

			// Assert
			TestFalse(TEXT("Code is not set"), ClassUnderTest.GetCode().IsSet());
			TestFalse(TEXT("Qr is not set"), ClassUnderTest.GetQr().IsSet());
		});

		It(TEXT("should be populated when given data"), [this]()
		{
			// Arrange
			FLinkingInfo ClassUnderTest;

			// Act
			ClassUnderTest.Deserialize(Json);

			// Assert
			TestTrue(TEXT("Code is set"), ClassUnderTest.GetCode().IsSet());
			TestTrue(TEXT("Qr is set"), ClassUnderTest.GetQr().IsSet());
		});

		It(TEXT("should reset when given empty JSON"), [this]()
		{
			// Arrange
			FLinkingInfo ClassUnderTest;
			ClassUnderTest.Deserialize(Json);

			// Assumptions
			TestTrue(TEXT("Assume Code is set"), ClassUnderTest.GetCode().IsSet());
			TestTrue(TEXT("Assume Qr is set"), ClassUnderTest.GetQr().IsSet());

			// Act
			ClassUnderTest.Deserialize(EmptyJson);

			// Assert
			TestFalse(TEXT("Code is not set"), ClassUnderTest.GetCode().IsSet());
			TestFalse(TEXT("Qr is not set"), ClassUnderTest.GetQr().IsSet());
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true when both sides are empty"), [this]()
		{
			// Arrange
			const FLinkingInfo Lhs;
			const FLinkingInfo Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});

		It(TEXT("should be false when only left-hand side is populated"), [this]()
		{
			// Arrange
			FLinkingInfo Lhs;
			const FLinkingInfo Rhs;
			Lhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be false when only right-hand side is populated"), [this]()
		{
			// Arrange
			const FLinkingInfo Lhs;
			FLinkingInfo Rhs;
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestFalse(TEXT("Both sides are not equal"), Actual);
		});

		It(TEXT("should be true when both sides are populated"), [this]()
		{
			// Arrange
			FLinkingInfo Lhs;
			FLinkingInfo Rhs;
			Lhs.Deserialize(Json);
			Rhs.Deserialize(Json);

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
