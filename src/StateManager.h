#pragma once
#include "EventSystem.h"
#include "State.h"

class StateManager
{
public:
	StateManager(EventSystem& eventSystem)
		: eventSystem(eventSystem), state(StateType::None) {};

	void ChangeState(StateType type);
	void Update();
private:
	EventSystem& eventSystem;
	State state; //or std::stack
};