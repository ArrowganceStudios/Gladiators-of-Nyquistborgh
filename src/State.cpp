#include "State.h"

State::State(StateType type, EventSystem & eventSystem, GraphicEngine & graphics)
	: type(type), eventSystem(eventSystem), graphics(graphics)
{
}

State::State(State const & other)
	: type(other.type), eventSystem(other.eventSystem), graphics(other.graphics)
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
	Event ev = Event(evType, val);
	this->eventSystem.Add(Event(evType, val));
}

//State & State::operator=(State const & other)
//{
//	type = other.type;
//	return (*this);
//}