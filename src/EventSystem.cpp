#include "EventSystem.h"

void EventSystem::Add(Event&& event)
{
	events.push(event);
}

Event EventSystem::Get() //Rvalue reference return? Todo
{
	Event event = events.front();
	events.pop();
	return event;
}
