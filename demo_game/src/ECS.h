






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
	Entity createEntity();

	void deleteEntity(Entity entity);

	void setSignature(Entity entity, ComponentSignature componentSignature);

};

class IComponentArray
{
public:
	virtual ~IComponentArray() = default;

	virtual void destroy() = 0;

};

template<typename T>
class ComponentArray : public IComponentArray
{
private:
	std::unordered_map<Entity, T> componentData;

public:

	void add(Entity entity, T component)
	{
		componentData.emplace(entity, component);
	}

	void remove(Entity entity)
	{
		componentData.erase(entity);
	}

	T* get(Entity entity)
	{
		auto it = componentData.find(entity);
		return it != componentData.end() ? &it->second : nullptr;
	}

	void destroy() override
	{

	}


};


class ComponentManager
{
private:
	std::unordered_map<size_t, std::shared_ptr<IComponentArray>> componentArray;

public:
	
	template<typename T>
	void registerComponent()
	{
		componentArray[typeid(T).hash_code()] = std::make_shared<ComponentArray<T>>();
	}

	template<typename T>
	void addComponent(Entity entity, T component)
	{
		getComponentArray<T>()->add(entity, component);
	}

	template<typename T>
	void removeComponent(Entity entity)
	{
		getComponentArray<T>()->remove(entity);
	}

	template<typename T>
	T* getComponent(Entity entity)
	{
		return getComponentArray<T>()->get(entity);
	}

private:
	template<typename T>
	std::shared_ptr<ComponentArray<T>> getComponentArray()
	{
		return std::static_pointer_cast<ComponentArray<T>>(componentArray[typeid(T).hash_code()]);
	}

};


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

			SDL_Rect r = componentManager->getComponent<BoxComponent>(e)->box;
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			SDL_RenderDrawRect(renderer, &r);

		}
	}

};
