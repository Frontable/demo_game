






#include "State.h"
#include "../Game.h"

MainMenuState::MainMenuState(std::shared_ptr<Context> context) : m_context(context) {}

void MainMenuState::OnEnter()  
{
    
    SDL_Log("PauseState entered");
}

void MainMenuState::OnExit()  
{
    
    SDL_Log("PauseState exited");
}

void MainMenuState::OnPause()  
{
    
    SDL_Log("PauseState paused");
}

void MainMenuState::OnResume()  
{
    
    SDL_Log("PauseState resumed");
}

void MainMenuState::ProcessInput()  
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            
        }
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                
                m_context->mStateManager->ResumePaused();
            }
        }
    }
}

void MainMenuState::Update(float deltaTime)
{
    
}

void MainMenuState::Render() 
{
    
    SDL_SetRenderDrawColor(m_context->mRenderer, 0, 0, 0, 128);
    SDL_Rect overlay = { 0, 0, 1024, 768 };
    SDL_RenderFillRect(m_context->mRenderer, &overlay);

    
}



InGameState::InGameState(std::shared_ptr<Context> context) : m_context(context) {}

void InGameState::OnEnter()
{
    
    SDL_Log("PauseState entered");
}

void InGameState::OnExit()
{
    
    SDL_Log("PauseState exited");
}

void InGameState::OnPause()
{
    
    SDL_Log("PauseState paused");
}

void InGameState::OnResume()
{
    
    SDL_Log("PauseState resumed");
}

void InGameState::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            
        }
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
               
                m_context->mStateManager->ResumePaused();
            }
        }
    }
}

void InGameState::Update(float deltaTime)
{
    
}

void InGameState::Render()
{
   
    SDL_SetRenderDrawColor(m_context->mRenderer, 0, 0, 0, 128);
    SDL_Rect overlay = { 0, 0, 1024, 768 };
    SDL_RenderFillRect(m_context->mRenderer, &overlay);

    
}



PauseState::PauseState(std::shared_ptr<Context> context) : m_context(context) {}

void PauseState::OnEnter()
{
    
    SDL_Log("PauseState entered");
}

void PauseState::OnExit()
{
    
    SDL_Log("PauseState exited");
}

void PauseState::OnPause()
{
    
    SDL_Log("PauseState paused");
}

void PauseState::OnResume()
{
    
    SDL_Log("PauseState resumed");
}

void PauseState::ProcessInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            
        }
        else if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                
                m_context->mStateManager->ResumePaused();
            }
        }
    }
}

void PauseState::Update(float deltaTime)
{
    
}

void PauseState::Render()
{
   
    SDL_SetRenderDrawColor(m_context->mRenderer, 0, 0, 0, 128);
    SDL_Rect overlay = { 0, 0, 1024, 768 };
    SDL_RenderFillRect(m_context->mRenderer, &overlay);

  
}