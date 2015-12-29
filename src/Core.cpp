#include "Core.h"

static unsigned int windowWidth = 800;
static unsigned int windowHeight = 600;

void Core::Loop()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
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
				break;
			case EventType::PlayerAction:
				break;
			case EventType::PlaySound:
				break;
			default:
				break;
			}
		}

		stateManager.Update();
		graphics.RenderScene();	// calls window.clear() and window.display()
	}
}

Core::Core()
	: window(sf::VideoMode(windowWidth, windowHeight), "Gladiators of Nyquistborgh"),
	graphics(window), audio(), eventSystem(), mainMenu(eventSystem, graphics), 
	stateManager(eventSystem, graphics, &mainMenu)
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	stateManager.ChangeState(StateType::MainMenu); //starting state //TBI
}

void Core::Run()
{
	//inits
	//...
	Loop();
}