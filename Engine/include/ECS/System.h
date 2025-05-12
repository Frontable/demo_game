









#pragma once

#include "Types.h"
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

class ECS; // Forward declaration

class ENGINE_API System {
public:
    ECS* ecs = nullptr;
    std::set<Entity> m_entities;
    virtual ~System() = default;
};

class ENGINE_API MovementSystem : public System {
public:
    void update(float deltaTime);
};

class ENGINE_API SpriteSystem : public System {
public:
    void update(SDL_Renderer* renderer);
};

class ENGINE_API InputSystem : public System {
public:
    void update(float deltaTime, const uint8_t* state);
};