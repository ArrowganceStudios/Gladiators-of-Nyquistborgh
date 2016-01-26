#include "Core.h"
#include "Constants.h"

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
				event.type == sf::Event::MouseMoved ||
				event.type == sf::Event::KeyPressed)
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
	: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gladiators of Nyquistborgh"),
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
	dataKeeper.InitData(eventSystem, graphics);
	graphics.Init();
	dataKeeper.GetMainMenu()->Init();
	dataKeeper.GetGameMenu()->Init();
	stateManager.ChangeState(StateType::Intro); //starting state

	Loop();
}