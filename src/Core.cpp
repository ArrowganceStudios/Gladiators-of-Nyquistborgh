#include "Core.h"
#include "Constants.h"

void Core::Loop()
{
	sf::Clock clock;
	sf::Time updateTime = sf::Time::Zero;
	const sf::Time perFrameTime = sf::seconds(1.f / (float)DEF_FPS);

	while (window.isOpen())
	{
		updateTime += clock.restart();

		while (updateTime > perFrameTime)
		{
			updateTime -= perFrameTime;

			stateManager.Update(perFrameTime);

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
		}
		graphics.RenderScene();	// calls window.clear() and window.display()
	}
}

void Core::ToggleFullscreen()
{
	fullscreen = true; 
	if (fullscreen)
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gladiators of Nyquistborgh", sf::Style::Fullscreen);
	else
		window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gladiators of Nyquistborgh", sf::Style::Close | sf::Style::Titlebar);

	fullscreen = !fullscreen;
}

Core::Core()
	: window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Gladiators of Nyquistborgh", sf::Style::Close | sf::Style::Titlebar), //sf::Style::Fullscreen
	dataKeeper(), fullscreen(false),
	graphics(window, dataKeeper), audio(), eventSystem(),
	stateManager(eventSystem, graphics, dataKeeper)
{
	window.setFramerateLimit(60);
	window.setVerticalSyncEnabled(true);
	//perhaps one day the below will be used
	//int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	//int screenHeight = GetSystemMetrics(SM_CYSCREEN);
}

void Core::Run()
{
	//inits
	dataKeeper.InitData(eventSystem, graphics);
	graphics.Init();
	//stateManager.ChangeState(StateType::Intro); //default starting state
	stateManager.ChangeState(StateType::GameMenu); //let's don't waste time aight

	Loop();
}