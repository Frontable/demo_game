









#pragma once
#include "EntityManager.h"
#include <unordered_map>
#include <typeinfo>

class IComponentArray
{
public:

	virtual ~IComponentArray() =  default;

	virtual void removeComponent(Entity t_entity) = 0;

};

template<typename T>
class ComponentArray : public IComponentArray
{
private:
	std::unordered_map<Entity, T> m_componentArray;

public:

	void addComponent(Entity t_entity, T component)
	{
		m_componentArray[t_entity] = component;
	}

	T* getComponent(Entity t_entity)
	{
		auto it = m_componentArray.find(t_entity);
		return it != m_componentArray.end() ? &it->second : nullptr;
	}

	void removeComponent(Entity t_entity) override
	{
		auto it = m_componentArray.find(t_entity);
		if (it != m_componentArray.end())
		{
			m_componentArray.erase(it);
		}
	}
};

class ComponentManager
{
private:
	std::unordered_map<size_t, std::shared_ptr<IComponentArray>> m_components;


public:

	template<typename T>
	void registerComponent()
	{
		m_components[typeid(T).hash_code()] = std::make_shared<ComponentArray<T>>();
	}

	template<typename T>
	void addComponent(Entity t_entity, T component)
	{
		getComponentArray<T>()->addComponent(t_entity, component);
	}

	template<typename T>
	T* getComponent(Entity t_entity)
	{
		return getComponentArray<T>()->getComponent(t_entity);
	}


private:

	template<typename T>
	std::shared_ptr<ComponentArray<T>> getComponentArray()
	{

		return std::static_pointer_cast<ComponentArray<T>>(m_components[typeid(T).hash_code()]);

	}

};