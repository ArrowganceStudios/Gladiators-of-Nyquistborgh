#include "MainMenu.h"
#include <iostream>

void MainMenu::SetInput(const sf::Event ev)
{
	newGame.SetInput(ev);
	quitGame.SetInput(ev);
}

void MainMenu::Init()
{
	//we could use graphic component, but in this case it's not neccessary
	uint8 sid = graphics.RequestSprite(GraphicEngine::GraphicID::MenuBackground, 0);
	graphics.SetPosition(sid, { 0, 0 });
	newGame.Init();
	quitGame.Init();
	newGame.SetPosition({ 550, 420 });
	quitGame.SetPosition({ 550, 500 });
}

void MainMenu::Update(const sf::Time& timeStep)
{
	newGame.Update();
	quitGame.Update();
}
