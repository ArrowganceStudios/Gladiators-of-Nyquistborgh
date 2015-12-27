#include "StateManager.h"

void StateManager::ChangeState(StateType type)
{
	state = State(type);
}

void StateManager::Update()
{
	state.Update();
}
