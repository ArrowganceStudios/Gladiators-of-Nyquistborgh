#include "MainMenu.h"
#include <iostream>

void MainMenu::Init()
{
	graphics.RequestSprite(GraphicEngine::GraphicID::MenuBackground, 0);
	//TODO: we have to provide some set of usable graphics to button, as currently
	//it cannot distinguish if it is quit or new game button
	newGame.Init();
	quitGame.Init();
	newGame.SetPosition({ 550, 430 });
	quitGame.SetPosition({ 550, 500 });

}

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
