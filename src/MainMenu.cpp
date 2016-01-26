#include "MainMenu.h"
#include <iostream>

void MainMenu::SetInput(const sf::Event ev)
{
	newGame.SetInput(ev);
	quitGame.SetInput(ev);
}

void MainMenu::Init()
{
	uint8 sid = graphics.RequestSprite(GraphicEngine::GraphicID::MenuBackground, 0);
	graphics.SetPosition(sid, { 0, 0 });
	newGame.Init();
	quitGame.Init();
	newGame.SetPosition({ 550, 420 });
	quitGame.SetPosition({ 550, 500 });
}

void MainMenu::Update()
{
	newGame.Update();
	quitGame.Update();
}
