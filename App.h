









#pragma once
#include "Cons.h"
#include <iostream>
#include <stdlib.h>
#include <ctime>

class App : public Game
{
public:
    std::shared_ptr<MovementSystem> m_movementSystem;
    std::shared_ptr<SpriteSystem> m_spriteSystem;
    std::shared_ptr<InputSystem> m_inputSystem;

    App(const char* title, int x, int y, int width, int height);

    void initialize();

    void update(float deltaTime) override;

    void render() override;

    void processInput() override;

    void shutDown();

};