#include "MainMenu.h"
#include <iostream>

#define BUTTONS_NUMBER 2

void MainMenu::SetInput(const sf::Event ev)
{
	newGame.SetInput(ev);
	quitGame.SetInput(ev);
}

void MainMenu::Init()
{
	//we could use graphic component, but in this case it's not neccessary
	InitGraphics();
	InitializeButtons();

	//	Testing texts
	txt1 = graphics.RequestText({ 50, 50 }, "SAMPLE TEXT1");
	txt1->setCharacterSize(10);
	txt1->setColor(sf::Color::Red);
	txt2 = graphics.RequestText({ 100, 100 }, "SAMPLE TEXT2");
	txt2->setCharacterSize(20);
	txt2->setColor(sf::Color::Green);
	txt3 = graphics.RequestText({ 150, 150 }, "SAMPLE TEXT3");
	txt3->setCharacterSize(30);
	txt3->setColor(sf::Color::Blue);

}

void MainMenu::Update(const sf::Time& timeStep)
{
	UpdateCloudAnimation();
	newGame.Update();
	quitGame.Update();
}

inline void MainMenu::InitializeButtons()
{
	for (int i = 0; i < BUTTONS_NUMBER; ++i)
		buttons[i].Init();

	constexpr float bottomPadding = BUTTON_HEIGHT + 50;
	constexpr float rightPadding = BUTTON_WIDTH + 60;
	constexpr float horizontalPosition = WINDOW_WIDTH - rightPadding;
	constexpr float baseVerticalPosition = WINDOW_HEIGHT - bottomPadding;

	for (int i = 0; i < BUTTONS_NUMBER; ++i)
	{
		const float verticalPosition = baseVerticalPosition - (BUTTONS_NUMBER - 1 - i) * BUTTON_HEIGHT;
		buttons[i].SetPosition({ horizontalPosition, verticalPosition });
	}
}

inline void MainMenu::InitGraphics()
{
	clouds_sid = graphics.RequestSprite(GraphicEngine::GraphicID::MenuBackgroundClouds, 0);
	uint8 sid = graphics.RequestSprite(GraphicEngine::GraphicID::MenuBackgroundTest, 0);
	graphics.SetPosition(sid, { 0, 0 });
}

inline void MainMenu::UpdateCloudAnimation()
{
	//reset position when it's half-way through
	if (graphics.GetPosition(clouds_sid).y < -WINDOW_HEIGHT)
		graphics.SetPosition(clouds_sid, { 0, 0 });
	graphics.MoveBy(clouds_sid, { 0, -1 });
}
