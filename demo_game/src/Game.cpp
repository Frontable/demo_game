







#include "Game.h"
#include <iostream>

Game::Game()
	:mWindow(nullptr)
	,mRenderer(nullptr)
	,isRunning(true)
	,componentManager(new ComponentManager())
{

}


bool Game::initialize()
{

	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) != 0)
	{
		printf("Failed to initialize SDL: %s \n", SDL_GetError());
		return false;
	}

	mWindow = SDL_CreateWindow("Game", 100, 100, 1024, 768, 0);
	if (mWindow == NULL)
	{
		printf("Failed to create window: %s \n", SDL_GetError());
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mRenderer == NULL)
	{
		printf("Failed to create renderer: %s \n", SDL_GetError());
		return false;
	}
		
	


	renderSystem.renderer = mRenderer;
	renderSystem.componentManager = componentManager;

	Entity e1 = entityManager.createEntity();
	componentManager->registerComponent<Position>();
	componentManager->registerComponent<BoxComponent>();

	componentManager->addComponent(e1, Position{ 1,1 });
	componentManager->addComponent(e1, BoxComponent(1,1,100,100));

	renderSystem.entities.insert(e1);



	return true;

}

void Game::processInput()
{

	SDL_Event e;
	while (SDL_PollEvent(&e))
	{

		switch (e.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
		}

	}

}

void Game::update()
{

}

void Game::generateOutput()
{

	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
	SDL_RenderClear(mRenderer);

	renderSystem.update();

	SDL_RenderPresent(mRenderer);

}

void Game::run()
{

	processInput();
	update();
	generateOutput();
}

void Game::shutDown()
{

	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();

}