#include "Intro.h"
#include "Constants.h"

#define DURATION 2.0f

void Intro::Init()
{
	logo_sid = graphics.RequestSprite(GraphicEngine::GraphicID::IntroLogo, 1);

	constexpr float logoWidth = 530;
	constexpr float logoHeight = 190;

	constexpr float verticalPosition = WINDOW_WIDTH / 2 - logoWidth / 2;
	constexpr float horizontalPosition = WINDOW_HEIGHT / 2 - logoHeight/ 2;

	graphics.SetPosition(logo_sid, {verticalPosition, horizontalPosition}); //we should do some simple alignment
												//like center, left top, bottom etc.
												//and conjunction using flags
	//135, 220
	timeElapsed = sf::Time::Zero;
	txtVersion = graphics.RequestText({ 0, 0 }, "Gladiator of Nyquistborgh v0.1");
	txtVersion->setColor(sf::Color::Black);
	txtVersion->setCharacterSize(12);
}

void Intro::Update(const sf::Time& timeStep)
{
	timeElapsed += timeStep;
	if(timeElapsed > sf::seconds(DURATION))
		RequestStateChange(StateType::MainMenu);

	graphics.SetAlpha(logo_sid, 1.0f - (timeElapsed.asSeconds() / DURATION));
}

void Intro::SetInput(const sf::Event ev)
{
	if (ev.type == sf::Event::KeyPressed)
		RequestStateChange(StateType::MainMenu);
}
