#pragma once
#include "State.h"

class GameMenu : public State
{
public:
	GameMenu(EventSystem& eventSystem, GraphicEngine& graphicEngine)
		: State(StateType::GameMenu, eventSystem, graphicEngine) {};
	void Update() override;

private:
	//Button enterShop;
	//Button enterBattle;
	//Button goBack;
	//InputCatcher input;

	//void InterpretInput();
};