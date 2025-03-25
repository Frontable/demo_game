







#include "Game.h"
#include <iostream>

Game::Game()
	:mWindow(nullptr)
	,mRenderer(nullptr)
	,isRunning(true)
	,componentManager(entityManager)
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
		
	
	
	systemManager.registerSystem<RenderSystem>();
	systemManager.getSystem<RenderSystem>()->renderer = mRenderer;
	systemManager.getSystem<RenderSystem>()->componentManager = &componentManager;


	Entity e1 = entityManager.createEntity();
	entities.insert(e1);

	systemManager.getSystem<RenderSystem>()->entities = entities;

	componentManager.registerComponent<Position>();
	componentManager.registerComponent<Velocity>();
	componentManager.registerComponent<BoxComponent>();
	componentManager.addComponent(e1, Position{0.0f, 0.0f});
	componentManager.addComponent(e1, Velocity{0.0f, 0.0f});
	componentManager.addComponent(e1, BoxComponent(0,0,100,100));


	
	return true;

}

void Game::processInput()
{

	SDL_Event e;
	const uint8_t* state = SDL_GetKeyboardState(NULL);

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

	systemManager.getSystem<RenderSystem>()->update();

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