






#include "App.h"


App::App(const char* title, int x, int y, int width, int height)
    :Game(title, x, y, width, height)
{


}

void App::initialize()
{
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    int number = rand() % 10;


    m_ecs.registerComponent<RigidBody2D>();
    m_ecs.registerComponent<SpriteComponent>();
    m_ecs.registerComponent<Identity>();

    m_movementSystem = m_ecs.registerSystem<MovementSystem>();
    m_spriteSystem = m_ecs.registerSystem<SpriteSystem>();
    m_inputSystem = m_ecs.registerSystem<InputSystem>();

    m_ecs.setSystemSignature<MovementSystem, RigidBody2D>();

    m_ecs.setSystemSignature<SpriteSystem, RigidBody2D>();
    m_ecs.setSystemSignature<SpriteSystem, SpriteComponent>();

    m_ecs.setSystemSignature<InputSystem, RigidBody2D>();
    m_ecs.setSystemSignature<InputSystem, Identity>();

    for (int i = 0; i < number; ++i)
    {
        Entity entity = m_ecs.createEntity();

        RigidBody2D rb;
        rb.x = rand() % 1000; // random x within screen width
        rb.y = rand() % 700;  // random y within screen height
        rb.vx = 100;
        rb.vy = 100;
        m_ecs.addComponent(entity, rb);

        SpriteComponent sprite;
        sprite.box.x = static_cast<int>(rb.x);
        sprite.box.y = static_cast<int>(rb.y);
        sprite.box.w = 100;
        sprite.box.h = 100;
        m_ecs.addComponent(entity, sprite);        
    }
}

void App::processInput()
{
    SDL_Event event;
    const uint8_t* state = SDL_GetKeyboardState(NULL);

    while (SDL_PollEvent(&event))
    {

        switch (event.type)
        {
        case SDL_QUIT:
            m_isRunning = false;
            break;
        default:
            break;
        }

        //m_inputSystem->update(deltaTime, state);

    }
}

void App::update(float deltaTime)
{    
    m_movementSystem->update(deltaTime);
}

void App::render()
{
    SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
    SDL_RenderClear(m_renderer);

    m_spriteSystem->update(m_renderer);

    SDL_RenderPresent(m_renderer);
}

void App::shutDown()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}