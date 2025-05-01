





#include "StateMachine.h"


void StateMachine::pushState(GameState* state)
{
	if (!m_states.empty())
	{
		m_states.top()->exit();
	}

	state->enter();
	m_states.push(state);

}
void StateMachine::popState()
{
	if (!m_states.empty())
	{
		GameState* oldState = m_states.top();
		m_states.top()->exit();
		m_states.pop();
		delete oldState;
	}

	if (!m_states.empty())
	{
		m_states.top()->enter();
	}

}

void StateMachine::changeState(GameState* state)
{
	while (!m_states.empty())
	{
		GameState* oldState = m_states.top();
		m_states.top()->exit();
		m_states.pop();
		delete oldState;
	}

	state->enter();
	m_states.push(state);

}

void StateMachine::changeStates(std::unique_ptr<GameState> state)
{
	while (!m_sta.empty())
	{
		m_sta.top()->exit();
		m_sta.pop();
	}

	state->enter();
	m_sta.push(std::move(state));
}

GameState* StateMachine::getCurrentState()
{
	return m_states.top();
}

void StateMachine::processInput(SDL_Event& event)
{
	if (!m_states.empty())
	{
		m_states.top()->processInput(event);
	}
}
void StateMachine::update(float deltaTime)
{
	if (!m_states.empty())
	{
		m_states.top()->update(deltaTime);
	}
}
void StateMachine::render()
{
	if (!m_states.empty())
	{
		m_states.top()->render();
	}
}