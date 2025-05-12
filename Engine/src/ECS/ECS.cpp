








#include "ECS/ECS.h"

ECS::ECS() {
    m_entityManager = std::make_unique<EntityManager>();
    m_componentManager = std::make_unique<ComponentManager>();
    m_systemManager = std::make_unique<SystemManager>();
}

Entity ECS::createEntity() {
    return m_entityManager->createEntity();
}

void ECS::destroyEntity(Entity entity) {
    m_entityManager->destroyEntity(entity);
}

Entity EntityManager::createEntity()
{

    Entity newEntity;
    if (m_availableEntities.empty())
    {
        newEntity = nextEntity++;
        printf("%d entity created.", newEntity);
        return newEntity;
    }
    else
    {
        newEntity = *m_availableEntities.begin();
        m_availableEntities.erase(newEntity);
        printf("%d entity created.", newEntity);
        return newEntity;
    }


}

void EntityManager::destroyEntity(Entity entity)
{
    m_entitySignature.erase(entity);
    m_availableEntities.insert(entity);
}

Signature& EntityManager::getSignature(Entity entity)
{
    return m_entitySignature[entity];
}

void EntityManager::setSignature(Entity entity, Signature signature)
{
    m_entitySignature[entity] = signature;
}

void MovementSystem::update(float deltaTime)
{
    if (!m_entities.empty())
    {
        for (auto& entity : m_entities)
        {
            auto& pos = ecs->getComponent<RigidBody2D>(entity);
            pos.x += pos.vx * deltaTime;
            pos.y += pos.vy * deltaTime;

            if (pos.x >= 900)
            {
                pos.x = 900;
                pos.vx *= -1;
            }
            if (pos.x <= 0)
            {
                pos.vx *= -1;
                pos.x = 0;
            }
            if (pos.y >= 500)
            {
                pos.vy *= -1;
                pos.y = 500;
            }
            if (pos.y <= 0)
            {
                pos.vy *= -1;
                pos.y = 0;
            }

        }             
    }    
}

void SpriteSystem::update(SDL_Renderer* renderer)
{
    if (!m_entities.empty())
    {
        for (auto& entity : m_entities)
        {
            auto& pos = ecs->getComponent<RigidBody2D>(entity);
            auto& sprite = ecs->getComponent<SpriteComponent>(entity);

            sprite.box.x = static_cast<int>(pos.x);
            sprite.box.y = static_cast<int>(pos.y);
            sprite.box.w = 100;
            sprite.box.h = 100;

            SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
            SDL_RenderDrawRect(renderer, &sprite.box);

        }
    }
    
}

void InputSystem::update(float deltaTime, const uint8_t* state)
{
    if (!m_entities.empty())
    {
        for (auto& entity : m_entities)
        {
            auto& pos = ecs->getComponent<RigidBody2D>(entity);

            if (state[SDL_SCANCODE_W]) pos.vy = -1;
            else if (state[SDL_SCANCODE_S]) pos.vy = 1;
            else pos.vy = 0;

            if (state[SDL_SCANCODE_A]) pos.vx = -1;
            else if (state[SDL_SCANCODE_D]) pos.vx = 1;
            else pos.vx = 0;

        }
    }

    
}