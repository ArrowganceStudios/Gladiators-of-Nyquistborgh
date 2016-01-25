#include "GameMenu.h"
#include <iostream>

void GameMenu::Init()
{
	enterShop.Init();
	enterBattle.Init();
	goBack.Init();
	enterShop.SetPosition({ 300, 340 });
	enterBattle.SetPosition({ 300, 420 });
	goBack.SetPosition({ 300, 500 });
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
