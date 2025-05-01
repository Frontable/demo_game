








#pragma once
#include "Game.h"

//class Grid;
class App : public Game
{
public:
    App()
        :Game("Snake Game", 1024, 768)
    {
        Entity e1 = m_entityManager.createEntity();
    }
    ~App()
    {
        shutDown();
    }
    void initialize() override
    {

    }

    void processInput(SDL_Event& event) override
    {

        const uint8_t* state = SDL_GetKeyboardState(NULL);
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_QUIT) {
                m_isRunning = false;
            }
            
            if (state[SDL_SCANCODE_D])
            {
                printf("d was pressed\n");
            }

        }
        
    }

    void update(float deltaTime) override
    {
        //printf("d was pressed\n");
    }

    void render() override
    {

    }

    void shutDown() override
    {

    }
	

};