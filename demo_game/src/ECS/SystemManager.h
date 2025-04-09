






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
#include <typeindex>







class System
{
public:
	
	
};


class SystemManager
{

private:
	std::unordered_map<std::type_index, std::shared_ptr<System>> systems;

public:

	template<typename T>
	void registerSystem()
	{
		systems[typeid(T)] = std::make_shared<T>();
	}

	template<typename T>
	T* getSystem()
	{
		return static_cast<T*>(systems[typeid(T)].get());
	}

};


class RenderSystem : public System
{
public:

	SDL_Renderer* renderer;
	ComponentManager* componentManager;

	void update(std::set<Entity>& entities)
	{
		for (auto e : entities)
		{
			Position* pos = componentManager->getComponent<Position>(e);
			BoxComponent* box = componentManager->getComponent<BoxComponent>(e);

			if (pos && box) {
				//SDL_Rect r = box->box;

				

				box->box.x = static_cast<int>(pos->x) - (box->box.w / 2);
				box->box.y = static_cast<int>(pos->y) - (box->box.h / 2);

				
				
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				SDL_RenderDrawRect(renderer, &box->box);
			}
		}
	}

};

class MovementSystem : public System
{

public:
	ComponentManager* componentManager;



	void update(std::set<Entity>& entities, float dt)
	{

		for (auto& e : entities)
		{
			Position* pos = componentManager->getComponent<Position>(e);
			Velocity* vel = componentManager->getComponent<Velocity>(e);
			//BoxComponent* box = componentManager->getComponent<BoxComponent>(e);

			if (pos && vel) {
				pos->x += vel->vx * dt;  // Multiply by delta time!
				pos->y += vel->vy * dt;
			}

			/*if (box->box.x <= 0)
			{
				box->box.x = 0;
				vel->vx *= -1;
			}

			if (box->box.x >= 1024)
			{
				box->box.x = 1024;
				vel->vx *= -1;
			}

			if (box->box.y <= 0)
			{
				box->box.y = 0;
				vel->vy *= -1;
			}

			if (box->box.y >= 768)
			{
				box->box.y = 768;
				vel->vx *= -1;
			}*/

		}

	}

};

class InputSystem : public System
{

public:

	ComponentManager* componentManager;

	void update(Entity& player,const uint8_t* state)
	{

		Velocity* vel = componentManager->getComponent<Velocity>(player);

		vel->vx = 0.0f;
		vel->vy = 0.0f;

		if (state[SDL_SCANCODE_D])
		{
			vel->vx += 250.0f;
		}

		if (state[SDL_SCANCODE_A])
		{
			vel->vx -= 250.0f;
		}
		
		if (state[SDL_SCANCODE_S])
		{
			vel->vy += 300.0f;
		}

		if (state[SDL_SCANCODE_W])
		{
			vel->vy -= 300.0f;
		}

	}

};

class CollisionSystem : public System
{

public:

	ComponentManager* componentManager;

	void update(std::set<Entity>& entities)
	{

		for (auto& e : entities)
		{
			
		}

	}

};