





#include "Cons.h"

#include <iostream>
//#include "SDL.h"

class Test
{

};

class App : public Game
{
public:
    App(const char* title, int x, int y, int width, int height)
        :Game(title, x, y, width, height)
    {
        Entity e1 = m_ecs.createEntity();
        m_ecs.registerComponent<Position>();
        m_ecs.registerComponent<Velocity>();
        //m_ecs.registerComponent<Test>();
        auto movementSystem = m_ecs.registerSystem<MovementSystem>();
        m_ecs.setSystemSignature<MovementSystem, Position>();
        m_ecs.addComponent(e1, Position());
        m_ecs.addComponent(e1, Velocity());



    }

    void update() override
    {
        
    }

    void render() override
    {
       
    }

    void processInput() override
    {
        SDL_Event event;
        
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
        }
    }

    void shutDown()
    {
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

};

int main(int argc, char* argv[]) {
    
    App app("Test", 100, 100, 1000, 600);
    
    app.run();

    app.shutDown();

    std::cout<<"Hi"<<std::endl;
    Console console;
    console.print("Hi");
    system("pause");
   
    return 0;
}

