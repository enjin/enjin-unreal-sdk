// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Shared/GetProject.h"

using namespace Enjin::Sdk::Shared;

BEGIN_DEFINE_SPEC(FSharedGetProjectSpec,
                  "Enjin.Sdk.Shared.GetProject",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
	const FString Json = TEXT(R"({})");

END_DEFINE_SPEC(FSharedGetProjectSpec)

void FSharedGetProjectSpec::Define()
{
	Describe(TEXT("Serialization"), [this]()
	{
		It(TEXT("should produce expected JSON"), [this]()
		{
			// Arrange
			const FString Expected = Json;
			const FGetProject ClassUnderTest = FGetProject();

			// Act
			const FString Actual = ClassUnderTest.Serialize();

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});

	Describe(TEXT("Equality operator"), [this]()
	{
		It(TEXT("should be true"), [this]()
		{
			// Arrange
			const FGetProject Lhs;
			const FGetProject Rhs;

			// Act
			const bool Actual = Lhs == Rhs;

			// Assert
			TestTrue(TEXT("Both sides are equal"), Actual);
		});
	});
}
