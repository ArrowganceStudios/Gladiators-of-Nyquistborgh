#include "GameMenu.h"
#include <iostream>

void GameMenu::Update()
{
	//test purposes
	std::cout << "I'm in gameMenu" << std::endl;
	eventSystem.Add(Event(EventType::ExitProgram, (bool)true));
	system("pause");
}
