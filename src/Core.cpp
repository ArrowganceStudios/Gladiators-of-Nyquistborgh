#include "Core.h"

static unsigned int windowWidth = 800;
static unsigned int windowHeight = 600;

void Core::Loop()
{
	while (window.isOpen())
	{
		stateManager.Update();
		

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed ||
				event.type == sf::Event::MouseButtonReleased ||
				event.type == sf::Event::MouseMoved)
				stateManager.PropagateInput(event);
		}
		while (!eventSystem.IsQueueEmpty())
		{
			Event event = eventSystem.Get();
			switch (event.type)
			{
			case EventType::StateChange:
				stateManager.ChangeState(event.Value.State);
				break;
			case EventType::ButtonClicked:
			case EventType::PlayerAction:
			case EventType::PlaySound:
				stateManager.PropagateEvent(event);
				break;
			case EventType::ExitProgram:
				window.close();
				break;
			default:
				break;
			}
		}
		graphics.RenderScene();	// calls window.clear() and window.display()
	}
}

Core::Core()
	: window(sf::VideoMode(windowWidth, windowHeight), "Gladiators of Nyquistborgh"),
	dataKeeper(),
	graphics(window, dataKeeper), audio(), eventSystem(), 
	stateManager(eventSystem, graphics, dataKeeper)
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
}

void Core::Run()
{
	//inits
	//...
	//graphics.LoadTextures();
	dataKeeper.InitData(eventSystem, graphics);
	graphics.Init();
	dataKeeper.GetMainMenu()->Init();
	dataKeeper.GetGameMenu()->Init();
	stateManager.ChangeState(StateType::MainMenu); //starting state

	Loop();
}