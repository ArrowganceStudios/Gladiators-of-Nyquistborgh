#include "Intro.h"

void Intro::Init()
{
	logo_sid = graphics.RequestSprite(GraphicEngine::GraphicID::IntroLogo, 1);
	graphics.SetPosition(logo_sid, {135, 2*110});
	clock.restart();
}

void Intro::Update()
{
	if (clock.getElapsedTime().asSeconds() > 3.0f)
	{
		RequestStateChange(StateType::MainMenu);
	}
	graphics.SetAlpha(logo_sid, 1.0f - (clock.getElapsedTime().asSeconds() / 3.0f));
}

void Intro::SetInput(const sf::Event ev)
{
	if (ev.type == sf::Event::KeyPressed)
		RequestStateChange(StateType::MainMenu);
}
