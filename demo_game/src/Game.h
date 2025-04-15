





#pragma once
#include "SDL.h"
#include "ECS/SystemManager.h"
#include "StateManager/StateManager.h"

struct Context
{
	std::unique_ptr<StateManager> mStateManager;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;

	Context()
		:mWindow(nullptr)
		,mRenderer(nullptr)
	{
		mStateManager = std::make_unique<StateManager>(this);
	}

};


class Game
{
public:
	Game();

	bool initialize();
	void run();
	void shutDown();

	bool running() const { return isRunning; }

private:

	std::shared_ptr<Context> mContext;

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

	

};