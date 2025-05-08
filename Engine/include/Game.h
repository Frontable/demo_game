






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
class ENGINE_API Game
{
public:
    Game(const char* title, int x, int y, int width, int height)
        :m_isRunning(true)
    {

        m_window = SDL_CreateWindow(title, x, y, width, height, 0);
        m_renderer = SDL_CreateRenderer(m_window, -1, 0);

       

    }

    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    ECS m_ecs;

    void run()
    {
        while (m_isRunning)
        {
            processInput();
            update();
            render();
        }
    }

    bool m_isRunning;

    virtual void processInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

};