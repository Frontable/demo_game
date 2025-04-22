







#include "Game.h"
#include <iostream>

Game::Game()
	:isRunning(true)
	,mContext(std::make_shared<Context>())
	
{
}

Game::~Game()
{
}


bool Game::initialize()
{

	if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) != 0)
	{
		printf("Failed to initialize SDL: %s \n", SDL_GetError());
		return false;
	}

	mContext->mWindow = SDL_CreateWindow("Game", 100, 100, 1024, 768, 0);
	if (mContext->mWindow == NULL)
	{
		printf("Failed to create window: %s \n", SDL_GetError());
		return false;
	}

	mContext->mRenderer = SDL_CreateRenderer(mContext->mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (mContext->mRenderer == NULL)
	{
		printf("Failed to create renderer: %s \n", SDL_GetError());
		return false;
	}

	
		
	mLastTick = SDL_GetTicks();
	Entity e1 = ent.createEntity();
	ent.deleteEntity(e1);
	Entity e2 = ent.createEntity();
	Entity e3 = ent.createEntity();
	Position* p = new Position();
	comp.addComponent(e1, p);
	auto pos = comp.getComponent(e1);
	printf("%f, %f\n", pos->x, pos->y);
	m_entities.emplace_back(e1);
	//mContext->mStateManager->Add(std::make_unique<MainMenuState>(mContext));
	
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

		mContext->mStateManager->ProcessInput(state);

	}

}

void Game::update()
{
	deltaTime = (SDL_GetTicks() - mLastTick) / 1000;
	//std::cout << deltaTime << std::endl;
	mLastTick = SDL_GetTicks();
	
	mContext->mStateManager->Update(deltaTime);

	for (auto e : m_entities)
	{
		auto pos = comp.getComponent(e);
		pos->x += 1;
		printf("%f, %f\n", pos->x, pos->y);
	}
	

}

void Game::generateOutput()
{

	SDL_SetRenderDrawColor(mContext->mRenderer, 0, 0, 0, 255);
	SDL_RenderClear(mContext->mRenderer);
		
	mContext->mStateManager->Render(mContext->mRenderer);

	SDL_RenderPresent(mContext->mRenderer);

}

void Game::run()
{

	processInput();
	update();
	generateOutput();	
	
}

void Game::shutDown()
{

	

	SDL_DestroyRenderer(mContext->mRenderer);
	SDL_DestroyWindow(mContext->mWindow);
	SDL_Quit();

}