#include "GameMenu.h"
#include <iostream>
#include "Constants.h"

#define BUTTONS_NUMBER 3

#define ANIM_BOX_DEBUG 0

void GameMenu::Init()
{
	InitGraphics();
	InitializeButtons();

#if ANIM_BOX_DEBUG
	anim.animationComponent.RequestTileset(2, 64, 64, 6);
	anim.animationComponent.graphicComponent.SetOrigin({ 32, 32 });
	anim.animationComponent.AddAnimation(0, 2, 500);
	anim.animationComponent.AddAnimation(3, 5, 500);
#endif
}

void GameMenu::Update(const sf::Time& timeStep)
{
	UpdateCloudAnimation();
	for (int i = 0; i < BUTTONS_NUMBER; ++i)
		buttons[i].Update();
#if ANIM_BOX_DEBUG
	anim.Update(timeStep);
#endif
}

void GameMenu::SetInput(const sf::Event ev)
{
#if ANIM_BOX_DEBUG
	if (ev.type == sf::Event::EventType::KeyPressed)
	{
		anim.animationComponent.Play(0);
		anim.physicsComponent.SetTarget(sf::Vector2f(32, 32), anim.velocity);
	}
	else if (ev.type == sf::Event::EventType::MouseButtonPressed)
	{
		anim.animationComponent.Play(1);
		anim.physicsComponent.SetTarget(sf::Vector2f((float)ev.mouseButton.x, (float)ev.mouseButton.y), anim.velocity);
	}
#endif
	enterShop.SetInput(ev);
	enterBattle.SetInput(ev);
	goBack.SetInput(ev);
}

inline void GameMenu::InitializeButtons()
{
	for (int i = 0; i < BUTTONS_NUMBER; ++i)
		buttons[i].Init();

	constexpr float bottomPadding = BUTTON_HEIGHT + 50;
	constexpr float rightPadding = BUTTON_WIDTH + 60;
	constexpr float horizontalPosition = WINDOW_WIDTH - rightPadding;
	constexpr float baseVerticalPosition = WINDOW_HEIGHT - bottomPadding;

	for (int i = 0; i < BUTTONS_NUMBER; ++i)
	{
		const float verticalPosition = baseVerticalPosition - (BUTTONS_NUMBER - 1 - i) * BUTTON_HEIGHT;
		buttons[i].SetPosition({ horizontalPosition, verticalPosition });
	}
}

inline void GameMenu::InitGraphics()
{
	clouds_sid = graphics.RequestSprite(GraphicEngine::GraphicID::MenuBackgroundClouds, 0);
	uint8 sid = graphics.RequestSprite(GraphicEngine::GraphicID::GameMenuBackground, 0);
	graphics.SetPosition(sid, { 0, 0 });
}

inline void GameMenu::UpdateCloudAnimation()
{
	//reset position when it's half-way through
	if (graphics.GetPosition(clouds_sid).y < -WINDOW_HEIGHT)
		graphics.SetPosition(clouds_sid, { 0, 0 });
	graphics.MoveBy(clouds_sid, { 0, -1 });
}
