







#include "Game.h"
#include <iostream>
#include <cstdlib>

Game::Game() 
	:m_window(nullptr)
	, m_renderer(nullptr)
	,isRunning(true)
	,m_screenWidth(1024)
	,m_screenHeight(768)
	,grid(m_screenWidth, m_screenHeight)
	,m_state(MAINMENU)
	
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

	m_window = SDL_CreateWindow("Game", 100, 100, m_screenWidth, m_screenHeight, 0);
	if (m_window == NULL)
	{
		printf("Failed to create window: %s \n", SDL_GetError());
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == NULL)
	{
		printf("Failed to create renderer: %s \n", SDL_GetError());
		return false;
	}	
		
	mLastTick = SDL_GetTicks();
	Entity e1 = ent.createEntity();
	ent.deleteEntity(e1);
	Entity e2 = ent.createEntity();
	Entity e3 = ent.createEntity();

	m_entities.emplace_back(e2);

	comp.registerComponent<Position>();
	comp.addComponent(e2, Position(1.0f, 1.0f));

	//mContext->mStateManager->Add(std::make_unique<MainMenuState>(mContext));
	
	
	int i = rand() % grid.getGridWidth();
	int j = rand() % grid.getGridHeight();
	auto box = grid.getBox(i, j);
	fruit = new Fruit(box);
	printf("WIDTH: %d ---------- HEIGHT: %d\n", i, j);

	return true;

}


/// 
/// INPUT PROCESS
///
void Game::processInput()
{

	SDL_Event e;
	const uint8_t* state = SDL_GetKeyboardState(NULL);
	int x, y;
	SDL_GetMouseState(&x, &y);
	while (SDL_PollEvent(&e))
	{

		switch (m_state)
		{
		case MAINMENU:processMenuInput(e, state, x, y);
			break;
		case INGAME:
			processInGameInput(e, state, x, y);
			break;
		default:
			break;
		}

		

	}

}

void Game::processMenuInput(SDL_Event e, const uint8_t* state, int t_mouseX, int t_mouseY)
{
	if (state[SDL_SCANCODE_ESCAPE])
	{
		m_state = INGAME;
	}
}

void Game::processInGameInput(SDL_Event e, const uint8_t* state, int t_mouseX, int t_mouseY)
{
	if (state[SDL_SCANCODE_ESCAPE])
	{
		m_state = MAINMENU;
	}
	grid.update(t_mouseX, t_mouseY);
}

///
/// GAME UPDATE
///
void Game::update()
{
	deltaTime = (SDL_GetTicks() - mLastTick) / 1000;
	//std::cout << deltaTime << std::endl;
	mLastTick = SDL_GetTicks();
	
	switch (m_state)
	{
	case MAINMENU:
		updateMenuState();
		break;
	case INGAME:
		updateInGameState();
		break;
	default:
		break;
	}

	
	

	for (auto e : m_entities)
	{
		/*
		Position* pos = comp.getComponent<Position>(e);
		printf("%f\n", pos->x);
		*/

	}
}

void Game::updateMenuState()
{
	//printf("MAINE MENU\n");
}

void Game::updateInGameState()
{
	//printf("IN GAME\n");
}

/// 
/// GENERATE OUTPUT
/// 
void Game::generateOutput()
{

	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_renderer);
		
	
	switch (m_state)
	{
	case MAINMENU:
		generateMenuOutput();
		break;
	case INGAME:
		generateInGameOutput();
		break;
	default:
		break;
	}
	

	SDL_RenderPresent(m_renderer);

}

void Game::generateMenuOutput()
{

}

void Game::generateInGameOutput()
{
	grid.print(m_renderer);
	fruit->printFruit(m_renderer);
}

void Game::run()
{

	processInput();
	update();
	generateOutput();	
	
}

void Game::shutDown()
{

	delete fruit;

	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}