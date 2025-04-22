





#pragma once
#include <cstdint>
#include <set>
#include <iostream>

using Entity = std::uint8_t;

class EntityManager
{

private:
	std::set<Entity> m_entities;
	std::set<Entity> m_availableEntities;

	Entity m_nextEntity = 0;


public:

	Entity createEntity()
	{


		Entity entity;

		if (m_availableEntities.empty())
		{
			entity = m_nextEntity;
			m_entities.insert(entity);
			m_nextEntity++;
			printf("Entity created: %d: \n", entity);
		}
		else
		{
			entity = *m_availableEntities.begin();
			m_entities.insert(entity);
			m_availableEntities.erase(entity);
			printf("Entity created: %d: \n", entity);
		}

		return entity;

	}

	void deleteEntity(Entity t_entity)
	{

		m_entities.erase(t_entity);
		m_availableEntities.insert(t_entity);
		printf("Entity deleted: %d: \n", t_entity);

	}

	~EntityManager()
	{
		for (auto& e : m_entities)
		{
			m_entities.erase(e);
		}

		for (auto& e : m_availableEntities)
		{
			m_availableEntities.erase(e);
		}

	}


};



