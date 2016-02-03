#pragma once
#include "ForwardDeclarations.h"
#include "State.h"
#include "AnimationComponent.h"

class GameMenu : public State
{
public:
	GameMenu(EventSystem& eventSystem, GraphicEngine& graphicEngine)
		: State(eventSystem, graphicEngine),
		enterShop(graphics, GraphicEngine::GraphicID::GameButtonEnterShop, [this] { this->RequestStateChange(StateType::Shop); }),
		enterBattle(graphics, GraphicEngine::GraphicID::GameButtonEnterBattle, [this] { this->RequestStateChange(StateType::Battle); }),
		goBack(graphics, GraphicEngine::GraphicID::GameButtonGoBack, [this] { this->RequestStateChange(StateType::MainMenu); }),
		anim(graphicEngine)
	{

	};
	void Init() override;
	void Update() override;
	void SetInput(const sf::Event ev) override;

private:
	Button enterShop;
	Button enterBattle;
	Button goBack;

	struct AnimationEffectTEST
	{
		AnimationComponent animationComponent;

		AnimationEffectTEST(GraphicEngine& graphicEngine)
			: animationComponent(graphicEngine, GraphicEngine::GraphicID::TestColorAnim)
		{};
	};
	AnimationEffectTEST anim;
};