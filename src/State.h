#pragma once
#include "ForwardDeclarations.h"
#include "EventSystem.h"
#include "GraphicEngine.h"

enum class StateType
{
	None,
	MainMenu,
	GameMenu,
	Intro,
	Shop,
	Battle
};

class State
{
public:
	State(StateType type, EventSystem& eventSystem, GraphicEngine& graphics);

	State(State const& other);
	//State& operator=(State const& other);

	virtual void Update() = 0;

private:
	StateType type; //prolly not needed in a fact TODO: remove if unused
protected:
	GraphicEngine& graphics;
	EventSystem& eventSystem;
};
