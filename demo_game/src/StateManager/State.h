






#pragma once
#include <memory>
#include <SDL.h>


struct Context;

class State {
public:
    virtual ~State() = default;

    
    virtual void OnEnter() {}       
    virtual void OnExit() {}        
    virtual void OnPause() {}       
    virtual void OnResume() {}      

    
    virtual void ProcessInput() = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Render() = 0;

protected:
    std::shared_ptr<Context> m_context;
};

class MainMenuState : public State
{
public:
    MainMenuState(std::shared_ptr<Context> context);

    void OnEnter() override;

    void OnExit() override;

    void OnPause() override;

    void OnResume() override;

    void ProcessInput() override;

    void Update(float deltaTime) override;

    void Render() override;

private:
    std::shared_ptr<Context> m_context;

};

class InGameState : public State
{
public:
    InGameState(std::shared_ptr<Context> context);

    void OnEnter() override;

    void OnExit() override;

    void OnPause() override;

    void OnResume() override;

    void ProcessInput() override;

    void Update(float deltaTime) override;

    void Render() override;

private:
    std::shared_ptr<Context> m_context;

};

class PauseState : public State
{
public:
    PauseState(std::shared_ptr<Context> context);

    void OnEnter() override;

    void OnExit() override;

    void OnPause() override;

    void OnResume() override;

    void ProcessInput() override;

    void Update(float deltaTime) override;

    void Render() override;

private:
    std::shared_ptr<Context> m_context;

};