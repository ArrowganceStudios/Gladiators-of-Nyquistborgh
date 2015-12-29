#pragma once
#include "State.h"

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
		: type(type), Value(value) {};
	Event(EventType type, int value)
		: type(type), Value(value) {};
	Event(EventType type, float value)
		: type(type), Value(value) {};
	Event(EventType type, StateType value)
		: type(type), Value(value) {};

	EventType type;
	union Value
	{
		bool Boolean;
		int Integer;
		float Float; //to be checked if ever used
		StateType State;

		Value(bool value) : Boolean(value) {};
		Value(int value) : Integer(value) {};
		Value(float value) : Float(value) {};
		Value(StateType value) : State(value) {};

	} Value;
};