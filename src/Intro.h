#pragma once
#include "ForwardDeclarations.h"
#include "State.h"

class Intro : public State
{
public:
	Intro(EventSystem& eventSystem, GraphicEngine& graphicEngine)
		: State(eventSystem, graphicEngine) {}

	void Init() override;
	void Update(const sf::Time& timeStep) override;
	void SetInput(const sf::Event ev) override;
private:
	uint8 logo_sid;
	sf::Time timeElapsed;
};