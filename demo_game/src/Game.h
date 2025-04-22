





#pragma once
#include "SDL.h"
#include "StateManager/StateManager.h"
#include "ECS/EntityManager.h"
#include "ECS/ComponentManager.h"
#include "ECS/Components.h"

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
	~Game();

	bool initialize();
	void run();
	void shutDown();

	bool running() const { return isRunning; }

private:
	std::vector<Entity> m_entities;
	std::shared_ptr<Context> mContext;

	void processInput();
	void update();
	void generateOutput();

	bool isRunning;

	float mLastTick;
	float mCurrTick;
	float deltaTime;

	EntityManager ent;
	ComponentArray<Position> comp;


	int mouseX, mouseY;

	

};