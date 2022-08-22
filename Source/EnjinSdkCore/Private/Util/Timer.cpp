// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "Timer.h"

// The namespace for this timer class is explicitly used to avoid confusion with UE's own FTimer class.

Enjin::Sdk::Util::FTimer::FTimer()
{
	TimerThread = FThread(TEXT("EnjinTimer"), [this]()
	{
		std::unique_lock<std::mutex> Lock(TimerMutex);

		while (!bTeardown)
		{
			if (!DurationOpt.IsSet())
			{
				/* Waits until notified of a state change, then loops again and checks if this timer is in its teardown
				 * phase or if the duration has been set.
				 */
				TimerConditionVariable.wait(Lock);
				continue;
			}

			TimerConditionVariable.wait_for(Lock, DurationOpt.GetValue());

			/* Stores the action to a local variable called outside the critical section to allow the scheduled action
			 * to call any of this timer's member-functions.
			 */
			TOptional<TFunction<void()>> TempActionOpt;
			if (bIsEnabled)
			{
				TempActionOpt = MoveTemp(ActionOpt);
				Reset();
			}

			Lock.unlock();

			if (TempActionOpt.IsSet())
			{
				TempActionOpt.GetValue()();
			}

			Lock.lock();
		}
	});
}

Enjin::Sdk::Util::FTimer::~FTimer()
{
	std::unique_lock<std::mutex> Lock(TimerMutex);
	bTeardown = true;
	bIsEnabled = false;
	TimerConditionVariable.notify_one();
	Lock.unlock();

	if (TimerThread.IsJoinable())
	{
		TimerThread.Join();
	}
}

void Enjin::Sdk::Util::FTimer::Cancel()
{
	std::lock_guard<std::mutex> Guard(TimerMutex);
	Reset();
	TimerConditionVariable.notify_one();
}

bool Enjin::Sdk::Util::FTimer::IsEnabled() const
{
	std::lock_guard<std::mutex> Guard(TimerMutex);
	return bIsEnabled;
}

void Enjin::Sdk::Util::FTimer::Schedule(TFunction<void()> Action, const int64 Duration)
{
	Cancel();

	std::lock_guard<std::mutex> Guard(TimerMutex);
	bIsEnabled = true;
	ActionOpt.Emplace(MoveTemp(Action));
	DurationOpt.Emplace(std::chrono::milliseconds(Duration));
	TimerConditionVariable.notify_one();
}

void Enjin::Sdk::Util::FTimer::Reset()
{
	bIsEnabled = false;
	ActionOpt.Reset();
	DurationOpt.Reset();
}
