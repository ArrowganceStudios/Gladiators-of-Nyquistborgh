#include "GameMenu.h"
#include <iostream>

void GameMenu::Init()
{
	enterShop.Init();
	enterBattle.Init();
	goBack.Init();
	enterShop.SetPosition({ 300, 360 });
	enterBattle.SetPosition({ 300, 430 });
	goBack.SetPosition({ 300, 500 });
}

void GameMenu::Update()
{
	enterShop.SetInput(input);
	enterBattle.SetInput(input);
	goBack.SetInput(input);
	enterShop.Update();
	enterBattle.Update();
	goBack.Update();

	//test purposes
	//std::cout << "I'm in gameMenu" << std::endl;
	//eventSystem.Add(Event(EventType::ExitProgram));
	//system("pause");
}
