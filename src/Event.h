#pragma once
#include "ForwardDeclarations.h"
//#include "State.h"

enum class EventType
{
	//stuff
	StateChange,
	ButtonClicked,
	PlayerAction, //idk bout that
	PlaySound, //idk bout that either
	ExitProgram
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
	Event(EventType type)
		: type(type), Value(false) {};

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