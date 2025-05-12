






#pragma once
#include "SDL.h"

#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

class ENGINE_API Timer
{
private:
	Timer();
	static Timer* m_instance;

	float mTicksCount;
	float m_lastTick;

	float m_deltaTime;

public:
	Timer* getInstance();

	void calculateDeltaTime();

	float getDeltaTime();
};