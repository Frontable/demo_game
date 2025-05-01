






#include "Game.h"
#include "StateManager/GameState.h"

Game::Game(const char* title, int width, int height) {
    m_window = SDL_CreateWindow(title,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    m_renderer = SDL_CreateRenderer(m_window, -1, 0);
    m_lastTick = SDL_GetTicks();

    
    m_stateMachine.changeStates(std::make_unique<MainMenuState>());

}

Game::~Game() {
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}

void Game::run() {
    initialize();

    SDL_Event event;
    while (m_isRunning) {
        while (SDL_PollEvent(&event)) {
            processInput(event);
            if (event.type == SDL_QUIT) {
                m_isRunning = false;
            }
        }

        calculateDeltaTime();
        update(m_deltaTime);
        render();
    }
}

void Game::calculateDeltaTime() {
    Uint32 currentTick = SDL_GetTicks();
    m_deltaTime = (currentTick - m_lastTick) / 1000.0f;
    m_lastTick = currentTick;
}