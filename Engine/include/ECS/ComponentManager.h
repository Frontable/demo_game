








#pragma once

#include "Types.h"
#include <unordered_map>
#include <memory>
#include <typeinfo>
#include <iostream>
#include "Math/Math.h"

#include "SDL.h"

#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif


struct RigidBody2D {
    Vector2 position;
    Vector2 velocity;
};

struct SpriteComponent
{
    SDL_Rect box;
};

struct Identity
{
    Identity() {}
    Identity(char* identity)
        :m_identity(identity)
    {
        
    }
    char* m_identity;
};

class IComponentArray {
public:
    virtual ~IComponentArray() = default;
    virtual void removeComponent(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
private:
    std::unordered_map<Entity, T> m_componentArray;

public:
    void addComponent(Entity entity, T component) {
        m_componentArray[entity] = component;
    }

    T& getComponent(Entity entity) {
        return m_componentArray[entity];
    }

    void removeComponent(Entity entity) override {
        m_componentArray.erase(entity);
    }
};

class ENGINE_API ComponentManager {
private:
    std::unordered_map<size_t, std::shared_ptr<IComponentArray>> m_componentArray;
    std::unordered_map<size_t, uint8_t> m_componentID;
    uint8_t m_nextID = 0;

public:
    template<typename T>
    void registerComponent() {
        size_t type = typeid(T).hash_code();
        m_componentArray[type] = std::make_shared<ComponentArray<T>>();
        m_componentID[type] = m_nextID++;
        std::cout << "Registered component " << typeid(T).name() << " with code " << type << std::endl;
    }

    template<typename T>
    void addComponent(Entity entity, T component) {
        getComponentArray<T>()->addComponent(entity, component);
    }

    template<typename T>
    void removeComponent(Entity entity) {
        getComponentArray<T>()->removeComponent(entity);
    }

    template<typename T>
    uint8_t& getComponentID() {
        return m_componentID[typeid(T).hash_code()];
    }

    template<typename T>
    T& getComponent(Entity entity) {
        return getComponentArray<T>()->getComponent(entity);
    }

    template<typename T>
    std::shared_ptr<ComponentArray<T>> getComponentArray() {
        return std::static_pointer_cast<ComponentArray<T>>(m_componentArray[typeid(T).hash_code()]);
    }
};
