







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
		
	mLastTick = SDL_GetTicks();
	
	systemManager.registerSystem<RenderSystem>();
	systemManager.registerSystem<MovementSystem>();
	systemManager.registerSystem<InputSystem>();
	systemManager.getSystem<RenderSystem>()->renderer = mRenderer;
	systemManager.getSystem<RenderSystem>()->componentManager = &componentManager;
	systemManager.getSystem<MovementSystem>()->componentManager = &componentManager;
	systemManager.getSystem<InputSystem>()->componentManager = &componentManager;


	Entity e1 = entityManager.createEntity();
	entities.insert(e1);

	Entity e2 = entityManager.createEntity();
	entities.insert(e2);

	componentManager.registerComponent<Position>();
	componentManager.registerComponent<Velocity>();
	componentManager.registerComponent<BoxComponent>();
	componentManager.addComponent(e1, Position{0.0f, 0.0f});
	componentManager.addComponent(e1, Velocity{0.0f, 0.0f});
	componentManager.addComponent(e1, BoxComponent(0,0,100,100));

	componentManager.addComponent(e2, Position{ 200.0f, 200.0f });
	componentManager.addComponent(e2, Velocity{ 200.0f, 100.0f });
	componentManager.addComponent(e2, BoxComponent(0, 0, 100, 100));

	player = entityManager.createEntity();
	entities.insert(player);
	componentManager.addComponent(player, Position{ 400.0f, 500.0f });
	componentManager.addComponent(player, Velocity{ 0.0f, 0.0f });
	std::cout << componentManager.getComponent<Position>(player)->x << std::endl;
	std::cout << componentManager.getComponent<Position>(player)->y << std::endl;
	componentManager.addComponent(player, BoxComponent(componentManager.getComponent<Position>(player)->x, componentManager.getComponent<Position>(player)->y, 100, 100));
	
	return true;

}

void Game::processInput()
{

	SDL_Event e;
	const uint8_t* state = SDL_GetKeyboardState(NULL);
	SDL_GetMouseState(&mouseX, &mouseY);

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

		systemManager.getSystem<InputSystem>()->update(player, state);

	}

}

void Game::update()
{
	deltaTime = (SDL_GetTicks() - mLastTick) / 1000;
	//std::cout << deltaTime << std::endl;
	mLastTick = SDL_GetTicks();

	systemManager.getSystem<MovementSystem>()->update(entities, deltaTime);

	
	

	std::cout << "Mouse x: " << mouseX << " y: " << mouseY << std::endl;

}

void Game::generateOutput()
{

	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
	SDL_RenderClear(mRenderer);

	systemManager.getSystem<RenderSystem>()->update(entities);

	SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
	SDL_RenderDrawLine(mRenderer, componentManager.getComponent<Position>(player)->x, componentManager.getComponent<Position>(player)->y, mouseX, mouseY);
	//std::cout << componentManager.getComponent<BoxComponent>(player)->box.x << std::endl;
	

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

	for (auto e : entities)
	{
		entities.erase(e);
	}

	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();

}