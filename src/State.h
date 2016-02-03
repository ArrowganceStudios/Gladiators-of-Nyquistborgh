#pragma once
#include <queue>
#include "ForwardDeclarations.h"
#include "EventSystem.h"
#include "GraphicEngine.h"
#include "BaseTypes.h"
#include "Button.h"


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
	State(EventSystem& eventSystem, GraphicEngine& graphics);

	State(State const& other) = delete;
	State& operator=(State const& other) = delete;

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void SetInput(const sf::Event ev) = 0;
	void PushEvent(const Event ev) { eventQueue.push(ev); }

private:
	std::queue<Event> eventQueue;
protected:
	GraphicEngine& graphics;
	EventSystem& eventSystem;

	void RequestStateChange(StateType toState);
	void SendEvent(EventType evType);
	void SendEvent(EventType evType, bool val);
	void SendEvent(EventType evType, int val);
	void SendEvent(EventType evType, float val);
};
