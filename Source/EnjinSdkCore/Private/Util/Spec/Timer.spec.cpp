// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Timer.h"
#include "Misc/AutomationTest.h"

// The namespace for this SDK's timer class is explicitly used to avoid confusion with UE's own FTimer class.

BEGIN_DEFINE_SPEC(FTimerSpec,
                  "Enjin.Sdk.Util.Timer",
                  EAutomationTestFlags::ProductFilter | EAutomationTestFlags::ApplicationContextMask)

	const int64 HalfSecondDuration = 500;
	const int64 OneSecondDuration = 1000;
	const int64 NoDuration = 0;
	const int64 TenSecondDuration = 10000;

END_DEFINE_SPEC(FTimerSpec)

void FTimerSpec::Define()
{
	Describe(TEXT("Schedule"), [this]()
	{
		It(TEXT("should be able to schedule an action and complete it"), [this]()
		{
			// Arrange
			Enjin::Sdk::Util::FTimer ClassUnderTest;
			bool bFlag = false;
			const TFunction<void()> Action = [&bFlag]()
			{
				bFlag = true;
			};

			// Act
			ClassUnderTest.Schedule(Action, NoDuration);

			FPlatformProcess::Sleep(1);

			// Assert
			TestTrue(TEXT("The scheduled action was completed"), bFlag);
		});

		It(TEXT("should be able to override the current scheduled action when a new action is scheduled"), [this]()
		{
			// Arrange
			Enjin::Sdk::Util::FTimer ClassUnderTest;
			bool bFlag1 = false;
			bool bFlag2 = false;
			const TFunction<void()> Action1 = [&bFlag1]()
			{
				bFlag1 = true;
			};
			const TFunction<void()> Action2 = [&bFlag2]()
			{
				bFlag2 = true;
			};
			ClassUnderTest.Schedule(Action1, TenSecondDuration);

			// Act
			ClassUnderTest.Schedule(Action2, NoDuration);

			FPlatformProcess::Sleep(1);

			// Assert
			TestFalse(TEXT("The first scheduled action was canceled"), bFlag1);
			TestTrue(TEXT("The second scheduled action was completed"), bFlag2);
		});

		It(TEXT("should be able to schedule a new action from within an already scheduled action"), [this]()
		{
			// Arrange
			Enjin::Sdk::Util::FTimer ClassUnderTest;
			bool bFlag1 = false;
			bool bFlag2 = false;
			const TFunction<void()> Action2 = [&bFlag2]()
			{
				bFlag2 = true;
			};
			const TFunction<void()> Action1 = [this, &ClassUnderTest, &Action2, &bFlag1]()
			{
				bFlag1 = true;
				ClassUnderTest.Schedule(Action2, NoDuration);
			};

			// Act
			ClassUnderTest.Schedule(Action1, NoDuration);

			FPlatformProcess::Sleep(1);

			// Assert
			TestTrue(TEXT("The first scheduled action was completed"), bFlag1);
			TestTrue(TEXT("The second scheduled action was completed"), bFlag2);
		});
	});

	Describe(TEXT("Cancel"), [this]()
	{
		It(TEXT("should be able to cancel a scheduled action"), [this]()
		{
			// Arrange
			Enjin::Sdk::Util::FTimer ClassUnderTest;
			bool bFlag = false;
			const TFunction<void()> Action = [&bFlag]()
			{
				bFlag = true;
			};
			ClassUnderTest.Schedule(Action, HalfSecondDuration);

			// Act
			ClassUnderTest.Cancel();

			FPlatformProcess::Sleep(1);

			// Assert
			TestFalse(TEXT("The scheduled action was canceled"), bFlag);
		});
	});

	Describe(TEXT("IsEnabled"), [this]()
	{
		It(TEXT("should not be enabled when no action is scheduled"), [this]()
		{
			// Arrange
			const Enjin::Sdk::Util::FTimer ClassUnderTest;

			// Act
			const bool bActual = ClassUnderTest.IsEnabled();

			// Assert
			TestFalse(TEXT("Timer is not enabled"), bActual);
		});

		It(TEXT("should be enabled when an action is scheduled"), [this]()
		{
			// Arrange
			Enjin::Sdk::Util::FTimer ClassUnderTest;
			const TFunction<void()> Action = []()
			{
			};
			ClassUnderTest.Schedule(Action, TenSecondDuration);

			// Act
			const bool bActual = ClassUnderTest.IsEnabled();

			// Assert
			TestTrue(TEXT("Timer is enabled"), bActual);
		});

		It(TEXT("should no longer be enabled after a scheduled action is completed"), [this]()
		{
			// Arrange
			Enjin::Sdk::Util::FTimer ClassUnderTest;
			bool bFlag = false;
			const TFunction<void()> Action = [&bFlag]()
			{
				bFlag = true;
			};
			ClassUnderTest.Schedule(Action, HalfSecondDuration);

			// Assumption
			TestTrue(TEXT("Assume timer is enabled"), ClassUnderTest.IsEnabled());

			FPlatformProcess::Sleep(1);

			// Assumption (continued)
			TestTrue(TEXT("Assume the scheduled action was completed"), bFlag);

			// Act
			const bool bActual = ClassUnderTest.IsEnabled();

			// Assert
			TestFalse(TEXT("Timer is not enabled"), bActual);
		});
	});
}
