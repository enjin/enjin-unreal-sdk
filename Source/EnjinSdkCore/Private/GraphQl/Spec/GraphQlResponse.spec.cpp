// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "GraphQlResponse.h"
#include "JsonUtil.h"
#include "Misc/AutomationTest.h"
#include "Test/DummyObject.h"

using namespace Enjin::Sdk::GraphQl;
using namespace Enjin::Sdk::Model;
using namespace Enjin::Sdk::Serialization;
using namespace Enjin::Sdk::Util;
using namespace Enjin::Test::Util;

BEGIN_DEFINE_SPEC(FGraphQlResponseSpec,
                  "Enjin.Sdk.GraphQl.GraphQlResponse",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FGraphQlResponseSpec)

const FString CursorJson = TEXT(
	R"({"currentPage":1,"from":1,"hasMorePages":true,"hasPages":true,"lastPage":1,"perPage":1,"to":1,"total":1})");

const FString ErrorJson = TEXT(R"({"code":1,"details":"xyz","locations":[{"key":1}],"message":"xyz"})");

FPaginationCursor CreateFakePaginationCursor()
{
	FPaginationCursor Cursor;
	Cursor.Deserialize(CursorJson);

	return MoveTemp(Cursor);
}

void FGraphQlResponseSpec::Define()
{
	Describe(TEXT("Processing errors"), [this]()
	{
		It(TEXT("should have expected errors"), [this]()
		{
			// Arrange
			const FString ResponseJson = FString::Printf(TEXT(R"({"errors":[%s,%s,%s]})"),
			                                             *ErrorJson,
			                                             *ErrorJson,
			                                             *ErrorJson);
			FGraphQlError Expected;
			Expected.Deserialize(ErrorJson);

			// Act
			const TGraphQlResponse<FDummyObject> ClassUnderTest = TGraphQlResponse<FDummyObject>(ResponseJson);

			// Assert
			TestTrue(TEXT("Response has errors"), ClassUnderTest.HasErrors());
			TestFalse(TEXT("Response is not successful"), ClassUnderTest.IsSuccessful());

			for (const FGraphQlError& Actual : ClassUnderTest.GetErrors().GetValue())
			{
				TestEqual(TEXT("Error element equals expected value"), Actual, Expected);
			}
		});
	});

	Describe(TEXT("Processing one result"), [this]()
	{
		It(TEXT("should have expected result"), [this]()
		{
			// Arrange
			const FDummyObject Expected = FDummyObject::CreateDefault();
			const FString JsonEntry = Expected.Serialize();
			const FString Json = FString::Printf(TEXT(R"({"data":{"result":%s}})"), *JsonEntry);

			// Act
			const TGraphQlResponse<FDummyObject> ClassUnderTest = TGraphQlResponse<FDummyObject>(Json);

			// Assert
			TestFalse(TEXT("Response is not empty"), ClassUnderTest.IsEmpty());
			TestTrue(TEXT("Response is successful"), ClassUnderTest.IsSuccessful());
			TestEqual(TEXT("Result equals expected value"), ClassUnderTest.GetResult().GetValue(), Expected);
		});
	});

	Describe(TEXT("Processing many results"), [this]()
	{
		It(TEXT("should have expected results and no cursor"), [this]()
		{
			// Arrange
			const FDummyObject Expected = FDummyObject::CreateDefault();
			const FString JsonEntry = Expected.Serialize();
			const FString Json = FString::Printf(TEXT(R"({"data":{"result":[%s,%s,%s]}})"),
			                                     *JsonEntry,
			                                     *JsonEntry,
			                                     *JsonEntry);

			// Act
			const TGraphQlResponse<TArray<FDummyObject>> ClassUnderTest = TGraphQlResponse<TArray<FDummyObject>>(Json);

			// Assert
			TestFalse(TEXT("Response is not empty"), ClassUnderTest.IsEmpty());
			TestTrue(TEXT("Response is successful"), ClassUnderTest.IsSuccessful());
			TestFalse(TEXT("Response has no cursor"), ClassUnderTest.IsPaginated());

			for (const FDummyObject& Actual : ClassUnderTest.GetResult().GetValue())
			{
				TestEqual(TEXT("Result element equals expected value"), Actual, Expected);
			}
		});

		It(TEXT("should have expected results and cursor"), [this]()
		{
			// Arrange
			const FPaginationCursor ExpectedCursor = CreateFakePaginationCursor();
			const FDummyObject ExpectedObject = FDummyObject::CreateDefault();
			const FString JsonEntry = ExpectedObject.Serialize();
			const FString Json = FString::Printf(TEXT(R"({"data":{"result":{"cursor":%s,"items":[%s,%s,%s]}}})"),
			                                     *CursorJson,
			                                     *JsonEntry,
			                                     *JsonEntry,
			                                     *JsonEntry);

			// Act
			const TGraphQlResponse<TArray<FDummyObject>> ClassUnderTest = TGraphQlResponse<TArray<FDummyObject>>(Json);

			// Assert
			TestFalse(TEXT("Response is not empty"), ClassUnderTest.IsEmpty());
			TestTrue(TEXT("Response is successful"), ClassUnderTest.IsSuccessful());
			TestTrue(TEXT("Response has cursor"), ClassUnderTest.IsPaginated());
			TestEqual(TEXT("Cursor equals expected value"), ClassUnderTest.GetCursor().GetValue(), ExpectedCursor);

			for (const FDummyObject& ActualObject : ClassUnderTest.GetResult().GetValue())
			{
				TestEqual(TEXT("Result element equals expected value"), ActualObject, ExpectedObject);
			}
		});
	});
}
