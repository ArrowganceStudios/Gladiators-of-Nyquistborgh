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
	State(StateType type, EventSystem& eventSystem, GraphicEngine& graphics);

	State(State const& other);
	//State& operator=(State const& other);

	virtual void Init() = 0;
	virtual void Update() = 0;
	void PushEvent(const Event ev) { eventQueue.push(ev); }
	void SetInput(const sf::Event ev) { input = ev; };

private:
	StateType type; //prolly not needed in a fact TODO: remove if unused
	std::queue<Event> eventQueue;	//	TODO: po co
protected:
	GraphicEngine& graphics;
	EventSystem& eventSystem;
	sf::Event input;

	void RequestStateChange(StateType toState);
	void SendEvent(EventType evType);
	void SendEvent(EventType evType, bool val);
	void SendEvent(EventType evType, int val);
	void SendEvent(EventType evType, float val);


};
