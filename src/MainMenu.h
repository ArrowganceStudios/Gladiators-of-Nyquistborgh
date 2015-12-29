#pragma once
#include "ForwardDeclarations.h"
#include "State.h"

class MainMenu : public State
{
public:
	MainMenu(EventSystem& eventSystem, GraphicEngine& graphicEngine)
		: State(StateType::MainMenu, eventSystem, graphicEngine) {};


	void Update() override;
private:
	//Button newGame;
	//Button quitGame;
	//InputCatcher input;
	
	//void InterpretInput();
};