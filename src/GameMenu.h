#pragma once
#include "ForwardDeclarations.h"
#include "State.h"

class GameMenu : public State
{
public:
	GameMenu(EventSystem& eventSystem, GraphicEngine& graphicEngine)
		: State(eventSystem, graphicEngine),
		enterShop(graphics, GraphicEngine::GraphicID::GameButtonEnterShop, [this] { this->RequestStateChange(StateType::Shop); }),
		enterBattle(graphics, GraphicEngine::GraphicID::GameButtonEnterBattle, [this] { this->RequestStateChange(StateType::Battle); }),
		goBack(graphics, GraphicEngine::GraphicID::GameButtonGoBack, [this] { this->RequestStateChange(StateType::MainMenu); })
	{

	};
	void Init() override;
	void Update() override;
	void SetInput(const sf::Event ev) override;

private:
	Button enterShop;
	Button enterBattle;
	Button goBack;
};