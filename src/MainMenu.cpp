#include "MainMenu.h"
#include <iostream>

void MainMenu::Update()
{
	newGame.SetInput(input);
	quitGame.SetInput(input);
	newGame.Update();
	quitGame.Update();
	//test purposes
	//std::cout << "I'm inside the friggin main menu" << std::endl;
	//eventSystem.Add(Event(EventType::StateChange, StateType::GameMenu));
	//event system check ^
}
