













#pragma once

#include "EntityManager.h"
#include "ComponentManager.h"
#include "SystemManager.h"
#include <memory>
#include <type_traits>

#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

class ENGINE_API ECS {
private:
    std::unique_ptr<EntityManager> m_entityManager;
    std::unique_ptr<ComponentManager> m_componentManager;
    std::unique_ptr<SystemManager> m_systemManager;

public:
    ECS();

    Entity createEntity();
    void destroyEntity(Entity entity);

    template<typename T>
    std::shared_ptr<T> registerSystem() {
        static_assert(std::is_base_of<System, T>::value, "T must be derived from System");

        auto system = std::make_shared<T>();
        system->ecs = this;

        m_systemManager->registerSystem<T>(system);
        return system;
    }

    template<typename T>
    void registerComponent() {
        m_componentManager->registerComponent<T>();
    }

    template<typename Sys, typename T>
    void setSystemSignature() {
        auto& sig = m_systemManager->getSignature<Sys>();
        sig.set(m_componentManager->getComponentID<T>());
        m_systemManager->setSignature<Sys>(sig);
    }

    template<typename T>
    void addComponent(Entity entity, T component) {
        auto& sig = m_entityManager->getSignature(entity);
        sig.set(m_componentManager->getComponentID<T>());
        m_componentManager->addComponent(entity, component);
        m_entityManager->setSignature(entity, sig);
        m_systemManager->entitySignatureChange(entity, sig);
    }

    template<typename T>
    T& getComponent(Entity entity) {
        return m_componentManager->getComponent<T>(entity);
    }
};
