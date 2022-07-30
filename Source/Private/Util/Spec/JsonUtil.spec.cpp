// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "JsonUtil.h"
#include "Misc/AutomationTest.h"
#include "Test/DummyObject.h"

using namespace Enjin::Sdk::Util;
using namespace Enjin::Test::Util;

BEGIN_DEFINE_SPEC(FJsonUtilSpec,
                  "Enjin.Sdk.Util.JsonUtil",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)
END_DEFINE_SPEC(FJsonUtilSpec)

void FJsonUtilSpec::Define()
{
	Describe(TEXT("Equals for FJsonObject reference"), [this]()
	{
		It(TEXT("should return true when both objects are the same"), [this]()
		{
			// Arrange
			const FString Json = TEXT(R"({"null":null,"bool":true,"number":1,"string":"xyz","array":[],"object":{}})");
			TSharedPtr<FJsonObject> FirstPtr = MakeShared<FJsonObject>();
			TSharedPtr<FJsonObject> SecondPtr = MakeShared<FJsonObject>();
			FJsonUtil::TryParseJsonObject(Json, FirstPtr);
			FJsonUtil::TryParseJsonObject(Json, SecondPtr);
			const TSharedRef<FJsonObject> FirstRef = FirstPtr.ToSharedRef();
			const TSharedRef<FJsonObject> SecondRef = SecondPtr.ToSharedRef();

			// Act
			const bool bResult = FJsonUtil::Equals(FirstRef, SecondRef);

			// Assert
			TestTrue(TEXT("First and second are equal"), bResult);
		});

		It(TEXT("should return false when both objects do not have the same number of keys"), [this]()
		{
			// Arrange
			const FString FirstJson = TEXT(R"({"field1":1,"field2":2})");
			const FString SecondJson = TEXT(R"({"field2":1})");
			TSharedPtr<FJsonObject> FirstPtr = MakeShared<FJsonObject>();
			TSharedPtr<FJsonObject> SecondPtr = MakeShared<FJsonObject>();
			FJsonUtil::TryParseJsonObject(FirstJson, FirstPtr);
			FJsonUtil::TryParseJsonObject(SecondJson, SecondPtr);
			const TSharedRef<FJsonObject> FirstRef = FirstPtr.ToSharedRef();
			const TSharedRef<FJsonObject> SecondRef = SecondPtr.ToSharedRef();

			// Act
			const bool bResult = FJsonUtil::Equals(FirstRef, SecondRef);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});

		It(TEXT("should return false when objects have different keys"), [this]()
		{
			// Arrange
			const FString FirstJson = TEXT(R"({"field1":1})");
			const FString SecondJson = TEXT(R"({"field2":1})");
			TSharedPtr<FJsonObject> FirstPtr = MakeShared<FJsonObject>();
			TSharedPtr<FJsonObject> SecondPtr = MakeShared<FJsonObject>();
			FJsonUtil::TryParseJsonObject(FirstJson, FirstPtr);
			FJsonUtil::TryParseJsonObject(SecondJson, SecondPtr);
			const TSharedRef<FJsonObject> FirstRef = FirstPtr.ToSharedRef();
			const TSharedRef<FJsonObject> SecondRef = SecondPtr.ToSharedRef();

			// Act
			const bool bResult = FJsonUtil::Equals(FirstRef, SecondRef);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});
	});

	Describe(TEXT("Equals for FJsonObject pointer"), [this]()
	{
		It(TEXT("should return true when both pointers are not valid"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonObject> First;
			const TSharedPtr<FJsonObject> Second;

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestTrue(TEXT("First and second are equal"), bResult);
		});

		It(TEXT("should return false when only first pointer is valid"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonObject> First = MakeShared<FJsonObject>();
			const TSharedPtr<FJsonObject> Second;

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});

		It(TEXT("should return false when only second pointer is valid"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonObject> First;
			const TSharedPtr<FJsonObject> Second = MakeShared<FJsonObject>();

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});

		It(TEXT("should return true when both pointers are valid and objects are the same"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonObject> First = MakeShared<FJsonObject>();
			const TSharedPtr<FJsonObject> Second = MakeShared<FJsonObject>();

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestTrue(TEXT("First and second are equal"), bResult);
		});
	});

	Describe(TEXT("Equals for FJsonObject optional"), [this]()
	{
		It(TEXT("should return true when both optionals are not set"), [this]()
		{
			// Arrange
			const TOptional<TSharedRef<FJsonObject>> First;
			const TOptional<TSharedRef<FJsonObject>> Second;

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestTrue(TEXT("First and second are equal"), bResult);
		});

		It(TEXT("should return false when only first optional has been set"), [this]()
		{
			// Arrange
			const TOptional<TSharedRef<FJsonObject>> First = MakeShared<FJsonObject>();
			const TOptional<TSharedRef<FJsonObject>> Second;

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});

		It(TEXT("should return false when only second optional has been set"), [this]()
		{
			// Arrange
			const TOptional<TSharedRef<FJsonObject>> First;
			const TOptional<TSharedRef<FJsonObject>> Second = MakeShared<FJsonObject>();

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});

		It(TEXT("should return true when both optionals are set and objects are the same"), [this]()
		{
			// Arrange
			const TOptional<TSharedRef<FJsonObject>> First = MakeShared<FJsonObject>();
			const TOptional<TSharedRef<FJsonObject>> Second = MakeShared<FJsonObject>();

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestTrue(TEXT("First and second are equal"), bResult);
		});
	});

	Describe(TEXT("Equals for FJsonValue reference"), [this]()
	{
		It(TEXT("should return true when both values are the same"), [this]()
		{
			// Arrange
			constexpr int32 Value = 1;
			const TSharedRef<FJsonValue> First = MakeShared<FJsonValueNumber>(Value);
			const TSharedRef<FJsonValue> Second = MakeShared<FJsonValueNumber>(Value);

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestTrue(TEXT("First and second are equal"), bResult);
		});

		It(TEXT("should return false when both values are the same type but different value"), [this]()
		{
			// Arrange
			const TSharedRef<FJsonValue> First = MakeShared<FJsonValueNumber>(1);
			const TSharedRef<FJsonValue> Second = MakeShared<FJsonValueNumber>(2);

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});

		It(TEXT("should return false when both values are not the same type"), [this]()
		{
			// Arrange
			const TSharedRef<FJsonValue> First = MakeShared<FJsonValueNumber>(1);
			const TSharedRef<FJsonValue> Second = MakeShared<FJsonValueBoolean>(true);

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});
	});

	Describe(TEXT("Equals for FJsonValue pointer"), [this]()
	{
		It(TEXT("should return true when both pointers are not valid"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonValue> First;
			const TSharedPtr<FJsonValue> Second;

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestTrue(TEXT("First and second are equal"), bResult);
		});

		It(TEXT("should return false when only first pointer is valid"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonValue> First = MakeShared<FJsonValueNull>();
			const TSharedPtr<FJsonValue> Second;

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});

		It(TEXT("should return false when only second pointer is valid"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonValue> First;
			const TSharedPtr<FJsonValue> Second = MakeShared<FJsonValueNull>();

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});

		It(TEXT("should return true when both pointers are valid and objects are the same"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonValue> First = MakeShared<FJsonValueNull>();
			const TSharedPtr<FJsonValue> Second = MakeShared<FJsonValueNull>();

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestTrue(TEXT("First and second are equal"), bResult);
		});
	});

	Describe(TEXT("Equals for FJsonValue array"), [this]()
	{
		It(TEXT("should return true when arrays are empty"), [this]()
		{
			// Arrange
			const TArray<TSharedPtr<FJsonValue>> First;
			const TArray<TSharedPtr<FJsonValue>> Second;

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestTrue(TEXT("First and second are equal"), bResult);
		});

		It(TEXT("should return true when arrays are the same length and have equal elements"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonValue> Element = MakeShared<FJsonValueNumber>(1);
			const TArray<TSharedPtr<FJsonValue>> First = {Element};
			const TArray<TSharedPtr<FJsonValue>> Second = {Element};

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestTrue(TEXT("First and second are equal"), bResult);
		});

		It(TEXT("should return false when arrays are the same length and have unequal elements"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonValue> Element1 = MakeShared<FJsonValueNumber>(1);
			const TSharedPtr<FJsonValue> Element2 = MakeShared<FJsonValueNumber>(2);
			const TArray<TSharedPtr<FJsonValue>> First = {Element1};
			const TArray<TSharedPtr<FJsonValue>> Second = {Element2};

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});

		It(TEXT("should return false when arrays are not the same length"), [this]()
		{
			// Arrange
			const TSharedPtr<FJsonValue> Element1 = MakeShared<FJsonValueNumber>(1);
			const TSharedPtr<FJsonValue> Element2 = MakeShared<FJsonValueNumber>(2);
			const TArray<TSharedPtr<FJsonValue>> First = {Element1, Element2};
			const TArray<TSharedPtr<FJsonValue>> Second = {Element2};

			// Act
			const bool bResult = FJsonUtil::Equals(First, Second);

			// Assert
			TestFalse(TEXT("First and second are not equal"), bResult);
		});
	});

	Describe(TEXT("GetTypeArrayAsJsonValueArray"), [this]()
	{
		It(TEXT("should return an array containing JSON values when given a array of serializable type"), [this]()
		{
			// Arrange
			const FDummyObject Expected = FDummyObject::CreateDefault();
			const TArray<FDummyObject> InArray
			{
				Expected,
				Expected,
				Expected,
			};

			// Act
			TArray<TSharedPtr<FJsonValue>> OutArray = FJsonUtil::GetTypeArrayAsJsonValueArray(InArray);

			// Assert
			for (TSharedPtr<FJsonValue> JsonValue : OutArray)
			{
				FDummyObject Actual;

				TestTrue(TEXT("Successfully get JSON value as type"),
				         FJsonUtil::TryGetValueAsType(JsonValue.ToSharedRef(), Actual));
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			}
		});

		It(TEXT("should return an array containing JSON values when given a string array"), [this]()
		{
			// Arrange
			const FString Expected = TEXT("xyz");
			const TArray<FString> InArray =
			{
				Expected,
				Expected,
				Expected,
			};

			// Act
			TArray<TSharedPtr<FJsonValue>> OutArray = FJsonUtil::GetTypeArrayAsJsonValueArray(InArray);

			// Assert
			for (const TSharedPtr<FJsonValue>& JsonValue : OutArray)
			{
				FString Actual;

				TestTrue(TEXT("Successfully get JSON value as string"), JsonValue->TryGetString(Actual));
				TestEqual(TEXT("Actual equals expected"), Actual, Expected);
			}
		});
	});

	Describe(TEXT("JoinObject"), [this]()
	{
		It(TEXT("should do something"), [this]()
		{
			// Arrange
			const FString ExpectedKey = TEXT("TestKey");
			constexpr double ExpectedValue = 1;
			const TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();
			const TSharedRef<FJsonObject> Other = MakeShared<FJsonObject>();
			Other->SetNumberField(ExpectedKey, ExpectedValue);

			// Act
			FJsonUtil::JoinObject(JsonRef, Other);

			// Assert
			TestTrue(TEXT("JSON object has expected key"), JsonRef->HasField(ExpectedKey));
			TestEqual(TEXT("JSON object has expected value"), JsonRef->GetNumberField(ExpectedKey), ExpectedValue);
		});
	});

	Describe(TEXT("SerializeJsonObject"), [this]()
	{
		It(TEXT("should equal expected raw data"), [this]()
		{
			// Arrange
			const FString Expected = TEXT(R"({"string":"xyz","int":1,"object":{"key":"value"},"array":[1,2]})");
			const TSharedRef<FJsonObject> JsonObject = MakeShared<FJsonObject>();
			const TSharedRef<FJsonObject> SubObject = MakeShared<FJsonObject>();
			TArray<TSharedPtr<FJsonValue>> SubArray;
			SubObject->SetStringField(TEXT("key"), TEXT("value"));
			SubArray.Add(MakeShared<FJsonValueNumber>(1));
			SubArray.Add(MakeShared<FJsonValueNumber>(2));
			JsonObject->SetStringField(TEXT("string"), TEXT("xyz"));
			JsonObject->SetNumberField(TEXT("int"), 1);
			JsonObject->SetObjectField(TEXT("object"), SubObject);
			JsonObject->SetArrayField(TEXT("array"), SubArray);

			// Act
			const FString Actual = FJsonUtil::SerializeJsonObject(JsonObject);

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});

	Describe(TEXT("TryGetArrayAsTypeArray"), [this]()
	{
		It(TEXT("should populate out array with data"), [this]()
		{
			// Arrange
			constexpr int32 ExpectedSize = 3;
			const FDummyObject ExpectedEntry = FDummyObject::CreateDefault();
			const FString JsonArrayEntry = ExpectedEntry.Serialize();
			const FString ArrayKey = TEXT("array");
			const FString Json = FString::Printf(TEXT("{\"%s\":[%s,%s,%s]}"),
			                                     *ArrayKey,
			                                     *JsonArrayEntry,
			                                     *JsonArrayEntry,
			                                     *JsonArrayEntry);
			TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
			const bool bJsonParsed = FJsonUtil::TryParseJsonObject(Json, JsonObject);

			// Assumptions
			TestTrue(TEXT("Assume JSON object was populated with parsed data"), bJsonParsed);

			// Act
			TArray<FDummyObject> ActualArray;
			const bool bResult = FJsonUtil::TryGetArrayAsTypeArray(JsonObject.ToSharedRef(), ArrayKey, ActualArray);

			// Assert
			TestTrue(TEXT("Try result is true"), bResult);
			TestEqual(TEXT("Array length equals expected"), ActualArray.Num(), ExpectedSize);

			for (const FDummyObject& ActualEntry : ActualArray)
			{
				TestEqual(TEXT("Entry equals expected"), ActualEntry, ExpectedEntry);
			}
		});
	});

	Describe(TEXT("TryGetObjectAsType"), [this]()
	{
		It(TEXT("should populate out object with data"), [this]()
		{
			// Arrange
			const FDummyObject Expected = FDummyObject::CreateDefault();
			const FString Key = TEXT("object");
			const FString Value = Expected.Serialize();
			const FString Json = FString::Printf(TEXT("{\"%s\":%s}"), *Key, *Value);
			TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
			const bool bJsonParsed = FJsonUtil::TryParseJsonObject(Json, JsonObject);

			// Assumptions
			TestTrue(TEXT("Assume JSON object was populated with parsed data"), bJsonParsed);

			// Act
			FDummyObject Actual;
			FJsonUtil::TryGetObjectAsType(JsonObject.ToSharedRef(), Key, Actual);

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});

	Describe(TEXT("TryGetValueAsType"), [this]()
	{
		It(TEXT("should populate out object with data"), [this]()
		{
			// Arrange
			const FDummyObject Expected = FDummyObject::CreateDefault();
			const FString Json = Expected.Serialize();
			TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
			const bool bJsonParsed = FJsonUtil::TryParseJsonObject(Json, JsonObject);

			// Assumptions
			TestTrue(TEXT("Assume JSON object was populated with parsed data"), bJsonParsed);

			// Arrange (continued)
			const TSharedPtr<FJsonValue> JsonValue = MakeShared<FJsonValueObject>(MoveTemp(JsonObject));

			// Act
			FDummyObject Actual;
			FJsonUtil::TryGetValueAsType(JsonValue.ToSharedRef(), Actual);

			// Assert
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});
	});

	Describe(TEXT("TryParseJsonObject"), [this]()
	{
		It(TEXT("should populate JSON object with raw data"), [this]()
		{
			// Arrange
			const FString ExpectedStringKey = TEXT("string");
			const FString ExpectedStringValue = TEXT("xyz");
			const FString ExpectedNumberKey = TEXT("number");
			constexpr double ExpectedNumberValue = 1;
			const FString Json = FString::Printf(TEXT("{\"%s\":\"%s\",\"%s\":%f}"),
			                                     *ExpectedStringKey, *ExpectedStringValue,
			                                     *ExpectedNumberKey, ExpectedNumberValue);
			TSharedPtr<FJsonObject> JsonObject;

			// Act
			FJsonUtil::TryParseJsonObject(Json, JsonObject);

			// Assert
			TestTrue(TEXT("Object has string field"), JsonObject->HasField(ExpectedStringKey));
			TestEqual(TEXT("String field equals expected"),
			          JsonObject->GetStringField(ExpectedStringKey),
			          ExpectedStringValue);
			TestTrue(TEXT("Object has number field"), JsonObject->HasField(ExpectedNumberKey));
			TestEqual(TEXT("Number field equals expected"),
			          JsonObject->GetNumberField(ExpectedNumberKey),
			          ExpectedNumberValue);
		});
	});

	Describe(TEXT("TryGetField"), [this]()
	{
		It(TEXT("should not set optional when data is not present"), [this]()
		{
			// Arrange
			const FString JsonKey = TEXT("key");
			const TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
			TOptional<FDummyObject> OutField;

			// Act
			const bool bResult = FJsonUtil::TryGetField(JsonObject.ToSharedRef(), JsonKey, OutField);

			// Assert
			TestFalse(TEXT("Operation returns false"), bResult);
			TestFalse(TEXT("Out optional is not set"), OutField.IsSet());
		});

		It(TEXT("should set optional with expected deserializable type"), [this]()
		{
			// Arrange
			const FDummyObject Expected = FDummyObject::CreateDefault();
			const FString JsonKey = TEXT("key");
			const FString JsonValue = Expected.Serialize();
			const FString Json = FString::Printf(TEXT("{\"%s\":%s}"), *JsonKey, *JsonValue);
			TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
			const bool bJsonParsed = FJsonUtil::TryParseJsonObject(Json, JsonObject);
			TOptional<FDummyObject> OutField(FDummyObject(5));

			// Assumptions
			TestTrue(TEXT("Assume JSON object was populated with parsed data"), bJsonParsed);
			TestNotEqual(TEXT("Assume out optional value does not equal expected"), OutField.GetValue(), Expected);

			// Act
			const bool bResult = FJsonUtil::TryGetField(JsonObject.ToSharedRef(), JsonKey, OutField);

			// Assert
			TestTrue(TEXT("Operation returns true"), bResult);
			TestTrue(TEXT("Out optional is set"), OutField.IsSet());
			TestEqual(TEXT("Out optional value equals expected"), OutField.GetValue(), Expected);
		});

		It(TEXT("should override optional with expected deserializable type"), [this]()
		{
			// Arrange
			const FDummyObject Expected = FDummyObject::CreateDefault();
			const FString JsonKey = TEXT("key");
			const FString JsonValue = Expected.Serialize();
			const FString Json = FString::Printf(TEXT("{\"%s\":%s}"), *JsonKey, *JsonValue);
			TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
			const bool bJsonParsed = FJsonUtil::TryParseJsonObject(Json, JsonObject);
			TOptional<FDummyObject> OutField;

			// Assumptions
			TestTrue(TEXT("Assume JSON object was populated with parsed data"), bJsonParsed);

			// Act
			const bool bResult = FJsonUtil::TryGetField(JsonObject.ToSharedRef(), JsonKey, OutField);

			// Assert
			TestTrue(TEXT("Operation returns true"), bResult);
			TestTrue(TEXT("Out optional is set"), OutField.IsSet());
			TestEqual(TEXT("Out optional value equals expected"), OutField.GetValue(), Expected);
		});

		It(TEXT("should reset optional when data is not present"), [this]()
		{
			// Arrange
			const FString JsonKey = TEXT("key");
			const TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
			TOptional<FDummyObject> OutField(FDummyObject::CreateDefault());

			// Assumptions
			TestTrue(TEXT("Assume optional is set"), OutField.IsSet());

			// Act
			const bool bResult = FJsonUtil::TryGetField(JsonObject.ToSharedRef(), JsonKey, OutField);

			// Assert
			TestFalse(TEXT("Operation returns false"), bResult);
			TestFalse(TEXT("Out optional is not set"), OutField.IsSet());
		});
	});

	Describe(TEXT("TrySetField"), [this]()
	{
		It(TEXT("should not set field when optional is not set and field is not populated"), [this]()
		{
			// Arrange
			const TOptional<FDummyObject> InField;
			const FString JsonKey = TEXT("key");
			const TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

			// Assumptions
			TestFalse(TEXT("Assume InField is not set"), InField.IsSet());
			TestFalse(TEXT("Assume JSON object does not have field"), JsonRef->HasField(JsonKey));

			// Act
			const bool bResult = FJsonUtil::TrySetField(JsonRef, JsonKey, InField);

			// Assert
			TestFalse(TEXT("Operation returns false"), bResult);
			TestFalse(TEXT("JSON object does not have field"), JsonRef->HasField(JsonKey));
		});

		It(TEXT("should set field when optional is not set and field is not populated"), [this]()
		{
			// Arrange
			const FDummyObject Expected = FDummyObject::CreateDefault();
			const TOptional<FDummyObject> InField(Expected);
			const FString JsonKey = TEXT("key");
			const TSharedRef<FJsonObject> JsonRef = MakeShared<FJsonObject>();

			// Assumptions
			TestTrue(TEXT("Assume InField is set"), InField.IsSet());
			TestFalse(TEXT("Assume JSON object does not have field"), JsonRef->HasField(JsonKey));

			// Act
			const bool bResult = FJsonUtil::TrySetField(JsonRef, JsonKey, InField);

			// Assert
			TestTrue(TEXT("Operation returns true"), bResult);
			TestTrue(TEXT("JSON object has field"), JsonRef->HasField(JsonKey));

			FDummyObject Actual;
			FJsonUtil::TryGetObjectAsType(JsonRef, JsonKey, Actual);
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should override field when optional is set and field is populated"), [this]()
		{
			// Arrange
			const FDummyObject Expected = FDummyObject::CreateDefault();
			const TOptional<FDummyObject> InField(Expected);
			const FString JsonKey = TEXT("key");
			const FString Json = FString::Printf(TEXT("{\"%s\":1}"), *JsonKey);
			TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
			FJsonUtil::TryParseJsonObject(Json, JsonObject);
			const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

			// Assumptions
			TestTrue(TEXT("Assume InField is set"), InField.IsSet());
			TestTrue(TEXT("Assume JSON object has field"), JsonRef->HasField(JsonKey));

			// Act
			const bool bResult = FJsonUtil::TrySetField(JsonRef, JsonKey, InField);

			// Assert
			TestTrue(TEXT("Operation returns true"), bResult);
			TestTrue(TEXT("JSON object has field"), JsonRef->HasField(JsonKey));

			FDummyObject Actual;
			FJsonUtil::TryGetObjectAsType(JsonRef, JsonKey, Actual);
			TestEqual(TEXT("Actual equals expected"), Actual, Expected);
		});

		It(TEXT("should clear field when optional is not set and field is populated"), [this]()
		{
			// Arrange
			const TOptional<FDummyObject> InField;
			const FString JsonKey = TEXT("key");
			const FString Json = FString::Printf(TEXT("{\"%s\":1}"), *JsonKey);
			TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();
			FJsonUtil::TryParseJsonObject(Json, JsonObject);
			const TSharedRef<FJsonObject> JsonRef = JsonObject.ToSharedRef();

			// Assumptions
			TestFalse(TEXT("Assume InField is not set"), InField.IsSet());
			TestTrue(TEXT("Assume JSON object has field"), JsonRef->HasField(JsonKey));

			// Act
			const bool bResult = FJsonUtil::TrySetField(JsonRef, JsonKey, InField);

			// Assert
			TestFalse(TEXT("Operation returns false"), bResult);
			TestFalse(TEXT("JSON object does not have field"), JsonRef->HasField(JsonKey));
		});
	});
}
