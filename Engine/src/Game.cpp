





#include "Game.h"
#include <iostream>

Game::Game(const char* title, int x, int y, int width, int height)
    :m_isRunning(true)
{

    m_window = SDL_CreateWindow(title, x, y, width, height, 0);
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    timer->getInstance();



}

void Game::run() {
    while (m_isRunning) {
        
        timer->getInstance()->calculateDeltaTime();
        processInput();
        update(timer->getInstance()->getDeltaTime());

        SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
        SDL_RenderClear(m_renderer);
        render();
        SDL_RenderPresent(m_renderer);
    }
}
