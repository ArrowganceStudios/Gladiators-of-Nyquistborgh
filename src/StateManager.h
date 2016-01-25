#pragma once
#include "ForwardDeclarations.h"
#include "DataKeeper.h"
#include "EventSystem.h"
#include "GraphicEngine.h"
#include "State.h"

class StateManager
{
public:
	StateManager(EventSystem& eventSystem, GraphicEngine& graphics, DataKeeper& dataKeeper)
		: eventSystem(eventSystem),
		  graphics(graphics),
		  dataKeeper(dataKeeper)
		  {};

	StateManager(StateManager const&) = delete;
	StateManager& operator=(StateManager const&) = delete;

	void ChangeState(StateType type);
	void Update();
	void PropagateEvent(const Event &ev);
	void PropagateInput(const sf::Event &ev);
private:
	State *GetCurState() { return state; }	//	in case of changed implementation of current state
	GraphicEngine& graphics;
	EventSystem& eventSystem;
	DataKeeper& dataKeeper;
	State* state; //or std::stack
	//^ it has to be a pointer since references cannot be rebounded.
};