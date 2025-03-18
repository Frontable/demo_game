







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


constexpr uint32_t MaxComponents = 32;
using Entity = uint32_t;
using ComponentSignature = std::bitset<MaxComponents>;


class EntityManager
{
private:
	std::unordered_map<Entity, ComponentSignature> entitySignature;
	std::set<Entity> availableEntities;
	Entity nextEntity = 0;

public:
	Entity createEntity()
	{


		Entity entity;
		if (!availableEntities.empty())
		{
			entity = *availableEntities.begin();
			availableEntities.erase(entity);
		}
		else
		{
			entity = nextEntity++;
		}

		entitySignature[entity] = ComponentSignature();
		return entity;


	}

	void deleteEntity(Entity entity)
	{

		entitySignature.erase(entity);
		availableEntities.insert(entity);

	}

	void setSignature(Entity entity, ComponentSignature componentSignature)
	{

		entitySignature[entity] = componentSignature;

	}

};