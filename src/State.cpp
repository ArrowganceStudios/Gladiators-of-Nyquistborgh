#include "State.h"

State::State(StateType type, EventSystem & eventSystem, GraphicEngine & graphics)
	: eventSystem(eventSystem), graphics(graphics)
{
}

void State::RequestStateChange(StateType toState)
{
	this->eventSystem.Add(Event(EventType::StateChange, toState));
}

void State::SendEvent(EventType evType)
{
	this->eventSystem.Add(Event(evType));
}

void State::SendEvent(EventType evType, bool val)
{
	this->eventSystem.Add(Event(evType, val));
}

void State::SendEvent(EventType evType, int val)
{
	this->eventSystem.Add(Event(evType, val));
}

void State::SendEvent(EventType evType, float val)
{
	this->eventSystem.Add(Event(evType, val));
}
