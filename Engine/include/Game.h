






#pragma once
#ifdef _WIN32
#ifdef ENGINE_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif
#else
#define ENGINE_API
#endif

#include "SDL.h"
#include "ECS/EntityManager.h"
#include "ECS/ECS.h"
#include "Timer.h"

class ENGINE_API Game
{
public:
    Game(const char* title, int x, int y, int width, int height);
    
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    ECS m_ecs;
    Timer* timer;
    bool m_isRunning;
    void run();
private:

    

    float now{};
    float last{};
    float  deltaTime{};

    virtual void processInput() = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render() = 0;

};