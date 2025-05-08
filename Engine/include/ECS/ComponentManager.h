






#pragma once
#include "EntityManager.h"
#include <unordered_map>
#include <memory>
#include <typeinfo>
#include <iostream>
#include "SystemManager.h"

#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

struct Component
{
	 uint8_t id = 5;
};



struct Position : public Component
{
	Position()
	{
		id++;
		std::cout << "Position id:" << id << std::endl;
	}
	int i;
};

struct Velocity : public Component
{
	Velocity()
	{
		id += 1;
		std::cout << "Velocity id:" << id << std::endl;
	}
	int i;
};

class IComponentArray
{
public:
	~IComponentArray() = default;
	virtual void removeComponent(Entity entity) = 0;

};




template<typename T>
class ComponentArray : public IComponentArray
{
private:
	std::unordered_map<Entity, T> m_componentArray;

public:

	void addComponent(Entity entity, T component)
	{
		auto it = m_componentArray.find(entity);
		if (it != m_componentArray.end())
		{
			m_componentArray.emplace(entity, component);
		}
		
	}
	

	void removeComponent(Entity entity) override
	{
		auto it = m_componentArray.find(entity);
		if (it != m_componentArray.end())
		{
			m_componentArray.erase(entity);
		}
	}
};

class ENGINE_API ComponentManager
{
private:
	std::unordered_map<size_t, std::shared_ptr<IComponentArray>> m_componentArray;
	std::unordered_map<size_t, uint8_t> m_componentID;
	uint8_t m_nextID = 0;
public:	

	template<typename T>
	void registerComponent()
	{		
		
		size_t type = typeid(T).hash_code();
		m_componentArray[type] = std::make_shared<ComponentArray<T>>();
		m_componentID[type] = m_nextID++;
		std::cout << "Registered component " << typeid(T).name() << " with code " << type << std::endl;
	}

	template<typename T>
	void addComponent(Entity entity, T component)
	{
		getComponentArray<T>()->addComponent(entity, component);
	}

	template<typename T>
	void removeComponent(Entity entity)
	{
		getComponentArray<T>()->removeComponent(entity);
	}
	
	template<typename T>
	uint8_t& getComponentID()
	{
		return m_componentID[typeid(T).hash_code()];
	}

public:
	template<typename T>
	std::shared_ptr<ComponentArray<T>> getComponentArray()
	{
		return std::static_pointer_cast<ComponentArray<T>>(m_componentArray[typeid(T).hash_code()]);
	}

};