#include "Intro.h"

#define DURATION 3.0f

void Intro::Init()
{
	logo_sid = graphics.RequestSprite(GraphicEngine::GraphicID::IntroLogo, 1);
	graphics.SetPosition(logo_sid, {135, 220}); //we should do some simple alignment
												//like center, left top, bottom etc.
												//and conjunction using flags
	clock.restart();
}

void Intro::Update()
{
	if (clock.getElapsedTime().asSeconds() > DURATION)
		RequestStateChange(StateType::MainMenu);

	graphics.SetAlpha(logo_sid, 1.0f - (clock.getElapsedTime().asSeconds() / DURATION));
}

void Intro::SetInput(const sf::Event ev)
{
	if (ev.type == sf::Event::KeyPressed)
		RequestStateChange(StateType::MainMenu);
}
