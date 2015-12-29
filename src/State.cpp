#include "State.h"

State::State(StateType type, EventSystem & eventSystem, GraphicEngine & graphics)
	: type(type), eventSystem(eventSystem), graphics(graphics)
{
}

State::State(State const & other)
	: type(other.type), eventSystem(other.eventSystem), graphics(other.graphics)
{
}

//State & State::operator=(State const & other)
//{
//	type = other.type;
//	return (*this);
//}