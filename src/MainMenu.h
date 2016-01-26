#pragma once
#include "ForwardDeclarations.h"
#include "State.h"

class MainMenu : public State
{
public:
	MainMenu(EventSystem& eventSystem, GraphicEngine& graphicEngine)
		: State(eventSystem, graphicEngine),
		newGame(graphics, GraphicEngine::GraphicID::MenuButtonNewGameStatic, [this] { RequestStateChange(StateType::GameMenu); }),
		quitGame(graphics, GraphicEngine::GraphicID::MenuButtonQuitStatic, [this] { SendEvent(EventType::ExitProgram); })
	{
	}

	void SetInput(const sf::Event ev) override;
	void Init() override;
	void Update() override;
private:
	Button newGame;
	Button quitGame;
};
