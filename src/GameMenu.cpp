#include "GameMenu.h"
#include <iostream>

void GameMenu::Init()
{
	uint8 sid = graphics.RequestSprite(GraphicEngine::GraphicID::MenuBackground, 0);
	graphics.SetPosition(sid, { 0, 0 });
	enterShop.Init();
	enterBattle.Init();
	goBack.Init();
	enterShop.SetPosition({ 550, 340 });
	enterBattle.SetPosition({ 550, 420 });
	goBack.SetPosition({ 550, 500 });
}

void GameMenu::Update()
{
	enterShop.Update();
	enterBattle.Update();
	goBack.Update();
}

void GameMenu::SetInput(const sf::Event ev)
{
	enterShop.SetInput(ev);
	enterBattle.SetInput(ev);
	goBack.SetInput(ev);
}
