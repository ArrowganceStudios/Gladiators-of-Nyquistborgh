#include <Windows.h>
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
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::F8)
					ToggleFullscreen();
			}
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

void Core::ToggleFullscreen()
{
	static bool fullscreen = true; //lol
	if (fullscreen)
	{
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gladiators of Nyquistborgh", sf::Style::Fullscreen);
		view = sf::View({ WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f }, { WINDOW_WIDTH, WINDOW_HEIGHT });
		if (aspectRatio > 1.4f) //== not 4 : 3
		{ //please kill me for writing this 
			const float panoramicRatio = 1.f / aspectRatio;
			view.setViewport(sf::FloatRect((1 - panoramicRatio) / 2.f, 0.0f, panoramicRatio, 1.f));
			window.setView(view);
		}
		fullscreen = false;
	}
	else
	{
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gladiators of Nyquistborgh", sf::Style::Close | sf::Style::Titlebar);
		fullscreen = true;
	}

}

Core::Core()
	: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gladiators of Nyquistborgh", sf::Style::Close | sf::Style::Titlebar), //sf::Style::Fullscreen
	dataKeeper(),
	graphics(window, dataKeeper), audio(), eventSystem(),
	stateManager(eventSystem, graphics, dataKeeper)
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	aspectRatio = float(screenWidth) / float(screenHeight);
}

void Core::Run()
{
	//inits
	dataKeeper.InitData(eventSystem, graphics);
	graphics.Init();
	stateManager.ChangeState(StateType::Intro); //starting state

	Loop();
}