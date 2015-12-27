#include "Core.h"

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
		//stateManager.Update(); // TODO
		graphics.RenderScene();	// calls window.clear() and window.display()
	}
}

Core::Core()
	: window(sf::VideoMode(200, 200), "Gladiators of Nyquistborgh"), stateManager(),
	graphics(window), audio()
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);

	//stateManager.ChangeState(StateType::MainMenu); //starting state //TBI
}

void Core::Run()
{
	//inits
	//...
	Loop();
}