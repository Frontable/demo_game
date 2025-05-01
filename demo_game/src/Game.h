





#pragma once
#include "SDL.h"
#include "ECS/EntityManager.h"
#include "ECS/ComponentManager.h"
#include "ECS/Components.h"
#include "StateManager/StateMachine.h"
#include "Grid.h"
#include "Fruit.h"
#include <memory>


class Game
{
public:
    Game(const char* title, int width, int height);
    virtual ~Game();

    void run();

protected:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    //std::unique_ptr<Window> m_window;
    EntityManager m_entityManager;
    ComponentManager m_componentManager;
    StateMachine m_stateMachine;

    float m_deltaTime{ 0.0f };
    bool m_isRunning{ true };

    // Core methods to be implemented by derived games
    virtual void initialize() = 0;
    virtual void processInput(SDL_Event& event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;
    virtual void shutDown() = 0;

private:
    void calculateDeltaTime();
    Uint32 m_lastTick{ 0 };
};