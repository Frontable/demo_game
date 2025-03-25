





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

	std::set<Entity> entities;

	EntityManager entityManager;
	ComponentManager componentManager;
	SystemManager systemManager;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

};