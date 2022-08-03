// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "HAL/Thread.h"
#include <chrono>
#include <condition_variable>
#include <mutex>

namespace Enjin
{
namespace Sdk
{
namespace Util
{
/**
 * @brief Timer class for scheduling a single action to run once after a given duration.
 */
class ENJINSDKCORE_API FTimer final
{
public:
	/**
	 * @brief Constructs an instance of this class.
	 */
	FTimer();

	/**
	 * @brief Deconstructs this instance.
	 */
	~FTimer();

	/**
	 * @brief Cancels the current scheduled action.
	 */
	void Cancel();

	/**
	 * @brief Determines if this timer is enabled.
	 * @return Whether this timer is enabled.
	 */
	bool IsEnabled() const;

	/**
	 * @brief Schedules an action to run after the given time duration passes.
	 * @param Action The action.
	 * @param Duration The duration in milliseconds.
	 */
	void Schedule(TFunction<void()> Action, const int64 Duration);

private:
	bool bIsEnabled = false;
	TOptional<TFunction<void()>> ActionOpt;
	TOptional<std::chrono::milliseconds> DurationOpt;

	bool bTeardown = false;
	FThread TimerThread;
	std::condition_variable TimerConditionVariable;

	// Mutexes
	mutable std::mutex TimerMutex;

	/**
	 * @brief Resets necessary fields used between different schedules of the timer.
	 * @remarks This member-function ought to only be called when the current thread has acquired
	 * @link TimerMutex @endlink.
	 */
	void Reset();
};
}
}
}
