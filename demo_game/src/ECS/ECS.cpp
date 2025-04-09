








#include "ECS.h"


ECS* ECS::s_Instance = nullptr;

void ECS::createEntity()
{
	entityManager.createEntity();
}
