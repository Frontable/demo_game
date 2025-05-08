






#pragma once
#include <cstdint>
#include <set>
#include <unordered_map>
#include <queue>
#include <bitset>
#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif


using Entity = uint32_t;
static const uint8_t MAX_COMPONENTS = 32;
using Signature = std::bitset<MAX_COMPONENTS>;

class ENGINE_API EntityManager
{
public:
	std::unordered_map<Entity, Signature> m_entitySignature;
	std::set<Entity> m_availableEntities;
	

	Entity nextEntity = 0;
	Entity createEntity()
	{
		Entity newEntity;
		if (!m_availableEntities.empty())
		{
			newEntity = *m_availableEntities.begin();
			m_availableEntities.erase(newEntity);
			m_entitySignature[newEntity] = Signature();
		}
		else
		{
			newEntity = nextEntity++;
			m_entitySignature[newEntity] = Signature();
		}

		printf("Entity %d created.\n", newEntity);
		
		return newEntity;

	}

	void destroyEntity(Entity entity)
	{
		if(m_entitySignature.count(entity))
		{
			m_entitySignature.erase(entity);
			m_availableEntities.insert(entity);
		}

		printf("Entity %d destroyed.\n", entity);

	}

	Signature getSignature(Entity entity)
	{
		return m_entitySignature[entity];
	}

	void setSignature(Entity entity, Signature signature)
	{
		m_entitySignature[entity] = signature;
	}



};

