#pragma once
#include "StateManager.h"
#include "GraphicEngine.h"
#include "AudioEngine.h"
#include "EventSystem.h"

class Core
{
private:
	StateManager stateManager;
	EventSystem eventSystem;
	GraphicEngine graphics;
	AudioEngine audio;
	sf::RenderWindow window;

	void Loop();

public:
	Core();

	Core(Core const&) = delete;
	Core& operator=(Core const&) = delete;

	void Run();
};