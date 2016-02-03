#include "StateManager.h"
#include "MainMenu.h"
#include "GameMenu.h"

void StateManager::ChangeStateTo(std::function<State*()> getState)
{
	graphics.ResetSprites();
	state = getState();
	state->Init();
}

void StateManager::ChangeState(StateType type)
{
	switch (type)
	{
	case StateType::None:
		break;
	case StateType::MainMenu:
		ChangeStateTo([this] { return dataKeeper.GetMainMenu();});
		break;
	case StateType::GameMenu:
		ChangeStateTo([this] { return dataKeeper.GetGameMenu();});
		break;
	case StateType::Shop:
		break;
	case StateType::Battle:
		break;
	case StateType::Intro:
		ChangeStateTo([this] { return dataKeeper.GetIntro();});
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
