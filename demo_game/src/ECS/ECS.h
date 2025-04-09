








#pragma once
#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"

class ECS
{

public:

	static ECS* getInstance()
	{
		if (s_Instance != nullptr)
		{
			return s_Instance;
		}
		else
		{
			s_Instance = new ECS();
		}

	}


	void createEntity();



private:

	EntityManager entityManager;
	ComponentManager componentManager;
	SystemManager systemManager;

	std::set<Entity> mEntities;

	ECS()
		:componentManager(entityManager)
	{
		

		std::cout << "Singleton created" << std::endl;
	}

	static ECS* s_Instance;

	


};