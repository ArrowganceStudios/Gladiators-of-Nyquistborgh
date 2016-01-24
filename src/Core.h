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
public:
	sf::RenderWindow window; //temp
private:
	//temp
	MainMenu mainMenu; //delete when datakeeper is implemented

	void Loop();

public:
	Core();

	Core(Core const&) = delete;
	Core& operator=(Core const&) = delete;

	void Run();
};