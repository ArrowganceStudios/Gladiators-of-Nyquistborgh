#pragma once

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
	State(StateType type)
		: type(type) {}

	//copy constructor and assignment operator to be written (todo)

	void Update();

private:
	StateType type;
	//Module& module

};