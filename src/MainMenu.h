#pragma once
#include "ForwardDeclarations.h"
#include "State.h"
#include "BaseTypes.h"
#include "Button.h"


class MainMenu : public State
{
public:
	MainMenu(EventSystem& eventSystem, GraphicEngine& graphicEngine)
		: State(StateType::MainMenu, eventSystem, graphicEngine),
		newGame(graphics, GraphicEngine::GraphicID::MenuButtonNewGameStatic, [] {}), 
		quitGame(graphics, GraphicEngine::GraphicID::MenuButtonQuitStatic, [] {}) 
	{
		graphics.RequestSprite(GraphicEngine::GraphicID::MenuBackground, 0);
		//TODO: we have to provide some set of usable graphics to button, as currently
		//it cannot distinguish if it is quit or new game button
		newGame.SetPosition({ 550, 430 });
		quitGame.SetPosition({ 550, 500 });
	}



	void Update() override;
private:
	Button newGame;
	Button quitGame;
};
