#pragma once
#include "ForwardDeclarations.h"
#include "State.h"
#include "AnimationComponent.h"
#include "PhysicsComponent.h"

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
	void Update(const sf::Time& timeStep) override;
	void SetInput(const sf::Event ev) override;

private:
	Button enterShop;
	Button enterBattle;
	Button goBack;

	//	OBJECT FOR TESTING NEW FUNCTIONALITIES
	struct AnimationEffectTEST
	{
		AnimationComponent animationComponent;
		PhysicsComponent physicsComponent;

		sf::Vector2f position;
		float velocity;
		float factorAcc;

		AnimationEffectTEST(GraphicEngine& graphicEngine)
			: animationComponent(graphicEngine, GraphicEngine::GraphicID::TestColorAnim)
		{
			position = { 32, 32 };
			velocity = 200;
			factorAcc = 0;
		};
		void Update(const sf::Time& timeStep)
		{
			factorAcc += timeStep.asSeconds();
			animationComponent.Update();
			animationComponent.graphicComponent.SetPosition(position);
			animationComponent.graphicComponent.SetRotation(50*sinf(factorAcc * 2));
			animationComponent.graphicComponent.SetScale(1 + 0.2f*sinf(factorAcc));

			physicsComponent.UpdatePosition(timeStep, position);
		}
	};
	AnimationEffectTEST anim;
};