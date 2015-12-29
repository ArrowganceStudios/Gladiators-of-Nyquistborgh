#pragma once
#include <queue>
#include "ForwardDeclarations.h"
#include "State.h"
#include "Event.h"

class EventSystem
{
public:
	//disable copy
	EventSystem() = default;
	EventSystem(EventSystem const&) = delete;
	EventSystem& operator=(EventSystem const&) = delete;

	void Add(Event&& event);
	Event Get();
	bool IsQueueEmpty() { return events.size() == 0; };

private:
	std::queue<Event> events;
};