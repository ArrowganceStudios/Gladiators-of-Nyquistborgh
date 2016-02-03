#include "GameMenu.h"
#include <iostream>

void GameMenu::Init()
{
	//we could use graphic component, but in this case it's not neccessary
	uint8 sid = graphics.RequestSprite(GraphicEngine::GraphicID::MenuBackground, 0);
	graphics.SetPosition(sid, { 0, 0 });
	enterShop.Init();
	enterBattle.Init();
	goBack.Init();
	enterShop.SetPosition({ 550, 340 });
	enterBattle.SetPosition({ 550, 420 });
	goBack.SetPosition({ 550, 500 });

	anim.animationComponent.RequestTileset(2, 64, 64, 6);
	anim.animationComponent.graphicComponent.SetOrigin({ 32, 32 });
	anim.animationComponent.AddAnimation(0, 2);
	anim.animationComponent.AddAnimation(3, 5);
}

void GameMenu::Update(const sf::Time& timeStep)
{
	enterShop.Update();
	enterBattle.Update();
	goBack.Update();

	anim.Update(timeStep);
}

void GameMenu::SetInput(const sf::Event ev)
{
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
	enterShop.SetInput(ev);
	enterBattle.SetInput(ev);
	goBack.SetInput(ev);
}
