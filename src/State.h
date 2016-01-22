#pragma once
#include <queue>
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
	void PushEvent(const Event ev) { eventQueue.push(ev); }

private:
	StateType type; //prolly not needed in a fact TODO: remove if unused
	std::queue<Event> eventQueue;
protected:
	GraphicEngine& graphics;
	EventSystem& eventSystem;
};
