#pragma once
#include "ForwardDeclarations.h"
#include "DataKeeper.h"
#include "StateManager.h"
#include "GraphicEngine.h"
#include "AudioEngine.h"
#include "EventSystem.h"
#include "MainMenu.h"

class Core
{
private:
	DataKeeper dataKeeper;
	StateManager stateManager;
	EventSystem eventSystem;
	GraphicEngine graphics;
	AudioEngine audio;
	sf::RenderWindow window;
	bool fullscreen;

	void Loop();
	void ToggleFullscreen();

public:
	Core();

	Core(Core const&) = delete;
	Core& operator=(Core const&) = delete;

	void Run();
};