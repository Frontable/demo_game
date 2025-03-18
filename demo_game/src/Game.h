





#pragma once
#include "SDL.h"
#include "SDL_image.h"
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

	EntityManager entityManager;
	ComponentManager* componentManager;
	RenderSystem renderSystem;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

};