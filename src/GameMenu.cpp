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
	anim.animationComponent.AddAnimation(0, 2);
	anim.animationComponent.AddAnimation(3, 5);
}

void GameMenu::Update()
{
	enterShop.Update();
	enterBattle.Update();
	goBack.Update();

	anim.animationComponent.Update();
}

void GameMenu::SetInput(const sf::Event ev)
{
	if(ev.type == sf::Event::EventType::KeyPressed)
		anim.animationComponent.Play(0);
	else if (ev.type == sf::Event::EventType::MouseButtonPressed)
		anim.animationComponent.Play(1);
	enterShop.SetInput(ev);
	enterBattle.SetInput(ev);
	goBack.SetInput(ev);
}
