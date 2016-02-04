#pragma once
#include "ForwardDeclarations.h"
#include "State.h"

class MainMenu : public State
{
public:
	MainMenu(EventSystem& eventSystem, GraphicEngine& graphicEngine)
		: State(eventSystem, graphicEngine),
		newGame(graphics, GraphicEngine::GraphicID::MenuButtonNewGame, [this] { RequestStateChange(StateType::GameMenu); }),
		quitGame(graphics, GraphicEngine::GraphicID::MenuButtonQuit, [this] { SendEvent(EventType::ExitProgram); }),
		buttons(&newGame)
	{
	}

	void SetInput(const sf::Event ev) override;
	void Init() override;
	void Update(const sf::Time& timeStep) override;
private:
	Button newGame;
	Button quitGame;

	Button* buttons;

	uint8 clouds_sid;

	inline void InitializeButtons();
	inline void InitGraphics();
	inline void UpdateCloudAnimation();
};
