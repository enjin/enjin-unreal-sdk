// Copyright 2022 Enjin Pte. Ltd. All Rights Reserved.

#include "EventListenerRegistration.h"

using namespace Enjin::Sdk::Event;
using namespace Enjin::Sdk::Model;

/**
 * @brief Convenience alias for referring to the registration configuration class.
 */
using FRegistrationListenerConfiguration = FEventListenerRegistration::FRegistrationListenerConfiguration;

const FEventMatcher FEventListenerRegistration::AllowAllMatcher = [](const EEventType)
{
	return true;
};

FEventListenerRegistration::FEventListenerRegistration(FEventListenerRef Listener, FEventMatcher Matcher)
	: RegisteredListener(MoveTemp(Listener)), RegisteredMatcher(MoveTemp(Matcher))
{
}

const FEventListenerRef& FEventListenerRegistration::GetListener() const
{
	return RegisteredListener;
}

const FEventMatcher& FEventListenerRegistration::GetMatcher() const
{
	return RegisteredMatcher;
}

FRegistrationListenerConfiguration::FRegistrationListenerConfiguration(FEventListenerRef Listener)
	: Listener(MoveTemp(Listener))
{
}

FEventListenerRegistrationRef FRegistrationListenerConfiguration::Create() const
{
	if (MatcherOpt.IsSet())
	{
		return FEventListenerRegistrationRef(new FEventListenerRegistration(Listener, MatcherOpt.GetValue()));
	}

	return FEventListenerRegistrationRef(new FEventListenerRegistration(Listener, AllowAllMatcher));
}

const FEventListenerRef& FRegistrationListenerConfiguration::GetListener() const
{
	return Listener;
}

FRegistrationListenerConfiguration& FRegistrationListenerConfiguration::WithAllowedEvents(TArray<EEventType> Types)
{
	FEventMatcher Matcher = [Types = MoveTemp(Types)](const EEventType Type)
	{
		return Types.Contains(Type);
	};

	MatcherOpt = MoveTemp(Matcher);
	return *this;
}

FRegistrationListenerConfiguration& FRegistrationListenerConfiguration::WithIgnoredEvents(TArray<EEventType> Types)
{
	FEventMatcher Matcher = [Types = MoveTemp(Types)](const EEventType Type)
	{
		return !Types.Contains(Type);
	};

	MatcherOpt = MoveTemp(Matcher);
	return *this;
}

FRegistrationListenerConfiguration& FRegistrationListenerConfiguration::WithMatcher(FEventMatcher Matcher)
{
	MatcherOpt = MoveTemp(Matcher);
	return *this;
}
