





#pragma once
#include "SDL.h"
#include "ECS/EntityManager.h"
#include "ECS/ComponentManager.h"
#include "ECS/Components.h"
#include "Grid.h"

enum State
{
	MAINMENU,
	INGAME
};


class Game
{
public:
	Game();
	~Game();

	bool initialize();
	void run();
	void shutDown();

	bool running() const { return isRunning; }

	void processMenuInput(SDL_Event e, const uint8_t* state, int t_mouseX, int t_mouseY);
	void updateMenuState();
	void generateMenuOutput();

	void processInGameInput(SDL_Event e, const uint8_t* state, int t_mouseX, int t_mouseY);
	void updateInGameState();
	void generateInGameOutput();

private:
	std::vector<Entity> m_entities;

	State m_state;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	void processInput();
	void update();
	void generateOutput();

	bool isRunning;

	float mLastTick;
	float mCurrTick;
	float deltaTime;

	EntityManager ent;
	ComponentManager comp;

	int m_screenWidth;
	int m_screenHeight;

	int mouseX, mouseY;

	Grid<32> grid;

};