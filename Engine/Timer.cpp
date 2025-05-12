






#include "Timer.h"
#include <iostream>

Timer* Timer::m_instance = nullptr;

Timer::Timer()
{

}

Timer* Timer::getInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new Timer();
		return m_instance;
	}
	else
	{
		return m_instance;
	}
}

void Timer::calculateDeltaTime()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

	m_deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
	if (m_deltaTime > 0.05f)
	{
		m_deltaTime = 0.05f;
	}
	mTicksCount = SDL_GetTicks();

	std::cout << m_deltaTime << std::endl;

}

float Timer::getDeltaTime()
{
	return m_deltaTime;
}