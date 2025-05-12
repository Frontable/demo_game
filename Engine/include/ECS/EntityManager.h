







#pragma once

#include "Types.h"
#include <unordered_map>
#include <set>

#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

class ENGINE_API EntityManager
{
public:
    std::unordered_map<Entity, Signature> m_entitySignature;
    std::set<Entity> m_availableEntities;

    Entity nextEntity = 0;

    Entity createEntity();
    void destroyEntity(Entity entity);
    Signature& getSignature(Entity entity);
    void setSignature(Entity entity, Signature signature);
};
