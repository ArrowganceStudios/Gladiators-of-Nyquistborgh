#pragma once
#include <queue>

enum class EventType
{
	//stuff
	StateChange,
	ButtonClicked,
	PlayerAction, //idk bout that
	PlaySound //idk bout that either
};

struct Event
{
	Event(EventType type, bool value)
		: type(type), Value(value) {}
	Event(EventType type, int value)
		: type(type), Value(value) {}
	Event(EventType type, float value)
		: type(type), Value(value) {}

	EventType type;
	union Value
	{
		bool Boolean;
		int Integer;
		float Float; //to be checked if ever used
		//StateType State;

		Value(bool value) : Boolean(value) {};
		Value(int value) : Integer(value) {};
		Value(float value) : Float(value) {};
	} Value;
};

class EventSystem
{
public:
	//disable copy
	EventSystem() = default;
	EventSystem(EventSystem const&) = delete;
	EventSystem& operator=(EventSystem const&) = delete;

	void Add(Event&& event);
	Event Get();
	bool IsQueueEmpty() { return events.size() == 0; };

private:
	std::queue<Event> events;
};