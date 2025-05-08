









#pragma once
#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include <memory>
#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

class ENGINE_API ECS
{
private:
	std::unique_ptr<EntityManager> m_entityManager;
	std::unique_ptr<ComponentManager> m_componentManager;
	std::unique_ptr<SystemManager> m_SystemManager;

public:

	ECS()
	{
		m_entityManager = std::make_unique<EntityManager>();
		m_componentManager = std::make_unique<ComponentManager>();
		m_SystemManager = std::make_unique<SystemManager>();
	}

	Entity createEntity()
	{
		return m_entityManager->createEntity();
	}

	void destroyEntity(Entity entity)
	{
		m_entityManager->destroyEntity(entity);
	}

	template<typename T>
	std::shared_ptr<T> registerSystem()
	{
		return m_SystemManager->registerSystem<T>();
	}

	template<typename T>
	void registerComponent()
	{
		m_componentManager->registerComponent<T>();
	}

	template<typename Sys,typename T>
	void setSystemSignature()
	{
		Signature& newSignature = m_SystemManager->getSignature<Sys>();
		newSignature.set(m_componentManager->getComponentID<T>());

		m_SystemManager->setSignature<Sys>(newSignature);

	}

	template<typename T>
	void addComponent(Entity entity, T component)
	{
		Signature& newSignature = m_entityManager->getSignature(entity);
		newSignature.set(m_componentManager->getComponentID<T>());
		m_componentManager->addComponent(entity, component);
		m_entityManager->setSignature(entity, newSignature);

		m_SystemManager->entitySignatureChange(entity, newSignature);

	}
};