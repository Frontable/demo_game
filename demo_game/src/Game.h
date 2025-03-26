





#pragma once
#include "SDL.h"
#include "SystemManager.h"


class Game
{
public:
	Game();

	bool initialize();
	void run();
	void shutDown();

	bool running() const { return isRunning; }

private:

	void processInput();
	void update();
	void generateOutput();

	bool isRunning;

	float mLastTick;
	float mCurrTick;
	float deltaTime;


	std::set<Entity> entities;

	Entity player;

	int mouseX, mouseY;

	EntityManager entityManager;
	ComponentManager componentManager;
	SystemManager systemManager;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

};