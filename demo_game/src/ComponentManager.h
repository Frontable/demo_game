






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
#include "EntityManager.h"


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
	std::unordered_map<size_t, size_t> componentID;
	EntityManager& entityManager;
	int nextComponentID = 0;

public:

	ComponentManager(EntityManager& em) :entityManager(em) {}

	template<typename T>
	void registerComponent()
	{
		size_t typehash = typeid(T).hash_code();
		if (componentID.find(typehash) == componentID.end())
		{
			componentID[typehash] = nextComponentID++;
			//std::cout << "ID = " << componentID[typehash] << std::endl;
		}

		componentArray[typehash] = std::make_shared<ComponentArray<T>>();
		//std::cout << "Registered component: "<< typeid(T).name() << " with ID: " << componentID[typehash] << std::endl;

	}

	template<typename T>
	void addComponent(Entity entity, T component)
	{
		getComponentArray<T>()->add(entity, component);
		ComponentSignature componentSignature = entityManager.getSignature(entity);
		componentSignature.set(getComponentID<T>());
		entityManager.setSignature(entity, componentSignature);
		//std::cout << componentSignature << std::endl;
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

	template<typename T>
	int getComponentID()
	{
		return componentID[typeid(T).hash_code()];
	}

};