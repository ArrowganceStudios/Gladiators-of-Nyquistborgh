#pragma once
#include "ForwardDeclarations.h"
#include "State.h"

class GameMenu : public State
{
public:
	GameMenu(EventSystem& eventSystem, GraphicEngine& graphicEngine)
		: State(StateType::GameMenu, eventSystem, graphicEngine),
		enterShop(graphics, GraphicEngine::GraphicID::MenuButtonNewGameStatic, [this] { this->RequestStateChange(StateType::Shop); }),
		enterBattle(graphics, GraphicEngine::GraphicID::MenuButtonNewGameStatic, [this] { this->RequestStateChange(StateType::Battle); }),
		goBack(graphics, GraphicEngine::GraphicID::MenuButtonNewGameStatic, [this] { this->RequestStateChange(StateType::MainMenu); })
	{

		//	TODO:	Button graphics...

	};
	void Init() override;
	void Update() override;

private:
	Button enterShop;
	Button enterBattle;
	Button goBack;
	//InputCatcher input;

	//void InterpretInput();
};