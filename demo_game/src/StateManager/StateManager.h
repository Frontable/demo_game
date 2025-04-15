





#pragma once
#include "State.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

class StateManager
{

private:
	std::unordered_map<StateID, State*>m_states;
	State* m_currentState;

public:

	StateManager(Context* t_context)
		:m_currentState(nullptr)
	{
		MainMenuState* mms = new MainMenuState(t_context);
		m_states[MainMenuID] = mms;
		m_currentState = mms;
		PausedState* ps = new PausedState(t_context);
		m_states[PausedID] = ps;

	}

	~StateManager()
	{
		m_states.clear();
	}

	void addState()
	{

	}

	void changeState(StateID t_id)
	{
		auto iter = m_states.find(t_id);
		if (iter != m_states.end())
		{
			m_currentState = iter->second;
		}

	}

	void ProcessInput(const uint8_t* state)
	{
		m_currentState->ProcessInput(state);
	}

	void Update(float t_deltaTime)
	{
		m_currentState->Update(t_deltaTime);
	}

	void Render(SDL_Renderer* t_renderer)
	{
		m_currentState->Render(t_renderer);
	}

};