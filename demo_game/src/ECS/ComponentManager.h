









#pragma once
#include "EntityManager.h"
#include <unordered_map>

class IComponentArray
{
public:

	virtual ~IComponentArray() =  default;

	virtual void destroy() = 0;

};

template<typename T>
class ComponentArray : public IComponentArray
{
private:
	std::unordered_map<Entity, T*> m_componentArray;


public:

	void addComponent(Entity t_entity, T* component)
	{
		m_componentArray[t_entity] = component;
	}

	T* getComponent(Entity t_entity)
	{
		return m_componentArray[t_entity];
	}

	void destroy() override
	{

	}

};

