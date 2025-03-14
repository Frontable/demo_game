





#include "ECS.h"

Entity EntityManager::createEntity()
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

void EntityManager::deleteEntity(Entity entity)
{
	entitySignature.erase(entity);
	availableEntities.insert(entity);
}


void EntityManager::setSignature(Entity entity, ComponentSignature componentSignature)
{
	entitySignature[entity] = componentSignature;
}

