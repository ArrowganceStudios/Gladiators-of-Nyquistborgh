#pragma once
#include <queue>
#include "ForwardDeclarations.h"
#include "Event.h"

class EventSystem
{
	friend class Core;	//	EVIL

public:
	//disable copy
	EventSystem() = default;
	EventSystem(EventSystem const&) = delete;
	EventSystem& operator=(EventSystem const&) = delete;

	void Add(Event&& event);

private:
	std::queue<Event> events;
	Event Get();
	bool IsQueueEmpty() { return events.size() == 0; };
};