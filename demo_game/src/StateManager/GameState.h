








#pragma once
#include "SDL.h"

class GameState {
public:

	virtual ~GameState() = default;

	virtual void enter() = 0;
	virtual void exit() = 0;

	virtual void processInput(SDL_Event& event) = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render() = 0;
};


class MainMenuState : public GameState
{
public:

	void enter() override
	{
		printf("Entered Main Menu State\n");
	}
	void exit() override
	{
		printf("Exited Main Menu State\n");
	}

	void processInput(SDL_Event& event) override
	{
		printf("Precessing input for Main Menu State\n");
	}
	void update(float deltaTime) override
	{
		printf("Updating Main Menu State\n");
	}
	void render() override
	{
		printf("Rendering Main Menu State\n");
	}
};