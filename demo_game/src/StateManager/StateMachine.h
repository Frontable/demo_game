







#pragma once
#include <stack>
#include <memory>
#include "GameState.h"

class StateMachine {
public:
    void pushState(GameState* state);
    void popState();    
    void changeState(GameState* state);
    void changeStates(std::unique_ptr<GameState> state);

    GameState* getCurrentState();

    void processInput(SDL_Event& event);
    void update(float deltaTime);
    void render();

private:
    std::stack<GameState*> m_states;
    std::stack<std::unique_ptr<GameState>> m_sta;
};


