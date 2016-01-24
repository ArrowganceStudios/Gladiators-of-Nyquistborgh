#pragma once
#include "ForwardDeclarations.h"
#include "State.h"

class MainMenu : public State
{
public:
	MainMenu(EventSystem& eventSystem, GraphicEngine& graphicEngine)
		: State(StateType::MainMenu, eventSystem, graphicEngine),
		newGame(graphics, GraphicEngine::GraphicID::MenuButtonNewGameStatic, [this] { RequestStateChange(StateType::GameMenu); }),
		quitGame(graphics, GraphicEngine::GraphicID::MenuButtonQuitStatic, [this] { SendEvent(EventType::ExitProgram); })
	{
	}


	void Init() override;
	void Update() override;
private:
	Button newGame;
	Button quitGame;
};
