#include "StateManager.h"
#include "MainMenu.h"
#include "GameMenu.h"

void StateManager::ChangeState(StateType type)
{
	switch (type)
	{
	case StateType::None:
		break;
	case StateType::MainMenu:
		state = dataKeeper.GetMainMenu();
		break;
	case StateType::GameMenu:
		state = dataKeeper.GetGameMenu();
		break;
	case StateType::Intro:
		break;
	case StateType::Shop:
		break;
	case StateType::Battle:
		break;
	default:
		break;
	}
}

void StateManager::Update()
{
	state->Update();
}

void StateManager::PropagateEvent(const Event &ev)
{
	GetCurState()->PushEvent(ev);
}

void StateManager::PropagateInput(const sf::Event & ev)
{
	GetCurState()->SetInput(ev);
}
