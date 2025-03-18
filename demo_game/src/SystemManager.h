






#pragma once
#include<iostream>
#include<unordered_map>
#include<set>
#include<bitset>
#include<memory>
#include<cstdint>
#include<typeinfo>
#include"Components.h"
#include "SDL.h"
#include "ComponentManager.h"







class System
{
public:
	std::set<Entity> entities;
	virtual void update() = 0;
};

class RenderSystem : public System
{
public:

	SDL_Renderer* renderer;
	ComponentManager* componentManager;

	void update() override
	{
		for (auto& e : entities)
		{

			Position* pos = componentManager->getComponent<Position>(e);
			Velocity* vel = componentManager->getComponent<Velocity>(e);

			SDL_Rect r = componentManager->getComponent<BoxComponent>(e)->box;
			r.x = pos->x;
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(renderer, &r);

			pos->x += vel->vx;

		}
	}

};
