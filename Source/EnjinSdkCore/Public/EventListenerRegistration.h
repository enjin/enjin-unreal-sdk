// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#pragma once

#include "IEventListener.h"
#include "Model/EventType.h"

namespace Enjin
{
namespace Sdk
{
namespace Event
{
class FEventListenerRegistration;

/**
 * @brief Alias for a shared-reference to a event listener.
 */
using FEventListenerRef = TSharedRef<IEventListener, ESPMode::ThreadSafe>;

/**
 * @brief Alias for a shared-reference to a event listener registration.
 */
using FEventListenerRegistrationRef = TSharedRef<FEventListenerRegistration, ESPMode::ThreadSafe>;

/**
 * @brief Alias for a functional event matcher.
 */
using FEventMatcher = TFunction<bool(const Model::EEventType)>;

/**
 * @brief Registration wrapper for a listener that receives cloud events.
 */
class ENJINSDKCORE_API FEventListenerRegistration final
{
public:
	/**
	 * @brief Configuration class for building an @link FEventListenerRegistration @endlink. Used internally.
	 */
	class ENJINSDKCORE_API FRegistrationListenerConfiguration final
	{
	public:
		FRegistrationListenerConfiguration() = delete;

		/**
		 * @brief Constructs an instance of this class.
		 * @param Listener The listener.
		 */
		explicit FRegistrationListenerConfiguration(FEventListenerRef Listener);

		/**
		 * @brief Class destructor.
		 */
		~FRegistrationListenerConfiguration() = default;

		/**
		 * @brief Creates a registration with the listener and event matcher set in this configuration.
		 * @return The registration instance.
		 * @remarks If no event matcher is set, then the registration will be created with the
		 * @link AllowAllMatcher @endlink.
		 */
		FEventListenerRegistrationRef Create() const;

		/**
		 * @brief Returns the listener held by this configuration.
		 * @return The listener.
		 */
		const FEventListenerRef& GetListener() const;

		/**
		 * @brief Sets the event types the event matcher ought to match for.
		 * @param Types The event types.
		 * @return This configuration for chaining.
		 */
		FRegistrationListenerConfiguration& WithAllowedEvents(TArray<Model::EEventType> Types);

		/**
		 * @brief Sets the event types the event matcher ought to not match for.
		 * @param Types The event types.
		 * @return This configuration for chaining.
		 */
		FRegistrationListenerConfiguration& WithIgnoredEvents(TArray<Model::EEventType> Types);

		/**
		 * @brief Sets the event matcher to be used for the listener.
		 * @param Matcher The matcher.
		 * @return This configuration for chaining.
		 */
		FRegistrationListenerConfiguration& WithMatcher(FEventMatcher Matcher);

	private:
		const FEventListenerRef Listener;
		TOptional<FEventMatcher> MatcherOpt;
	};

	/**
	 * @brief A matcher that returns true for any event.
	 */
	static const FEventMatcher AllowAllMatcher;

	FEventListenerRegistration() = delete;

	/**
	 * @brief Class destructor.
	 */
	~FEventListenerRegistration() = default;

	/**
	 * @brief Returns the listener for this registration.
	 * @return The listener.
	 */
	const FEventListenerRef& GetListener() const;

	/**
	 * @brief Returns the matcher for this registration.
	 * @return The matcher.
	 */
	const FEventMatcher& GetMatcher() const;

private:
	const FEventListenerRef RegisteredListener;
	const FEventMatcher RegisteredMatcher;

	/**
	 * @brief Constructs an instance of this class.
	 * @param Listener The listener.
	 * @param Matcher The matcher.
	 */
	FEventListenerRegistration(FEventListenerRef Listener, FEventMatcher Matcher);
};
}
}
}
