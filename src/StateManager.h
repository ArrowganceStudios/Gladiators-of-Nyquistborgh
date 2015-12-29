#pragma once
#include "ForwardDeclarations.h"
#include "EventSystem.h"
#include "GraphicEngine.h"
#include "State.h"

class StateManager
{
public:
	StateManager(EventSystem& eventSystem, GraphicEngine& graphics, State* initialState)
		: eventSystem(eventSystem),
		  state(initialState),
		  graphics(graphics)
		  {};

	void ChangeState(StateType type);
	void Update();
private:
	GraphicEngine& graphics;
	EventSystem& eventSystem;
	State* state; //or std::stack
	//^ it has to be a pointer since references cannot be rebounded.
};