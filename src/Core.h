#pragma once
#include "StateManager.h"
#include "GraphicEngine.h"
#include "AudioEngine.h"

class Core
{
private:
	StateManager stateManager;
	GraphicEngine graphics;
	AudioEngine audio;
	sf::RenderWindow window;

	void Loop();

public:
	Core();

	void Run();
};